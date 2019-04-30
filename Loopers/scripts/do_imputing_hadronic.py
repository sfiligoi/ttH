import sys, os
sys.path.append("../")

import parallel_utils
import workflow_utils

import argparse
parser = argparse.ArgumentParser()
parser.add_argument("--tag", help = "tag to denote with", type=str)
args = parser.parse_args()

bdt = "none"

os.chdir("../")
#parallel_utils.run('./ttHHadronicLooper "ttHHadronic_RunII_DiPhotonFits_Presel" "RunII" "%s" "%s" "none"' % (args.tag + "prefit", bdt))
os.chdir("Plots")
#workflow_utils.make_tables_and_plots("../ttHHadronic_RunII_DiPhotonFits_Presel_%s_histogramsRunII.root" % (args.tag + "prefit"), "ttH Hadronic|DiPhoton Fit Presel.|Pre-Fit")
os.chdir("../PhotonID_Sideband/")
parallel_utils.run('python derive_shape_fake.py --input "../ttHHadronic_RunII_DiPhotonFits_Presel_%s_histogramsRunII.root" --hist_name "hFakePhotonIDMVA"' % (args.tag + "prefit"))
dummy_input = raw_input("You probably want to update ttHLooper.h with results of deriving fake shape. Press any key to continue")

os.chdir("../")
command_list = []
command_list.append('./ttHHadronicLooper "ttHHadronic_RunII_MVA_Presel" "RunII" "%s" "%s" "impute_no_scale"' % (args.tag + "_impute_prefit", bdt))
command_list.append('./ttHHadronicLooper "ttHHadronic_RunII_MVA_Presel_CutPtoM_light" "RunII" "%s" "%s" "impute_no_scale"' % (args.tag + "_impute_prefit", bdt))
command_list.append('./ttHHadronicLooper "ttHHadronic_RunII_MVA_Presel_CutPtoM" "RunII" "%s" "%s" "impute_no_scale"' % (args.tag + "_impute_prefit", bdt))
parallel_utils.submit_jobs(command_list, 3)

os.chdir("Plots")
workflow_utils.make_tables_and_plots("../ttHHadronic_RunII_MVA_Presel_%s_histogramsRunII.root" % (args.tag + "_impute_prefit"), "ttH Hadronic|Loose MVA Presel.|Pre-Fit")

os.chdir("../tt_template_fit/")
parallel_utils.run('python do_fits_impute.py --input_file "../ttHHadronic_RunII_MVA_Presel_%s_histogramsRunII.root" --jet_bin "2+"' % (args.tag + "_impute_prefit"))

dummy_input = raw_input("You probably want to update ttHLooper.h with results of DiPhoton Fits. Press any key to continue")

os.chdir("../")
command_list = []
command_list.append('./ttHHadronicLooper "ttHHadronic_RunII_MVA_Presel" "RunII" "%s" "%s" "impute"' % (args.tag + "_impute", bdt))
command_list.append('./ttHHadronicLooper "ttHHadronic_RunII_MVA_Presel_CutPtoM" "RunII" "%s" "%s" "impute"' % (args.tag + "_impute", bdt))
parallel_utils.submit_jobs(command_list, 2)
command_list = []

os.chdir("Plots")
workflow_utils.make_tables_and_plots("../ttHHadronic_RunII_MVA_Presel_%s_histogramsRunII.root" % (args.tag + "_impute"), "ttH Hadronic|Loose MVA Presel.")
workflow_utils.make_tables_and_plots("../ttHHadronic_RunII_MVA_Presel_CutPtoM%s_histogramsRunII.root" % (args.tag + "_impute"), "ttH Hadronic|Loose MVA Presel.|Cut on #gamma p_{T}/m_{#gamma#gamma}")

do_mva = True
if do_mva:
  os.chdir("../")
  parallel_utils.run('./ttHHadronicMVABabyMaker "ttHHadronic_RunII_MVA_Presel" "RunII" "%s_RunII_MVA_Presel_impute" "impute"' % (args.tag))

  os.chdir("../MVAs/")

  # DNN
  parallel_utils.run('python prep_dnn.py --input "../Loopers/MVABaby_ttHHadronic_%s_RunII_MVA_Presel_impute.root" --channel "Hadronic" --signal "ttH" --background "dipho"' % (args.tag))
  parallel_utils.run('python train_dnn.py --input "ttHHadronic_%s_RunII_MVA_Presel_impute_dnn_features_.hdf5" --tag "ttHHadronic_ttH_vs_dipho_%s" --channel "Hadronic"' % (args.tag, args.tag))

  parallel_utils.run('python prep_dnn.py --input "../Loopers/MVABaby_ttHHadronic_%s_RunII_MVA_Presel_impute.root" --channel "Hadronic" --signal "ttH" --background "ttGG"' % (args.tag))
  parallel_utils.run('python train_dnn.py --input "ttHHadronic_%s_RunII_MVA_Presel_impute_dnn_features_.hdf5" --tag "ttHHadronic_ttH_vs_ttGG_%s" --channel "Hadronic"' % (args.tag, args.tag))

  # BDT
  parallel_utils.run('python prep.py --input "../Loopers/MVABaby_ttHHadronic_%s_RunII_MVA_Presel_impute.root" --channel "Hadronic" --cut_ptoM --tag "cutPtoM"' % (args.tag))
  parallel_utils.run('python train.py --input "ttHHadronic_%s_RunII_MVA_Presel_impute_featurescutPtoM.hdf5" --channel "Hadronic" --tag "_%s_RunII_MVA_Presel_impute_cutPtoM" --ext ""' % (args.tag, args.tag))
  parallel_utils.run('python prep.py --input "../Loopers/MVABaby_ttHHadronic_%s_RunII_MVA_Presel_impute.root" --channel "Hadronic"' % (args.tag))
  parallel_utils.run('python train.py --input "ttHHadronic_%s_RunII_MVA_Presel_impute_features.hdf5" --channel "Hadronic" --tag "_%s_RunII_MVA_Presel_impute" --ext ""' % (args.tag, args.tag))
  parallel_utils.run('python prep.py --input "../Loopers/MVABaby_ttHHadronic_%s_RunII_MVA_Presel_impute.root" --channel "Hadronic" --dnn_models "dnn_weights/ttHHadronic_ttH_vs_dipho_%s_weights_00.hdf5,dnn_weights/ttHHadronic_ttH_vs_ttGG_%s_weights_00.hdf5" --tag "addDNNs"' % (args.tag, args.tag, args.tag))
  parallel_utils.run('python train.py --input "ttHHadronic_%s_RunII_MVA_Presel_impute_featuresaddDNNs.hdf5" --channel "Hadronic" --tag "_%s_RunII_MVA_Presel_impute_addDNNs" --ext ""' % (args.tag, args.tag))

  parallel_utils.run('python prep.py --input "../Loopers/MVABaby_ttHHadronic_%s_RunII_MVA_Presel_impute.root" --channel "Hadronic" --dnn_models "dnn_weights/ttHHadronic_ttH_vs_dipho_%s_weights_00.hdf5,dnn_weights/ttHHadronic_ttH_vs_ttGG_%s_weights_00.hdf5" --tag "addDNNs_addTopTag" --do_top_tag' % (args.tag))
  parallel_utils.run('python train.py --input "ttHHadronic_%s_RunII_MVA_Presel_impute_featuresaddDNNs_addTopTag.hdf5" --channel "Hadronic" --tag "_%s_RunII_MVA_Presel_impute_addDNNs_addTopTag" --ext ""' % (args.tag, args.tag))
