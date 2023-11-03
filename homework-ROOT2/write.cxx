#include "AParticle.h"
#include <TFile.h>
#include <TTree.h>
#include <TRandom3.h>
#include <TBuffer.h>

ClassImp(AParticle);

void writeData() {
    TFile *file = new TFile("tree_file.root", "RECREATE");
    TTree *tree = new TTree("tree", "Tree containing Particle data");
    AParticle *particle = nullptr;

    tree->Branch("particle", &particle);

    Int_t nEvents = 100;

    for (Int_t i = 0; i < nEvents; i++) {
        particle = new AParticle();

        particle->setPx(gRandom->Gaus(0, 0.02));
        particle->setPy(gRandom->Gaus(0, 0.02));
        particle->setPz(gRandom->Gaus(0, 0.02));

        particle->calculateMomentumMagnitude();

        tree->Fill();
        delete particle;
        particle = nullptr;
    }

    tree->Write();
    file->Close();
}