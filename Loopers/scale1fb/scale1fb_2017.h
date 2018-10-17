double scale1fb_2017(TString currentFileTitle) {
  std::map<TString, double> m = {
  	{"VHToGG_M123_13TeV_amcatnloFXFX_madspin_pythia8", 0.0000258279},
  	{"GluGluHToGG_M125_13TeV_amcatnloFXFX_pythia8_PSWeights", 0.0017546008},
  	{"VBFHToGG_M125_13TeV_amcatnlo_pythia8", 0.0000144892},
  	{"GluGluHToGG_M100_13TeV_amcatnloFXFX_pythia8", 0.0056454175},
  	{"VHToGG_M70_13TeV_amcatnloFXFX_madspin_pythia8", 0.0026582774},
  	{"ttHJetToGG_M126_13TeV_amcatnloFXFX_madspin_pythia8", 0.0000105071},
  	{"GluGluHToGG_M127_13TeV_amcatnloFXFX_pythia8", 0.0003704933},
  	{"VBFHToGG_M130_13TeV_amcatnlo_pythia8", 0.0000267781},
  	{"VHToGG_M80_13TeV_amcatnloFXFX_madspin_pythia8", 0.0028070224},
  	{"GluGluHToGG_M130_13TeV_amcatnloFXFX_pythia8", 0.0003695627},
  	{"VHToGG_M130_13TeV_amcatnloFXFX_madspin_pythia8", 0.0000214234},
  	{"VBFHToGG_M-125_13TeV_powheg_pythia8", 0.0000086269},
  	{"QCD_Pt-30toInf_DoubleEMEnriched_MGG-40to80_TuneCP5_13TeV_Pythia8", 5.7538798168},
  	{"GJets_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8", 0.8668177812},
  	{"ttHToGG_M125_13TeV_powheg_pythia8", 0.0000012284},
  	{"GluGluHToGG_M-125_13TeV_powheg_pythia8", 0.0001061978},
  	{"VBFHToGG_M126_13TeV_amcatnlo_pythia8", 0.0000553306},
  	{"VHToGG_M90_13TeV_amcatnloFXFX_madspin_pythia8", 0.0031096389},
  	{"GluGluHToGG_M95_13TeV_amcatnloFXFX_pythia8", 0.0138404309},
  	{"bbHToGG_M-125_4FS_yb2_13TeV_amcatnlo", 0.0000076634},
  	{"ggZH_HToGG_ZToQQ_M125_13TeV_powheg_pythia8", 0.0000000000},
  	{"ttHJetToGG_M65_13TeV_amcatnloFXFX_madspin_pythia8", 0.0069038525},
  	{"ggZH_HToGG_ZToNuNu_M126_13TeV_powheg_pythia8", 0.0000000000},
  	{"ttHJetToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8", 0.0000080828},
  	{"VBFHToGG_M120_13TeV_amcatnlo_pythia8", 0.0000285356},
  	{"VBFHToGG_M127_13TeV_amcatnlo_pythia8", 0.0000549883},
  	{"THW_ctcvcp_HToGG_M125_13TeV-madgraph-pythia8_TuneCP5", 0.0000000357},
  	{"VHToGG_M100_13TeV_amcatnloFXFX_madspin_pythia8", 0.0029940243},
  	{"ttHJetToGG_M130_13TeV_amcatnloFXFX_madspin_pythia8", 0.0000096869},
  	{"ttHJetToGG_M90_13TeV_amcatnloFXFX_madspin_pythia8", 0.0055321622},
  	{"GluGluHToGG_M70_13TeV_amcatnloFXFX_pythia8", 0.0053428159},
  	{"GluGluHToGG_M110_13TeV_amcatnloFXFX_pythia8", 0.0057372585},
  	{"DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8", 0.0203027598},
  	{"QCD_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8", 5.7796679016},
  	{"GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8", 3.8818469098},
  	{"GluGluHToGG_M75_13TeV_amcatnloFXFX_pythia8", 0.0136072901},
  	{"TTJets_TuneCP5_13TeV-amcatnloFXFX-pythia8", 0.0145498805},
  	{"GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8", 0.0131740456},
  	{"ZH_HToGG_ZToAll_M125_13TeV_powheg_pythia8", 0.0035417037},
  	{"VHToGG_M124_13TeV_amcatnloFXFX_madspin_pythia8", 0.0000252512},
  	{"ttHJetToGG_M127_13TeV_amcatnloFXFX_madspin_pythia8", 0.0000102200},
  	{"VHToGG_M127_13TeV_amcatnloFXFX_madspin_pythia8", 0.0000243771},
  	{"ttHJetToGG_M110_13TeV_amcatnloFXFX_madspin_pythia8", 0.0073164258},
  	{"VBFHToGG_M110_13TeV_amcatnlo_pythia8", 0.0108752629},
  	{"GluGluHToGG_M80_13TeV_amcatnloFXFX_pythia8", 0.0054815800},
  	{"VBFHToGG_M60_13TeV_amcatnlo_pythia8", 0.0223514134},
  	{"GluGluHToGG_M60_13TeV_amcatnloFXFX_pythia8", 0.0051954025},
  	{"ggZH_HToGG_ZToNuNu_M125_13TeV_powheg_pythia8", 0.0000000000},
  	{"ttHJetToGG_M123_13TeV_amcatnloFXFX_madspin_pythia8", 0.0000111588},
  	{"VBFHToGG_M123_13TeV_amcatnlo_pythia8", 0.0000573402},
  	{"GluGluHToGG_M123_13TeV_amcatnloFXFX_pythia8", 0.0003910576},
  	{"VHToGG_M126_13TeV_amcatnloFXFX_madspin_pythia8", 0.0000240761},
  	{"GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8", 0.0110810490},
  	{"DiPhotonJetsBox_MGG-80toInf_13TeV-Sherpa", 0.0016645612},
  	{"GJets_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8", 0.1179531876},
  	{"VBFHToGG_M70_13TeV_amcatnlo_pythia8", 0.0221150380},
  	{"ttHJetToGG_M120_13TeV_amcatnloFXFX_madspin_pythia8", 0.0000117420},
  	{"VHToGG_M95_13TeV_amcatnloFXFX_madspin_pythia8", 0.0032864479},
  	{"ttHJetToGG_M80_13TeV_amcatnloFXFX_madspin_pythia8", 0.0058662403},
  	{"ggZH_HToGG_ZToLL_M125_13TeV_powheg_pythia8", 0.0000000000},
  	{"VHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8", 0.0000148715},
  	{"GluGluHToGG_M120_13TeV_amcatnloFXFX_pythia8", 0.0004190548},
  	{"VHToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8_PSWeights", 0.0016407186},
  	{"ttHJetToGG_M100_13TeV_amcatnloFXFX_madspin_pythia8", 0.0071774636},
  	{"GluGluHToGG_M126_13TeV_amcatnloFXFX_pythia8", 0.0003748622},
  	{"GJet_Pt-20toInf_DoubleEMEnriched_MGG-40to80_TuneCP5_13TeV_Pythia8", 0.0752378636},
  	{"VHToGG_M85_13TeV_amcatnloFXFX_madspin_pythia8", 0.0028287414},
  	{"GluGluHToGG_M90_13TeV_amcatnloFXFX_pythia8", 0.0056058478},
  	{"VHToGG_M120_13TeV_amcatnloFXFX_madspin_pythia8", 0.0000265987},
  	{"WminusH_HToGG_WToAll_M125_13TeV_powheg_pythia8", 0.0035226400},
  	{"VBFHToGG_M80_13TeV_amcatnlo_pythia8", 0.0327653997},
  	{"ggZH_HToGG_ZToLL_M126_13TeV_powheg_pythia8", 0.0000000000},
  	{"WplusH_HToGG_WToAll_M125_13TeV_powheg_pythia8", 0.0035702044},
  	{"VHToGG_M60_13TeV_amcatnloFXFX_madspin_pythia8", 0.0025089343},
  	{"ttHJetToGG_M70_13TeV_amcatnloFXFX_madspin_pythia8", 0.0080600739},
  	{"VHToGG_M115_13TeV_amcatnloFXFX_madspin_pythia8", 0.0033169131},
  	{"QCD_Pt-30to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV_Pythia8", 1.7108221048},
  	{"VBFHToGG_M124_13TeV_amcatnlo_pythia8", 0.0000570813},
  	{"VBFHToGG_M65_13TeV_amcatnlo_pythia8", 0.0120195457},
  	{"ttHJetToGG_M60_13TeV_amcatnloFXFX_madspin_pythia8", 0.0078803660},
  	{"GluGluHToGG_M115_13TeV_amcatnloFXFX_pythia8", 0.0144139826},
  	{"ttHJetToGG_M75_13TeV_amcatnloFXFX_madspin_pythia8", 0.0069405074},
  	{"VBFHToGG_M75_13TeV_amcatnlo_pythia8", 0.0114429565},
  	{"GluGluHToGG_M65_13TeV_amcatnloFXFX_pythia8", 0.0133327918},
  	{"VHToGG_M110_13TeV_amcatnloFXFX_madspin_pythia8", 0.0030792299},
  	{"GluGluHToGG_M124_13TeV_amcatnloFXFX_pythia8", 0.0003836684},
  	{"ttHJetToGG_M95_13TeV_amcatnloFXFX_madspin_pythia8", 0.0074694388},
  	{"GluGluHToGG_M125_13TeV_amcatnloFXFX_pythia8", 0.0000993564},
  	{"TTGJets_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8", 0.0021268834},
  	{"TTGG_0Jets_TuneCP5_13TeV_amcatnlo_madspin_pythia8", 0.0000074081},
  	{"THQ_ctcvcp_HToGG_M125_13TeV-madgraph-pythia8_TuneCP5", 0.0000000893},
  	{"VHToGG_M65_13TeV_amcatnloFXFX_madspin_pythia8", 0.0027637740},
  	{"VHToGG_M75_13TeV_amcatnloFXFX_madspin_pythia8", 0.0030543043},
  	{"GluGluHToGG_M85_13TeV_amcatnloFXFX_pythia8", 0.0137841607},
  	{"VBFHToGG_M100_13TeV_amcatnlo_pythia8", 0.0108389100},
  	{"ggZH_HToGG_ZToQQ_M126_13TeV_powheg_pythia8", 0.0000000000},
  	{"GJets_HT-600ToInf_TuneCP5_13TeV-madgraphMLM-pythia8", 0.1595262775},
  	{"VBFHToGG_M95_13TeV_amcatnlo_pythia8", 0.0110446225},
  	{"VBFHToGG_M90_13TeV_amcatnlo_pythia8", 0.0330884786},
  	{"ttHJetToGG_M125_13TeV_amcatnloFXFX_madspin_pythia8_PSWeights", 0.0028509873},
  	{"ttHJetToGG_M124_13TeV_amcatnloFXFX_madspin_pythia8", 0.0000110369},
  };
  TObjArray *tx = currentFileTitle.Tokenize("/");
  TString key = ((TObjString *)(tx->At(tx->GetEntries()-2)))->String();
  TString tag = "v1.3";
  TString to_replace = "__ttH_Babies_" + tag + "_2017";
  TString replace_with = "";
  key = key.ReplaceAll(to_replace, replace_with);
  return m.find(key)->second;
}
