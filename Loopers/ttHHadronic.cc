#include "ttHHadronic.h"
ttHHadronic cms3;

void ttHHadronic::Init(TTree *tree) {

  tree->SetMakeClass(1);

  candidate_id_branch = tree->GetBranch("candidate_id");
  if (candidate_id_branch) candidate_id_branch->SetAddress(&candidate_id_);
  weight_branch = tree->GetBranch("weight");
  if (weight_branch) weight_branch->SetAddress(&weight_);
  dipho_sumpt_branch = tree->GetBranch("dipho_sumpt");
  if (dipho_sumpt_branch) dipho_sumpt_branch->SetAddress(&dipho_sumpt_);
  dipho_cosphi_branch = tree->GetBranch("dipho_cosphi");
  if (dipho_cosphi_branch) dipho_cosphi_branch->SetAddress(&dipho_cosphi_);
  mass_branch = tree->GetBranch("mass");
  if (mass_branch) mass_branch->SetAddress(&mass_);
  leadPt_branch = tree->GetBranch("leadPt");
  if (leadPt_branch) leadPt_branch->SetAddress(&leadPt_);
  leadEt_branch = tree->GetBranch("leadEt");
  if (leadEt_branch) leadEt_branch->SetAddress(&leadEt_);
  leadEnergy_branch = tree->GetBranch("leadEnergy");
  if (leadEnergy_branch) leadEnergy_branch->SetAddress(&leadEnergy_);
  leadEta_branch = tree->GetBranch("leadEta");
  if (leadEta_branch) leadEta_branch->SetAddress(&leadEta_);
  leadPhi_branch = tree->GetBranch("leadPhi");
  if (leadPhi_branch) leadPhi_branch->SetAddress(&leadPhi_);
  lead_sieie_branch = tree->GetBranch("lead_sieie");
  if (lead_sieie_branch) lead_sieie_branch->SetAddress(&lead_sieie_);
  lead_hoe_branch = tree->GetBranch("lead_hoe");
  if (lead_hoe_branch) lead_hoe_branch->SetAddress(&lead_hoe_);
  lead_sigmaEoE_branch = tree->GetBranch("lead_sigmaEoE");
  if (lead_sigmaEoE_branch) lead_sigmaEoE_branch->SetAddress(&lead_sigmaEoE_);
  lead_ptoM_branch = tree->GetBranch("lead_ptoM");
  if (lead_ptoM_branch) lead_ptoM_branch->SetAddress(&lead_ptoM_);
  leadR9_branch = tree->GetBranch("leadR9");
  if (leadR9_branch) leadR9_branch->SetAddress(&leadR9_);
  leadGenMatch_branch = tree->GetBranch("leadGenMatch");
  if (leadGenMatch_branch) leadGenMatch_branch->SetAddress(&leadGenMatch_);
  leadPtGen_branch = tree->GetBranch("leadPtGen");
  if (leadPtGen_branch) leadPtGen_branch->SetAddress(&leadPtGen_);
  leadGendeltaR_branch = tree->GetBranch("leadGendeltaR");
  if (leadGendeltaR_branch) leadGendeltaR_branch->SetAddress(&leadGendeltaR_);
  subleadPt_branch = tree->GetBranch("subleadPt");
  if (subleadPt_branch) subleadPt_branch->SetAddress(&subleadPt_);
  subleadEt_branch = tree->GetBranch("subleadEt");
  if (subleadEt_branch) subleadEt_branch->SetAddress(&subleadEt_);
  subleadEnergy_branch = tree->GetBranch("subleadEnergy");
  if (subleadEnergy_branch) subleadEnergy_branch->SetAddress(&subleadEnergy_);
  subleadEta_branch = tree->GetBranch("subleadEta");
  if (subleadEta_branch) subleadEta_branch->SetAddress(&subleadEta_);
  subleadPhi_branch = tree->GetBranch("subleadPhi");
  if (subleadPhi_branch) subleadPhi_branch->SetAddress(&subleadPhi_);
  sublead_sieie_branch = tree->GetBranch("sublead_sieie");
  if (sublead_sieie_branch) sublead_sieie_branch->SetAddress(&sublead_sieie_);
  sublead_hoe_branch = tree->GetBranch("sublead_hoe");
  if (sublead_hoe_branch) sublead_hoe_branch->SetAddress(&sublead_hoe_);
  sublead_sigmaEoE_branch = tree->GetBranch("sublead_sigmaEoE");
  if (sublead_sigmaEoE_branch) sublead_sigmaEoE_branch->SetAddress(&sublead_sigmaEoE_);
  sublead_ptoM_branch = tree->GetBranch("sublead_ptoM");
  if (sublead_ptoM_branch) sublead_ptoM_branch->SetAddress(&sublead_ptoM_);
  subleadR9_branch = tree->GetBranch("subleadR9");
  if (subleadR9_branch) subleadR9_branch->SetAddress(&subleadR9_);
  subleadGenMatch_branch = tree->GetBranch("subleadGenMatch");
  if (subleadGenMatch_branch) subleadGenMatch_branch->SetAddress(&subleadGenMatch_);
  subleadPtGen_branch = tree->GetBranch("subleadPtGen");
  if (subleadPtGen_branch) subleadPtGen_branch->SetAddress(&subleadPtGen_);
  subleadGendeltaR_branch = tree->GetBranch("subleadGendeltaR");
  if (subleadGendeltaR_branch) subleadGendeltaR_branch->SetAddress(&subleadGendeltaR_);
  leadIDMVA_branch = tree->GetBranch("leadIDMVA");
  if (leadIDMVA_branch) leadIDMVA_branch->SetAddress(&leadIDMVA_);
  subleadIDMVA_branch = tree->GetBranch("subleadIDMVA");
  if (subleadIDMVA_branch) subleadIDMVA_branch->SetAddress(&subleadIDMVA_);
  dipho_rapidity_branch = tree->GetBranch("dipho_rapidity");
  if (dipho_rapidity_branch) dipho_rapidity_branch->SetAddress(&dipho_rapidity_);
  vertex_idx_branch = tree->GetBranch("vertex_idx");
  if (vertex_idx_branch) vertex_idx_branch->SetAddress(&vertex_idx_);
  nGoodEls_branch = tree->GetBranch("nGoodEls");
  if (nGoodEls_branch) nGoodEls_branch->SetAddress(&nGoodEls_);
  nGoodElsFromTau_branch = tree->GetBranch("nGoodElsFromTau");
  if (nGoodElsFromTau_branch) nGoodElsFromTau_branch->SetAddress(&nGoodElsFromTau_);
  nGoodMus_branch = tree->GetBranch("nGoodMus");
  if (nGoodMus_branch) nGoodMus_branch->SetAddress(&nGoodMus_);
  nGoodMusFromTau_branch = tree->GetBranch("nGoodMusFromTau");
  if (nGoodMusFromTau_branch) nGoodMusFromTau_branch->SetAddress(&nGoodMusFromTau_);
  nGoodTaus_branch = tree->GetBranch("nGoodTaus");
  if (nGoodTaus_branch) nGoodTaus_branch->SetAddress(&nGoodTaus_);
  diphoMVARes_branch = tree->GetBranch("diphoMVARes");
  if (diphoMVARes_branch) diphoMVARes_branch->SetAddress(&diphoMVARes_);
  leadPassEVeto_branch = tree->GetBranch("leadPassEVeto");
  if (leadPassEVeto_branch) leadPassEVeto_branch->SetAddress(&leadPassEVeto_);
  subleadPassEVeto_branch = tree->GetBranch("subleadPassEVeto");
  if (subleadPassEVeto_branch) subleadPassEVeto_branch->SetAddress(&subleadPassEVeto_);
  leadPixelSeed_branch = tree->GetBranch("leadPixelSeed");
  if (leadPixelSeed_branch) leadPixelSeed_branch->SetAddress(&leadPixelSeed_);
  subleadPixelSeed_branch = tree->GetBranch("subleadPixelSeed");
  if (subleadPixelSeed_branch) subleadPixelSeed_branch->SetAddress(&subleadPixelSeed_);
  nb_loose_branch = tree->GetBranch("nb_loose");
  if (nb_loose_branch) nb_loose_branch->SetAddress(&nb_loose_);
  nb_medium_branch = tree->GetBranch("nb_medium");
  if (nb_medium_branch) nb_medium_branch->SetAddress(&nb_medium_);
  nb_tight_branch = tree->GetBranch("nb_tight");
  if (nb_tight_branch) nb_tight_branch->SetAddress(&nb_tight_);
  rand_branch = tree->GetBranch("rand");
  if (rand_branch) rand_branch->SetAddress(&rand_);
  lead_photon_type_branch = tree->GetBranch("lead_photon_type");
  if (lead_photon_type_branch) lead_photon_type_branch->SetAddress(&lead_photon_type_);
  sublead_photon_type_branch = tree->GetBranch("sublead_photon_type");
  if (sublead_photon_type_branch) sublead_photon_type_branch->SetAddress(&sublead_photon_type_);
  lead_closest_gen_Pt_branch = tree->GetBranch("lead_closest_gen_Pt");
  if (lead_closest_gen_Pt_branch) lead_closest_gen_Pt_branch->SetAddress(&lead_closest_gen_Pt_);
  sublead_closest_gen_Pt_branch = tree->GetBranch("sublead_closest_gen_Pt");
  if (sublead_closest_gen_Pt_branch) sublead_closest_gen_Pt_branch->SetAddress(&sublead_closest_gen_Pt_);
  lead_closest_gen_dR_branch = tree->GetBranch("lead_closest_gen_dR");
  if (lead_closest_gen_dR_branch) lead_closest_gen_dR_branch->SetAddress(&lead_closest_gen_dR_);
  sublead_closest_gen_dR_branch = tree->GetBranch("sublead_closest_gen_dR");
  if (sublead_closest_gen_dR_branch) sublead_closest_gen_dR_branch->SetAddress(&sublead_closest_gen_dR_);
  lead_PhoGenPt_branch = tree->GetBranch("lead_PhoGenPt");
  if (lead_PhoGenPt_branch) lead_PhoGenPt_branch->SetAddress(&lead_PhoGenPt_);
  lead_PhoGenEta_branch = tree->GetBranch("lead_PhoGenEta");
  if (lead_PhoGenEta_branch) lead_PhoGenEta_branch->SetAddress(&lead_PhoGenEta_);
  lead_PhoGenPhi_branch = tree->GetBranch("lead_PhoGenPhi");
  if (lead_PhoGenPhi_branch) lead_PhoGenPhi_branch->SetAddress(&lead_PhoGenPhi_);
  lead_Prompt_branch = tree->GetBranch("lead_Prompt");
  if (lead_Prompt_branch) lead_Prompt_branch->SetAddress(&lead_Prompt_);
  lead_Mad_branch = tree->GetBranch("lead_Mad");
  if (lead_Mad_branch) lead_Mad_branch->SetAddress(&lead_Mad_);
  lead_Pythia_branch = tree->GetBranch("lead_Pythia");
  if (lead_Pythia_branch) lead_Pythia_branch->SetAddress(&lead_Pythia_);
  lead_SimpleMomID_branch = tree->GetBranch("lead_SimpleMomID");
  if (lead_SimpleMomID_branch) lead_SimpleMomID_branch->SetAddress(&lead_SimpleMomID_);
  lead_SimpleMomStatus_branch = tree->GetBranch("lead_SimpleMomStatus");
  if (lead_SimpleMomStatus_branch) lead_SimpleMomStatus_branch->SetAddress(&lead_SimpleMomStatus_);
  lead_MomID_branch = tree->GetBranch("lead_MomID");
  if (lead_MomID_branch) lead_MomID_branch->SetAddress(&lead_MomID_);
  lead_MomMomID_branch = tree->GetBranch("lead_MomMomID");
  if (lead_MomMomID_branch) lead_MomMomID_branch->SetAddress(&lead_MomMomID_);
  lead_PassFrix_branch = tree->GetBranch("lead_PassFrix");
  if (lead_PassFrix_branch) lead_PassFrix_branch->SetAddress(&lead_PassFrix_);
  lead_SmallestDr_branch = tree->GetBranch("lead_SmallestDr");
  if (lead_SmallestDr_branch) lead_SmallestDr_branch->SetAddress(&lead_SmallestDr_);
  sublead_PhoGenPt_branch = tree->GetBranch("sublead_PhoGenPt");
  if (sublead_PhoGenPt_branch) sublead_PhoGenPt_branch->SetAddress(&sublead_PhoGenPt_);
  sublead_PhoGenEta_branch = tree->GetBranch("sublead_PhoGenEta");
  if (sublead_PhoGenEta_branch) sublead_PhoGenEta_branch->SetAddress(&sublead_PhoGenEta_);
  sublead_PhoGenPhi_branch = tree->GetBranch("sublead_PhoGenPhi");
  if (sublead_PhoGenPhi_branch) sublead_PhoGenPhi_branch->SetAddress(&sublead_PhoGenPhi_);
  sublead_Prompt_branch = tree->GetBranch("sublead_Prompt");
  if (sublead_Prompt_branch) sublead_Prompt_branch->SetAddress(&sublead_Prompt_);
  sublead_Mad_branch = tree->GetBranch("sublead_Mad");
  if (sublead_Mad_branch) sublead_Mad_branch->SetAddress(&sublead_Mad_);
  sublead_Pythia_branch = tree->GetBranch("sublead_Pythia");
  if (sublead_Pythia_branch) sublead_Pythia_branch->SetAddress(&sublead_Pythia_);
  sublead_SimpleMomID_branch = tree->GetBranch("sublead_SimpleMomID");
  if (sublead_SimpleMomID_branch) sublead_SimpleMomID_branch->SetAddress(&sublead_SimpleMomID_);
  sublead_SimpleMomStatus_branch = tree->GetBranch("sublead_SimpleMomStatus");
  if (sublead_SimpleMomStatus_branch) sublead_SimpleMomStatus_branch->SetAddress(&sublead_SimpleMomStatus_);
  sublead_MomID_branch = tree->GetBranch("sublead_MomID");
  if (sublead_MomID_branch) sublead_MomID_branch->SetAddress(&sublead_MomID_);
  sublead_MomMomID_branch = tree->GetBranch("sublead_MomMomID");
  if (sublead_MomMomID_branch) sublead_MomMomID_branch->SetAddress(&sublead_MomMomID_);
  sublead_PassFrix_branch = tree->GetBranch("sublead_PassFrix");
  if (sublead_PassFrix_branch) sublead_PassFrix_branch->SetAddress(&sublead_PassFrix_);
  sublead_SmallestDr_branch = tree->GetBranch("sublead_SmallestDr");
  if (sublead_SmallestDr_branch) sublead_SmallestDr_branch->SetAddress(&sublead_SmallestDr_);
  n_bjets_branch = tree->GetBranch("n_bjets");
  if (n_bjets_branch) n_bjets_branch->SetAddress(&n_bjets_);
  n_jets_branch = tree->GetBranch("n_jets");
  if (n_jets_branch) n_jets_branch->SetAddress(&n_jets_);
  bjet1_pt_branch = tree->GetBranch("bjet1_pt");
  if (bjet1_pt_branch) bjet1_pt_branch->SetAddress(&bjet1_pt_);
  bjet2_pt_branch = tree->GetBranch("bjet2_pt");
  if (bjet2_pt_branch) bjet2_pt_branch->SetAddress(&bjet2_pt_);
  MetPt_branch = tree->GetBranch("MetPt");
  if (MetPt_branch) MetPt_branch->SetAddress(&MetPt_);
  MetPhi_branch = tree->GetBranch("MetPhi");
  if (MetPhi_branch) MetPhi_branch->SetAddress(&MetPhi_);
  jet1_pt_branch = tree->GetBranch("jet1_pt");
  if (jet1_pt_branch) jet1_pt_branch->SetAddress(&jet1_pt_);
  jet2_pt_branch = tree->GetBranch("jet2_pt");
  if (jet2_pt_branch) jet2_pt_branch->SetAddress(&jet2_pt_);
  jet3_pt_branch = tree->GetBranch("jet3_pt");
  if (jet3_pt_branch) jet3_pt_branch->SetAddress(&jet3_pt_);
  jet4_pt_branch = tree->GetBranch("jet4_pt");
  if (jet4_pt_branch) jet4_pt_branch->SetAddress(&jet4_pt_);
  jet5_pt_branch = tree->GetBranch("jet5_pt");
  if (jet5_pt_branch) jet5_pt_branch->SetAddress(&jet5_pt_);
  jet6_pt_branch = tree->GetBranch("jet6_pt");
  if (jet6_pt_branch) jet6_pt_branch->SetAddress(&jet6_pt_);
  jet7_pt_branch = tree->GetBranch("jet7_pt");
  if (jet7_pt_branch) jet7_pt_branch->SetAddress(&jet7_pt_);
  jet8_pt_branch = tree->GetBranch("jet8_pt");
  if (jet8_pt_branch) jet8_pt_branch->SetAddress(&jet8_pt_);
  jet9_pt_branch = tree->GetBranch("jet9_pt");
  if (jet9_pt_branch) jet9_pt_branch->SetAddress(&jet9_pt_);
  jet10_pt_branch = tree->GetBranch("jet10_pt");
  if (jet10_pt_branch) jet10_pt_branch->SetAddress(&jet10_pt_);
  jet11_pt_branch = tree->GetBranch("jet11_pt");
  if (jet11_pt_branch) jet11_pt_branch->SetAddress(&jet11_pt_);
  jet12_pt_branch = tree->GetBranch("jet12_pt");
  if (jet12_pt_branch) jet12_pt_branch->SetAddress(&jet12_pt_);
  jet13_pt_branch = tree->GetBranch("jet13_pt");
  if (jet13_pt_branch) jet13_pt_branch->SetAddress(&jet13_pt_);
  jet14_pt_branch = tree->GetBranch("jet14_pt");
  if (jet14_pt_branch) jet14_pt_branch->SetAddress(&jet14_pt_);
  jet15_pt_branch = tree->GetBranch("jet15_pt");
  if (jet15_pt_branch) jet15_pt_branch->SetAddress(&jet15_pt_);
  jet1_eta_branch = tree->GetBranch("jet1_eta");
  if (jet1_eta_branch) jet1_eta_branch->SetAddress(&jet1_eta_);
  jet2_eta_branch = tree->GetBranch("jet2_eta");
  if (jet2_eta_branch) jet2_eta_branch->SetAddress(&jet2_eta_);
  jet3_eta_branch = tree->GetBranch("jet3_eta");
  if (jet3_eta_branch) jet3_eta_branch->SetAddress(&jet3_eta_);
  jet4_eta_branch = tree->GetBranch("jet4_eta");
  if (jet4_eta_branch) jet4_eta_branch->SetAddress(&jet4_eta_);
  jet5_eta_branch = tree->GetBranch("jet5_eta");
  if (jet5_eta_branch) jet5_eta_branch->SetAddress(&jet5_eta_);
  jet6_eta_branch = tree->GetBranch("jet6_eta");
  if (jet6_eta_branch) jet6_eta_branch->SetAddress(&jet6_eta_);
  jet7_eta_branch = tree->GetBranch("jet7_eta");
  if (jet7_eta_branch) jet7_eta_branch->SetAddress(&jet7_eta_);
  jet8_eta_branch = tree->GetBranch("jet8_eta");
  if (jet8_eta_branch) jet8_eta_branch->SetAddress(&jet8_eta_);
  jet9_eta_branch = tree->GetBranch("jet9_eta");
  if (jet9_eta_branch) jet9_eta_branch->SetAddress(&jet9_eta_);
  jet10_eta_branch = tree->GetBranch("jet10_eta");
  if (jet10_eta_branch) jet10_eta_branch->SetAddress(&jet10_eta_);
  jet11_eta_branch = tree->GetBranch("jet11_eta");
  if (jet11_eta_branch) jet11_eta_branch->SetAddress(&jet11_eta_);
  jet12_eta_branch = tree->GetBranch("jet12_eta");
  if (jet12_eta_branch) jet12_eta_branch->SetAddress(&jet12_eta_);
  jet13_eta_branch = tree->GetBranch("jet13_eta");
  if (jet13_eta_branch) jet13_eta_branch->SetAddress(&jet13_eta_);
  jet14_eta_branch = tree->GetBranch("jet14_eta");
  if (jet14_eta_branch) jet14_eta_branch->SetAddress(&jet14_eta_);
  jet15_eta_branch = tree->GetBranch("jet15_eta");
  if (jet15_eta_branch) jet15_eta_branch->SetAddress(&jet15_eta_);
  jet1_phi_branch = tree->GetBranch("jet1_phi");
  if (jet1_phi_branch) jet1_phi_branch->SetAddress(&jet1_phi_);
  jet2_phi_branch = tree->GetBranch("jet2_phi");
  if (jet2_phi_branch) jet2_phi_branch->SetAddress(&jet2_phi_);
  jet3_phi_branch = tree->GetBranch("jet3_phi");
  if (jet3_phi_branch) jet3_phi_branch->SetAddress(&jet3_phi_);
  jet4_phi_branch = tree->GetBranch("jet4_phi");
  if (jet4_phi_branch) jet4_phi_branch->SetAddress(&jet4_phi_);
  jet5_phi_branch = tree->GetBranch("jet5_phi");
  if (jet5_phi_branch) jet5_phi_branch->SetAddress(&jet5_phi_);
  jet6_phi_branch = tree->GetBranch("jet6_phi");
  if (jet6_phi_branch) jet6_phi_branch->SetAddress(&jet6_phi_);
  jet7_phi_branch = tree->GetBranch("jet7_phi");
  if (jet7_phi_branch) jet7_phi_branch->SetAddress(&jet7_phi_);
  jet8_phi_branch = tree->GetBranch("jet8_phi");
  if (jet8_phi_branch) jet8_phi_branch->SetAddress(&jet8_phi_);
  jet9_phi_branch = tree->GetBranch("jet9_phi");
  if (jet9_phi_branch) jet9_phi_branch->SetAddress(&jet9_phi_);
  jet10_phi_branch = tree->GetBranch("jet10_phi");
  if (jet10_phi_branch) jet10_phi_branch->SetAddress(&jet10_phi_);
  jet11_phi_branch = tree->GetBranch("jet11_phi");
  if (jet11_phi_branch) jet11_phi_branch->SetAddress(&jet11_phi_);
  jet12_phi_branch = tree->GetBranch("jet12_phi");
  if (jet12_phi_branch) jet12_phi_branch->SetAddress(&jet12_phi_);
  jet13_phi_branch = tree->GetBranch("jet13_phi");
  if (jet13_phi_branch) jet13_phi_branch->SetAddress(&jet13_phi_);
  jet14_phi_branch = tree->GetBranch("jet14_phi");
  if (jet14_phi_branch) jet14_phi_branch->SetAddress(&jet14_phi_);
  jet15_phi_branch = tree->GetBranch("jet15_phi");
  if (jet15_phi_branch) jet15_phi_branch->SetAddress(&jet15_phi_);
  jet1_bdiscriminant_branch = tree->GetBranch("jet1_bdiscriminant");
  if (jet1_bdiscriminant_branch) jet1_bdiscriminant_branch->SetAddress(&jet1_bdiscriminant_);
  jet2_bdiscriminant_branch = tree->GetBranch("jet2_bdiscriminant");
  if (jet2_bdiscriminant_branch) jet2_bdiscriminant_branch->SetAddress(&jet2_bdiscriminant_);
  jet3_bdiscriminant_branch = tree->GetBranch("jet3_bdiscriminant");
  if (jet3_bdiscriminant_branch) jet3_bdiscriminant_branch->SetAddress(&jet3_bdiscriminant_);
  jet4_bdiscriminant_branch = tree->GetBranch("jet4_bdiscriminant");
  if (jet4_bdiscriminant_branch) jet4_bdiscriminant_branch->SetAddress(&jet4_bdiscriminant_);
  jet5_bdiscriminant_branch = tree->GetBranch("jet5_bdiscriminant");
  if (jet5_bdiscriminant_branch) jet5_bdiscriminant_branch->SetAddress(&jet5_bdiscriminant_);
  jet6_bdiscriminant_branch = tree->GetBranch("jet6_bdiscriminant");
  if (jet6_bdiscriminant_branch) jet6_bdiscriminant_branch->SetAddress(&jet6_bdiscriminant_);
  jet7_bdiscriminant_branch = tree->GetBranch("jet7_bdiscriminant");
  if (jet7_bdiscriminant_branch) jet7_bdiscriminant_branch->SetAddress(&jet7_bdiscriminant_);
  jet8_bdiscriminant_branch = tree->GetBranch("jet8_bdiscriminant");
  if (jet8_bdiscriminant_branch) jet8_bdiscriminant_branch->SetAddress(&jet8_bdiscriminant_);
  jet9_bdiscriminant_branch = tree->GetBranch("jet9_bdiscriminant");
  if (jet9_bdiscriminant_branch) jet9_bdiscriminant_branch->SetAddress(&jet9_bdiscriminant_);
  jet10_bdiscriminant_branch = tree->GetBranch("jet10_bdiscriminant");
  if (jet10_bdiscriminant_branch) jet10_bdiscriminant_branch->SetAddress(&jet10_bdiscriminant_);
  jet11_bdiscriminant_branch = tree->GetBranch("jet11_bdiscriminant");
  if (jet11_bdiscriminant_branch) jet11_bdiscriminant_branch->SetAddress(&jet11_bdiscriminant_);
  jet12_bdiscriminant_branch = tree->GetBranch("jet12_bdiscriminant");
  if (jet12_bdiscriminant_branch) jet12_bdiscriminant_branch->SetAddress(&jet12_bdiscriminant_);
  jet13_bdiscriminant_branch = tree->GetBranch("jet13_bdiscriminant");
  if (jet13_bdiscriminant_branch) jet13_bdiscriminant_branch->SetAddress(&jet13_bdiscriminant_);
  jet14_bdiscriminant_branch = tree->GetBranch("jet14_bdiscriminant");
  if (jet14_bdiscriminant_branch) jet14_bdiscriminant_branch->SetAddress(&jet14_bdiscriminant_);
  jet15_bdiscriminant_branch = tree->GetBranch("jet15_bdiscriminant");
  if (jet15_bdiscriminant_branch) jet15_bdiscriminant_branch->SetAddress(&jet15_bdiscriminant_);
  jet1_bbdiscriminant_branch = tree->GetBranch("jet1_bbdiscriminant");
  if (jet1_bbdiscriminant_branch) jet1_bbdiscriminant_branch->SetAddress(&jet1_bbdiscriminant_);
  jet2_bbdiscriminant_branch = tree->GetBranch("jet2_bbdiscriminant");
  if (jet2_bbdiscriminant_branch) jet2_bbdiscriminant_branch->SetAddress(&jet2_bbdiscriminant_);
  jet3_bbdiscriminant_branch = tree->GetBranch("jet3_bbdiscriminant");
  if (jet3_bbdiscriminant_branch) jet3_bbdiscriminant_branch->SetAddress(&jet3_bbdiscriminant_);
  jet4_bbdiscriminant_branch = tree->GetBranch("jet4_bbdiscriminant");
  if (jet4_bbdiscriminant_branch) jet4_bbdiscriminant_branch->SetAddress(&jet4_bbdiscriminant_);
  jet5_bbdiscriminant_branch = tree->GetBranch("jet5_bbdiscriminant");
  if (jet5_bbdiscriminant_branch) jet5_bbdiscriminant_branch->SetAddress(&jet5_bbdiscriminant_);
  jet6_bbdiscriminant_branch = tree->GetBranch("jet6_bbdiscriminant");
  if (jet6_bbdiscriminant_branch) jet6_bbdiscriminant_branch->SetAddress(&jet6_bbdiscriminant_);
  jet7_bbdiscriminant_branch = tree->GetBranch("jet7_bbdiscriminant");
  if (jet7_bbdiscriminant_branch) jet7_bbdiscriminant_branch->SetAddress(&jet7_bbdiscriminant_);
  jet8_bbdiscriminant_branch = tree->GetBranch("jet8_bbdiscriminant");
  if (jet8_bbdiscriminant_branch) jet8_bbdiscriminant_branch->SetAddress(&jet8_bbdiscriminant_);
  jet9_bbdiscriminant_branch = tree->GetBranch("jet9_bbdiscriminant");
  if (jet9_bbdiscriminant_branch) jet9_bbdiscriminant_branch->SetAddress(&jet9_bbdiscriminant_);
  jet10_bbdiscriminant_branch = tree->GetBranch("jet10_bbdiscriminant");
  if (jet10_bbdiscriminant_branch) jet10_bbdiscriminant_branch->SetAddress(&jet10_bbdiscriminant_);
  jet11_bbdiscriminant_branch = tree->GetBranch("jet11_bbdiscriminant");
  if (jet11_bbdiscriminant_branch) jet11_bbdiscriminant_branch->SetAddress(&jet11_bbdiscriminant_);
  jet12_bbdiscriminant_branch = tree->GetBranch("jet12_bbdiscriminant");
  if (jet12_bbdiscriminant_branch) jet12_bbdiscriminant_branch->SetAddress(&jet12_bbdiscriminant_);
  jet13_bbdiscriminant_branch = tree->GetBranch("jet13_bbdiscriminant");
  if (jet13_bbdiscriminant_branch) jet13_bbdiscriminant_branch->SetAddress(&jet13_bbdiscriminant_);
  jet14_bbdiscriminant_branch = tree->GetBranch("jet14_bbdiscriminant");
  if (jet14_bbdiscriminant_branch) jet14_bbdiscriminant_branch->SetAddress(&jet14_bbdiscriminant_);
  jet15_bbdiscriminant_branch = tree->GetBranch("jet15_bbdiscriminant");
  if (jet15_bbdiscriminant_branch) jet15_bbdiscriminant_branch->SetAddress(&jet15_bbdiscriminant_);
  jet1_cdiscriminant_branch = tree->GetBranch("jet1_cdiscriminant");
  if (jet1_cdiscriminant_branch) jet1_cdiscriminant_branch->SetAddress(&jet1_cdiscriminant_);
  jet2_cdiscriminant_branch = tree->GetBranch("jet2_cdiscriminant");
  if (jet2_cdiscriminant_branch) jet2_cdiscriminant_branch->SetAddress(&jet2_cdiscriminant_);
  jet3_cdiscriminant_branch = tree->GetBranch("jet3_cdiscriminant");
  if (jet3_cdiscriminant_branch) jet3_cdiscriminant_branch->SetAddress(&jet3_cdiscriminant_);
  jet4_cdiscriminant_branch = tree->GetBranch("jet4_cdiscriminant");
  if (jet4_cdiscriminant_branch) jet4_cdiscriminant_branch->SetAddress(&jet4_cdiscriminant_);
  jet5_cdiscriminant_branch = tree->GetBranch("jet5_cdiscriminant");
  if (jet5_cdiscriminant_branch) jet5_cdiscriminant_branch->SetAddress(&jet5_cdiscriminant_);
  jet6_cdiscriminant_branch = tree->GetBranch("jet6_cdiscriminant");
  if (jet6_cdiscriminant_branch) jet6_cdiscriminant_branch->SetAddress(&jet6_cdiscriminant_);
  jet7_cdiscriminant_branch = tree->GetBranch("jet7_cdiscriminant");
  if (jet7_cdiscriminant_branch) jet7_cdiscriminant_branch->SetAddress(&jet7_cdiscriminant_);
  jet8_cdiscriminant_branch = tree->GetBranch("jet8_cdiscriminant");
  if (jet8_cdiscriminant_branch) jet8_cdiscriminant_branch->SetAddress(&jet8_cdiscriminant_);
  jet9_cdiscriminant_branch = tree->GetBranch("jet9_cdiscriminant");
  if (jet9_cdiscriminant_branch) jet9_cdiscriminant_branch->SetAddress(&jet9_cdiscriminant_);
  jet10_cdiscriminant_branch = tree->GetBranch("jet10_cdiscriminant");
  if (jet10_cdiscriminant_branch) jet10_cdiscriminant_branch->SetAddress(&jet10_cdiscriminant_);
  jet11_cdiscriminant_branch = tree->GetBranch("jet11_cdiscriminant");
  if (jet11_cdiscriminant_branch) jet11_cdiscriminant_branch->SetAddress(&jet11_cdiscriminant_);
  jet12_cdiscriminant_branch = tree->GetBranch("jet12_cdiscriminant");
  if (jet12_cdiscriminant_branch) jet12_cdiscriminant_branch->SetAddress(&jet12_cdiscriminant_);
  jet13_cdiscriminant_branch = tree->GetBranch("jet13_cdiscriminant");
  if (jet13_cdiscriminant_branch) jet13_cdiscriminant_branch->SetAddress(&jet13_cdiscriminant_);
  jet14_cdiscriminant_branch = tree->GetBranch("jet14_cdiscriminant");
  if (jet14_cdiscriminant_branch) jet14_cdiscriminant_branch->SetAddress(&jet14_cdiscriminant_);
  jet15_cdiscriminant_branch = tree->GetBranch("jet15_cdiscriminant");
  if (jet15_cdiscriminant_branch) jet15_cdiscriminant_branch->SetAddress(&jet15_cdiscriminant_);
  jet1_udsgdiscriminant_branch = tree->GetBranch("jet1_udsgdiscriminant");
  if (jet1_udsgdiscriminant_branch) jet1_udsgdiscriminant_branch->SetAddress(&jet1_udsgdiscriminant_);
  jet2_udsgdiscriminant_branch = tree->GetBranch("jet2_udsgdiscriminant");
  if (jet2_udsgdiscriminant_branch) jet2_udsgdiscriminant_branch->SetAddress(&jet2_udsgdiscriminant_);
  jet3_udsgdiscriminant_branch = tree->GetBranch("jet3_udsgdiscriminant");
  if (jet3_udsgdiscriminant_branch) jet3_udsgdiscriminant_branch->SetAddress(&jet3_udsgdiscriminant_);
  jet4_udsgdiscriminant_branch = tree->GetBranch("jet4_udsgdiscriminant");
  if (jet4_udsgdiscriminant_branch) jet4_udsgdiscriminant_branch->SetAddress(&jet4_udsgdiscriminant_);
  jet5_udsgdiscriminant_branch = tree->GetBranch("jet5_udsgdiscriminant");
  if (jet5_udsgdiscriminant_branch) jet5_udsgdiscriminant_branch->SetAddress(&jet5_udsgdiscriminant_);
  jet6_udsgdiscriminant_branch = tree->GetBranch("jet6_udsgdiscriminant");
  if (jet6_udsgdiscriminant_branch) jet6_udsgdiscriminant_branch->SetAddress(&jet6_udsgdiscriminant_);
  jet7_udsgdiscriminant_branch = tree->GetBranch("jet7_udsgdiscriminant");
  if (jet7_udsgdiscriminant_branch) jet7_udsgdiscriminant_branch->SetAddress(&jet7_udsgdiscriminant_);
  jet8_udsgdiscriminant_branch = tree->GetBranch("jet8_udsgdiscriminant");
  if (jet8_udsgdiscriminant_branch) jet8_udsgdiscriminant_branch->SetAddress(&jet8_udsgdiscriminant_);
  jet9_udsgdiscriminant_branch = tree->GetBranch("jet9_udsgdiscriminant");
  if (jet9_udsgdiscriminant_branch) jet9_udsgdiscriminant_branch->SetAddress(&jet9_udsgdiscriminant_);
  jet10_udsgdiscriminant_branch = tree->GetBranch("jet10_udsgdiscriminant");
  if (jet10_udsgdiscriminant_branch) jet10_udsgdiscriminant_branch->SetAddress(&jet10_udsgdiscriminant_);
  jet11_udsgdiscriminant_branch = tree->GetBranch("jet11_udsgdiscriminant");
  if (jet11_udsgdiscriminant_branch) jet11_udsgdiscriminant_branch->SetAddress(&jet11_udsgdiscriminant_);
  jet12_udsgdiscriminant_branch = tree->GetBranch("jet12_udsgdiscriminant");
  if (jet12_udsgdiscriminant_branch) jet12_udsgdiscriminant_branch->SetAddress(&jet12_udsgdiscriminant_);
  jet13_udsgdiscriminant_branch = tree->GetBranch("jet13_udsgdiscriminant");
  if (jet13_udsgdiscriminant_branch) jet13_udsgdiscriminant_branch->SetAddress(&jet13_udsgdiscriminant_);
  jet14_udsgdiscriminant_branch = tree->GetBranch("jet14_udsgdiscriminant");
  if (jet14_udsgdiscriminant_branch) jet14_udsgdiscriminant_branch->SetAddress(&jet14_udsgdiscriminant_);
  jet15_udsgdiscriminant_branch = tree->GetBranch("jet15_udsgdiscriminant");
  if (jet15_udsgdiscriminant_branch) jet15_udsgdiscriminant_branch->SetAddress(&jet15_udsgdiscriminant_);
  jet1_energy_branch = tree->GetBranch("jet1_energy");
  if (jet1_energy_branch) jet1_energy_branch->SetAddress(&jet1_energy_);
  jet2_energy_branch = tree->GetBranch("jet2_energy");
  if (jet2_energy_branch) jet2_energy_branch->SetAddress(&jet2_energy_);
  jet3_energy_branch = tree->GetBranch("jet3_energy");
  if (jet3_energy_branch) jet3_energy_branch->SetAddress(&jet3_energy_);
  jet4_energy_branch = tree->GetBranch("jet4_energy");
  if (jet4_energy_branch) jet4_energy_branch->SetAddress(&jet4_energy_);
  jet5_energy_branch = tree->GetBranch("jet5_energy");
  if (jet5_energy_branch) jet5_energy_branch->SetAddress(&jet5_energy_);
  jet6_energy_branch = tree->GetBranch("jet6_energy");
  if (jet6_energy_branch) jet6_energy_branch->SetAddress(&jet6_energy_);
  jet7_energy_branch = tree->GetBranch("jet7_energy");
  if (jet7_energy_branch) jet7_energy_branch->SetAddress(&jet7_energy_);
  jet8_energy_branch = tree->GetBranch("jet8_energy");
  if (jet8_energy_branch) jet8_energy_branch->SetAddress(&jet8_energy_);
  jet9_energy_branch = tree->GetBranch("jet9_energy");
  if (jet9_energy_branch) jet9_energy_branch->SetAddress(&jet9_energy_);
  jet10_energy_branch = tree->GetBranch("jet10_energy");
  if (jet10_energy_branch) jet10_energy_branch->SetAddress(&jet10_energy_);
  jet11_energy_branch = tree->GetBranch("jet11_energy");
  if (jet11_energy_branch) jet11_energy_branch->SetAddress(&jet11_energy_);
  jet12_energy_branch = tree->GetBranch("jet12_energy");
  if (jet12_energy_branch) jet12_energy_branch->SetAddress(&jet12_energy_);
  jet13_energy_branch = tree->GetBranch("jet13_energy");
  if (jet13_energy_branch) jet13_energy_branch->SetAddress(&jet13_energy_);
  jet14_energy_branch = tree->GetBranch("jet14_energy");
  if (jet14_energy_branch) jet14_energy_branch->SetAddress(&jet14_energy_);
  jet15_energy_branch = tree->GetBranch("jet15_energy");
  if (jet15_energy_branch) jet15_energy_branch->SetAddress(&jet15_energy_);
  bjet1_csv_branch = tree->GetBranch("bjet1_csv");
  if (bjet1_csv_branch) bjet1_csv_branch->SetAddress(&bjet1_csv_);
  bjet2_csv_branch = tree->GetBranch("bjet2_csv");
  if (bjet2_csv_branch) bjet2_csv_branch->SetAddress(&bjet2_csv_);
  tthMVA_branch = tree->GetBranch("tthMVA");
  if (tthMVA_branch) tthMVA_branch->SetAddress(&tthMVA_);
  rho_branch = tree->GetBranch("rho");
  if (rho_branch) rho_branch->SetAddress(&rho_);
  nvtx_branch = tree->GetBranch("nvtx");
  if (nvtx_branch) nvtx_branch->SetAddress(&nvtx_);
  event_branch = tree->GetBranch("event");
  if (event_branch) event_branch->SetAddress(&event_);
  lumi_branch = tree->GetBranch("lumi");
  if (lumi_branch) lumi_branch->SetAddress(&lumi_);
  processIndex_branch = tree->GetBranch("processIndex");
  if (processIndex_branch) processIndex_branch->SetAddress(&processIndex_);
  run_branch = tree->GetBranch("run");
  if (run_branch) run_branch->SetAddress(&run_);
  npu_branch = tree->GetBranch("npu");
  if (npu_branch) npu_branch->SetAddress(&npu_);
  puweight_branch = tree->GetBranch("puweight");
  if (puweight_branch) puweight_branch->SetAddress(&puweight_);

  tree->SetMakeClass(0);
}

void ttHHadronic::GetEntry(unsigned int idx) {
  // this only marks branches as not loaded, saving a lot of time
  index = idx;
  candidate_id_isLoaded = false;
  weight_isLoaded = false;
  dipho_sumpt_isLoaded = false;
  dipho_cosphi_isLoaded = false;
  mass_isLoaded = false;
  leadPt_isLoaded = false;
  leadEt_isLoaded = false;
  leadEnergy_isLoaded = false;
  leadEta_isLoaded = false;
  leadPhi_isLoaded = false;
  lead_sieie_isLoaded = false;
  lead_hoe_isLoaded = false;
  lead_sigmaEoE_isLoaded = false;
  lead_ptoM_isLoaded = false;
  leadR9_isLoaded = false;
  leadGenMatch_isLoaded = false;
  leadPtGen_isLoaded = false;
  leadGendeltaR_isLoaded = false;
  subleadPt_isLoaded = false;
  subleadEt_isLoaded = false;
  subleadEnergy_isLoaded = false;
  subleadEta_isLoaded = false;
  subleadPhi_isLoaded = false;
  sublead_sieie_isLoaded = false;
  sublead_hoe_isLoaded = false;
  sublead_sigmaEoE_isLoaded = false;
  sublead_ptoM_isLoaded = false;
  subleadR9_isLoaded = false;
  subleadGenMatch_isLoaded = false;
  subleadPtGen_isLoaded = false;
  subleadGendeltaR_isLoaded = false;
  leadIDMVA_isLoaded = false;
  subleadIDMVA_isLoaded = false;
  dipho_rapidity_isLoaded = false;
  vertex_idx_isLoaded = false;
  nGoodEls_isLoaded = false;
  nGoodElsFromTau_isLoaded = false;
  nGoodMus_isLoaded = false;
  nGoodMusFromTau_isLoaded = false;
  nGoodTaus_isLoaded = false;
  diphoMVARes_isLoaded = false;
  leadPassEVeto_isLoaded = false;
  subleadPassEVeto_isLoaded = false;
  leadPixelSeed_isLoaded = false;
  subleadPixelSeed_isLoaded = false;
  nb_loose_isLoaded = false;
  nb_medium_isLoaded = false;
  nb_tight_isLoaded = false;
  rand_isLoaded = false;
  lead_photon_type_isLoaded = false;
  sublead_photon_type_isLoaded = false;
  lead_closest_gen_Pt_isLoaded = false;
  sublead_closest_gen_Pt_isLoaded = false;
  lead_closest_gen_dR_isLoaded = false;
  sublead_closest_gen_dR_isLoaded = false;
  lead_PhoGenPt_isLoaded = false;
  lead_PhoGenEta_isLoaded = false;
  lead_PhoGenPhi_isLoaded = false;
  lead_Prompt_isLoaded = false;
  lead_Mad_isLoaded = false;
  lead_Pythia_isLoaded = false;
  lead_SimpleMomID_isLoaded = false;
  lead_SimpleMomStatus_isLoaded = false;
  lead_MomID_isLoaded = false;
  lead_MomMomID_isLoaded = false;
  lead_PassFrix_isLoaded = false;
  lead_SmallestDr_isLoaded = false;
  sublead_PhoGenPt_isLoaded = false;
  sublead_PhoGenEta_isLoaded = false;
  sublead_PhoGenPhi_isLoaded = false;
  sublead_Prompt_isLoaded = false;
  sublead_Mad_isLoaded = false;
  sublead_Pythia_isLoaded = false;
  sublead_SimpleMomID_isLoaded = false;
  sublead_SimpleMomStatus_isLoaded = false;
  sublead_MomID_isLoaded = false;
  sublead_MomMomID_isLoaded = false;
  sublead_PassFrix_isLoaded = false;
  sublead_SmallestDr_isLoaded = false;
  n_bjets_isLoaded = false;
  n_jets_isLoaded = false;
  bjet1_pt_isLoaded = false;
  bjet2_pt_isLoaded = false;
  MetPt_isLoaded = false;
  MetPhi_isLoaded = false;
  jet1_pt_isLoaded = false;
  jet2_pt_isLoaded = false;
  jet3_pt_isLoaded = false;
  jet4_pt_isLoaded = false;
  jet5_pt_isLoaded = false;
  jet6_pt_isLoaded = false;
  jet7_pt_isLoaded = false;
  jet8_pt_isLoaded = false;
  jet9_pt_isLoaded = false;
  jet10_pt_isLoaded = false;
  jet11_pt_isLoaded = false;
  jet12_pt_isLoaded = false;
  jet13_pt_isLoaded = false;
  jet14_pt_isLoaded = false;
  jet15_pt_isLoaded = false;
  jet1_eta_isLoaded = false;
  jet2_eta_isLoaded = false;
  jet3_eta_isLoaded = false;
  jet4_eta_isLoaded = false;
  jet5_eta_isLoaded = false;
  jet6_eta_isLoaded = false;
  jet7_eta_isLoaded = false;
  jet8_eta_isLoaded = false;
  jet9_eta_isLoaded = false;
  jet10_eta_isLoaded = false;
  jet11_eta_isLoaded = false;
  jet12_eta_isLoaded = false;
  jet13_eta_isLoaded = false;
  jet14_eta_isLoaded = false;
  jet15_eta_isLoaded = false;
  jet1_phi_isLoaded = false;
  jet2_phi_isLoaded = false;
  jet3_phi_isLoaded = false;
  jet4_phi_isLoaded = false;
  jet5_phi_isLoaded = false;
  jet6_phi_isLoaded = false;
  jet7_phi_isLoaded = false;
  jet8_phi_isLoaded = false;
  jet9_phi_isLoaded = false;
  jet10_phi_isLoaded = false;
  jet11_phi_isLoaded = false;
  jet12_phi_isLoaded = false;
  jet13_phi_isLoaded = false;
  jet14_phi_isLoaded = false;
  jet15_phi_isLoaded = false;
  jet1_bdiscriminant_isLoaded = false;
  jet2_bdiscriminant_isLoaded = false;
  jet3_bdiscriminant_isLoaded = false;
  jet4_bdiscriminant_isLoaded = false;
  jet5_bdiscriminant_isLoaded = false;
  jet6_bdiscriminant_isLoaded = false;
  jet7_bdiscriminant_isLoaded = false;
  jet8_bdiscriminant_isLoaded = false;
  jet9_bdiscriminant_isLoaded = false;
  jet10_bdiscriminant_isLoaded = false;
  jet11_bdiscriminant_isLoaded = false;
  jet12_bdiscriminant_isLoaded = false;
  jet13_bdiscriminant_isLoaded = false;
  jet14_bdiscriminant_isLoaded = false;
  jet15_bdiscriminant_isLoaded = false;
  jet1_bbdiscriminant_isLoaded = false;
  jet2_bbdiscriminant_isLoaded = false;
  jet3_bbdiscriminant_isLoaded = false;
  jet4_bbdiscriminant_isLoaded = false;
  jet5_bbdiscriminant_isLoaded = false;
  jet6_bbdiscriminant_isLoaded = false;
  jet7_bbdiscriminant_isLoaded = false;
  jet8_bbdiscriminant_isLoaded = false;
  jet9_bbdiscriminant_isLoaded = false;
  jet10_bbdiscriminant_isLoaded = false;
  jet11_bbdiscriminant_isLoaded = false;
  jet12_bbdiscriminant_isLoaded = false;
  jet13_bbdiscriminant_isLoaded = false;
  jet14_bbdiscriminant_isLoaded = false;
  jet15_bbdiscriminant_isLoaded = false;
  jet1_cdiscriminant_isLoaded = false;
  jet2_cdiscriminant_isLoaded = false;
  jet3_cdiscriminant_isLoaded = false;
  jet4_cdiscriminant_isLoaded = false;
  jet5_cdiscriminant_isLoaded = false;
  jet6_cdiscriminant_isLoaded = false;
  jet7_cdiscriminant_isLoaded = false;
  jet8_cdiscriminant_isLoaded = false;
  jet9_cdiscriminant_isLoaded = false;
  jet10_cdiscriminant_isLoaded = false;
  jet11_cdiscriminant_isLoaded = false;
  jet12_cdiscriminant_isLoaded = false;
  jet13_cdiscriminant_isLoaded = false;
  jet14_cdiscriminant_isLoaded = false;
  jet15_cdiscriminant_isLoaded = false;
  jet1_udsgdiscriminant_isLoaded = false;
  jet2_udsgdiscriminant_isLoaded = false;
  jet3_udsgdiscriminant_isLoaded = false;
  jet4_udsgdiscriminant_isLoaded = false;
  jet5_udsgdiscriminant_isLoaded = false;
  jet6_udsgdiscriminant_isLoaded = false;
  jet7_udsgdiscriminant_isLoaded = false;
  jet8_udsgdiscriminant_isLoaded = false;
  jet9_udsgdiscriminant_isLoaded = false;
  jet10_udsgdiscriminant_isLoaded = false;
  jet11_udsgdiscriminant_isLoaded = false;
  jet12_udsgdiscriminant_isLoaded = false;
  jet13_udsgdiscriminant_isLoaded = false;
  jet14_udsgdiscriminant_isLoaded = false;
  jet15_udsgdiscriminant_isLoaded = false;
  jet1_energy_isLoaded = false;
  jet2_energy_isLoaded = false;
  jet3_energy_isLoaded = false;
  jet4_energy_isLoaded = false;
  jet5_energy_isLoaded = false;
  jet6_energy_isLoaded = false;
  jet7_energy_isLoaded = false;
  jet8_energy_isLoaded = false;
  jet9_energy_isLoaded = false;
  jet10_energy_isLoaded = false;
  jet11_energy_isLoaded = false;
  jet12_energy_isLoaded = false;
  jet13_energy_isLoaded = false;
  jet14_energy_isLoaded = false;
  jet15_energy_isLoaded = false;
  bjet1_csv_isLoaded = false;
  bjet2_csv_isLoaded = false;
  tthMVA_isLoaded = false;
  rho_isLoaded = false;
  nvtx_isLoaded = false;
  event_isLoaded = false;
  lumi_isLoaded = false;
  processIndex_isLoaded = false;
  run_isLoaded = false;
  npu_isLoaded = false;
  puweight_isLoaded = false;
}

void ttHHadronic::LoadAllBranches() {
  // load all branches
  if (candidate_id_branch != 0) candidate_id();
  if (weight_branch != 0) weight();
  if (dipho_sumpt_branch != 0) dipho_sumpt();
  if (dipho_cosphi_branch != 0) dipho_cosphi();
  if (mass_branch != 0) mass();
  if (leadPt_branch != 0) leadPt();
  if (leadEt_branch != 0) leadEt();
  if (leadEnergy_branch != 0) leadEnergy();
  if (leadEta_branch != 0) leadEta();
  if (leadPhi_branch != 0) leadPhi();
  if (lead_sieie_branch != 0) lead_sieie();
  if (lead_hoe_branch != 0) lead_hoe();
  if (lead_sigmaEoE_branch != 0) lead_sigmaEoE();
  if (lead_ptoM_branch != 0) lead_ptoM();
  if (leadR9_branch != 0) leadR9();
  if (leadGenMatch_branch != 0) leadGenMatch();
  if (leadPtGen_branch != 0) leadPtGen();
  if (leadGendeltaR_branch != 0) leadGendeltaR();
  if (subleadPt_branch != 0) subleadPt();
  if (subleadEt_branch != 0) subleadEt();
  if (subleadEnergy_branch != 0) subleadEnergy();
  if (subleadEta_branch != 0) subleadEta();
  if (subleadPhi_branch != 0) subleadPhi();
  if (sublead_sieie_branch != 0) sublead_sieie();
  if (sublead_hoe_branch != 0) sublead_hoe();
  if (sublead_sigmaEoE_branch != 0) sublead_sigmaEoE();
  if (sublead_ptoM_branch != 0) sublead_ptoM();
  if (subleadR9_branch != 0) subleadR9();
  if (subleadGenMatch_branch != 0) subleadGenMatch();
  if (subleadPtGen_branch != 0) subleadPtGen();
  if (subleadGendeltaR_branch != 0) subleadGendeltaR();
  if (leadIDMVA_branch != 0) leadIDMVA();
  if (subleadIDMVA_branch != 0) subleadIDMVA();
  if (dipho_rapidity_branch != 0) dipho_rapidity();
  if (vertex_idx_branch != 0) vertex_idx();
  if (nGoodEls_branch != 0) nGoodEls();
  if (nGoodElsFromTau_branch != 0) nGoodElsFromTau();
  if (nGoodMus_branch != 0) nGoodMus();
  if (nGoodMusFromTau_branch != 0) nGoodMusFromTau();
  if (nGoodTaus_branch != 0) nGoodTaus();
  if (diphoMVARes_branch != 0) diphoMVARes();
  if (leadPassEVeto_branch != 0) leadPassEVeto();
  if (subleadPassEVeto_branch != 0) subleadPassEVeto();
  if (leadPixelSeed_branch != 0) leadPixelSeed();
  if (subleadPixelSeed_branch != 0) subleadPixelSeed();
  if (nb_loose_branch != 0) nb_loose();
  if (nb_medium_branch != 0) nb_medium();
  if (nb_tight_branch != 0) nb_tight();
  if (rand_branch != 0) rand();
  if (lead_photon_type_branch != 0) lead_photon_type();
  if (sublead_photon_type_branch != 0) sublead_photon_type();
  if (lead_closest_gen_Pt_branch != 0) lead_closest_gen_Pt();
  if (sublead_closest_gen_Pt_branch != 0) sublead_closest_gen_Pt();
  if (lead_closest_gen_dR_branch != 0) lead_closest_gen_dR();
  if (sublead_closest_gen_dR_branch != 0) sublead_closest_gen_dR();
  if (lead_PhoGenPt_branch != 0) lead_PhoGenPt();
  if (lead_PhoGenEta_branch != 0) lead_PhoGenEta();
  if (lead_PhoGenPhi_branch != 0) lead_PhoGenPhi();
  if (lead_Prompt_branch != 0) lead_Prompt();
  if (lead_Mad_branch != 0) lead_Mad();
  if (lead_Pythia_branch != 0) lead_Pythia();
  if (lead_SimpleMomID_branch != 0) lead_SimpleMomID();
  if (lead_SimpleMomStatus_branch != 0) lead_SimpleMomStatus();
  if (lead_MomID_branch != 0) lead_MomID();
  if (lead_MomMomID_branch != 0) lead_MomMomID();
  if (lead_PassFrix_branch != 0) lead_PassFrix();
  if (lead_SmallestDr_branch != 0) lead_SmallestDr();
  if (sublead_PhoGenPt_branch != 0) sublead_PhoGenPt();
  if (sublead_PhoGenEta_branch != 0) sublead_PhoGenEta();
  if (sublead_PhoGenPhi_branch != 0) sublead_PhoGenPhi();
  if (sublead_Prompt_branch != 0) sublead_Prompt();
  if (sublead_Mad_branch != 0) sublead_Mad();
  if (sublead_Pythia_branch != 0) sublead_Pythia();
  if (sublead_SimpleMomID_branch != 0) sublead_SimpleMomID();
  if (sublead_SimpleMomStatus_branch != 0) sublead_SimpleMomStatus();
  if (sublead_MomID_branch != 0) sublead_MomID();
  if (sublead_MomMomID_branch != 0) sublead_MomMomID();
  if (sublead_PassFrix_branch != 0) sublead_PassFrix();
  if (sublead_SmallestDr_branch != 0) sublead_SmallestDr();
  if (n_bjets_branch != 0) n_bjets();
  if (n_jets_branch != 0) n_jets();
  if (bjet1_pt_branch != 0) bjet1_pt();
  if (bjet2_pt_branch != 0) bjet2_pt();
  if (MetPt_branch != 0) MetPt();
  if (MetPhi_branch != 0) MetPhi();
  if (jet1_pt_branch != 0) jet1_pt();
  if (jet2_pt_branch != 0) jet2_pt();
  if (jet3_pt_branch != 0) jet3_pt();
  if (jet4_pt_branch != 0) jet4_pt();
  if (jet5_pt_branch != 0) jet5_pt();
  if (jet6_pt_branch != 0) jet6_pt();
  if (jet7_pt_branch != 0) jet7_pt();
  if (jet8_pt_branch != 0) jet8_pt();
  if (jet9_pt_branch != 0) jet9_pt();
  if (jet10_pt_branch != 0) jet10_pt();
  if (jet11_pt_branch != 0) jet11_pt();
  if (jet12_pt_branch != 0) jet12_pt();
  if (jet13_pt_branch != 0) jet13_pt();
  if (jet14_pt_branch != 0) jet14_pt();
  if (jet15_pt_branch != 0) jet15_pt();
  if (jet1_eta_branch != 0) jet1_eta();
  if (jet2_eta_branch != 0) jet2_eta();
  if (jet3_eta_branch != 0) jet3_eta();
  if (jet4_eta_branch != 0) jet4_eta();
  if (jet5_eta_branch != 0) jet5_eta();
  if (jet6_eta_branch != 0) jet6_eta();
  if (jet7_eta_branch != 0) jet7_eta();
  if (jet8_eta_branch != 0) jet8_eta();
  if (jet9_eta_branch != 0) jet9_eta();
  if (jet10_eta_branch != 0) jet10_eta();
  if (jet11_eta_branch != 0) jet11_eta();
  if (jet12_eta_branch != 0) jet12_eta();
  if (jet13_eta_branch != 0) jet13_eta();
  if (jet14_eta_branch != 0) jet14_eta();
  if (jet15_eta_branch != 0) jet15_eta();
  if (jet1_phi_branch != 0) jet1_phi();
  if (jet2_phi_branch != 0) jet2_phi();
  if (jet3_phi_branch != 0) jet3_phi();
  if (jet4_phi_branch != 0) jet4_phi();
  if (jet5_phi_branch != 0) jet5_phi();
  if (jet6_phi_branch != 0) jet6_phi();
  if (jet7_phi_branch != 0) jet7_phi();
  if (jet8_phi_branch != 0) jet8_phi();
  if (jet9_phi_branch != 0) jet9_phi();
  if (jet10_phi_branch != 0) jet10_phi();
  if (jet11_phi_branch != 0) jet11_phi();
  if (jet12_phi_branch != 0) jet12_phi();
  if (jet13_phi_branch != 0) jet13_phi();
  if (jet14_phi_branch != 0) jet14_phi();
  if (jet15_phi_branch != 0) jet15_phi();
  if (jet1_bdiscriminant_branch != 0) jet1_bdiscriminant();
  if (jet2_bdiscriminant_branch != 0) jet2_bdiscriminant();
  if (jet3_bdiscriminant_branch != 0) jet3_bdiscriminant();
  if (jet4_bdiscriminant_branch != 0) jet4_bdiscriminant();
  if (jet5_bdiscriminant_branch != 0) jet5_bdiscriminant();
  if (jet6_bdiscriminant_branch != 0) jet6_bdiscriminant();
  if (jet7_bdiscriminant_branch != 0) jet7_bdiscriminant();
  if (jet8_bdiscriminant_branch != 0) jet8_bdiscriminant();
  if (jet9_bdiscriminant_branch != 0) jet9_bdiscriminant();
  if (jet10_bdiscriminant_branch != 0) jet10_bdiscriminant();
  if (jet11_bdiscriminant_branch != 0) jet11_bdiscriminant();
  if (jet12_bdiscriminant_branch != 0) jet12_bdiscriminant();
  if (jet13_bdiscriminant_branch != 0) jet13_bdiscriminant();
  if (jet14_bdiscriminant_branch != 0) jet14_bdiscriminant();
  if (jet15_bdiscriminant_branch != 0) jet15_bdiscriminant();
  if (jet1_bbdiscriminant_branch != 0) jet1_bbdiscriminant();
  if (jet2_bbdiscriminant_branch != 0) jet2_bbdiscriminant();
  if (jet3_bbdiscriminant_branch != 0) jet3_bbdiscriminant();
  if (jet4_bbdiscriminant_branch != 0) jet4_bbdiscriminant();
  if (jet5_bbdiscriminant_branch != 0) jet5_bbdiscriminant();
  if (jet6_bbdiscriminant_branch != 0) jet6_bbdiscriminant();
  if (jet7_bbdiscriminant_branch != 0) jet7_bbdiscriminant();
  if (jet8_bbdiscriminant_branch != 0) jet8_bbdiscriminant();
  if (jet9_bbdiscriminant_branch != 0) jet9_bbdiscriminant();
  if (jet10_bbdiscriminant_branch != 0) jet10_bbdiscriminant();
  if (jet11_bbdiscriminant_branch != 0) jet11_bbdiscriminant();
  if (jet12_bbdiscriminant_branch != 0) jet12_bbdiscriminant();
  if (jet13_bbdiscriminant_branch != 0) jet13_bbdiscriminant();
  if (jet14_bbdiscriminant_branch != 0) jet14_bbdiscriminant();
  if (jet15_bbdiscriminant_branch != 0) jet15_bbdiscriminant();
  if (jet1_cdiscriminant_branch != 0) jet1_cdiscriminant();
  if (jet2_cdiscriminant_branch != 0) jet2_cdiscriminant();
  if (jet3_cdiscriminant_branch != 0) jet3_cdiscriminant();
  if (jet4_cdiscriminant_branch != 0) jet4_cdiscriminant();
  if (jet5_cdiscriminant_branch != 0) jet5_cdiscriminant();
  if (jet6_cdiscriminant_branch != 0) jet6_cdiscriminant();
  if (jet7_cdiscriminant_branch != 0) jet7_cdiscriminant();
  if (jet8_cdiscriminant_branch != 0) jet8_cdiscriminant();
  if (jet9_cdiscriminant_branch != 0) jet9_cdiscriminant();
  if (jet10_cdiscriminant_branch != 0) jet10_cdiscriminant();
  if (jet11_cdiscriminant_branch != 0) jet11_cdiscriminant();
  if (jet12_cdiscriminant_branch != 0) jet12_cdiscriminant();
  if (jet13_cdiscriminant_branch != 0) jet13_cdiscriminant();
  if (jet14_cdiscriminant_branch != 0) jet14_cdiscriminant();
  if (jet15_cdiscriminant_branch != 0) jet15_cdiscriminant();
  if (jet1_udsgdiscriminant_branch != 0) jet1_udsgdiscriminant();
  if (jet2_udsgdiscriminant_branch != 0) jet2_udsgdiscriminant();
  if (jet3_udsgdiscriminant_branch != 0) jet3_udsgdiscriminant();
  if (jet4_udsgdiscriminant_branch != 0) jet4_udsgdiscriminant();
  if (jet5_udsgdiscriminant_branch != 0) jet5_udsgdiscriminant();
  if (jet6_udsgdiscriminant_branch != 0) jet6_udsgdiscriminant();
  if (jet7_udsgdiscriminant_branch != 0) jet7_udsgdiscriminant();
  if (jet8_udsgdiscriminant_branch != 0) jet8_udsgdiscriminant();
  if (jet9_udsgdiscriminant_branch != 0) jet9_udsgdiscriminant();
  if (jet10_udsgdiscriminant_branch != 0) jet10_udsgdiscriminant();
  if (jet11_udsgdiscriminant_branch != 0) jet11_udsgdiscriminant();
  if (jet12_udsgdiscriminant_branch != 0) jet12_udsgdiscriminant();
  if (jet13_udsgdiscriminant_branch != 0) jet13_udsgdiscriminant();
  if (jet14_udsgdiscriminant_branch != 0) jet14_udsgdiscriminant();
  if (jet15_udsgdiscriminant_branch != 0) jet15_udsgdiscriminant();
  if (jet1_energy_branch != 0) jet1_energy();
  if (jet2_energy_branch != 0) jet2_energy();
  if (jet3_energy_branch != 0) jet3_energy();
  if (jet4_energy_branch != 0) jet4_energy();
  if (jet5_energy_branch != 0) jet5_energy();
  if (jet6_energy_branch != 0) jet6_energy();
  if (jet7_energy_branch != 0) jet7_energy();
  if (jet8_energy_branch != 0) jet8_energy();
  if (jet9_energy_branch != 0) jet9_energy();
  if (jet10_energy_branch != 0) jet10_energy();
  if (jet11_energy_branch != 0) jet11_energy();
  if (jet12_energy_branch != 0) jet12_energy();
  if (jet13_energy_branch != 0) jet13_energy();
  if (jet14_energy_branch != 0) jet14_energy();
  if (jet15_energy_branch != 0) jet15_energy();
  if (bjet1_csv_branch != 0) bjet1_csv();
  if (bjet2_csv_branch != 0) bjet2_csv();
  if (tthMVA_branch != 0) tthMVA();
  if (rho_branch != 0) rho();
  if (nvtx_branch != 0) nvtx();
  if (event_branch != 0) event();
  if (lumi_branch != 0) lumi();
  if (processIndex_branch != 0) processIndex();
  if (run_branch != 0) run();
  if (npu_branch != 0) npu();
  if (puweight_branch != 0) puweight();
}

const int &ttHHadronic::candidate_id() {
  if (not candidate_id_isLoaded) {
    if (candidate_id_branch != 0) {
      candidate_id_branch->GetEntry(index);
    } else {
      printf("branch candidate_id_branch does not exist!\n");
      exit(1);
    }
    candidate_id_isLoaded = true;
  }
  return candidate_id_;
}

const float &ttHHadronic::weight() {
  if (not weight_isLoaded) {
    if (weight_branch != 0) {
      weight_branch->GetEntry(index);
    } else {
      printf("branch weight_branch does not exist!\n");
      exit(1);
    }
    weight_isLoaded = true;
  }
  return weight_;
}

const float &ttHHadronic::dipho_sumpt() {
  if (not dipho_sumpt_isLoaded) {
    if (dipho_sumpt_branch != 0) {
      dipho_sumpt_branch->GetEntry(index);
    } else {
      printf("branch dipho_sumpt_branch does not exist!\n");
      exit(1);
    }
    dipho_sumpt_isLoaded = true;
  }
  return dipho_sumpt_;
}

const float &ttHHadronic::dipho_cosphi() {
  if (not dipho_cosphi_isLoaded) {
    if (dipho_cosphi_branch != 0) {
      dipho_cosphi_branch->GetEntry(index);
    } else {
      printf("branch dipho_cosphi_branch does not exist!\n");
      exit(1);
    }
    dipho_cosphi_isLoaded = true;
  }
  return dipho_cosphi_;
}

const float &ttHHadronic::mass() {
  if (not mass_isLoaded) {
    if (mass_branch != 0) {
      mass_branch->GetEntry(index);
    } else {
      printf("branch mass_branch does not exist!\n");
      exit(1);
    }
    mass_isLoaded = true;
  }
  return mass_;
}

const float &ttHHadronic::leadPt() {
  if (not leadPt_isLoaded) {
    if (leadPt_branch != 0) {
      leadPt_branch->GetEntry(index);
    } else {
      printf("branch leadPt_branch does not exist!\n");
      exit(1);
    }
    leadPt_isLoaded = true;
  }
  return leadPt_;
}

const float &ttHHadronic::leadEt() {
  if (not leadEt_isLoaded) {
    if (leadEt_branch != 0) {
      leadEt_branch->GetEntry(index);
    } else {
      printf("branch leadEt_branch does not exist!\n");
      exit(1);
    }
    leadEt_isLoaded = true;
  }
  return leadEt_;
}

const float &ttHHadronic::leadEnergy() {
  if (not leadEnergy_isLoaded) {
    if (leadEnergy_branch != 0) {
      leadEnergy_branch->GetEntry(index);
    } else {
      printf("branch leadEnergy_branch does not exist!\n");
      exit(1);
    }
    leadEnergy_isLoaded = true;
  }
  return leadEnergy_;
}

const float &ttHHadronic::leadEta() {
  if (not leadEta_isLoaded) {
    if (leadEta_branch != 0) {
      leadEta_branch->GetEntry(index);
    } else {
      printf("branch leadEta_branch does not exist!\n");
      exit(1);
    }
    leadEta_isLoaded = true;
  }
  return leadEta_;
}

const float &ttHHadronic::leadPhi() {
  if (not leadPhi_isLoaded) {
    if (leadPhi_branch != 0) {
      leadPhi_branch->GetEntry(index);
    } else {
      printf("branch leadPhi_branch does not exist!\n");
      exit(1);
    }
    leadPhi_isLoaded = true;
  }
  return leadPhi_;
}

const float &ttHHadronic::lead_sieie() {
  if (not lead_sieie_isLoaded) {
    if (lead_sieie_branch != 0) {
      lead_sieie_branch->GetEntry(index);
    } else {
      printf("branch lead_sieie_branch does not exist!\n");
      exit(1);
    }
    lead_sieie_isLoaded = true;
  }
  return lead_sieie_;
}

const float &ttHHadronic::lead_hoe() {
  if (not lead_hoe_isLoaded) {
    if (lead_hoe_branch != 0) {
      lead_hoe_branch->GetEntry(index);
    } else {
      printf("branch lead_hoe_branch does not exist!\n");
      exit(1);
    }
    lead_hoe_isLoaded = true;
  }
  return lead_hoe_;
}

const float &ttHHadronic::lead_sigmaEoE() {
  if (not lead_sigmaEoE_isLoaded) {
    if (lead_sigmaEoE_branch != 0) {
      lead_sigmaEoE_branch->GetEntry(index);
    } else {
      printf("branch lead_sigmaEoE_branch does not exist!\n");
      exit(1);
    }
    lead_sigmaEoE_isLoaded = true;
  }
  return lead_sigmaEoE_;
}

const float &ttHHadronic::lead_ptoM() {
  if (not lead_ptoM_isLoaded) {
    if (lead_ptoM_branch != 0) {
      lead_ptoM_branch->GetEntry(index);
    } else {
      printf("branch lead_ptoM_branch does not exist!\n");
      exit(1);
    }
    lead_ptoM_isLoaded = true;
  }
  return lead_ptoM_;
}

const float &ttHHadronic::leadR9() {
  if (not leadR9_isLoaded) {
    if (leadR9_branch != 0) {
      leadR9_branch->GetEntry(index);
    } else {
      printf("branch leadR9_branch does not exist!\n");
      exit(1);
    }
    leadR9_isLoaded = true;
  }
  return leadR9_;
}

const float &ttHHadronic::leadGenMatch() {
  if (not leadGenMatch_isLoaded) {
    if (leadGenMatch_branch != 0) {
      leadGenMatch_branch->GetEntry(index);
    } else {
      printf("branch leadGenMatch_branch does not exist!\n");
      exit(1);
    }
    leadGenMatch_isLoaded = true;
  }
  return leadGenMatch_;
}

const float &ttHHadronic::leadPtGen() {
  if (not leadPtGen_isLoaded) {
    if (leadPtGen_branch != 0) {
      leadPtGen_branch->GetEntry(index);
    } else {
      printf("branch leadPtGen_branch does not exist!\n");
      exit(1);
    }
    leadPtGen_isLoaded = true;
  }
  return leadPtGen_;
}

const float &ttHHadronic::leadGendeltaR() {
  if (not leadGendeltaR_isLoaded) {
    if (leadGendeltaR_branch != 0) {
      leadGendeltaR_branch->GetEntry(index);
    } else {
      printf("branch leadGendeltaR_branch does not exist!\n");
      exit(1);
    }
    leadGendeltaR_isLoaded = true;
  }
  return leadGendeltaR_;
}

const float &ttHHadronic::subleadPt() {
  if (not subleadPt_isLoaded) {
    if (subleadPt_branch != 0) {
      subleadPt_branch->GetEntry(index);
    } else {
      printf("branch subleadPt_branch does not exist!\n");
      exit(1);
    }
    subleadPt_isLoaded = true;
  }
  return subleadPt_;
}

const float &ttHHadronic::subleadEt() {
  if (not subleadEt_isLoaded) {
    if (subleadEt_branch != 0) {
      subleadEt_branch->GetEntry(index);
    } else {
      printf("branch subleadEt_branch does not exist!\n");
      exit(1);
    }
    subleadEt_isLoaded = true;
  }
  return subleadEt_;
}

const float &ttHHadronic::subleadEnergy() {
  if (not subleadEnergy_isLoaded) {
    if (subleadEnergy_branch != 0) {
      subleadEnergy_branch->GetEntry(index);
    } else {
      printf("branch subleadEnergy_branch does not exist!\n");
      exit(1);
    }
    subleadEnergy_isLoaded = true;
  }
  return subleadEnergy_;
}

const float &ttHHadronic::subleadEta() {
  if (not subleadEta_isLoaded) {
    if (subleadEta_branch != 0) {
      subleadEta_branch->GetEntry(index);
    } else {
      printf("branch subleadEta_branch does not exist!\n");
      exit(1);
    }
    subleadEta_isLoaded = true;
  }
  return subleadEta_;
}

const float &ttHHadronic::subleadPhi() {
  if (not subleadPhi_isLoaded) {
    if (subleadPhi_branch != 0) {
      subleadPhi_branch->GetEntry(index);
    } else {
      printf("branch subleadPhi_branch does not exist!\n");
      exit(1);
    }
    subleadPhi_isLoaded = true;
  }
  return subleadPhi_;
}

const float &ttHHadronic::sublead_sieie() {
  if (not sublead_sieie_isLoaded) {
    if (sublead_sieie_branch != 0) {
      sublead_sieie_branch->GetEntry(index);
    } else {
      printf("branch sublead_sieie_branch does not exist!\n");
      exit(1);
    }
    sublead_sieie_isLoaded = true;
  }
  return sublead_sieie_;
}

const float &ttHHadronic::sublead_hoe() {
  if (not sublead_hoe_isLoaded) {
    if (sublead_hoe_branch != 0) {
      sublead_hoe_branch->GetEntry(index);
    } else {
      printf("branch sublead_hoe_branch does not exist!\n");
      exit(1);
    }
    sublead_hoe_isLoaded = true;
  }
  return sublead_hoe_;
}

const float &ttHHadronic::sublead_sigmaEoE() {
  if (not sublead_sigmaEoE_isLoaded) {
    if (sublead_sigmaEoE_branch != 0) {
      sublead_sigmaEoE_branch->GetEntry(index);
    } else {
      printf("branch sublead_sigmaEoE_branch does not exist!\n");
      exit(1);
    }
    sublead_sigmaEoE_isLoaded = true;
  }
  return sublead_sigmaEoE_;
}

const float &ttHHadronic::sublead_ptoM() {
  if (not sublead_ptoM_isLoaded) {
    if (sublead_ptoM_branch != 0) {
      sublead_ptoM_branch->GetEntry(index);
    } else {
      printf("branch sublead_ptoM_branch does not exist!\n");
      exit(1);
    }
    sublead_ptoM_isLoaded = true;
  }
  return sublead_ptoM_;
}

const float &ttHHadronic::subleadR9() {
  if (not subleadR9_isLoaded) {
    if (subleadR9_branch != 0) {
      subleadR9_branch->GetEntry(index);
    } else {
      printf("branch subleadR9_branch does not exist!\n");
      exit(1);
    }
    subleadR9_isLoaded = true;
  }
  return subleadR9_;
}

const float &ttHHadronic::subleadGenMatch() {
  if (not subleadGenMatch_isLoaded) {
    if (subleadGenMatch_branch != 0) {
      subleadGenMatch_branch->GetEntry(index);
    } else {
      printf("branch subleadGenMatch_branch does not exist!\n");
      exit(1);
    }
    subleadGenMatch_isLoaded = true;
  }
  return subleadGenMatch_;
}

const float &ttHHadronic::subleadPtGen() {
  if (not subleadPtGen_isLoaded) {
    if (subleadPtGen_branch != 0) {
      subleadPtGen_branch->GetEntry(index);
    } else {
      printf("branch subleadPtGen_branch does not exist!\n");
      exit(1);
    }
    subleadPtGen_isLoaded = true;
  }
  return subleadPtGen_;
}

const float &ttHHadronic::subleadGendeltaR() {
  if (not subleadGendeltaR_isLoaded) {
    if (subleadGendeltaR_branch != 0) {
      subleadGendeltaR_branch->GetEntry(index);
    } else {
      printf("branch subleadGendeltaR_branch does not exist!\n");
      exit(1);
    }
    subleadGendeltaR_isLoaded = true;
  }
  return subleadGendeltaR_;
}

const float &ttHHadronic::leadIDMVA() {
  if (not leadIDMVA_isLoaded) {
    if (leadIDMVA_branch != 0) {
      leadIDMVA_branch->GetEntry(index);
    } else {
      printf("branch leadIDMVA_branch does not exist!\n");
      exit(1);
    }
    leadIDMVA_isLoaded = true;
  }
  return leadIDMVA_;
}

const float &ttHHadronic::subleadIDMVA() {
  if (not subleadIDMVA_isLoaded) {
    if (subleadIDMVA_branch != 0) {
      subleadIDMVA_branch->GetEntry(index);
    } else {
      printf("branch subleadIDMVA_branch does not exist!\n");
      exit(1);
    }
    subleadIDMVA_isLoaded = true;
  }
  return subleadIDMVA_;
}

const float &ttHHadronic::dipho_rapidity() {
  if (not dipho_rapidity_isLoaded) {
    if (dipho_rapidity_branch != 0) {
      dipho_rapidity_branch->GetEntry(index);
    } else {
      printf("branch dipho_rapidity_branch does not exist!\n");
      exit(1);
    }
    dipho_rapidity_isLoaded = true;
  }
  return dipho_rapidity_;
}

const float &ttHHadronic::vertex_idx() {
  if (not vertex_idx_isLoaded) {
    if (vertex_idx_branch != 0) {
      vertex_idx_branch->GetEntry(index);
    } else {
      printf("branch vertex_idx_branch does not exist!\n");
      exit(1);
    }
    vertex_idx_isLoaded = true;
  }
  return vertex_idx_;
}

const float &ttHHadronic::nGoodEls() {
  if (not nGoodEls_isLoaded) {
    if (nGoodEls_branch != 0) {
      nGoodEls_branch->GetEntry(index);
    } else {
      printf("branch nGoodEls_branch does not exist!\n");
      exit(1);
    }
    nGoodEls_isLoaded = true;
  }
  return nGoodEls_;
}

const float &ttHHadronic::nGoodElsFromTau() {
  if (not nGoodElsFromTau_isLoaded) {
    if (nGoodElsFromTau_branch != 0) {
      nGoodElsFromTau_branch->GetEntry(index);
    } else {
      printf("branch nGoodElsFromTau_branch does not exist!\n");
      exit(1);
    }
    nGoodElsFromTau_isLoaded = true;
  }
  return nGoodElsFromTau_;
}

const float &ttHHadronic::nGoodMus() {
  if (not nGoodMus_isLoaded) {
    if (nGoodMus_branch != 0) {
      nGoodMus_branch->GetEntry(index);
    } else {
      printf("branch nGoodMus_branch does not exist!\n");
      exit(1);
    }
    nGoodMus_isLoaded = true;
  }
  return nGoodMus_;
}

const float &ttHHadronic::nGoodMusFromTau() {
  if (not nGoodMusFromTau_isLoaded) {
    if (nGoodMusFromTau_branch != 0) {
      nGoodMusFromTau_branch->GetEntry(index);
    } else {
      printf("branch nGoodMusFromTau_branch does not exist!\n");
      exit(1);
    }
    nGoodMusFromTau_isLoaded = true;
  }
  return nGoodMusFromTau_;
}

const float &ttHHadronic::nGoodTaus() {
  if (not nGoodTaus_isLoaded) {
    if (nGoodTaus_branch != 0) {
      nGoodTaus_branch->GetEntry(index);
    } else {
      printf("branch nGoodTaus_branch does not exist!\n");
      exit(1);
    }
    nGoodTaus_isLoaded = true;
  }
  return nGoodTaus_;
}

const float &ttHHadronic::diphoMVARes() {
  if (not diphoMVARes_isLoaded) {
    if (diphoMVARes_branch != 0) {
      diphoMVARes_branch->GetEntry(index);
    } else {
      printf("branch diphoMVARes_branch does not exist!\n");
      exit(1);
    }
    diphoMVARes_isLoaded = true;
  }
  return diphoMVARes_;
}

const float &ttHHadronic::leadPassEVeto() {
  if (not leadPassEVeto_isLoaded) {
    if (leadPassEVeto_branch != 0) {
      leadPassEVeto_branch->GetEntry(index);
    } else {
      printf("branch leadPassEVeto_branch does not exist!\n");
      exit(1);
    }
    leadPassEVeto_isLoaded = true;
  }
  return leadPassEVeto_;
}

const float &ttHHadronic::subleadPassEVeto() {
  if (not subleadPassEVeto_isLoaded) {
    if (subleadPassEVeto_branch != 0) {
      subleadPassEVeto_branch->GetEntry(index);
    } else {
      printf("branch subleadPassEVeto_branch does not exist!\n");
      exit(1);
    }
    subleadPassEVeto_isLoaded = true;
  }
  return subleadPassEVeto_;
}

const float &ttHHadronic::leadPixelSeed() {
  if (not leadPixelSeed_isLoaded) {
    if (leadPixelSeed_branch != 0) {
      leadPixelSeed_branch->GetEntry(index);
    } else {
      printf("branch leadPixelSeed_branch does not exist!\n");
      exit(1);
    }
    leadPixelSeed_isLoaded = true;
  }
  return leadPixelSeed_;
}

const float &ttHHadronic::subleadPixelSeed() {
  if (not subleadPixelSeed_isLoaded) {
    if (subleadPixelSeed_branch != 0) {
      subleadPixelSeed_branch->GetEntry(index);
    } else {
      printf("branch subleadPixelSeed_branch does not exist!\n");
      exit(1);
    }
    subleadPixelSeed_isLoaded = true;
  }
  return subleadPixelSeed_;
}

const float &ttHHadronic::nb_loose() {
  if (not nb_loose_isLoaded) {
    if (nb_loose_branch != 0) {
      nb_loose_branch->GetEntry(index);
    } else {
      printf("branch nb_loose_branch does not exist!\n");
      exit(1);
    }
    nb_loose_isLoaded = true;
  }
  return nb_loose_;
}

const float &ttHHadronic::nb_medium() {
  if (not nb_medium_isLoaded) {
    if (nb_medium_branch != 0) {
      nb_medium_branch->GetEntry(index);
    } else {
      printf("branch nb_medium_branch does not exist!\n");
      exit(1);
    }
    nb_medium_isLoaded = true;
  }
  return nb_medium_;
}

const float &ttHHadronic::nb_tight() {
  if (not nb_tight_isLoaded) {
    if (nb_tight_branch != 0) {
      nb_tight_branch->GetEntry(index);
    } else {
      printf("branch nb_tight_branch does not exist!\n");
      exit(1);
    }
    nb_tight_isLoaded = true;
  }
  return nb_tight_;
}

const float &ttHHadronic::rand() {
  if (not rand_isLoaded) {
    if (rand_branch != 0) {
      rand_branch->GetEntry(index);
    } else {
      printf("branch rand_branch does not exist!\n");
      exit(1);
    }
    rand_isLoaded = true;
  }
  return rand_;
}

const float &ttHHadronic::lead_photon_type() {
  if (not lead_photon_type_isLoaded) {
    if (lead_photon_type_branch != 0) {
      lead_photon_type_branch->GetEntry(index);
    } else {
      printf("branch lead_photon_type_branch does not exist!\n");
      exit(1);
    }
    lead_photon_type_isLoaded = true;
  }
  return lead_photon_type_;
}

const float &ttHHadronic::sublead_photon_type() {
  if (not sublead_photon_type_isLoaded) {
    if (sublead_photon_type_branch != 0) {
      sublead_photon_type_branch->GetEntry(index);
    } else {
      printf("branch sublead_photon_type_branch does not exist!\n");
      exit(1);
    }
    sublead_photon_type_isLoaded = true;
  }
  return sublead_photon_type_;
}

const float &ttHHadronic::lead_closest_gen_Pt() {
  if (not lead_closest_gen_Pt_isLoaded) {
    if (lead_closest_gen_Pt_branch != 0) {
      lead_closest_gen_Pt_branch->GetEntry(index);
    } else {
      printf("branch lead_closest_gen_Pt_branch does not exist!\n");
      exit(1);
    }
    lead_closest_gen_Pt_isLoaded = true;
  }
  return lead_closest_gen_Pt_;
}

const float &ttHHadronic::sublead_closest_gen_Pt() {
  if (not sublead_closest_gen_Pt_isLoaded) {
    if (sublead_closest_gen_Pt_branch != 0) {
      sublead_closest_gen_Pt_branch->GetEntry(index);
    } else {
      printf("branch sublead_closest_gen_Pt_branch does not exist!\n");
      exit(1);
    }
    sublead_closest_gen_Pt_isLoaded = true;
  }
  return sublead_closest_gen_Pt_;
}

const float &ttHHadronic::lead_closest_gen_dR() {
  if (not lead_closest_gen_dR_isLoaded) {
    if (lead_closest_gen_dR_branch != 0) {
      lead_closest_gen_dR_branch->GetEntry(index);
    } else {
      printf("branch lead_closest_gen_dR_branch does not exist!\n");
      exit(1);
    }
    lead_closest_gen_dR_isLoaded = true;
  }
  return lead_closest_gen_dR_;
}

const float &ttHHadronic::sublead_closest_gen_dR() {
  if (not sublead_closest_gen_dR_isLoaded) {
    if (sublead_closest_gen_dR_branch != 0) {
      sublead_closest_gen_dR_branch->GetEntry(index);
    } else {
      printf("branch sublead_closest_gen_dR_branch does not exist!\n");
      exit(1);
    }
    sublead_closest_gen_dR_isLoaded = true;
  }
  return sublead_closest_gen_dR_;
}

const float &ttHHadronic::lead_PhoGenPt() {
  if (not lead_PhoGenPt_isLoaded) {
    if (lead_PhoGenPt_branch != 0) {
      lead_PhoGenPt_branch->GetEntry(index);
    } else {
      printf("branch lead_PhoGenPt_branch does not exist!\n");
      exit(1);
    }
    lead_PhoGenPt_isLoaded = true;
  }
  return lead_PhoGenPt_;
}

const float &ttHHadronic::lead_PhoGenEta() {
  if (not lead_PhoGenEta_isLoaded) {
    if (lead_PhoGenEta_branch != 0) {
      lead_PhoGenEta_branch->GetEntry(index);
    } else {
      printf("branch lead_PhoGenEta_branch does not exist!\n");
      exit(1);
    }
    lead_PhoGenEta_isLoaded = true;
  }
  return lead_PhoGenEta_;
}

const float &ttHHadronic::lead_PhoGenPhi() {
  if (not lead_PhoGenPhi_isLoaded) {
    if (lead_PhoGenPhi_branch != 0) {
      lead_PhoGenPhi_branch->GetEntry(index);
    } else {
      printf("branch lead_PhoGenPhi_branch does not exist!\n");
      exit(1);
    }
    lead_PhoGenPhi_isLoaded = true;
  }
  return lead_PhoGenPhi_;
}

const float &ttHHadronic::lead_Prompt() {
  if (not lead_Prompt_isLoaded) {
    if (lead_Prompt_branch != 0) {
      lead_Prompt_branch->GetEntry(index);
    } else {
      printf("branch lead_Prompt_branch does not exist!\n");
      exit(1);
    }
    lead_Prompt_isLoaded = true;
  }
  return lead_Prompt_;
}

const float &ttHHadronic::lead_Mad() {
  if (not lead_Mad_isLoaded) {
    if (lead_Mad_branch != 0) {
      lead_Mad_branch->GetEntry(index);
    } else {
      printf("branch lead_Mad_branch does not exist!\n");
      exit(1);
    }
    lead_Mad_isLoaded = true;
  }
  return lead_Mad_;
}

const float &ttHHadronic::lead_Pythia() {
  if (not lead_Pythia_isLoaded) {
    if (lead_Pythia_branch != 0) {
      lead_Pythia_branch->GetEntry(index);
    } else {
      printf("branch lead_Pythia_branch does not exist!\n");
      exit(1);
    }
    lead_Pythia_isLoaded = true;
  }
  return lead_Pythia_;
}

const float &ttHHadronic::lead_SimpleMomID() {
  if (not lead_SimpleMomID_isLoaded) {
    if (lead_SimpleMomID_branch != 0) {
      lead_SimpleMomID_branch->GetEntry(index);
    } else {
      printf("branch lead_SimpleMomID_branch does not exist!\n");
      exit(1);
    }
    lead_SimpleMomID_isLoaded = true;
  }
  return lead_SimpleMomID_;
}

const float &ttHHadronic::lead_SimpleMomStatus() {
  if (not lead_SimpleMomStatus_isLoaded) {
    if (lead_SimpleMomStatus_branch != 0) {
      lead_SimpleMomStatus_branch->GetEntry(index);
    } else {
      printf("branch lead_SimpleMomStatus_branch does not exist!\n");
      exit(1);
    }
    lead_SimpleMomStatus_isLoaded = true;
  }
  return lead_SimpleMomStatus_;
}

const float &ttHHadronic::lead_MomID() {
  if (not lead_MomID_isLoaded) {
    if (lead_MomID_branch != 0) {
      lead_MomID_branch->GetEntry(index);
    } else {
      printf("branch lead_MomID_branch does not exist!\n");
      exit(1);
    }
    lead_MomID_isLoaded = true;
  }
  return lead_MomID_;
}

const float &ttHHadronic::lead_MomMomID() {
  if (not lead_MomMomID_isLoaded) {
    if (lead_MomMomID_branch != 0) {
      lead_MomMomID_branch->GetEntry(index);
    } else {
      printf("branch lead_MomMomID_branch does not exist!\n");
      exit(1);
    }
    lead_MomMomID_isLoaded = true;
  }
  return lead_MomMomID_;
}

const float &ttHHadronic::lead_PassFrix() {
  if (not lead_PassFrix_isLoaded) {
    if (lead_PassFrix_branch != 0) {
      lead_PassFrix_branch->GetEntry(index);
    } else {
      printf("branch lead_PassFrix_branch does not exist!\n");
      exit(1);
    }
    lead_PassFrix_isLoaded = true;
  }
  return lead_PassFrix_;
}

const float &ttHHadronic::lead_SmallestDr() {
  if (not lead_SmallestDr_isLoaded) {
    if (lead_SmallestDr_branch != 0) {
      lead_SmallestDr_branch->GetEntry(index);
    } else {
      printf("branch lead_SmallestDr_branch does not exist!\n");
      exit(1);
    }
    lead_SmallestDr_isLoaded = true;
  }
  return lead_SmallestDr_;
}

const float &ttHHadronic::sublead_PhoGenPt() {
  if (not sublead_PhoGenPt_isLoaded) {
    if (sublead_PhoGenPt_branch != 0) {
      sublead_PhoGenPt_branch->GetEntry(index);
    } else {
      printf("branch sublead_PhoGenPt_branch does not exist!\n");
      exit(1);
    }
    sublead_PhoGenPt_isLoaded = true;
  }
  return sublead_PhoGenPt_;
}

const float &ttHHadronic::sublead_PhoGenEta() {
  if (not sublead_PhoGenEta_isLoaded) {
    if (sublead_PhoGenEta_branch != 0) {
      sublead_PhoGenEta_branch->GetEntry(index);
    } else {
      printf("branch sublead_PhoGenEta_branch does not exist!\n");
      exit(1);
    }
    sublead_PhoGenEta_isLoaded = true;
  }
  return sublead_PhoGenEta_;
}

const float &ttHHadronic::sublead_PhoGenPhi() {
  if (not sublead_PhoGenPhi_isLoaded) {
    if (sublead_PhoGenPhi_branch != 0) {
      sublead_PhoGenPhi_branch->GetEntry(index);
    } else {
      printf("branch sublead_PhoGenPhi_branch does not exist!\n");
      exit(1);
    }
    sublead_PhoGenPhi_isLoaded = true;
  }
  return sublead_PhoGenPhi_;
}

const float &ttHHadronic::sublead_Prompt() {
  if (not sublead_Prompt_isLoaded) {
    if (sublead_Prompt_branch != 0) {
      sublead_Prompt_branch->GetEntry(index);
    } else {
      printf("branch sublead_Prompt_branch does not exist!\n");
      exit(1);
    }
    sublead_Prompt_isLoaded = true;
  }
  return sublead_Prompt_;
}

const float &ttHHadronic::sublead_Mad() {
  if (not sublead_Mad_isLoaded) {
    if (sublead_Mad_branch != 0) {
      sublead_Mad_branch->GetEntry(index);
    } else {
      printf("branch sublead_Mad_branch does not exist!\n");
      exit(1);
    }
    sublead_Mad_isLoaded = true;
  }
  return sublead_Mad_;
}

const float &ttHHadronic::sublead_Pythia() {
  if (not sublead_Pythia_isLoaded) {
    if (sublead_Pythia_branch != 0) {
      sublead_Pythia_branch->GetEntry(index);
    } else {
      printf("branch sublead_Pythia_branch does not exist!\n");
      exit(1);
    }
    sublead_Pythia_isLoaded = true;
  }
  return sublead_Pythia_;
}

const float &ttHHadronic::sublead_SimpleMomID() {
  if (not sublead_SimpleMomID_isLoaded) {
    if (sublead_SimpleMomID_branch != 0) {
      sublead_SimpleMomID_branch->GetEntry(index);
    } else {
      printf("branch sublead_SimpleMomID_branch does not exist!\n");
      exit(1);
    }
    sublead_SimpleMomID_isLoaded = true;
  }
  return sublead_SimpleMomID_;
}

const float &ttHHadronic::sublead_SimpleMomStatus() {
  if (not sublead_SimpleMomStatus_isLoaded) {
    if (sublead_SimpleMomStatus_branch != 0) {
      sublead_SimpleMomStatus_branch->GetEntry(index);
    } else {
      printf("branch sublead_SimpleMomStatus_branch does not exist!\n");
      exit(1);
    }
    sublead_SimpleMomStatus_isLoaded = true;
  }
  return sublead_SimpleMomStatus_;
}

const float &ttHHadronic::sublead_MomID() {
  if (not sublead_MomID_isLoaded) {
    if (sublead_MomID_branch != 0) {
      sublead_MomID_branch->GetEntry(index);
    } else {
      printf("branch sublead_MomID_branch does not exist!\n");
      exit(1);
    }
    sublead_MomID_isLoaded = true;
  }
  return sublead_MomID_;
}

const float &ttHHadronic::sublead_MomMomID() {
  if (not sublead_MomMomID_isLoaded) {
    if (sublead_MomMomID_branch != 0) {
      sublead_MomMomID_branch->GetEntry(index);
    } else {
      printf("branch sublead_MomMomID_branch does not exist!\n");
      exit(1);
    }
    sublead_MomMomID_isLoaded = true;
  }
  return sublead_MomMomID_;
}

const float &ttHHadronic::sublead_PassFrix() {
  if (not sublead_PassFrix_isLoaded) {
    if (sublead_PassFrix_branch != 0) {
      sublead_PassFrix_branch->GetEntry(index);
    } else {
      printf("branch sublead_PassFrix_branch does not exist!\n");
      exit(1);
    }
    sublead_PassFrix_isLoaded = true;
  }
  return sublead_PassFrix_;
}

const float &ttHHadronic::sublead_SmallestDr() {
  if (not sublead_SmallestDr_isLoaded) {
    if (sublead_SmallestDr_branch != 0) {
      sublead_SmallestDr_branch->GetEntry(index);
    } else {
      printf("branch sublead_SmallestDr_branch does not exist!\n");
      exit(1);
    }
    sublead_SmallestDr_isLoaded = true;
  }
  return sublead_SmallestDr_;
}

const float &ttHHadronic::n_bjets() {
  if (not n_bjets_isLoaded) {
    if (n_bjets_branch != 0) {
      n_bjets_branch->GetEntry(index);
    } else {
      printf("branch n_bjets_branch does not exist!\n");
      exit(1);
    }
    n_bjets_isLoaded = true;
  }
  return n_bjets_;
}

const float &ttHHadronic::n_jets() {
  if (not n_jets_isLoaded) {
    if (n_jets_branch != 0) {
      n_jets_branch->GetEntry(index);
    } else {
      printf("branch n_jets_branch does not exist!\n");
      exit(1);
    }
    n_jets_isLoaded = true;
  }
  return n_jets_;
}

const float &ttHHadronic::bjet1_pt() {
  if (not bjet1_pt_isLoaded) {
    if (bjet1_pt_branch != 0) {
      bjet1_pt_branch->GetEntry(index);
    } else {
      printf("branch bjet1_pt_branch does not exist!\n");
      exit(1);
    }
    bjet1_pt_isLoaded = true;
  }
  return bjet1_pt_;
}

const float &ttHHadronic::bjet2_pt() {
  if (not bjet2_pt_isLoaded) {
    if (bjet2_pt_branch != 0) {
      bjet2_pt_branch->GetEntry(index);
    } else {
      printf("branch bjet2_pt_branch does not exist!\n");
      exit(1);
    }
    bjet2_pt_isLoaded = true;
  }
  return bjet2_pt_;
}

const float &ttHHadronic::MetPt() {
  if (not MetPt_isLoaded) {
    if (MetPt_branch != 0) {
      MetPt_branch->GetEntry(index);
    } else {
      printf("branch MetPt_branch does not exist!\n");
      exit(1);
    }
    MetPt_isLoaded = true;
  }
  return MetPt_;
}

const float &ttHHadronic::MetPhi() {
  if (not MetPhi_isLoaded) {
    if (MetPhi_branch != 0) {
      MetPhi_branch->GetEntry(index);
    } else {
      printf("branch MetPhi_branch does not exist!\n");
      exit(1);
    }
    MetPhi_isLoaded = true;
  }
  return MetPhi_;
}

const float &ttHHadronic::jet1_pt() {
  if (not jet1_pt_isLoaded) {
    if (jet1_pt_branch != 0) {
      jet1_pt_branch->GetEntry(index);
    } else {
      printf("branch jet1_pt_branch does not exist!\n");
      exit(1);
    }
    jet1_pt_isLoaded = true;
  }
  return jet1_pt_;
}

const float &ttHHadronic::jet2_pt() {
  if (not jet2_pt_isLoaded) {
    if (jet2_pt_branch != 0) {
      jet2_pt_branch->GetEntry(index);
    } else {
      printf("branch jet2_pt_branch does not exist!\n");
      exit(1);
    }
    jet2_pt_isLoaded = true;
  }
  return jet2_pt_;
}

const float &ttHHadronic::jet3_pt() {
  if (not jet3_pt_isLoaded) {
    if (jet3_pt_branch != 0) {
      jet3_pt_branch->GetEntry(index);
    } else {
      printf("branch jet3_pt_branch does not exist!\n");
      exit(1);
    }
    jet3_pt_isLoaded = true;
  }
  return jet3_pt_;
}

const float &ttHHadronic::jet4_pt() {
  if (not jet4_pt_isLoaded) {
    if (jet4_pt_branch != 0) {
      jet4_pt_branch->GetEntry(index);
    } else {
      printf("branch jet4_pt_branch does not exist!\n");
      exit(1);
    }
    jet4_pt_isLoaded = true;
  }
  return jet4_pt_;
}

const float &ttHHadronic::jet5_pt() {
  if (not jet5_pt_isLoaded) {
    if (jet5_pt_branch != 0) {
      jet5_pt_branch->GetEntry(index);
    } else {
      printf("branch jet5_pt_branch does not exist!\n");
      exit(1);
    }
    jet5_pt_isLoaded = true;
  }
  return jet5_pt_;
}

const float &ttHHadronic::jet6_pt() {
  if (not jet6_pt_isLoaded) {
    if (jet6_pt_branch != 0) {
      jet6_pt_branch->GetEntry(index);
    } else {
      printf("branch jet6_pt_branch does not exist!\n");
      exit(1);
    }
    jet6_pt_isLoaded = true;
  }
  return jet6_pt_;
}

const float &ttHHadronic::jet7_pt() {
  if (not jet7_pt_isLoaded) {
    if (jet7_pt_branch != 0) {
      jet7_pt_branch->GetEntry(index);
    } else {
      printf("branch jet7_pt_branch does not exist!\n");
      exit(1);
    }
    jet7_pt_isLoaded = true;
  }
  return jet7_pt_;
}

const float &ttHHadronic::jet8_pt() {
  if (not jet8_pt_isLoaded) {
    if (jet8_pt_branch != 0) {
      jet8_pt_branch->GetEntry(index);
    } else {
      printf("branch jet8_pt_branch does not exist!\n");
      exit(1);
    }
    jet8_pt_isLoaded = true;
  }
  return jet8_pt_;
}

const float &ttHHadronic::jet9_pt() {
  if (not jet9_pt_isLoaded) {
    if (jet9_pt_branch != 0) {
      jet9_pt_branch->GetEntry(index);
    } else {
      printf("branch jet9_pt_branch does not exist!\n");
      exit(1);
    }
    jet9_pt_isLoaded = true;
  }
  return jet9_pt_;
}

const float &ttHHadronic::jet10_pt() {
  if (not jet10_pt_isLoaded) {
    if (jet10_pt_branch != 0) {
      jet10_pt_branch->GetEntry(index);
    } else {
      printf("branch jet10_pt_branch does not exist!\n");
      exit(1);
    }
    jet10_pt_isLoaded = true;
  }
  return jet10_pt_;
}

const float &ttHHadronic::jet11_pt() {
  if (not jet11_pt_isLoaded) {
    if (jet11_pt_branch != 0) {
      jet11_pt_branch->GetEntry(index);
    } else {
      printf("branch jet11_pt_branch does not exist!\n");
      exit(1);
    }
    jet11_pt_isLoaded = true;
  }
  return jet11_pt_;
}

const float &ttHHadronic::jet12_pt() {
  if (not jet12_pt_isLoaded) {
    if (jet12_pt_branch != 0) {
      jet12_pt_branch->GetEntry(index);
    } else {
      printf("branch jet12_pt_branch does not exist!\n");
      exit(1);
    }
    jet12_pt_isLoaded = true;
  }
  return jet12_pt_;
}

const float &ttHHadronic::jet13_pt() {
  if (not jet13_pt_isLoaded) {
    if (jet13_pt_branch != 0) {
      jet13_pt_branch->GetEntry(index);
    } else {
      printf("branch jet13_pt_branch does not exist!\n");
      exit(1);
    }
    jet13_pt_isLoaded = true;
  }
  return jet13_pt_;
}

const float &ttHHadronic::jet14_pt() {
  if (not jet14_pt_isLoaded) {
    if (jet14_pt_branch != 0) {
      jet14_pt_branch->GetEntry(index);
    } else {
      printf("branch jet14_pt_branch does not exist!\n");
      exit(1);
    }
    jet14_pt_isLoaded = true;
  }
  return jet14_pt_;
}

const float &ttHHadronic::jet15_pt() {
  if (not jet15_pt_isLoaded) {
    if (jet15_pt_branch != 0) {
      jet15_pt_branch->GetEntry(index);
    } else {
      printf("branch jet15_pt_branch does not exist!\n");
      exit(1);
    }
    jet15_pt_isLoaded = true;
  }
  return jet15_pt_;
}

const float &ttHHadronic::jet1_eta() {
  if (not jet1_eta_isLoaded) {
    if (jet1_eta_branch != 0) {
      jet1_eta_branch->GetEntry(index);
    } else {
      printf("branch jet1_eta_branch does not exist!\n");
      exit(1);
    }
    jet1_eta_isLoaded = true;
  }
  return jet1_eta_;
}

const float &ttHHadronic::jet2_eta() {
  if (not jet2_eta_isLoaded) {
    if (jet2_eta_branch != 0) {
      jet2_eta_branch->GetEntry(index);
    } else {
      printf("branch jet2_eta_branch does not exist!\n");
      exit(1);
    }
    jet2_eta_isLoaded = true;
  }
  return jet2_eta_;
}

const float &ttHHadronic::jet3_eta() {
  if (not jet3_eta_isLoaded) {
    if (jet3_eta_branch != 0) {
      jet3_eta_branch->GetEntry(index);
    } else {
      printf("branch jet3_eta_branch does not exist!\n");
      exit(1);
    }
    jet3_eta_isLoaded = true;
  }
  return jet3_eta_;
}

const float &ttHHadronic::jet4_eta() {
  if (not jet4_eta_isLoaded) {
    if (jet4_eta_branch != 0) {
      jet4_eta_branch->GetEntry(index);
    } else {
      printf("branch jet4_eta_branch does not exist!\n");
      exit(1);
    }
    jet4_eta_isLoaded = true;
  }
  return jet4_eta_;
}

const float &ttHHadronic::jet5_eta() {
  if (not jet5_eta_isLoaded) {
    if (jet5_eta_branch != 0) {
      jet5_eta_branch->GetEntry(index);
    } else {
      printf("branch jet5_eta_branch does not exist!\n");
      exit(1);
    }
    jet5_eta_isLoaded = true;
  }
  return jet5_eta_;
}

const float &ttHHadronic::jet6_eta() {
  if (not jet6_eta_isLoaded) {
    if (jet6_eta_branch != 0) {
      jet6_eta_branch->GetEntry(index);
    } else {
      printf("branch jet6_eta_branch does not exist!\n");
      exit(1);
    }
    jet6_eta_isLoaded = true;
  }
  return jet6_eta_;
}

const float &ttHHadronic::jet7_eta() {
  if (not jet7_eta_isLoaded) {
    if (jet7_eta_branch != 0) {
      jet7_eta_branch->GetEntry(index);
    } else {
      printf("branch jet7_eta_branch does not exist!\n");
      exit(1);
    }
    jet7_eta_isLoaded = true;
  }
  return jet7_eta_;
}

const float &ttHHadronic::jet8_eta() {
  if (not jet8_eta_isLoaded) {
    if (jet8_eta_branch != 0) {
      jet8_eta_branch->GetEntry(index);
    } else {
      printf("branch jet8_eta_branch does not exist!\n");
      exit(1);
    }
    jet8_eta_isLoaded = true;
  }
  return jet8_eta_;
}

const float &ttHHadronic::jet9_eta() {
  if (not jet9_eta_isLoaded) {
    if (jet9_eta_branch != 0) {
      jet9_eta_branch->GetEntry(index);
    } else {
      printf("branch jet9_eta_branch does not exist!\n");
      exit(1);
    }
    jet9_eta_isLoaded = true;
  }
  return jet9_eta_;
}

const float &ttHHadronic::jet10_eta() {
  if (not jet10_eta_isLoaded) {
    if (jet10_eta_branch != 0) {
      jet10_eta_branch->GetEntry(index);
    } else {
      printf("branch jet10_eta_branch does not exist!\n");
      exit(1);
    }
    jet10_eta_isLoaded = true;
  }
  return jet10_eta_;
}

const float &ttHHadronic::jet11_eta() {
  if (not jet11_eta_isLoaded) {
    if (jet11_eta_branch != 0) {
      jet11_eta_branch->GetEntry(index);
    } else {
      printf("branch jet11_eta_branch does not exist!\n");
      exit(1);
    }
    jet11_eta_isLoaded = true;
  }
  return jet11_eta_;
}

const float &ttHHadronic::jet12_eta() {
  if (not jet12_eta_isLoaded) {
    if (jet12_eta_branch != 0) {
      jet12_eta_branch->GetEntry(index);
    } else {
      printf("branch jet12_eta_branch does not exist!\n");
      exit(1);
    }
    jet12_eta_isLoaded = true;
  }
  return jet12_eta_;
}

const float &ttHHadronic::jet13_eta() {
  if (not jet13_eta_isLoaded) {
    if (jet13_eta_branch != 0) {
      jet13_eta_branch->GetEntry(index);
    } else {
      printf("branch jet13_eta_branch does not exist!\n");
      exit(1);
    }
    jet13_eta_isLoaded = true;
  }
  return jet13_eta_;
}

const float &ttHHadronic::jet14_eta() {
  if (not jet14_eta_isLoaded) {
    if (jet14_eta_branch != 0) {
      jet14_eta_branch->GetEntry(index);
    } else {
      printf("branch jet14_eta_branch does not exist!\n");
      exit(1);
    }
    jet14_eta_isLoaded = true;
  }
  return jet14_eta_;
}

const float &ttHHadronic::jet15_eta() {
  if (not jet15_eta_isLoaded) {
    if (jet15_eta_branch != 0) {
      jet15_eta_branch->GetEntry(index);
    } else {
      printf("branch jet15_eta_branch does not exist!\n");
      exit(1);
    }
    jet15_eta_isLoaded = true;
  }
  return jet15_eta_;
}

const float &ttHHadronic::jet1_phi() {
  if (not jet1_phi_isLoaded) {
    if (jet1_phi_branch != 0) {
      jet1_phi_branch->GetEntry(index);
    } else {
      printf("branch jet1_phi_branch does not exist!\n");
      exit(1);
    }
    jet1_phi_isLoaded = true;
  }
  return jet1_phi_;
}

const float &ttHHadronic::jet2_phi() {
  if (not jet2_phi_isLoaded) {
    if (jet2_phi_branch != 0) {
      jet2_phi_branch->GetEntry(index);
    } else {
      printf("branch jet2_phi_branch does not exist!\n");
      exit(1);
    }
    jet2_phi_isLoaded = true;
  }
  return jet2_phi_;
}

const float &ttHHadronic::jet3_phi() {
  if (not jet3_phi_isLoaded) {
    if (jet3_phi_branch != 0) {
      jet3_phi_branch->GetEntry(index);
    } else {
      printf("branch jet3_phi_branch does not exist!\n");
      exit(1);
    }
    jet3_phi_isLoaded = true;
  }
  return jet3_phi_;
}

const float &ttHHadronic::jet4_phi() {
  if (not jet4_phi_isLoaded) {
    if (jet4_phi_branch != 0) {
      jet4_phi_branch->GetEntry(index);
    } else {
      printf("branch jet4_phi_branch does not exist!\n");
      exit(1);
    }
    jet4_phi_isLoaded = true;
  }
  return jet4_phi_;
}

const float &ttHHadronic::jet5_phi() {
  if (not jet5_phi_isLoaded) {
    if (jet5_phi_branch != 0) {
      jet5_phi_branch->GetEntry(index);
    } else {
      printf("branch jet5_phi_branch does not exist!\n");
      exit(1);
    }
    jet5_phi_isLoaded = true;
  }
  return jet5_phi_;
}

const float &ttHHadronic::jet6_phi() {
  if (not jet6_phi_isLoaded) {
    if (jet6_phi_branch != 0) {
      jet6_phi_branch->GetEntry(index);
    } else {
      printf("branch jet6_phi_branch does not exist!\n");
      exit(1);
    }
    jet6_phi_isLoaded = true;
  }
  return jet6_phi_;
}

const float &ttHHadronic::jet7_phi() {
  if (not jet7_phi_isLoaded) {
    if (jet7_phi_branch != 0) {
      jet7_phi_branch->GetEntry(index);
    } else {
      printf("branch jet7_phi_branch does not exist!\n");
      exit(1);
    }
    jet7_phi_isLoaded = true;
  }
  return jet7_phi_;
}

const float &ttHHadronic::jet8_phi() {
  if (not jet8_phi_isLoaded) {
    if (jet8_phi_branch != 0) {
      jet8_phi_branch->GetEntry(index);
    } else {
      printf("branch jet8_phi_branch does not exist!\n");
      exit(1);
    }
    jet8_phi_isLoaded = true;
  }
  return jet8_phi_;
}

const float &ttHHadronic::jet9_phi() {
  if (not jet9_phi_isLoaded) {
    if (jet9_phi_branch != 0) {
      jet9_phi_branch->GetEntry(index);
    } else {
      printf("branch jet9_phi_branch does not exist!\n");
      exit(1);
    }
    jet9_phi_isLoaded = true;
  }
  return jet9_phi_;
}

const float &ttHHadronic::jet10_phi() {
  if (not jet10_phi_isLoaded) {
    if (jet10_phi_branch != 0) {
      jet10_phi_branch->GetEntry(index);
    } else {
      printf("branch jet10_phi_branch does not exist!\n");
      exit(1);
    }
    jet10_phi_isLoaded = true;
  }
  return jet10_phi_;
}

const float &ttHHadronic::jet11_phi() {
  if (not jet11_phi_isLoaded) {
    if (jet11_phi_branch != 0) {
      jet11_phi_branch->GetEntry(index);
    } else {
      printf("branch jet11_phi_branch does not exist!\n");
      exit(1);
    }
    jet11_phi_isLoaded = true;
  }
  return jet11_phi_;
}

const float &ttHHadronic::jet12_phi() {
  if (not jet12_phi_isLoaded) {
    if (jet12_phi_branch != 0) {
      jet12_phi_branch->GetEntry(index);
    } else {
      printf("branch jet12_phi_branch does not exist!\n");
      exit(1);
    }
    jet12_phi_isLoaded = true;
  }
  return jet12_phi_;
}

const float &ttHHadronic::jet13_phi() {
  if (not jet13_phi_isLoaded) {
    if (jet13_phi_branch != 0) {
      jet13_phi_branch->GetEntry(index);
    } else {
      printf("branch jet13_phi_branch does not exist!\n");
      exit(1);
    }
    jet13_phi_isLoaded = true;
  }
  return jet13_phi_;
}

const float &ttHHadronic::jet14_phi() {
  if (not jet14_phi_isLoaded) {
    if (jet14_phi_branch != 0) {
      jet14_phi_branch->GetEntry(index);
    } else {
      printf("branch jet14_phi_branch does not exist!\n");
      exit(1);
    }
    jet14_phi_isLoaded = true;
  }
  return jet14_phi_;
}

const float &ttHHadronic::jet15_phi() {
  if (not jet15_phi_isLoaded) {
    if (jet15_phi_branch != 0) {
      jet15_phi_branch->GetEntry(index);
    } else {
      printf("branch jet15_phi_branch does not exist!\n");
      exit(1);
    }
    jet15_phi_isLoaded = true;
  }
  return jet15_phi_;
}

const float &ttHHadronic::jet1_bdiscriminant() {
  if (not jet1_bdiscriminant_isLoaded) {
    if (jet1_bdiscriminant_branch != 0) {
      jet1_bdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet1_bdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet1_bdiscriminant_isLoaded = true;
  }
  return jet1_bdiscriminant_;
}

const float &ttHHadronic::jet2_bdiscriminant() {
  if (not jet2_bdiscriminant_isLoaded) {
    if (jet2_bdiscriminant_branch != 0) {
      jet2_bdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet2_bdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet2_bdiscriminant_isLoaded = true;
  }
  return jet2_bdiscriminant_;
}

const float &ttHHadronic::jet3_bdiscriminant() {
  if (not jet3_bdiscriminant_isLoaded) {
    if (jet3_bdiscriminant_branch != 0) {
      jet3_bdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet3_bdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet3_bdiscriminant_isLoaded = true;
  }
  return jet3_bdiscriminant_;
}

const float &ttHHadronic::jet4_bdiscriminant() {
  if (not jet4_bdiscriminant_isLoaded) {
    if (jet4_bdiscriminant_branch != 0) {
      jet4_bdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet4_bdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet4_bdiscriminant_isLoaded = true;
  }
  return jet4_bdiscriminant_;
}

const float &ttHHadronic::jet5_bdiscriminant() {
  if (not jet5_bdiscriminant_isLoaded) {
    if (jet5_bdiscriminant_branch != 0) {
      jet5_bdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet5_bdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet5_bdiscriminant_isLoaded = true;
  }
  return jet5_bdiscriminant_;
}

const float &ttHHadronic::jet6_bdiscriminant() {
  if (not jet6_bdiscriminant_isLoaded) {
    if (jet6_bdiscriminant_branch != 0) {
      jet6_bdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet6_bdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet6_bdiscriminant_isLoaded = true;
  }
  return jet6_bdiscriminant_;
}

const float &ttHHadronic::jet7_bdiscriminant() {
  if (not jet7_bdiscriminant_isLoaded) {
    if (jet7_bdiscriminant_branch != 0) {
      jet7_bdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet7_bdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet7_bdiscriminant_isLoaded = true;
  }
  return jet7_bdiscriminant_;
}

const float &ttHHadronic::jet8_bdiscriminant() {
  if (not jet8_bdiscriminant_isLoaded) {
    if (jet8_bdiscriminant_branch != 0) {
      jet8_bdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet8_bdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet8_bdiscriminant_isLoaded = true;
  }
  return jet8_bdiscriminant_;
}

const float &ttHHadronic::jet9_bdiscriminant() {
  if (not jet9_bdiscriminant_isLoaded) {
    if (jet9_bdiscriminant_branch != 0) {
      jet9_bdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet9_bdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet9_bdiscriminant_isLoaded = true;
  }
  return jet9_bdiscriminant_;
}

const float &ttHHadronic::jet10_bdiscriminant() {
  if (not jet10_bdiscriminant_isLoaded) {
    if (jet10_bdiscriminant_branch != 0) {
      jet10_bdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet10_bdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet10_bdiscriminant_isLoaded = true;
  }
  return jet10_bdiscriminant_;
}

const float &ttHHadronic::jet11_bdiscriminant() {
  if (not jet11_bdiscriminant_isLoaded) {
    if (jet11_bdiscriminant_branch != 0) {
      jet11_bdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet11_bdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet11_bdiscriminant_isLoaded = true;
  }
  return jet11_bdiscriminant_;
}

const float &ttHHadronic::jet12_bdiscriminant() {
  if (not jet12_bdiscriminant_isLoaded) {
    if (jet12_bdiscriminant_branch != 0) {
      jet12_bdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet12_bdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet12_bdiscriminant_isLoaded = true;
  }
  return jet12_bdiscriminant_;
}

const float &ttHHadronic::jet13_bdiscriminant() {
  if (not jet13_bdiscriminant_isLoaded) {
    if (jet13_bdiscriminant_branch != 0) {
      jet13_bdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet13_bdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet13_bdiscriminant_isLoaded = true;
  }
  return jet13_bdiscriminant_;
}

const float &ttHHadronic::jet14_bdiscriminant() {
  if (not jet14_bdiscriminant_isLoaded) {
    if (jet14_bdiscriminant_branch != 0) {
      jet14_bdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet14_bdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet14_bdiscriminant_isLoaded = true;
  }
  return jet14_bdiscriminant_;
}

const float &ttHHadronic::jet15_bdiscriminant() {
  if (not jet15_bdiscriminant_isLoaded) {
    if (jet15_bdiscriminant_branch != 0) {
      jet15_bdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet15_bdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet15_bdiscriminant_isLoaded = true;
  }
  return jet15_bdiscriminant_;
}

const float &ttHHadronic::jet1_bbdiscriminant() {
  if (not jet1_bbdiscriminant_isLoaded) {
    if (jet1_bbdiscriminant_branch != 0) {
      jet1_bbdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet1_bbdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet1_bbdiscriminant_isLoaded = true;
  }
  return jet1_bbdiscriminant_;
}

const float &ttHHadronic::jet2_bbdiscriminant() {
  if (not jet2_bbdiscriminant_isLoaded) {
    if (jet2_bbdiscriminant_branch != 0) {
      jet2_bbdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet2_bbdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet2_bbdiscriminant_isLoaded = true;
  }
  return jet2_bbdiscriminant_;
}

const float &ttHHadronic::jet3_bbdiscriminant() {
  if (not jet3_bbdiscriminant_isLoaded) {
    if (jet3_bbdiscriminant_branch != 0) {
      jet3_bbdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet3_bbdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet3_bbdiscriminant_isLoaded = true;
  }
  return jet3_bbdiscriminant_;
}

const float &ttHHadronic::jet4_bbdiscriminant() {
  if (not jet4_bbdiscriminant_isLoaded) {
    if (jet4_bbdiscriminant_branch != 0) {
      jet4_bbdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet4_bbdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet4_bbdiscriminant_isLoaded = true;
  }
  return jet4_bbdiscriminant_;
}

const float &ttHHadronic::jet5_bbdiscriminant() {
  if (not jet5_bbdiscriminant_isLoaded) {
    if (jet5_bbdiscriminant_branch != 0) {
      jet5_bbdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet5_bbdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet5_bbdiscriminant_isLoaded = true;
  }
  return jet5_bbdiscriminant_;
}

const float &ttHHadronic::jet6_bbdiscriminant() {
  if (not jet6_bbdiscriminant_isLoaded) {
    if (jet6_bbdiscriminant_branch != 0) {
      jet6_bbdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet6_bbdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet6_bbdiscriminant_isLoaded = true;
  }
  return jet6_bbdiscriminant_;
}

const float &ttHHadronic::jet7_bbdiscriminant() {
  if (not jet7_bbdiscriminant_isLoaded) {
    if (jet7_bbdiscriminant_branch != 0) {
      jet7_bbdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet7_bbdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet7_bbdiscriminant_isLoaded = true;
  }
  return jet7_bbdiscriminant_;
}

const float &ttHHadronic::jet8_bbdiscriminant() {
  if (not jet8_bbdiscriminant_isLoaded) {
    if (jet8_bbdiscriminant_branch != 0) {
      jet8_bbdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet8_bbdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet8_bbdiscriminant_isLoaded = true;
  }
  return jet8_bbdiscriminant_;
}

const float &ttHHadronic::jet9_bbdiscriminant() {
  if (not jet9_bbdiscriminant_isLoaded) {
    if (jet9_bbdiscriminant_branch != 0) {
      jet9_bbdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet9_bbdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet9_bbdiscriminant_isLoaded = true;
  }
  return jet9_bbdiscriminant_;
}

const float &ttHHadronic::jet10_bbdiscriminant() {
  if (not jet10_bbdiscriminant_isLoaded) {
    if (jet10_bbdiscriminant_branch != 0) {
      jet10_bbdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet10_bbdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet10_bbdiscriminant_isLoaded = true;
  }
  return jet10_bbdiscriminant_;
}

const float &ttHHadronic::jet11_bbdiscriminant() {
  if (not jet11_bbdiscriminant_isLoaded) {
    if (jet11_bbdiscriminant_branch != 0) {
      jet11_bbdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet11_bbdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet11_bbdiscriminant_isLoaded = true;
  }
  return jet11_bbdiscriminant_;
}

const float &ttHHadronic::jet12_bbdiscriminant() {
  if (not jet12_bbdiscriminant_isLoaded) {
    if (jet12_bbdiscriminant_branch != 0) {
      jet12_bbdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet12_bbdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet12_bbdiscriminant_isLoaded = true;
  }
  return jet12_bbdiscriminant_;
}

const float &ttHHadronic::jet13_bbdiscriminant() {
  if (not jet13_bbdiscriminant_isLoaded) {
    if (jet13_bbdiscriminant_branch != 0) {
      jet13_bbdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet13_bbdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet13_bbdiscriminant_isLoaded = true;
  }
  return jet13_bbdiscriminant_;
}

const float &ttHHadronic::jet14_bbdiscriminant() {
  if (not jet14_bbdiscriminant_isLoaded) {
    if (jet14_bbdiscriminant_branch != 0) {
      jet14_bbdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet14_bbdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet14_bbdiscriminant_isLoaded = true;
  }
  return jet14_bbdiscriminant_;
}

const float &ttHHadronic::jet15_bbdiscriminant() {
  if (not jet15_bbdiscriminant_isLoaded) {
    if (jet15_bbdiscriminant_branch != 0) {
      jet15_bbdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet15_bbdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet15_bbdiscriminant_isLoaded = true;
  }
  return jet15_bbdiscriminant_;
}

const float &ttHHadronic::jet1_cdiscriminant() {
  if (not jet1_cdiscriminant_isLoaded) {
    if (jet1_cdiscriminant_branch != 0) {
      jet1_cdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet1_cdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet1_cdiscriminant_isLoaded = true;
  }
  return jet1_cdiscriminant_;
}

const float &ttHHadronic::jet2_cdiscriminant() {
  if (not jet2_cdiscriminant_isLoaded) {
    if (jet2_cdiscriminant_branch != 0) {
      jet2_cdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet2_cdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet2_cdiscriminant_isLoaded = true;
  }
  return jet2_cdiscriminant_;
}

const float &ttHHadronic::jet3_cdiscriminant() {
  if (not jet3_cdiscriminant_isLoaded) {
    if (jet3_cdiscriminant_branch != 0) {
      jet3_cdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet3_cdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet3_cdiscriminant_isLoaded = true;
  }
  return jet3_cdiscriminant_;
}

const float &ttHHadronic::jet4_cdiscriminant() {
  if (not jet4_cdiscriminant_isLoaded) {
    if (jet4_cdiscriminant_branch != 0) {
      jet4_cdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet4_cdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet4_cdiscriminant_isLoaded = true;
  }
  return jet4_cdiscriminant_;
}

const float &ttHHadronic::jet5_cdiscriminant() {
  if (not jet5_cdiscriminant_isLoaded) {
    if (jet5_cdiscriminant_branch != 0) {
      jet5_cdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet5_cdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet5_cdiscriminant_isLoaded = true;
  }
  return jet5_cdiscriminant_;
}

const float &ttHHadronic::jet6_cdiscriminant() {
  if (not jet6_cdiscriminant_isLoaded) {
    if (jet6_cdiscriminant_branch != 0) {
      jet6_cdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet6_cdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet6_cdiscriminant_isLoaded = true;
  }
  return jet6_cdiscriminant_;
}

const float &ttHHadronic::jet7_cdiscriminant() {
  if (not jet7_cdiscriminant_isLoaded) {
    if (jet7_cdiscriminant_branch != 0) {
      jet7_cdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet7_cdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet7_cdiscriminant_isLoaded = true;
  }
  return jet7_cdiscriminant_;
}

const float &ttHHadronic::jet8_cdiscriminant() {
  if (not jet8_cdiscriminant_isLoaded) {
    if (jet8_cdiscriminant_branch != 0) {
      jet8_cdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet8_cdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet8_cdiscriminant_isLoaded = true;
  }
  return jet8_cdiscriminant_;
}

const float &ttHHadronic::jet9_cdiscriminant() {
  if (not jet9_cdiscriminant_isLoaded) {
    if (jet9_cdiscriminant_branch != 0) {
      jet9_cdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet9_cdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet9_cdiscriminant_isLoaded = true;
  }
  return jet9_cdiscriminant_;
}

const float &ttHHadronic::jet10_cdiscriminant() {
  if (not jet10_cdiscriminant_isLoaded) {
    if (jet10_cdiscriminant_branch != 0) {
      jet10_cdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet10_cdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet10_cdiscriminant_isLoaded = true;
  }
  return jet10_cdiscriminant_;
}

const float &ttHHadronic::jet11_cdiscriminant() {
  if (not jet11_cdiscriminant_isLoaded) {
    if (jet11_cdiscriminant_branch != 0) {
      jet11_cdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet11_cdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet11_cdiscriminant_isLoaded = true;
  }
  return jet11_cdiscriminant_;
}

const float &ttHHadronic::jet12_cdiscriminant() {
  if (not jet12_cdiscriminant_isLoaded) {
    if (jet12_cdiscriminant_branch != 0) {
      jet12_cdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet12_cdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet12_cdiscriminant_isLoaded = true;
  }
  return jet12_cdiscriminant_;
}

const float &ttHHadronic::jet13_cdiscriminant() {
  if (not jet13_cdiscriminant_isLoaded) {
    if (jet13_cdiscriminant_branch != 0) {
      jet13_cdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet13_cdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet13_cdiscriminant_isLoaded = true;
  }
  return jet13_cdiscriminant_;
}

const float &ttHHadronic::jet14_cdiscriminant() {
  if (not jet14_cdiscriminant_isLoaded) {
    if (jet14_cdiscriminant_branch != 0) {
      jet14_cdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet14_cdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet14_cdiscriminant_isLoaded = true;
  }
  return jet14_cdiscriminant_;
}

const float &ttHHadronic::jet15_cdiscriminant() {
  if (not jet15_cdiscriminant_isLoaded) {
    if (jet15_cdiscriminant_branch != 0) {
      jet15_cdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet15_cdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet15_cdiscriminant_isLoaded = true;
  }
  return jet15_cdiscriminant_;
}

const float &ttHHadronic::jet1_udsgdiscriminant() {
  if (not jet1_udsgdiscriminant_isLoaded) {
    if (jet1_udsgdiscriminant_branch != 0) {
      jet1_udsgdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet1_udsgdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet1_udsgdiscriminant_isLoaded = true;
  }
  return jet1_udsgdiscriminant_;
}

const float &ttHHadronic::jet2_udsgdiscriminant() {
  if (not jet2_udsgdiscriminant_isLoaded) {
    if (jet2_udsgdiscriminant_branch != 0) {
      jet2_udsgdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet2_udsgdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet2_udsgdiscriminant_isLoaded = true;
  }
  return jet2_udsgdiscriminant_;
}

const float &ttHHadronic::jet3_udsgdiscriminant() {
  if (not jet3_udsgdiscriminant_isLoaded) {
    if (jet3_udsgdiscriminant_branch != 0) {
      jet3_udsgdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet3_udsgdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet3_udsgdiscriminant_isLoaded = true;
  }
  return jet3_udsgdiscriminant_;
}

const float &ttHHadronic::jet4_udsgdiscriminant() {
  if (not jet4_udsgdiscriminant_isLoaded) {
    if (jet4_udsgdiscriminant_branch != 0) {
      jet4_udsgdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet4_udsgdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet4_udsgdiscriminant_isLoaded = true;
  }
  return jet4_udsgdiscriminant_;
}

const float &ttHHadronic::jet5_udsgdiscriminant() {
  if (not jet5_udsgdiscriminant_isLoaded) {
    if (jet5_udsgdiscriminant_branch != 0) {
      jet5_udsgdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet5_udsgdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet5_udsgdiscriminant_isLoaded = true;
  }
  return jet5_udsgdiscriminant_;
}

const float &ttHHadronic::jet6_udsgdiscriminant() {
  if (not jet6_udsgdiscriminant_isLoaded) {
    if (jet6_udsgdiscriminant_branch != 0) {
      jet6_udsgdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet6_udsgdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet6_udsgdiscriminant_isLoaded = true;
  }
  return jet6_udsgdiscriminant_;
}

const float &ttHHadronic::jet7_udsgdiscriminant() {
  if (not jet7_udsgdiscriminant_isLoaded) {
    if (jet7_udsgdiscriminant_branch != 0) {
      jet7_udsgdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet7_udsgdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet7_udsgdiscriminant_isLoaded = true;
  }
  return jet7_udsgdiscriminant_;
}

const float &ttHHadronic::jet8_udsgdiscriminant() {
  if (not jet8_udsgdiscriminant_isLoaded) {
    if (jet8_udsgdiscriminant_branch != 0) {
      jet8_udsgdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet8_udsgdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet8_udsgdiscriminant_isLoaded = true;
  }
  return jet8_udsgdiscriminant_;
}

const float &ttHHadronic::jet9_udsgdiscriminant() {
  if (not jet9_udsgdiscriminant_isLoaded) {
    if (jet9_udsgdiscriminant_branch != 0) {
      jet9_udsgdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet9_udsgdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet9_udsgdiscriminant_isLoaded = true;
  }
  return jet9_udsgdiscriminant_;
}

const float &ttHHadronic::jet10_udsgdiscriminant() {
  if (not jet10_udsgdiscriminant_isLoaded) {
    if (jet10_udsgdiscriminant_branch != 0) {
      jet10_udsgdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet10_udsgdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet10_udsgdiscriminant_isLoaded = true;
  }
  return jet10_udsgdiscriminant_;
}

const float &ttHHadronic::jet11_udsgdiscriminant() {
  if (not jet11_udsgdiscriminant_isLoaded) {
    if (jet11_udsgdiscriminant_branch != 0) {
      jet11_udsgdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet11_udsgdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet11_udsgdiscriminant_isLoaded = true;
  }
  return jet11_udsgdiscriminant_;
}

const float &ttHHadronic::jet12_udsgdiscriminant() {
  if (not jet12_udsgdiscriminant_isLoaded) {
    if (jet12_udsgdiscriminant_branch != 0) {
      jet12_udsgdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet12_udsgdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet12_udsgdiscriminant_isLoaded = true;
  }
  return jet12_udsgdiscriminant_;
}

const float &ttHHadronic::jet13_udsgdiscriminant() {
  if (not jet13_udsgdiscriminant_isLoaded) {
    if (jet13_udsgdiscriminant_branch != 0) {
      jet13_udsgdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet13_udsgdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet13_udsgdiscriminant_isLoaded = true;
  }
  return jet13_udsgdiscriminant_;
}

const float &ttHHadronic::jet14_udsgdiscriminant() {
  if (not jet14_udsgdiscriminant_isLoaded) {
    if (jet14_udsgdiscriminant_branch != 0) {
      jet14_udsgdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet14_udsgdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet14_udsgdiscriminant_isLoaded = true;
  }
  return jet14_udsgdiscriminant_;
}

const float &ttHHadronic::jet15_udsgdiscriminant() {
  if (not jet15_udsgdiscriminant_isLoaded) {
    if (jet15_udsgdiscriminant_branch != 0) {
      jet15_udsgdiscriminant_branch->GetEntry(index);
    } else {
      printf("branch jet15_udsgdiscriminant_branch does not exist!\n");
      exit(1);
    }
    jet15_udsgdiscriminant_isLoaded = true;
  }
  return jet15_udsgdiscriminant_;
}

const float &ttHHadronic::jet1_energy() {
  if (not jet1_energy_isLoaded) {
    if (jet1_energy_branch != 0) {
      jet1_energy_branch->GetEntry(index);
    } else {
      printf("branch jet1_energy_branch does not exist!\n");
      exit(1);
    }
    jet1_energy_isLoaded = true;
  }
  return jet1_energy_;
}

const float &ttHHadronic::jet2_energy() {
  if (not jet2_energy_isLoaded) {
    if (jet2_energy_branch != 0) {
      jet2_energy_branch->GetEntry(index);
    } else {
      printf("branch jet2_energy_branch does not exist!\n");
      exit(1);
    }
    jet2_energy_isLoaded = true;
  }
  return jet2_energy_;
}

const float &ttHHadronic::jet3_energy() {
  if (not jet3_energy_isLoaded) {
    if (jet3_energy_branch != 0) {
      jet3_energy_branch->GetEntry(index);
    } else {
      printf("branch jet3_energy_branch does not exist!\n");
      exit(1);
    }
    jet3_energy_isLoaded = true;
  }
  return jet3_energy_;
}

const float &ttHHadronic::jet4_energy() {
  if (not jet4_energy_isLoaded) {
    if (jet4_energy_branch != 0) {
      jet4_energy_branch->GetEntry(index);
    } else {
      printf("branch jet4_energy_branch does not exist!\n");
      exit(1);
    }
    jet4_energy_isLoaded = true;
  }
  return jet4_energy_;
}

const float &ttHHadronic::jet5_energy() {
  if (not jet5_energy_isLoaded) {
    if (jet5_energy_branch != 0) {
      jet5_energy_branch->GetEntry(index);
    } else {
      printf("branch jet5_energy_branch does not exist!\n");
      exit(1);
    }
    jet5_energy_isLoaded = true;
  }
  return jet5_energy_;
}

const float &ttHHadronic::jet6_energy() {
  if (not jet6_energy_isLoaded) {
    if (jet6_energy_branch != 0) {
      jet6_energy_branch->GetEntry(index);
    } else {
      printf("branch jet6_energy_branch does not exist!\n");
      exit(1);
    }
    jet6_energy_isLoaded = true;
  }
  return jet6_energy_;
}

const float &ttHHadronic::jet7_energy() {
  if (not jet7_energy_isLoaded) {
    if (jet7_energy_branch != 0) {
      jet7_energy_branch->GetEntry(index);
    } else {
      printf("branch jet7_energy_branch does not exist!\n");
      exit(1);
    }
    jet7_energy_isLoaded = true;
  }
  return jet7_energy_;
}

const float &ttHHadronic::jet8_energy() {
  if (not jet8_energy_isLoaded) {
    if (jet8_energy_branch != 0) {
      jet8_energy_branch->GetEntry(index);
    } else {
      printf("branch jet8_energy_branch does not exist!\n");
      exit(1);
    }
    jet8_energy_isLoaded = true;
  }
  return jet8_energy_;
}

const float &ttHHadronic::jet9_energy() {
  if (not jet9_energy_isLoaded) {
    if (jet9_energy_branch != 0) {
      jet9_energy_branch->GetEntry(index);
    } else {
      printf("branch jet9_energy_branch does not exist!\n");
      exit(1);
    }
    jet9_energy_isLoaded = true;
  }
  return jet9_energy_;
}

const float &ttHHadronic::jet10_energy() {
  if (not jet10_energy_isLoaded) {
    if (jet10_energy_branch != 0) {
      jet10_energy_branch->GetEntry(index);
    } else {
      printf("branch jet10_energy_branch does not exist!\n");
      exit(1);
    }
    jet10_energy_isLoaded = true;
  }
  return jet10_energy_;
}

const float &ttHHadronic::jet11_energy() {
  if (not jet11_energy_isLoaded) {
    if (jet11_energy_branch != 0) {
      jet11_energy_branch->GetEntry(index);
    } else {
      printf("branch jet11_energy_branch does not exist!\n");
      exit(1);
    }
    jet11_energy_isLoaded = true;
  }
  return jet11_energy_;
}

const float &ttHHadronic::jet12_energy() {
  if (not jet12_energy_isLoaded) {
    if (jet12_energy_branch != 0) {
      jet12_energy_branch->GetEntry(index);
    } else {
      printf("branch jet12_energy_branch does not exist!\n");
      exit(1);
    }
    jet12_energy_isLoaded = true;
  }
  return jet12_energy_;
}

const float &ttHHadronic::jet13_energy() {
  if (not jet13_energy_isLoaded) {
    if (jet13_energy_branch != 0) {
      jet13_energy_branch->GetEntry(index);
    } else {
      printf("branch jet13_energy_branch does not exist!\n");
      exit(1);
    }
    jet13_energy_isLoaded = true;
  }
  return jet13_energy_;
}

const float &ttHHadronic::jet14_energy() {
  if (not jet14_energy_isLoaded) {
    if (jet14_energy_branch != 0) {
      jet14_energy_branch->GetEntry(index);
    } else {
      printf("branch jet14_energy_branch does not exist!\n");
      exit(1);
    }
    jet14_energy_isLoaded = true;
  }
  return jet14_energy_;
}

const float &ttHHadronic::jet15_energy() {
  if (not jet15_energy_isLoaded) {
    if (jet15_energy_branch != 0) {
      jet15_energy_branch->GetEntry(index);
    } else {
      printf("branch jet15_energy_branch does not exist!\n");
      exit(1);
    }
    jet15_energy_isLoaded = true;
  }
  return jet15_energy_;
}

const float &ttHHadronic::bjet1_csv() {
  if (not bjet1_csv_isLoaded) {
    if (bjet1_csv_branch != 0) {
      bjet1_csv_branch->GetEntry(index);
    } else {
      printf("branch bjet1_csv_branch does not exist!\n");
      exit(1);
    }
    bjet1_csv_isLoaded = true;
  }
  return bjet1_csv_;
}

const float &ttHHadronic::bjet2_csv() {
  if (not bjet2_csv_isLoaded) {
    if (bjet2_csv_branch != 0) {
      bjet2_csv_branch->GetEntry(index);
    } else {
      printf("branch bjet2_csv_branch does not exist!\n");
      exit(1);
    }
    bjet2_csv_isLoaded = true;
  }
  return bjet2_csv_;
}

const float &ttHHadronic::tthMVA() {
  if (not tthMVA_isLoaded) {
    if (tthMVA_branch != 0) {
      tthMVA_branch->GetEntry(index);
    } else {
      printf("branch tthMVA_branch does not exist!\n");
      exit(1);
    }
    tthMVA_isLoaded = true;
  }
  return tthMVA_;
}

const float &ttHHadronic::rho() {
  if (not rho_isLoaded) {
    if (rho_branch != 0) {
      rho_branch->GetEntry(index);
    } else {
      printf("branch rho_branch does not exist!\n");
      exit(1);
    }
    rho_isLoaded = true;
  }
  return rho_;
}

const int &ttHHadronic::nvtx() {
  if (not nvtx_isLoaded) {
    if (nvtx_branch != 0) {
      nvtx_branch->GetEntry(index);
    } else {
      printf("branch nvtx_branch does not exist!\n");
      exit(1);
    }
    nvtx_isLoaded = true;
  }
  return nvtx_;
}

const unsigned long long &ttHHadronic::event() {
  if (not event_isLoaded) {
    if (event_branch != 0) {
      event_branch->GetEntry(index);
    } else {
      printf("branch event_branch does not exist!\n");
      exit(1);
    }
    event_isLoaded = true;
  }
  return event_;
}

const unsigned int &ttHHadronic::lumi() {
  if (not lumi_isLoaded) {
    if (lumi_branch != 0) {
      lumi_branch->GetEntry(index);
    } else {
      printf("branch lumi_branch does not exist!\n");
      exit(1);
    }
    lumi_isLoaded = true;
  }
  return lumi_;
}

const int &ttHHadronic::processIndex() {
  if (not processIndex_isLoaded) {
    if (processIndex_branch != 0) {
      processIndex_branch->GetEntry(index);
    } else {
      printf("branch processIndex_branch does not exist!\n");
      exit(1);
    }
    processIndex_isLoaded = true;
  }
  return processIndex_;
}

const unsigned int &ttHHadronic::run() {
  if (not run_isLoaded) {
    if (run_branch != 0) {
      run_branch->GetEntry(index);
    } else {
      printf("branch run_branch does not exist!\n");
      exit(1);
    }
    run_isLoaded = true;
  }
  return run_;
}

const float &ttHHadronic::npu() {
  if (not npu_isLoaded) {
    if (npu_branch != 0) {
      npu_branch->GetEntry(index);
    } else {
      printf("branch npu_branch does not exist!\n");
      exit(1);
    }
    npu_isLoaded = true;
  }
  return npu_;
}

const float &ttHHadronic::puweight() {
  if (not puweight_isLoaded) {
    if (puweight_branch != 0) {
      puweight_branch->GetEntry(index);
    } else {
      printf("branch puweight_branch does not exist!\n");
      exit(1);
    }
    puweight_isLoaded = true;
  }
  return puweight_;
}


void ttHHadronic::progress( int nEventsTotal, int nEventsChain ){
  int period = 1000;
  if (nEventsTotal%1000 == 0) {
    // xterm magic from L. Vacavant and A. Cerri
    if (isatty(1)) {
      if ((nEventsChain - nEventsTotal) > period) {
        float frac = (float)nEventsTotal/(nEventsChain*0.01);
        printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
             "\033[0m\033[32m <---\033[0m\015", frac);
        fflush(stdout);
      }
      else {
        printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
               "\033[0m\033[32m <---\033[0m\015", 100.);
        cout << endl;
      }
    }
  }
}

namespace tas {

const int &candidate_id() { return cms3.candidate_id(); }
const float &weight() { return cms3.weight(); }
const float &dipho_sumpt() { return cms3.dipho_sumpt(); }
const float &dipho_cosphi() { return cms3.dipho_cosphi(); }
const float &mass() { return cms3.mass(); }
const float &leadPt() { return cms3.leadPt(); }
const float &leadEt() { return cms3.leadEt(); }
const float &leadEnergy() { return cms3.leadEnergy(); }
const float &leadEta() { return cms3.leadEta(); }
const float &leadPhi() { return cms3.leadPhi(); }
const float &lead_sieie() { return cms3.lead_sieie(); }
const float &lead_hoe() { return cms3.lead_hoe(); }
const float &lead_sigmaEoE() { return cms3.lead_sigmaEoE(); }
const float &lead_ptoM() { return cms3.lead_ptoM(); }
const float &leadR9() { return cms3.leadR9(); }
const float &leadGenMatch() { return cms3.leadGenMatch(); }
const float &leadPtGen() { return cms3.leadPtGen(); }
const float &leadGendeltaR() { return cms3.leadGendeltaR(); }
const float &subleadPt() { return cms3.subleadPt(); }
const float &subleadEt() { return cms3.subleadEt(); }
const float &subleadEnergy() { return cms3.subleadEnergy(); }
const float &subleadEta() { return cms3.subleadEta(); }
const float &subleadPhi() { return cms3.subleadPhi(); }
const float &sublead_sieie() { return cms3.sublead_sieie(); }
const float &sublead_hoe() { return cms3.sublead_hoe(); }
const float &sublead_sigmaEoE() { return cms3.sublead_sigmaEoE(); }
const float &sublead_ptoM() { return cms3.sublead_ptoM(); }
const float &subleadR9() { return cms3.subleadR9(); }
const float &subleadGenMatch() { return cms3.subleadGenMatch(); }
const float &subleadPtGen() { return cms3.subleadPtGen(); }
const float &subleadGendeltaR() { return cms3.subleadGendeltaR(); }
const float &leadIDMVA() { return cms3.leadIDMVA(); }
const float &subleadIDMVA() { return cms3.subleadIDMVA(); }
const float &dipho_rapidity() { return cms3.dipho_rapidity(); }
const float &vertex_idx() { return cms3.vertex_idx(); }
const float &nGoodEls() { return cms3.nGoodEls(); }
const float &nGoodElsFromTau() { return cms3.nGoodElsFromTau(); }
const float &nGoodMus() { return cms3.nGoodMus(); }
const float &nGoodMusFromTau() { return cms3.nGoodMusFromTau(); }
const float &nGoodTaus() { return cms3.nGoodTaus(); }
const float &diphoMVARes() { return cms3.diphoMVARes(); }
const float &leadPassEVeto() { return cms3.leadPassEVeto(); }
const float &subleadPassEVeto() { return cms3.subleadPassEVeto(); }
const float &leadPixelSeed() { return cms3.leadPixelSeed(); }
const float &subleadPixelSeed() { return cms3.subleadPixelSeed(); }
const float &nb_loose() { return cms3.nb_loose(); }
const float &nb_medium() { return cms3.nb_medium(); }
const float &nb_tight() { return cms3.nb_tight(); }
const float &rand() { return cms3.rand(); }
const float &lead_photon_type() { return cms3.lead_photon_type(); }
const float &sublead_photon_type() { return cms3.sublead_photon_type(); }
const float &lead_closest_gen_Pt() { return cms3.lead_closest_gen_Pt(); }
const float &sublead_closest_gen_Pt() { return cms3.sublead_closest_gen_Pt(); }
const float &lead_closest_gen_dR() { return cms3.lead_closest_gen_dR(); }
const float &sublead_closest_gen_dR() { return cms3.sublead_closest_gen_dR(); }
const float &lead_PhoGenPt() { return cms3.lead_PhoGenPt(); }
const float &lead_PhoGenEta() { return cms3.lead_PhoGenEta(); }
const float &lead_PhoGenPhi() { return cms3.lead_PhoGenPhi(); }
const float &lead_Prompt() { return cms3.lead_Prompt(); }
const float &lead_Mad() { return cms3.lead_Mad(); }
const float &lead_Pythia() { return cms3.lead_Pythia(); }
const float &lead_SimpleMomID() { return cms3.lead_SimpleMomID(); }
const float &lead_SimpleMomStatus() { return cms3.lead_SimpleMomStatus(); }
const float &lead_MomID() { return cms3.lead_MomID(); }
const float &lead_MomMomID() { return cms3.lead_MomMomID(); }
const float &lead_PassFrix() { return cms3.lead_PassFrix(); }
const float &lead_SmallestDr() { return cms3.lead_SmallestDr(); }
const float &sublead_PhoGenPt() { return cms3.sublead_PhoGenPt(); }
const float &sublead_PhoGenEta() { return cms3.sublead_PhoGenEta(); }
const float &sublead_PhoGenPhi() { return cms3.sublead_PhoGenPhi(); }
const float &sublead_Prompt() { return cms3.sublead_Prompt(); }
const float &sublead_Mad() { return cms3.sublead_Mad(); }
const float &sublead_Pythia() { return cms3.sublead_Pythia(); }
const float &sublead_SimpleMomID() { return cms3.sublead_SimpleMomID(); }
const float &sublead_SimpleMomStatus() { return cms3.sublead_SimpleMomStatus(); }
const float &sublead_MomID() { return cms3.sublead_MomID(); }
const float &sublead_MomMomID() { return cms3.sublead_MomMomID(); }
const float &sublead_PassFrix() { return cms3.sublead_PassFrix(); }
const float &sublead_SmallestDr() { return cms3.sublead_SmallestDr(); }
const float &n_bjets() { return cms3.n_bjets(); }
const float &n_jets() { return cms3.n_jets(); }
const float &bjet1_pt() { return cms3.bjet1_pt(); }
const float &bjet2_pt() { return cms3.bjet2_pt(); }
const float &MetPt() { return cms3.MetPt(); }
const float &MetPhi() { return cms3.MetPhi(); }
const float &jet1_pt() { return cms3.jet1_pt(); }
const float &jet2_pt() { return cms3.jet2_pt(); }
const float &jet3_pt() { return cms3.jet3_pt(); }
const float &jet4_pt() { return cms3.jet4_pt(); }
const float &jet5_pt() { return cms3.jet5_pt(); }
const float &jet6_pt() { return cms3.jet6_pt(); }
const float &jet7_pt() { return cms3.jet7_pt(); }
const float &jet8_pt() { return cms3.jet8_pt(); }
const float &jet9_pt() { return cms3.jet9_pt(); }
const float &jet10_pt() { return cms3.jet10_pt(); }
const float &jet11_pt() { return cms3.jet11_pt(); }
const float &jet12_pt() { return cms3.jet12_pt(); }
const float &jet13_pt() { return cms3.jet13_pt(); }
const float &jet14_pt() { return cms3.jet14_pt(); }
const float &jet15_pt() { return cms3.jet15_pt(); }
const float &jet1_eta() { return cms3.jet1_eta(); }
const float &jet2_eta() { return cms3.jet2_eta(); }
const float &jet3_eta() { return cms3.jet3_eta(); }
const float &jet4_eta() { return cms3.jet4_eta(); }
const float &jet5_eta() { return cms3.jet5_eta(); }
const float &jet6_eta() { return cms3.jet6_eta(); }
const float &jet7_eta() { return cms3.jet7_eta(); }
const float &jet8_eta() { return cms3.jet8_eta(); }
const float &jet9_eta() { return cms3.jet9_eta(); }
const float &jet10_eta() { return cms3.jet10_eta(); }
const float &jet11_eta() { return cms3.jet11_eta(); }
const float &jet12_eta() { return cms3.jet12_eta(); }
const float &jet13_eta() { return cms3.jet13_eta(); }
const float &jet14_eta() { return cms3.jet14_eta(); }
const float &jet15_eta() { return cms3.jet15_eta(); }
const float &jet1_phi() { return cms3.jet1_phi(); }
const float &jet2_phi() { return cms3.jet2_phi(); }
const float &jet3_phi() { return cms3.jet3_phi(); }
const float &jet4_phi() { return cms3.jet4_phi(); }
const float &jet5_phi() { return cms3.jet5_phi(); }
const float &jet6_phi() { return cms3.jet6_phi(); }
const float &jet7_phi() { return cms3.jet7_phi(); }
const float &jet8_phi() { return cms3.jet8_phi(); }
const float &jet9_phi() { return cms3.jet9_phi(); }
const float &jet10_phi() { return cms3.jet10_phi(); }
const float &jet11_phi() { return cms3.jet11_phi(); }
const float &jet12_phi() { return cms3.jet12_phi(); }
const float &jet13_phi() { return cms3.jet13_phi(); }
const float &jet14_phi() { return cms3.jet14_phi(); }
const float &jet15_phi() { return cms3.jet15_phi(); }
const float &jet1_bdiscriminant() { return cms3.jet1_bdiscriminant(); }
const float &jet2_bdiscriminant() { return cms3.jet2_bdiscriminant(); }
const float &jet3_bdiscriminant() { return cms3.jet3_bdiscriminant(); }
const float &jet4_bdiscriminant() { return cms3.jet4_bdiscriminant(); }
const float &jet5_bdiscriminant() { return cms3.jet5_bdiscriminant(); }
const float &jet6_bdiscriminant() { return cms3.jet6_bdiscriminant(); }
const float &jet7_bdiscriminant() { return cms3.jet7_bdiscriminant(); }
const float &jet8_bdiscriminant() { return cms3.jet8_bdiscriminant(); }
const float &jet9_bdiscriminant() { return cms3.jet9_bdiscriminant(); }
const float &jet10_bdiscriminant() { return cms3.jet10_bdiscriminant(); }
const float &jet11_bdiscriminant() { return cms3.jet11_bdiscriminant(); }
const float &jet12_bdiscriminant() { return cms3.jet12_bdiscriminant(); }
const float &jet13_bdiscriminant() { return cms3.jet13_bdiscriminant(); }
const float &jet14_bdiscriminant() { return cms3.jet14_bdiscriminant(); }
const float &jet15_bdiscriminant() { return cms3.jet15_bdiscriminant(); }
const float &jet1_bbdiscriminant() { return cms3.jet1_bbdiscriminant(); }
const float &jet2_bbdiscriminant() { return cms3.jet2_bbdiscriminant(); }
const float &jet3_bbdiscriminant() { return cms3.jet3_bbdiscriminant(); }
const float &jet4_bbdiscriminant() { return cms3.jet4_bbdiscriminant(); }
const float &jet5_bbdiscriminant() { return cms3.jet5_bbdiscriminant(); }
const float &jet6_bbdiscriminant() { return cms3.jet6_bbdiscriminant(); }
const float &jet7_bbdiscriminant() { return cms3.jet7_bbdiscriminant(); }
const float &jet8_bbdiscriminant() { return cms3.jet8_bbdiscriminant(); }
const float &jet9_bbdiscriminant() { return cms3.jet9_bbdiscriminant(); }
const float &jet10_bbdiscriminant() { return cms3.jet10_bbdiscriminant(); }
const float &jet11_bbdiscriminant() { return cms3.jet11_bbdiscriminant(); }
const float &jet12_bbdiscriminant() { return cms3.jet12_bbdiscriminant(); }
const float &jet13_bbdiscriminant() { return cms3.jet13_bbdiscriminant(); }
const float &jet14_bbdiscriminant() { return cms3.jet14_bbdiscriminant(); }
const float &jet15_bbdiscriminant() { return cms3.jet15_bbdiscriminant(); }
const float &jet1_cdiscriminant() { return cms3.jet1_cdiscriminant(); }
const float &jet2_cdiscriminant() { return cms3.jet2_cdiscriminant(); }
const float &jet3_cdiscriminant() { return cms3.jet3_cdiscriminant(); }
const float &jet4_cdiscriminant() { return cms3.jet4_cdiscriminant(); }
const float &jet5_cdiscriminant() { return cms3.jet5_cdiscriminant(); }
const float &jet6_cdiscriminant() { return cms3.jet6_cdiscriminant(); }
const float &jet7_cdiscriminant() { return cms3.jet7_cdiscriminant(); }
const float &jet8_cdiscriminant() { return cms3.jet8_cdiscriminant(); }
const float &jet9_cdiscriminant() { return cms3.jet9_cdiscriminant(); }
const float &jet10_cdiscriminant() { return cms3.jet10_cdiscriminant(); }
const float &jet11_cdiscriminant() { return cms3.jet11_cdiscriminant(); }
const float &jet12_cdiscriminant() { return cms3.jet12_cdiscriminant(); }
const float &jet13_cdiscriminant() { return cms3.jet13_cdiscriminant(); }
const float &jet14_cdiscriminant() { return cms3.jet14_cdiscriminant(); }
const float &jet15_cdiscriminant() { return cms3.jet15_cdiscriminant(); }
const float &jet1_udsgdiscriminant() { return cms3.jet1_udsgdiscriminant(); }
const float &jet2_udsgdiscriminant() { return cms3.jet2_udsgdiscriminant(); }
const float &jet3_udsgdiscriminant() { return cms3.jet3_udsgdiscriminant(); }
const float &jet4_udsgdiscriminant() { return cms3.jet4_udsgdiscriminant(); }
const float &jet5_udsgdiscriminant() { return cms3.jet5_udsgdiscriminant(); }
const float &jet6_udsgdiscriminant() { return cms3.jet6_udsgdiscriminant(); }
const float &jet7_udsgdiscriminant() { return cms3.jet7_udsgdiscriminant(); }
const float &jet8_udsgdiscriminant() { return cms3.jet8_udsgdiscriminant(); }
const float &jet9_udsgdiscriminant() { return cms3.jet9_udsgdiscriminant(); }
const float &jet10_udsgdiscriminant() { return cms3.jet10_udsgdiscriminant(); }
const float &jet11_udsgdiscriminant() { return cms3.jet11_udsgdiscriminant(); }
const float &jet12_udsgdiscriminant() { return cms3.jet12_udsgdiscriminant(); }
const float &jet13_udsgdiscriminant() { return cms3.jet13_udsgdiscriminant(); }
const float &jet14_udsgdiscriminant() { return cms3.jet14_udsgdiscriminant(); }
const float &jet15_udsgdiscriminant() { return cms3.jet15_udsgdiscriminant(); }
const float &jet1_energy() { return cms3.jet1_energy(); }
const float &jet2_energy() { return cms3.jet2_energy(); }
const float &jet3_energy() { return cms3.jet3_energy(); }
const float &jet4_energy() { return cms3.jet4_energy(); }
const float &jet5_energy() { return cms3.jet5_energy(); }
const float &jet6_energy() { return cms3.jet6_energy(); }
const float &jet7_energy() { return cms3.jet7_energy(); }
const float &jet8_energy() { return cms3.jet8_energy(); }
const float &jet9_energy() { return cms3.jet9_energy(); }
const float &jet10_energy() { return cms3.jet10_energy(); }
const float &jet11_energy() { return cms3.jet11_energy(); }
const float &jet12_energy() { return cms3.jet12_energy(); }
const float &jet13_energy() { return cms3.jet13_energy(); }
const float &jet14_energy() { return cms3.jet14_energy(); }
const float &jet15_energy() { return cms3.jet15_energy(); }
const float &bjet1_csv() { return cms3.bjet1_csv(); }
const float &bjet2_csv() { return cms3.bjet2_csv(); }
const float &tthMVA() { return cms3.tthMVA(); }
const float &rho() { return cms3.rho(); }
const int &nvtx() { return cms3.nvtx(); }
const unsigned long long &event() { return cms3.event(); }
const unsigned int &lumi() { return cms3.lumi(); }
const int &processIndex() { return cms3.processIndex(); }
const unsigned int &run() { return cms3.run(); }
const float &npu() { return cms3.npu(); }
const float &puweight() { return cms3.puweight(); }

}
