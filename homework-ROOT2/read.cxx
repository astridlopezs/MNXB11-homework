#include "AParticle.h" 
#include <TFile.h>
#include <TTree.h>
#include <TH2.h>
#include <TCanvas.h>

void read() {
    AParticle *particle = nullptr;

    TFile *file = TFile::Open("tree_file.root");
    TTree *tree = dynamic_cast<TTree*>(file->Get("tree"));

    tree->SetBranchAddress("particle", &particle);

    TH2D *hist2D = new TH2D("hist2D", "2D Histogram of px and py", 100, -1, 1, 100, -1, 1);

    for (Int_t i = 0; i < tree->GetEntries(); i++) {
        tree->GetEntry(i);

        hist2D->Fill(particle->getPx(), particle->getPy());

        // Calculate momentum magnitude (Ensure this function is correctly computing the magnitude)
        particle->calculateMomentumMagnitude();

        // Set a condition to draw a scatter plot based on the particle's momentum magnitude
        if (particle->getPz() > 0.1) {
            TCanvas *c = new TCanvas("c", "Scatter plot");
            tree->Draw("particle->getPx() * particle->getPy():particle->getPz()", "", "COLZ");
            break; // Draw only for the first entry that satisfies the criterion
        }
    }

    hist2D->Draw("COLZ");
    delete file;
}