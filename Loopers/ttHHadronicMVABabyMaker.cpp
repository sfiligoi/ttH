#include "MakeMVABabies_ttHHadronic.C"

int main(int argc, char* argv[]) {
  TString tag = argc <= 1 ? "ttHHadronicLoose" : argv[1];
  cout << "Running ttH Hadronic MVA babymaker for tag: " << tag << endl;

  TString year = argc <= 2 ? "2016" : argv[2];
  cout << "Running for year: " << year << endl;

  TChain *ch = new TChain("tthHadronicTagDumper/trees/tth_13TeV_all");
  add_samples(ch, year);


  BabyMaker *looper = new BabyMaker();
  looper->ScanChain(ch, tag);
  return 0; 
}
