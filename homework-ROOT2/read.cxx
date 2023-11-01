#include "particle.h" // Include your Particle class header file if it's defined in a separate file

#include <TFile.h>
#include <TTree.h>
#include <TH2.h>
#include <TCanvas.h>

void read() {
    // Initialize your object
    Particle particle; // Assuming Particle class contains px, py, pz members

    // Open your file
    TFile *file = TFile::Open("tree_file.root");

    // Get your tree
    TTree *tree = dynamic_cast<TTree*>(file->Get("tree"));

    // Remember to set the branch address
    tree->SetBranchAddress("px", &particle.px);
    tree->SetBranchAddress("py", &particle.py);
    tree->SetBranchAddress("pz", &particle.pz);

    // Some criterion on the magnitude of momentum
    double momentumMagnitudeCriterion = 0.1; // Set a threshold

    TH2D *hist2D = new TH2D("hist2D", "2D Histogram of px and py", 100, -1, 1, 100, -1, 1);

    // Loop over the whole tree
    for (Int_t i = 0; i < tree->GetEntries(); i++) {
        tree->GetEntry(i);

        // Fill a TH2 with px and py
        hist2D->Fill(particle.px, particle.py);

        // Check criterion on the magnitude of momentum
        // Assuming the Particle class has the method to calculate the magnitude
        particle.calculateMomentumMagnitude();

        if (particle.momentumMagnitude > momentumMagnitudeCriterion) {
            // Draw scatter plot of px*py vs pz
            TCanvas *c = new TCanvas("c", "Scatter plot");
            tree->Draw("px*py:pz", Form("Entry$==%d", i), "COLZ");
            break; // Draw only for the first entry that satisfies the criterion
        }
    }

    hist2D->Draw("COLZ"); // Drawing the 2D histogram
    delete file; // Close the file and free memory
}