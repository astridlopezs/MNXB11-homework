#ifndef PARTICLE_H__
#define PARTICLE_H__

#include <TObject.h>

class Particle : public TObject {
public:
    Particle();  // default constructor
    Particle(Int_t particleType, Double_t energy, Double_t px, Double_t py, Double_t pz);  // parameterized constructor
    virtual ~Particle();  // destructor

    // Getters and setters for particle properties
    Int_t getParticleType() const;
    Double_t getEnergy() const;
    Double_t getPx() const;
    Double_t getPy() const;
    Double_t getPz() const;
    void setParticleType(Int_t particleType);
    void setEnergy(Double_t energy);
    void setPx(Double_t px);
    void setPy(Double_t py);
    void setPz(Double_t pz);

private:
    Int_t particleType;
    Double_t energy;
    Double_t px, py, pz;  // New member variables for momentum components

    ClassDef(Particle, 1); 
};

#endif // PARTICLE_H__