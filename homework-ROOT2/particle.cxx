#include "particle.h"

Particle::Particle() : particleType(0), energy(0.0), px(0.0), py(0.0), pz(0.0) {
    // Default constructor: initializing member variables
}

Particle::Particle(Int_t particleType, Double_t energy, Double_t px, Double_t py, Double_t pz)
    : particleType(particleType), energy(energy), px(px), py(py), pz(pz) {
    // Parameterized constructor: initializing member variables with parameters
}

Particle::~Particle() {
    // Destructor
}

// Getters for particle properties
Int_t Particle::getParticleType() const {
    return particleType;
}

Double_t Particle::getEnergy() const {
    return energy;
}

Double_t Particle::getPx() const {
    return px;
}

Double_t Particle::getPy() const {
    return py;
}

Double_t Particle::getPz() const {
    return pz;
}

// Setters for particle properties
void Particle::setParticleType(Int_t particleType) {
    this->particleType = particleType;
}

void Particle::setEnergy(Double_t energy) {
    this->energy = energy;
}

void Particle::setPx(Double_t px) {
    this->px = px;
}

void Particle::setPy(Double_t py) {
    this->py = py;
}

void Particle::setPz(Double_t pz) {
    this->pz = pz;
}