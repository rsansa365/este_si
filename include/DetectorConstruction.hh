#ifndef DETECTOR_CONSTRUCTION_HH
#define DETECTOR_CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4LogicalVolume.hh"


class DetectorConstruction : public G4VUserDetectorConstruction
{

public:

    DetectorConstruction();
    virtual ~DetectorConstruction();


    virtual G4VPhysicalVolume* Construct();


private:

    G4LogicalVolume* logicDetector;


    virtual void ConstructSDandField();
};


#endif
