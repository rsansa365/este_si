#ifndef SENSITIVE_DETECTOR_HH
#define SENSITIVE_DETECTOR_HH


#include "G4VSensitiveDetector.hh"


class SensitiveDetector : public G4VSensitiveDetector
{

public:

    SensitiveDetector(G4String name);

    virtual ~SensitiveDetector();


    virtual G4bool ProcessHits(
        G4Step* step,
        G4TouchableHistory* history
    );


private:

    G4int numberOfParticles;
};


#endif
