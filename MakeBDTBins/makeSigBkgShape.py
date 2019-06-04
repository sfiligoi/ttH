from ROOT import *
from tdrStyle import *
setTDRStyle()
from subprocess import call

gSystem.AddIncludePath("-I$CMSSW_BASE/src/ ")
#gSystem.Load("$CMSSW_BASE/lib/slc6_amd64_gcc481/libHiggsAnalysisCombinedLimit.so")
gSystem.Load("$CMSSW_BASE/lib/slc6_amd64_gcc630/libHiggsAnalysisCombinedLimit.so")
gSystem.AddIncludePath("-I$ROOFITSYS/include")
gSystem.AddIncludePath("-Iinclude/")


def GetMultiDataset(t, cuts, datanameTag, debug=False):
    w = RooWorkspace("wbkg_13TeV")

    # for tree from train.py
    rv_mass = RooRealVar("mass","",100,180)
    rv_mva_score = RooRealVar("mva_score","",0,1)
    rv_sample_id = RooRealVar("sample_id","",0,2)
    rv_weight = RooRealVar("weight","",-999,999)
    
    h_mgg_hists = []
    d_mgg_unbin = []
    d_mgg_unbin_rename = []
    
    for i in range(len(cuts)):

        h_mgg_hists.append(TH1F("h_mgg_hist_" + str(i), "", 160, 100, 180))
        #t.Project(h_mgg_hists[-1].GetName(), "mass_", "evt_weight_*(" + cuts[i] + ")")
        #d_mgg_bin.append(RooDataHist(datanameTag + '_' + str(i), "", RooArgList(w.var("CMS_hgg_mass")), h_mgg_hists[-1], 1) )

        tmpdata = RooDataSet(datanameTag + '_' + str(i),"",t,RooArgSet(rv_mass, rv_sample_id, rv_weight, rv_mva_score), cuts[i])
        d_mgg_unbin.append( RooDataSet(tmpdata.GetName(), "", tmpdata, tmpdata.get(), "1", "weight" ) )

        d_mgg_unbin.append(tmpdata)
        #getattr(w,'import')(d_mgg_bin[-1], datanameTag + '_' + str(i), RooCmdArg())
        getattr(w,'import')(d_mgg_unbin[-1], RooCmdArg())
       
    w.writeToFile("allData.root")
        
def GetDataset(t, cut, tag, savepath, debug=False):

    w = RooWorkspace("w")
    w.factory("CMS_hgg_mass[100,180]")
    w.factory("MH[125]")

    h_mgg = TH1F("h_mgg", "h_mgg", 160, 100, 180)
    h_mgg.Sumw2()
    t.Project(h_mgg.GetName(), "mass", "weight*(" + cut + ")")
    #t.Project(h_mgg.GetName(), "mass", "1*(" + cut + ")")
    print "integral", h_mgg.Integral()
    
    #d_mgg_bin = RooDataHist("roohist_data_mass_TTHHadronicTag", "", RooArgList(w.var("CMS_hgg_mass")), h_mgg, 1)
    d_mgg_bin = RooDataHist("roohist_data_mass_" + tag, "", RooArgList(w.var("CMS_hgg_mass")), h_mgg, 1)
    print "bin dataset", d_mgg_bin.sumEntries(), d_mgg_bin.numEntries()


    '''
    rv_sample_id = RooRealVar("sample_id","",0,2)
    rv_mass = RooRealVar("mass","",100,180)
    rv_weight = RooRealVar("weight","",-999,999)
    rv_mva_score = RooRealVar("mva_score","",0,1)
    rv_signal_mass_label = RooRealVar("signal_mass_label","",0,2)

    d_mgg_unbin = RooDataSet("d_mgg_unbin","",t,RooArgSet(rv_mass, rv_sample_id, rv_weight, rv_mva_score, rv_signal_mass_label), cut)
    d_mgg_unbin_w = RooDataSet(d_mgg_unbin.GetName(), "", d_mgg_unbin, d_mgg_unbin.get(), "1", "weight") 
    #print d_mgg_unbin.sumEntries(), d_mgg_unbin.numEntries()
    print "unbin dataset", d_mgg_unbin_w.sumEntries(), d_mgg_unbin_w.numEntries()
    '''
    
    if debug:

        h_mgg_sig = TH1F("h_mgg_sig", "h_mgg_sig", 160, 100, 180)
        h_mgg_bkg = TH1F("h_mgg_bkg", "h_mgg_bkg", 160, 100, 180)
        h_mgg_data = TH1F("h_mgg_data", "h_mgg_data", 160, 100, 180)
        t.Project(h_mgg_sig.GetName(), "mass", "weight*( sample_id == 1 && mass > 100 && mass < 180 && signal_mass_label== 0)")
        t.Project(h_mgg_bkg.GetName(), "mass", "weight*( sample_id == 0 && ((mass > 100 && mass < 120) || ( mass > 130 &&mass < 180 )))")
        t.Project(h_mgg_data.GetName(), "mass", "weight*( sample_id == 2 && mass > 100 && mass < 180)")
  
        c1 = TCanvas("c1", "c1", 800, 800)
        dummy = TH1D("dummy","dummy",1,100,180)
        dummy.SetMinimum(0)
        yMax = h_mgg_data.GetMaximum()*1.5
        #yMax = h_mgg.GetMaximum()*1.5
        dummy.SetMaximum(yMax)
        dummy.SetLineColor(0)
        dummy.SetMarkerColor(0)
        dummy.SetLineWidth(0)
        dummy.SetMarkerSize(0)
        dummy.GetYaxis().SetTitle("Events")
        dummy.GetYaxis().SetTitleOffset(1.3)
        dummy.GetXaxis().SetTitle("m_{#gamma#gamma}")
        dummy.Draw()

        h_mgg_sig.SetFillColor(2)
        h_mgg_bkg.SetFillColor(4)
        mc = THStack("mc","mc")
        mc.Add(h_mgg_bkg)
        mc.Add(h_mgg_sig)
        mc.Draw("same hist")

        h_mgg_data.SetMarkerStyle(20)
        h_mgg_data.Draw("same pe")

        h_mgg.Draw("same pe")
        
        c1.SaveAs(savepath+"/" + tag + "_data_mc.png")
        c1.SaveAs(savepath+"/" + tag + "_data_mc.pdf")

    return d_mgg_bin

def GetSigPdf(events, tag, savename, savepath, modelpath):

    # input is a RooDataSet
    # tag is TTHHadronic_n
    call("mkdir -p models/" + modelpath, shell=True)
    
    w = RooWorkspace("wsig_13TeV")
    w.factory("CMS_hgg_mass[100,180]")
    w.factory("MH[125]")

    norm = events.sumEntries()
    print "sumEtries: ", norm
    
    # change pdf name, parameters name
    w.factory("DoubleCB:"+tag+"(CMS_hgg_mass, mean_"+tag+"[125,120,130], sigma_"+tag+"[1,0,5], a1_"+tag+"[1,0,10], n1_"+tag+"[1,0,10], a2_"+tag+"[1,0,10], n2_"+tag+"[1,0,10])")

    w.pdf(tag).fitTo(events)

    w.var("mean_"+tag).setConstant()
    w.var("sigma_"+tag).setConstant()
    w.var("a1_"+tag).setConstant()
    w.var("a2_"+tag).setConstant()
    w.var("n1_"+tag).setConstant()
    w.var("n2_"+tag).setConstant()

    #rv_norm = RooRealVar("rv_norm_"+tag, "", norm)
    rv_norm = RooRealVar(tag+"_norm", "", norm)

    exPdf = RooExtendPdf("extend" + tag, "", w.pdf(tag), rv_norm)
    getattr(w,'import')(rv_norm)
    getattr(w,'import')(exPdf)
    
    frame = w.var("CMS_hgg_mass").frame()
    events.plotOn(frame)
    w.pdf(tag).plotOn(frame)
    w.pdf(tag).paramOn(frame)
    
    c1 = TCanvas("c1", "c1", 800, 800)
    dummy = TH1D("dummy","dummy",1,100,180)
    dummy.SetMinimum(0)
    yMax = norm*0.2
    dummy.SetMaximum(yMax)
    dummy.SetLineColor(0)
    dummy.SetMarkerColor(0)
    dummy.SetLineWidth(0)
    dummy.SetMarkerSize(0)
    dummy.GetYaxis().SetTitle("Events")
    dummy.GetYaxis().SetTitleOffset(1.3)
    dummy.GetXaxis().SetTitle("m_{#gamma#gamma}")
    dummy.Draw()

    frame.Draw("same")
    c1.SaveAs(savepath + "/fit_sig_" + savename + ".png")
    c1.SaveAs(savepath + "/fit_sig_" + savename + ".pdf")

    w.writeToFile("models/" + modelpath + "/" + savename + ".root")
    
def GetBkgPdf(events, tag, savename, savepath, modelpath):

    call("mkdir -p models/" + modelpath, shell=True)

    # input is a RooDataSet
    # tag is TTHHadronic_n or TTHLeptonic_n
    w = RooWorkspace("wbkg_13TeV")
    w.factory("CMS_hgg_mass[100,180]")
    
    norm = events.sumEntries()

    # change pdf name, parameters name
    #w.factory("DoubleCB:dcb(CMS_hgg_mass, mean[125,120,130], sigma[1,0,5], a1[1,0,10], n1[1,0,10], a2[1,0,10], n2[1,0,10])")

    w.var("CMS_hgg_mass").setRange("SL", 100, 120)
    w.var("CMS_hgg_mass").setRange("SU", 130, 180)

    w.factory("Exponential::"+tag+"(CMS_hgg_mass, tau[-1,-10,0])")
    
    w.pdf(tag).fitTo(events, RooFit.Range("SL,SU"))

    frame = w.var("CMS_hgg_mass").frame()

    events.plotOn(frame, RooFit.CutRange("unblindReg_1"), RooFit.Binning(80))
    events.plotOn(frame, RooFit.CutRange("unblindReg_2"), RooFit.Binning(80))
    #events.plotOn(frame, RooFit.Invisible())

    w.pdf(tag).plotOn(frame)

    w.var("CMS_hgg_mass").setRange("blind",120,130)
    l=ROOT.RooArgSet(w.var("CMS_hgg_mass"))
    frac = w.pdf(tag).createIntegral(l,l,"blind")
    print "frac", frac.getVal()

    norm = norm/(1-frac.getVal())
    w.factory(tag+"_norm["+str(norm)+",0,"+str(3*norm)+"]")
    
    c1 = TCanvas("c1", "c1", 800, 800)
    dummy = TH1D("dummy","dummy",1,100,180)
    dummy.SetMinimum(0)
    yMax = norm*0.2
    dummy.SetMaximum(yMax)
    dummy.SetLineColor(0)
    dummy.SetMarkerColor(0)
    dummy.SetLineWidth(0)
    dummy.SetMarkerSize(0)
    dummy.GetYaxis().SetTitle("Events")
    dummy.GetYaxis().SetTitleOffset(1.3)
    dummy.GetXaxis().SetTitle("m_{#gamma#gamma}")
    dummy.Draw()

    frame.Draw("same")
    c1.SaveAs(savepath + "/fit_bkg_" + savename + ".png")
    c1.SaveAs(savepath + "/fit_bkg_" + savename + ".pdf")

    events.SetName(events.GetName() + "_" + args.nbin)
    getattr(w,'import')(events, RooCmdArg()) 
    w.writeToFile("models/" + modelpath + "/" + savename + ".root")

### as of May 30 th, it works under CMSSW_7_1_5

# need yield and shape for given events with mgg
#filename = "ttHHadronic_1617_FinalFitTree.root"
#filename = "ttHHadronic_v05.08_FinalFitTree.root"
#filename = "/home/users/sjmay/ttH/MVAs/ttHHadronic__v1.5_8May2019_forHualin_2017_Presel_impute_FinalFitTree.root"
#filename = "/home/users/sjmay/ttH/MVAs/ttHHadronic__v1.5_1May2019_RunII_MVA_Presel_impute_cutPtoM_FinalFitTree.root"
#filename = "/home/users/sjmay/ttH/MVAs/ttHHadronic__v1.5_1May2019_RunII_MVA_Presel_impute_FinalFitTree.root"
#filename = "/home/users/sjmay/ttH/Loopers/MVABaby_ttHHadronic_v1.5_8May2019_forHualin_2017_Presel_impute.root"
#filename = "/home/users/sjmay/ttH/MVAs/ttHHadronic__unblinded_forHualin_15May2019_2017_Presel_impute_FinalFitTree.root"
#filename = "/home/users/sjmay/ttH/MVAs/ttHHadronic__unblinded_forHualin_15May2019_RunII_MVA_Presel_impute_cutPtoM_FinalFitTree.root"
#filename = "/home/users/sjmay/ttH/MVAs/ttHHadronic__unblinded_forHualin_15May2019_RunII_MVA_Presel_impute_FinalFitTree.root"
#filename = "/home/users/sjmay/ttH/MVAs/ttHHadronic__v1.5_forHualin_16May2019_RunII_MVA_Presel_impute_cutPtoM_FinalFitTree.root"
#filename = "/home/users/sjmay/ttH/MVAs/ttHHadronic__v1.5_forHualin_16May2019_RunII_MVA_Presel_impute_FinalFitTree.root"

# had
#hadfilename = "/home/users/sjmay/ttH/MVAs/ttHHadronic__v1.6_28May2019_RunII_MVA_Presel_impute_addDNNs_addTopTag_FinalFitTree.root"
hadfilename = "/home/users/sjmay/ttH/MVAs/ttHHadronic__unblinded_forHualin_15May2019_2017_Presel_impute_FinalFitTree.root"
# lep
#lepfilename = "/home/users/sjmay/ttH/MVAs/ttHLeptonic__v1.6_28May2019_RunII_MVA_Presel_addDNN_FinalFitTree.root"
lepfilename = "/home/users/hmei/ttH/MVAs/ttHLeptonic_test2017_FinalFitTree.root"
#tag = "TTHHadronicTag"
#tag = "TTHLeptonicTag"
filename = ""

## do scan
import argparse
def ParseOption():

    parser = argparse.ArgumentParser(description='submit all')
    parser.add_argument('-l', dest='low', type=str, help='low bdt cut')
    parser.add_argument('--hi', dest='high', type=str, help='high bdt cut')
    parser.add_argument('-b', dest='nbin', type=str, help='bin number')
    parser.add_argument('-i', dest='index', type=str, help='for version')
    parser.add_argument('--tag', dest='tag', type=str, help='lep or had')
    parser.add_argument('--modelPath', dest='modelPath', type=str, help='model path')
    args = parser.parse_args()
    return args

args=ParseOption()

tag = args.tag
if tag == "TTHHadronicTag":
    filename = hadfilename
if tag == "TTHLeptonicTag":
    filename = lepfilename

savepath = "/home/users/hmei/public_html/2019/20190531_ttH_BDT_bins/"

f = TFile.Open(filename)
t = f.Get("t")

modelpath = args.modelPath

# ------------------------------------------------------------------------#
## This part is prepare inputs for binning scan
### sample_id: 0 bkg, 1 sig, 2 data
### signal_mass_label: 0 mH125

#d_mgg_sig = GetDataset(t, "mva_score > " + str(args.low) + " && mva_score < " + str(args.high) + " && sample_id == 1 && signal_mass_label == 0 ", tag, savepath, True) # mH125
d_mgg_sig = GetDataset(t, "tth_2017_reference_mva > " + str(args.low) + " && tth_2017_reference_mva < " + str(args.high) + " && sample_id == 1 && signal_mass_label == 0 ", tag, savepath, True) # mH125
GetSigPdf(d_mgg_sig,
          "hggpdfsmrel_13TeV_TTH_" + tag + "_"+str(args.nbin),
          "CMS-HGG_sigfit_mva_TTH_" + tag + "_"+str(args.nbin)+"_v" + str(args.index),
          savepath, modelpath
)

#d_mgg_bkg = GetDataset(t, "mva_score > " + str(args.low) + " && mva_score < " + str(args.high) + " && sample_id == 2 && ((mass > 100 && mass < 120) || ( mass > 130 && mass < 180)) ", tag, savepath, False)
d_mgg_bkg = GetDataset(t, "tth_2017_reference_mva > " + str(args.low) + " && tth_2017_reference_mva < " + str(args.high) + " && sample_id == 2 && ((mass > 100 && mass < 120) || ( mass > 130 && mass < 180)) ", tag, savepath, False)
GetBkgPdf(d_mgg_bkg,"CMS_hgg_" + tag + "_" + str(args.nbin) + "_13TeV_bkgshape", "CMS-HGG_bkg_TTH_" + tag + "_" + str(args.nbin) + "_v" + str(args.index), savepath, modelpath)

# ------------------------------------------------------------------------#
## This part is to provide inputs for making RooMultiPdf -> envelope method
'''
datanameTag = "test_13TeV_TTHHadronicTag"
cut1 = 0.2
cut2 = 0.3
# cut on pt/mgg before bdt
cut3 = 0.9585
#filename = "/home/users/sjmay/ttH/MVAs/ttHHadronic__v1.5_forHualin_16May2019_RunII_MVA_Presel_impute_cutPtoM_FinalFitTree.root"
# no cut on pt/mgg before bdt
#cut3 = 0.98
#filename = "/home/users/sjmay/ttH/MVAs/ttHHadronic__v1.5_forHualin_16May2019_RunII_MVA_Presel_impute_FinalFitTree.root"

### using tree from train.py
cutbase = "sample_id == 2 && ((mass > 100 && mass < 180)) && "
cutBins = ["mva_score > " + str(cut3), "mva_score > " + str(cut2) + " && mva_score < " + str(cut3), "mva_score > " + str(cut1) + " && mva_score < " + str(cut2)]

cuts = []
for i in range(len(cutBins)):
    cuts.append(cutbase + cutBins[i])
#GetMultiDataset(t, cuts, datanameTag, debug=False)
'''

call('chmod -R 755 ~/public_html', shell=True)