import sys, os
sys.path.append("../")

import parallel_utils
import workflow_utils

import argparse
parser = argparse.ArgumentParser()
parser.add_argument("--tag", help = "tag to denote with", type=str)
parser.add_argument("--baby_version", help = "which version of babies to use", type=str)
args = parser.parse_args()

bdt = "none"

os.chdir("../")

plot_types = ["std", "std_linear", "std_2016", "std_2017", "std_2018"]

do_syst = True
if do_syst:
    syst = "--do_systematics"
else:
    syst = ""

derive_fake_shape = False
if derive_fake_shape:
    # Derive photon fake ID shape
    parallel_utils.run('python looper_wrapper.py --channel "Hadronic" --baby_version "%s" --tag "%s" --selection "ttHHadronic_RunII_DiPhotonFits_Presel" --bkg_options "none" --bdt "none"' % (args.baby_version, args.tag))
    os.chdir("Plots")
    for plot_type in plot_types: 
        parallel_utils.run('python plot_wrapper.py --input_file "../ttHHadronic_RunII_DiPhotonFits_Presel_%s_histogramsRunII.root" --backgrounds "DiPhoton|GammaJets|QCD|TTGG|TTGJets|TTJets" --signals "TT_FCNC_hut" --plot_type "%s" --plot_labels "Hadronic Channel|DiPhoton Fits Presel."' % (args.tag, plot_type))

    os.chdir("../PhotonID_Sideband/")
    parallel_utils.run('python derive_shape_fake.py --input "../ttHHadronic_RunII_DiPhotonFits_Presel_%s_histogramsRunII.root" --hist_name "hFakePhotonIDMVA"' % (args.tag))

    os.chdir("../")
    dummy_input = raw_input("You probably want to update ttHLooper.h with results of deriving fake shape. Press any key to continue")


do_diphoton_fits = False
if do_diphoton_fits:
    # Run imputing with no fit
    parallel_utils.run('python looper_wrapper.py --channel "Hadronic" --baby_version "%s" --tag "%s" --selection "ttHHadronic_RunII_MVA_Presel" --bkg_options "none" --bdt "none" --fcnc %s' % (args.baby_version, args.tag + "_no_scale", syst))
    parallel_utils.run('python looper_wrapper.py --channel "Hadronic" --baby_version "%s" --tag "%s" --selection "ttHHadronic_RunII_MVA_Presel" --bkg_options "impute_no_scale" --bdt "none" --fcnc %s' % (args.baby_version, args.tag + "_impute_no_scale", syst))
    os.chdir("Plots")
    for plot_type in plot_types:
        parallel_utils.run('python plot_wrapper.py --input_file "../ttHHadronic_RunII_MVA_Presel_%s_histogramsRunII.root" --backgrounds "DiPhoton|QCD_GammaJets_imputed|TTGG|TTGJets|TTJets|VG|Other" --signals "TT_FCNC_hut" --plot_type "%s" --plot_labels "Hadronic Channel|Preselection"' % (args.tag + "_impute_no_scale_FCNC", plot_type))
        parallel_utils.run('python plot_wrapper.py --input_file "../ttHHadronic_RunII_MVA_Presel_%s_histogramsRunII.root" --backgrounds "DiPhoton|GammaJets|QCD|TTGG|TTGJets|TTJets|VG|Other" --signals "TT_FCNC_hut" --plot_type "%s" --plot_labels "Hadronic Channel|Preselection"' % (args.tag + "_no_scale_FCNC", plot_type))

    # Do fit
    os.chdir("../tt_template_fit/")
    parallel_utils.run('python do_fits_impute.py --input_file "../ttHHadronic_RunII_MVA_Presel_%s_histogramsRunII.root" --jet_bin "2+"' % (args.tag + "_impute_no_scale_FCNC"))
    parallel_utils.run('python do_fits_qcd.py --input_file "../ttHHadronic_RunII_MVA_Presel_%s_histogramsRunII.root" --jet_bin "2+"' % (args.tag + "_no_scale_FCNC"))

    os.chdir("../")
    dummy_input = raw_input("You probably want to update ttHLooper.h with results of DiPhoton Fits. Press any key to continue")


# Run imputing with fit
do_imputing = False
if do_imputing:
    parallel_utils.run('python looper_wrapper.py --channel "Hadronic" --baby_version "%s" --tag "%s" --selection "ttHHadronic_RunII_MVA_Presel" --bkg_options "impute" --bdt "none" --fcnc %s' % (args.baby_version, args.tag + "_impute", syst))
    os.chdir("Plots")
    for plot_type in plot_types:
        parallel_utils.run('python plot_wrapper.py --input_file "../ttHHadronic_RunII_MVA_Presel_%s_histogramsRunII.root" --backgrounds "DiPhoton|QCD_GammaJets_imputed|TTGG|TTGJets|TTJets|VG|Other" --signals "TT_FCNC_hut" --plot_type "%s" --plot_labels "Hadronic Channel|Preselection"' % (args.tag + "_impute_FCNC", plot_type))

    # Run QCD + X with fit
    os.chdir("../")
    parallel_utils.run('python looper_wrapper.py --channel "Hadronic" --baby_version "%s" --tag "%s" --selection "ttHHadronic_RunII_MVA_Presel" --bkg_options "scale_diphoton" --bdt "none" --fcnc %s' % (args.baby_version, args.tag + "_scale_diphoton", syst))
    os.chdir("Plots")
    for plot_type in plot_types:
        parallel_utils.run('python plot_wrapper.py --input_file "../ttHHadronic_RunII_MVA_Presel_%s_histogramsRunII.root" --backgrounds "DiPhoton|GammaJets|QCD|TTGG|TTGJets|TTJets|VG|Other" --signals "TT_FCNC_hut" --plot_type "%s" --plot_labels "Hadronic Channel|Preselection"' % (args.tag + "_scale_diphoton_FCNC", plot_type))
    os.chdir("../")

do_babies = False
if do_babies:
    parallel_utils.run('python looper_wrapper.py --channel "Hadronic" --baby_version "%s" --tag "%s" --selection "ttHHadronic_RunII_MVA_Presel" --bkg_options "impute" --babymaker --fcnc' % (args.baby_version, args.tag + "_impute"))
    parallel_utils.run('python looper_wrapper.py --channel "Hadronic" --baby_version "%s" --tag "%s" --selection "ttHHadronic_RunII_MVA_Presel" --bkg_options "scale_diphoton" --babymaker --fcnc' % (args.baby_version, args.tag + "_scale_diphoton"))


# Compare mva performances
non_resonant_bkg_mc = "dy,dipho,ttgg,ttg,vgamma,tt,tgamma,ttz,vv,tv,ttw,gjets"
non_resonant_bkg = "dy,dipho,ttgg,ttg,vgamma,tt,tgamma,ttz,vv,tv,ttw,qcd_gjets"
sm_higgs = "tth,thq,thw,ggh,vbf,vh"

bdt_training_features_base = ["helicity_angle_", "dipho_pt_over_mass_", "met_", "dipho_rapidity_", "dipho_cosphi_", "subleadPSV_", "leadPSV_", "jet3_btag_", "jet3_eta_", "jet3_pt_", "jet2_btag_", "jet2_eta_", "jet2_pt_", "jet1_btag_", "jet1_eta_", "jet1_pt_", "sublead_eta_", "lead_eta_", "subleadptoM_", "leadptoM_", "ht_", "njets_", "dipho_delta_R", "max1_btag_", "max2_btag_", "minIDMVA_", "maxIDMVA_", "jet4_btag_", "jet4_eta_", "jet4_pt_", "m_ggj_", "m_jjj_"]
top_tagger_bdt = ["top_tag_score_"]
top_chi2_hadronic = ["chi2_tbw_mass_", "chi2_tbw_pt_", "chi2_tbw_eta_", "chi2_tbw_deltaR_dipho_", "chi2_qjet_pt_", "chi2_qjet_eta_", "chi2_qjet_btag_", "chi2_qjet_deltaR_dipho_", "chi2_tqh_ptOverM_", "chi2_tqh_eta_", "chi2_tqh_deltaR_tbw_", "chi2_tqh_deltaR_dipho_", "chi2_3x3_tbw_mass_", "chi2_3x3_tbw_pt_", "chi2_3x3_tbw_eta_", "chi2_3x3_tbw_deltaR_dipho_", "chi2_3x3_qjet_pt_", "chi2_3x3_qjet_eta_", "chi2_3x3_qjet_btag_", "chi2_3x3_qjet_deltaR_dipho_", "chi2_3x3_tqh_ptOverM_", "chi2_3x3_tqh_eta_", "chi2_3x3_tqh_deltaR_tbw_", "chi2_3x3_tqh_deltaR_dipho_"]
bdt_training_features_all = bdt_training_features_base + top_tagger_bdt + top_chi2_hadronic

training_features_base = ",".join(bdt_training_features_base)
training_features_all  = ",".join(bdt_training_features_all)

do_prep = False
if do_prep:
    os.chdir("../MVAs/")
    #os.system("source ~/ttH/MVAs/setup.sh")
    command_list = []

    for coupling in ["Hut", "Hct"]:
        # Baseline
        command_list.append('python prep.py --input "../Loopers/MVABaby_ttHHadronic_%s_scale_diphoton_FCNC.root" --channel "Hadronic" --signal "tt_fcnc_%s,st_fcnc_%s" --bkg "%s" --features "%s" --tag "baseline_%s"' % (args.tag, coupling.lower(), coupling.lower(), non_resonant_bkg_mc + "," + sm_higgs, training_features_base, coupling.lower()))

        # Non-resonant
        command_list.append('python prep.py --input "../Loopers/MVABaby_ttHHadronic_%s_scale_diphoton_FCNC.root" --channel "Hadronic" --signal "tt_fcnc_%s,st_fcnc_%s" --bkg "%s" --features "%s" --tag "nonres_%s"' % (args.tag, coupling.lower(), coupling.lower(), non_resonant_bkg_mc, training_features_base, coupling.lower())) 
        # SM Higgs
        command_list.append('python prep.py --input "../Loopers/MVABaby_ttHHadronic_%s_impute_FCNC.root" --channel "Hadronic" --signal "tt_fcnc_%s,st_fcnc_%s" --bkg "%s" --features "%s" --tag "smhiggs_%s"' % (args.tag, coupling.lower(), coupling.lower(), sm_higgs, training_features_base, coupling.lower()))

        # Impute
        command_list.append('python prep.py --input "../Loopers/MVABaby_ttHHadronic_%s_impute_FCNC.root" --channel "Hadronic" --signal "tt_fcnc_%s,st_fcnc_%s" --bkg "%s" --features "%s" --tag "impute_%s"' % (args.tag, coupling.lower(), coupling.lower(), non_resonant_bkg + "," + sm_higgs, training_features_base, coupling.lower()))
        # Impute non-resonant
        command_list.append('python prep.py --input "../Loopers/MVABaby_ttHHadronic_%s_impute_FCNC.root" --channel "Hadronic" --signal "tt_fcnc_%s,st_fcnc_%s" --bkg "%s" --features "%s" --tag "impute_nonres_%s"' % (args.tag, coupling.lower(), coupling.lower(), non_resonant_bkg, training_features_base, coupling.lower()))
        
        # Add top taggers
        command_list.append('python prep.py --input "../Loopers/MVABaby_ttHHadronic_%s_impute_FCNC.root" --channel "Hadronic" --signal "tt_fcnc_%s,st_fcnc_%s" --bkg "%s" --features "%s" --tag "addTopTaggers_%s"' % (args.tag, coupling.lower(), coupling.lower(), non_resonant_bkg + "," + sm_higgs, training_features_all, coupling.lower()))
        # Add top taggers non-resonant
        command_list.append('python prep.py --input "../Loopers/MVABaby_ttHHadronic_%s_impute_FCNC.root" --channel "Hadronic" --signal "tt_fcnc_%s,st_fcnc_%s" --bkg "%s" --features "%s" --tag "addTopTaggers_nonres_%s"' % (args.tag, coupling.lower(), coupling.lower(), non_resonant_bkg, training_features_all, coupling.lower()))
        # Add top taggers sm higgs
        command_list.append('python prep.py --input "../Loopers/MVABaby_ttHHadronic_%s_impute_FCNC.root" --channel "Hadronic" --signal "tt_fcnc_%s,st_fcnc_%s" --bkg "%s" --features "%s" --tag "addTopTaggers_smhiggs_%s"' % (args.tag, coupling.lower(), coupling.lower(), sm_higgs, training_features_all, coupling.lower()))

    parallel_utils.submit_jobs(command_list, 6)

do_mvas = False
if do_mvas:
    os.chdir("../MVAs/")
    #os.system("source ~/ttH/MVAs/setup.sh")
    command_list = []

    for coupling in ["Hut", "Hct"]:
        # Baseline
        command_list.append('python train_bdt.py --input "ttHHadronic_%s_scale_diphoton_FCNC_features_baseline_%s.hdf5" --channel "Hadronic" --tag "baseline_%s_%s"' % (args.tag, coupling.lower(), args.tag, coupling.lower()))

        # Non-resonant
        command_list.append('python train_bdt.py --input "ttHHadronic_%s_scale_diphoton_FCNC_features_nonres_%s.hdf5" --channel "Hadronic" --tag "nonres_%s_%s"' % (args.tag, coupling.lower(), args.tag, coupling.lower()))
        # SM Higgs
        command_list.append('python train_bdt.py --input "ttHHadronic_%s_impute_FCNC_features_smhiggs_%s.hdf5" --channel "Hadronic" --tag "smhiggs_%s_%s"' % (args.tag, coupling.lower(), args.tag, coupling.lower()))

        # Impute non-resonant
        command_list.append('python train_bdt.py --input "ttHHadronic_%s_impute_FCNC_features_impute_nonres_%s.hdf5" --channel "Hadronic" --tag "impute_nonres_%s_%s"' % (args.tag, coupling.lower(), args.tag, coupling.lower()))

        # Add top taggers non-resonant
        command_list.append('python train_bdt.py --input "ttHHadronic_%s_impute_FCNC_features_addTopTaggers_nonres_%s.hdf5" --channel "Hadronic" --tag "addTopTaggers_nonres_%s_%s"' % (args.tag, coupling.lower(), args.tag, coupling.lower()))
        # Add top taggers sm higgs
        command_list.append('python train_bdt.py --input "ttHHadronic_%s_impute_FCNC_features_addTopTaggers_smhiggs_%s.hdf5" --channel "Hadronic" --tag "addTopTaggers_smhiggs_%s_%s"' % (args.tag, coupling.lower(), args.tag, coupling.lower()))

    parallel_utils.submit_jobs(command_list, 1)

do_merge = False
if do_merge:
    os.chdir("../MVAs/")
    #os.system("source ~/ttH/MVAs/setup.sh")
    for coupling in ["Hut", "Hct"]:
        parallel_utils.run('python make_optimization_tree.py --input "ttHHadronic_%s_impute_FCNC_features_impute_%s.hdf5" --channel "Hadronic" --tag "%s_baseline_merge1d_%s" --mvas "Hadronic_baseline_%s_%s_bdt.xgb,Hadronic_nonres_%s_%s_bdt.xgb,Hadronic_smhiggs_%s_%s_bdt.xgb,Hadronic_impute_nonres_%s_%s_bdt.xgb" --names "mva_score,mva_nonres_score,mva_smhiggs_score,mva_nonres_impute_score"' % (args.tag, coupling.lower(), coupling.lower(), args.tag, args.tag, coupling.lower(), args.tag, coupling.lower(), args.tag, coupling.lower(), args.tag, coupling.lower()))
        parallel_utils.run('python make_optimization_tree.py --input "ttHHadronic_%s_impute_FCNC_features_addTopTaggers_%s.hdf5" --channel "Hadronic" --tag "%s_merge2d_%s" --mvas "Hadronic_addTopTaggers_nonres_%s_%s_bdt.xgb,Hadronic_addTopTaggers_smhiggs_%s_%s_bdt.xgb" --names "mva_nonres_score,mva_smhiggs_score"' % (args.tag, coupling.lower(), coupling.lower(), args.tag, args.tag, coupling.lower(), args.tag, coupling.lower()))

do_limits = True
if do_limits:
    os.chdir("../Binning/")

    for coupling in ["Hut", "Hct"]:
        parallel_utils.run('python optimize_srs.py --channel "Hadronic" --file "../MVAs/Hadronic_%s_baseline_merge1d_%s.root" --coupling "%s" --sm_higgs_unc 0.4 --nCores 12 --tag "1d_baseline" --mvas "mva_score"' % (coupling.lower(), args.tag, coupling))
        parallel_utils.run('python optimize_srs.py --channel "Hadronic" --file "../MVAs/Hadronic_%s_baseline_merge1d_%s.root" --coupling "%s" --sm_higgs_unc 0.4 --nCores 12 --tag "2d_baseline" --mvas "mva_nonres_score,mva_smhiggs_score"' % (coupling.lower(), args.tag, coupling))
        parallel_utils.run('python optimize_srs.py --channel "Hadronic" --file "../MVAs/Hadronic_%s_baseline_merge1d_%s.root" --coupling "%s" --sm_higgs_unc 0.4 --nCores 12 --tag "2d_impute" --mvas "mva_nonres_impute_score,mva_smhiggs_score"' % (coupling.lower(), args.tag, coupling))
        parallel_utils.run('python optimize_srs.py --channel "Hadronic" --file "../MVAs/Hadronic_%s_merge2d_%s.root" --coupling "%s" --sm_higgs_unc 0.4 --nCores 12 --tag "2d_addTopTaggers" --mvas "mva_smhiggs_score,mva_nonres_score"' % (coupling.lower(), args.tag, coupling))
