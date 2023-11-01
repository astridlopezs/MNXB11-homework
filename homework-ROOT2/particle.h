#ifndef __PARTICLE_H__
#define __PARTICLE_H__

#include <TObject.h>

class Particle : public TObject {
public:
    Particle();  // default constructor
    Particle(Int_t particleType, Double_t energy);  // parameterized constructor
    virtual ~Particle();  // destructor

    // Getters and setters (methods to access and modify private members)
    Int_t getParticleType() const;
    Double_t getEnergy() const;
    void setParticleType(Int_t particleType);
    void setEnergy(Double_t energy);

private:
    Int_t particleType;
    Double_t energy;

    ClassDef(Particle, 1); 
};

#endif // __PARTICLE_H__