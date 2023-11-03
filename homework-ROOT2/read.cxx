#include "AParticle.h" 
#include <TFile.h>
#include <TTree.h>
#include <TH2.h>
#include <TCanvas.h>

void read() {
    TFile *file = TFile::Open("tree_file.root");
    TTree *tree = dynamic_cast<TTree*>(file->Get("tree"));

    AParticle *particle = nullptr;
    tree->SetBranchAddress("particle", &particle);

    TH2D *hist2D = new TH2D("hist2D", "2D Histogram of px and py", 100, -1, 1, 100, -1, 1);

    for (Int_t i = 0; i < tree->GetEntries(); ++i) {
        tree->GetEntry(i);

        // Perform operations with the 'particle' data
        hist2D->Fill(particle->getPx(), particle->getPy());
    }

    // Draw the histogram (2D) with the collected data
    hist2D->Draw("COLZ");

    // Close the file
    file->Close();
}