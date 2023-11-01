#include "particle.h"
#include <TFile.h>
#include <TTree.h>
#include <TRandom3.h>

void write(){
// Initialize your object e.g. as a pointer
Particle *particle = new Particle();
// Create your root file here
TFile *file = new TFile("tree_file.root", "RECREATE");  // Creating a ROOT file
// Create your TTree here
TTree *tree = new TTree("tree", "Tree containing Particle data");
// And the associated branches underneath
Double_t px, py, pz, momentumMagnitude;
// for example a branch with your personal object type
tree->Branch("px", &px, "px/D");
tree->Branch("py", &py, "py/D");
tree->Branch("pz", &pz, "pz/D");
tree->Branch("momentumMagnitude", &momentumMagnitude, "momentumMagnitude/D");

// Now we create our loop for filling the tree with some random data
// For loop here
Int_t nEvents = 100;  // define how many events you want
for (Int_t i{0}; i<nEvents; i++){ 
// Initialize your new object below
particle->px = gRandom->Gaus(0, 0.02);
particle->py = gRandom->Gaus(0, 0.02);
particle->pz = gRandom->Gaus(0, 0.02);
 // Calculate the momentum magnitude
        momentumMagnitude = sqrt(particle->px * particle->px + particle->py * particle->py + particle->pz * particle->pz);
// Now fill tree
tree->Fill();
// Remember to delete it again otherise you will have memory leak!
}
delete particle;

// save the tree/file
tree->Write();
file->Close();
}