#include "AParticle.h"
#include <cmath> 

AParticle::AParticle() : particleType(0), energy(0.0), px(0.0), py(0.0), pz(0.0), momentumMagnitude(0.0) {
    // Default constructor: initializing member variables
}

AParticle::AParticle(Int_t particleType, Double_t energy, Double_t px, Double_t py, Double_t pz)
    : particleType(particleType), energy(energy), px(px), py(py), pz(pz), momentumMagnitude(0.0) {
    // Parameterized constructor: initializing member variables with parameters
}

AParticle::~AParticle() {
    // Destructor
}

// Getters for particle properties
Int_t AParticle::getParticleType() const {
    return particleType;
}

Double_t AParticle::getEnergy() const {
    return energy;
}

Double_t AParticle::getPx() const {
    return px;
}

Double_t AParticle::getPy() const {
    return py;
}

Double_t AParticle::getPz() const {
    return pz;
}

void AParticle::setParticleType(Int_t particleType) {
    this->particleType = particleType;
}

void AParticle::setEnergy(Double_t energy) {
    this->energy = energy;
}

void AParticle::setPx(Double_t px) {
    this->px = px;
}

void AParticle::setPy(Double_t py) {
    this->py = py;
}

void AParticle::setPz(Double_t pz) {
    this->pz = pz;
}

Double_t AParticle::calculateMomentumMagnitude() {
    momentumMagnitude = sqrt(px * px + py * py + pz * pz);
    return momentumMagnitude;
}