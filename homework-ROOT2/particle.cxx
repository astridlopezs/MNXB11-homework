#include "particle.h"

Particle::Particle() : particleType(0), energy(0.0) {
    // Default constructor: initializing member variables
}

Particle::Particle(Int_t particleType, Double_t energy)
    : particleType(particleType), energy(energy) {
    // Parameterized constructor: initializing member variables with parameters
}

Particle::~Particle() {
    // Destructor
}

Int_t Particle::getParticleType() const {
    return particleType;
}

Double_t Particle::getEnergy() const {
    return energy;
}

void Particle::setParticleType(Int_t particleType) {
    this->particleType = particleType;
}

void Particle::setEnergy(Double_t energy) {
    this->energy = energy;
}