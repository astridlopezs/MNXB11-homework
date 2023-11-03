#include "AParticle.h" 
#include <TFile.h>
#include <TTree.h>
#include <TH2.h>
#include <TCanvas.h>

void read() {
    AParticle particle;

    TFile *file = TFile::Open("tree_file.root");

    TTree *tree = dynamic_cast<TTree*>(file->Get("tree"));

    tree->SetBranchAddress("particle", &particle);

    double momentumMagnitudeCriterion = 0.1; // Set a threshold

    TH2D *hist2D = new TH2D("hist2D", "2D Histogram of px and py", 100, -1, 1, 100, -1, 1);

    for (Int_t i = 0; i < tree->GetEntries(); i++) {
        tree->GetEntry(i);

        hist2D->Fill(particle.getPx(), particle.getPy());

        particle.calculateMomentumMagnitude();

        if (particle.calculateMomentumMagnitude() > momentumMagnitudeCriterion) {
            TCanvas *c = new TCanvas("c", "Scatter plot");
            tree->Draw("particle.px*particle.py:particle.pz", Form("Entry$==%d", i), "COLZ");
            break; // Draw only for the first entry that satisfies the criterion
        }
    }

    hist2D->Draw("COLZ");
    delete file;
}