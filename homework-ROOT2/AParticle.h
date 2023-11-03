#ifndef APARTICLE_H__
#define APARTICLE_H__

#include <TObject.h>

class AParticle : public TObject {
public:
    AParticle();  // default constructor
    AParticle(Int_t particleType, Double_t energy, Double_t px, Double_t py, Double_t pz);  // parameterized constructor
    virtual ~AParticle();  // destructor

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
    Double_t calculateMomentumMagnitude();

private:
    Int_t particleType;
    Double_t energy;
    Double_t px; 
    Double_t py;
    Double_t pz;  // Member variables for momentum components
    Double_t momentumMagnitude;  // Member variable for magnitude

    ClassDef(AParticle, 1); 
};

#endif // APARTICLE_H__