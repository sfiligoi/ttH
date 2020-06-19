import sys, os
sys.path.append("../")

import parallel_utils
import workflow_utils

import argparse
parser = argparse.ArgumentParser()
parser.add_argument("--tag", help = "tag to denote with", type=str)
parser.add_argument("--baby_version", help = "which version of babies to use", type=str)
args = parser.parse_args()

os.chdir("../")

plot_types = ["std", "std_linear", "std_2016", "std_2017", "std_2018"]
#plot_types = ["std_linear"]

do_syst = True
if do_syst:
    syst = "--do_systematics"
else:
    syst = ""

do_looping = False
if do_looping:
    parallel_utils.run('python looper_wrapper.py --channel "Leptonic" --baby_version "%s" --tag "%s" --selection "ttHLeptonic_RunII_MVA_Presel" --bkg_options "none" --bdt "none" --fcnc %s' % (args.baby_version, args.tag, syst))
    os.chdir("Plots")
    for plot_type in plot_types:
        parallel_utils.run('python plot_wrapper.py --input_file "../ttHLeptonic_RunII_MVA_Presel_%s_histogramsRunII.root" --backgrounds "DiPhoton|GammaJets|TTGG|TTGJets|TTJets|VG|Other" --signals "TT_FCNC_hut" --plot_type "%s" --plot_labels "Leptonic Channel|Preselection"' % (args.tag + "_FCNC", plot_type))
    os.chdir("../")


do_babies = False
if do_babies:
    parallel_utils.run('python looper_wrapper.py --channel "Leptonic" --baby_version "%s" --tag "%s" --selection "ttHLeptonic_RunII_MVA_Presel" --bkg_options "none" --babymaker --fcnc' % (args.baby_version, args.tag))


bdt_training_features_base = ["helicity_angle_", "dipho_pt_over_mass_", "met_", "dipho_rapidity_", "dipho_cosphi_", "subleadPSV_", "leadPSV_", "jet3_btag_", "jet3_eta_", "jet3_pt_", "jet2_btag_", "jet2_eta_", "jet2_pt_", "jet1_btag_", "jet1_eta_", "jet1_pt_", "sublead_eta_", "lead_eta_", "subleadptoM_", "leadptoM_", "ht_", "njets_", "dipho_delta_R", "max1_btag_", "max2_btag_", "minIDMVA_", "maxIDMVA_","lep_pt_", "lep_eta_", "n_lep_tight_"]
top_tagger_bdt = ["top_tag_score_"]
top_chi2_leptonic = ["chi2_neutrino_pz_", "chi2_tbw_mass_", "chi2_tbw_pt_", "chi2_tbw_eta_", "chi2_tbw_deltaR_dipho_", "chi2_qjet_pt_", "chi2_qjet_eta_", "chi2_qjet_btag_", "chi2_qjet_deltaR_dipho_", "chi2_tqh_ptOverM_", "chi2_tqh_eta_", "chi2_tqh_deltaR_tbw_", "chi2_tqh_deltaR_dipho_"]
bdt_training_features_all = bdt_training_features_base + top_tagger_bdt + top_chi2_leptonic

training_features_base = ",".join(bdt_training_features_base)
training_features_all  = ",".join(bdt_training_features_all)

non_resonant_bkg = "dy,dipho,ttgg,ttg,vgamma,tt,tgamma,ttz,vv,tv,ttw,gjets"
sm_higgs = "tth,thq,thw,ggh,vbf,vh"


do_prep = False
if do_prep:
    os.chdir("../MVAs/")
    command_list = []

    for coupling in ["Hut", "Hct"]:
        # Baseline
        command_list.append('python prep.py --input "../Loopers/MVABaby_ttHLeptonic_%s_FCNC.root" --channel "Leptonic" --signal "tt_fcnc_%s,st_fcnc_%s" --bkg "%s" --features "%s" --tag "baseline_%s"' % (args.tag, coupling.lower(), coupling.lower(), non_resonant_bkg + "," + sm_higgs, training_features_base, coupling.lower()))
        # Non-resonant
        command_list.append('python prep.py --input "../Loopers/MVABaby_ttHLeptonic_%s_FCNC.root" --channel "Leptonic" --signal "tt_fcnc_%s,st_fcnc_%s" --bkg "%s" --features "%s" --tag "nonres_%s"' % (args.tag, coupling.lower(), coupling.lower(), non_resonant_bkg, training_features_base, coupling.lower()))
        # SM Higgs
        command_list.append('python prep.py --input "../Loopers/MVABaby_ttHLeptonic_%s_FCNC.root" --channel "Leptonic" --signal "tt_fcnc_%s,st_fcnc_%s" --bkg "%s" --features "%s" --tag "smhiggs_%s"' % (args.tag, coupling.lower(), coupling.lower(), sm_higgs, training_features_base, coupling.lower()))

        # Add top taggers
        command_list.append('python prep.py --input "../Loopers/MVABaby_ttHLeptonic_%s_FCNC.root" --channel "Leptonic" --signal "tt_fcnc_%s,st_fcnc_%s" --bkg "%s" --features "%s" --tag "addTopTaggers_%s"' % (args.tag, coupling.lower(), coupling.lower(), non_resonant_bkg + "," + sm_higgs, training_features_all, coupling.lower()))
        # Add top taggers Non-resonant
        command_list.append('python prep.py --input "../Loopers/MVABaby_ttHLeptonic_%s_FCNC.root" --channel "Leptonic" --signal "tt_fcnc_%s,st_fcnc_%s" --bkg "%s" --features "%s" --tag "addTopTaggers_nonres_%s"' % (args.tag, coupling.lower(), coupling.lower(), non_resonant_bkg, training_features_all, coupling.lower()))
        # Add top taggers SM Higgs
        command_list.append('python prep.py --input "../Loopers/MVABaby_ttHLeptonic_%s_FCNC.root" --channel "Leptonic" --signal "tt_fcnc_%s,st_fcnc_%s" --bkg "%s" --features "%s" --tag "addTopTaggers_smhiggs_%s"' % (args.tag, coupling.lower(), coupling.lower(), sm_higgs, training_features_all, coupling.lower()))

    parallel_utils.submit_jobs(command_list, 6)

do_mvas = False
if do_mvas:
    os.chdir("../MVAs/")
    command_list = []

    for coupling in ["Hut", "Hct"]:
        # Baseline
        command_list.append('python train_bdt.py --input "ttHLeptonic_%s_FCNC_features_baseline_%s.hdf5" --channel "Leptonic" --tag "baseline_%s_%s"' % (args.tag, coupling.lower(), args.tag, coupling.lower()))
        #  Non-resonant
        command_list.append('python train_bdt.py --input "ttHLeptonic_%s_FCNC_features_nonres_%s.hdf5" --channel "Leptonic" --tag "nonres_%s_%s"' % (args.tag, coupling.lower(), args.tag, coupling.lower()))
        # SM Higgs
        command_list.append('python train_bdt.py --input "ttHLeptonic_%s_FCNC_features_smhiggs_%s.hdf5" --channel "Leptonic" --tag "smhiggs_%s_%s"' % (args.tag, coupling.lower(), args.tag, coupling.lower()))
        # Add top taggers Non-resonant
        command_list.append('python train_bdt.py --input "ttHLeptonic_%s_FCNC_features_addTopTaggers_nonres_%s.hdf5" --channel "Leptonic" --tag "addTopTaggers_nonres_%s_%s"' % (args.tag, coupling.lower(), args.tag, coupling.lower()))
        # Add top taggers SM Higgs
        command_list.append('python train_bdt.py --input "ttHLeptonic_%s_FCNC_features_addTopTaggers_smhiggs_%s.hdf5" --channel "Leptonic" --tag "addTopTaggers_smhiggs_%s_%s"' % (args.tag, coupling.lower(), args.tag, coupling.lower()))

    parallel_utils.submit_jobs(command_list, 1)

do_merge = False
if do_merge:
    os.chdir("../MVAs/")
    for coupling in ["Hut", "Hct"]:
        parallel_utils.run('python make_optimization_tree.py --input "ttHLeptonic_%s_FCNC_features_baseline_%s.hdf5" --channel "Leptonic" --tag "%s_merge1d_%s" --mvas "Leptonic_baseline_%s_%s_bdt.xgb,Leptonic_nonres_%s_%s_bdt.xgb,Leptonic_smhiggs_%s_%s_bdt.xgb" --names "mva_score,mva_nonres_score,mva_smhiggs_score"' % (args.tag, coupling.lower(), coupling.lower(), args.tag, args.tag, coupling.lower(), args.tag, coupling.lower(), args.tag, coupling.lower())) 
        parallel_utils.run('python make_optimization_tree.py --input "ttHLeptonic_%s_FCNC_features_addTopTaggers_%s.hdf5" --channel "Leptonic" --tag "%s_merge2d_%s" --mvas "Leptonic_addTopTaggers_nonres_%s_%s_bdt.xgb,Leptonic_addTopTaggers_smhiggs_%s_%s_bdt.xgb" --names "mva_nonres_score,mva_smhiggs_score"' % (args.tag, coupling.lower(), coupling.lower(), args.tag, args.tag, coupling.lower(), args.tag, coupling.lower()))

do_limits = True
if do_limits:
    os.chdir("../Binning/")

    for coupling in ["Hut", "Hct"]:
        parallel_utils.run('python optimize_srs.py --channel "Leptonic" --file "../MVAs/Leptonic_%s_merge1d_%s.root" --coupling "%s" --sm_higgs_unc 0.4 --nCores 12 --tag "1d_baseline" --mvas "mva_score"' % (coupling.lower(), args.tag, coupling))
        parallel_utils.run('python optimize_srs.py --channel "Leptonic" --file "../MVAs/Leptonic_%s_merge1d_%s.root" --coupling "%s" --sm_higgs_unc 0.4 --nCores 12 --tag "2d_baseline" --mvas "mva_nonres_score,mva_smhiggs_score"' % (coupling.lower(), args.tag, coupling))
        parallel_utils.run('python optimize_srs.py --channel "Leptonic" --file "../MVAs/Leptonic_%s_merge2d_%s.root" --coupling "%s" --sm_higgs_unc 0.4 --nCores 12 --tag "2d_addTopTaggers" --mvas "mva_smhiggs_score,mva_nonres_score"' % (coupling.lower(), args.tag, coupling))
