#include "DetectorConstruction.hh"
#include "SensitiveDetector.hh"

#include "G4NistManager.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4SDManager.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"

DetectorConstruction::DetectorConstruction()
{
}

DetectorConstruction::~DetectorConstruction()
{
}

G4VPhysicalVolume* DetectorConstruction::Construct()
{
    G4NistManager* nist = G4NistManager::Instance();

    //=========================
   // Materiales
    //=========================

    G4Material* air = nist->FindOrBuildMaterial("G4_AIR");
    G4Material* silicon = nist->FindOrBuildMaterial("G4_Si");

    //=========================
    // Mundo
    //=========================

    G4Box* solidWorld =
        new G4Box("World", 50*m, 50*m, 60*m);

    G4LogicalVolume* logicWorld =
        new G4LogicalVolume(
            solidWorld,
            air,
            "World");

    G4VPhysicalVolume* physWorld =
        new G4PVPlacement(
            0,
            G4ThreeVector(),
          logicWorld,
            "World",
            0,
            false,
            0,
            true);
   //=========================
    // Atm  sfera superior
    //=========================

    G4Box* solidLayer1 =
        new G4Box("Layer1",40*m,40*m,10*m);

    G4LogicalVolume* logicLayer1 =
        new G4LogicalVolume(
            solidLayer1,
            air,
            "Layer1");

    new G4PVPlacement(
        0,
        G4ThreeVector(0,0,30*m),
        logicLayer1,
        "Layer1",
        logicWorld,
        false,
        0,
        true);
   //=========================
    // Atm  sfera media
    //=========================

    G4Box* solidLayer2 =
        new G4Box("Layer2",40*m,40*m,10*m);

    G4LogicalVolume* logicLayer2 =
        new G4LogicalVolume(
            solidLayer2,
            air,
            "Layer2");

    new G4PVPlacement(
        0,
        G4ThreeVector(0,0,10*m),
        logicLayer2,
        "Layer2",
        logicWorld,
        false,
        0,
        true);
   //=========================
    // Atm  sfera inferior
    //=========================

    G4Box* solidLayer3 =
        new G4Box("Layer3",40*m,40*m,10*m);

    G4LogicalVolume* logicLayer3 =
        new G4LogicalVolume(
            solidLayer3,
            air,
            "Layer3");

    new G4PVPlacement(
        0,
        G4ThreeVector(0,0,-10*m),
        logicLayer3,
        "Layer3",
        logicWorld,
        false,
        0,
        true);
  //=========================
    // Detector
    //=========================

    G4Box* solidDetector =
        new G4Box("Detector",5*m,5*m,0.5*m);

    logicDetector =
        new G4LogicalVolume(
            solidDetector,
            silicon,
            "Detector");

    new G4PVPlacement(
        0,
        G4ThreeVector(0,0,-30*m),
        logicDetector,
        "Detector",
        logicWorld,
        false,
        0,
        true);
  // Colores
    //=========================

     G4VisAttributes* worldVis =
        new G4VisAttributes(G4Colour(1.0,1.0,1.0));
    worldVis->SetVisibility(false);
    logicWorld->SetVisAttributes(worldVis);

    G4VisAttributes* layer1Vis =
        new G4VisAttributes(G4Colour(0.0,0.0,1.0));
    layer1Vis->SetForceSolid(true);
    logicLayer1->SetVisAttributes(layer1Vis);

    G4VisAttributes* layer2Vis =
        new G4VisAttributes(G4Colour(0.0,1.0,0.0));
    layer2Vis->SetForceSolid(true);
    logicLayer2->SetVisAttributes(layer2Vis);
    G4VisAttributes* layer3Vis =
        new G4VisAttributes(G4Colour(1.0,1.0,0.0));
    layer3Vis->SetForceSolid(true);
    logicLayer3->SetVisAttributes(layer3Vis);

    G4VisAttributes* detectorVis =
        new G4VisAttributes(G4Colour(1.0,0.0,0.0));
    detectorVis->SetForceSolid(true);
    logicDetector->SetVisAttributes(detectorVis);

    return physWorld;
}

void DetectorConstruction::ConstructSDandField()
{
    SensitiveDetector* sensDet =
        new SensitiveDetector("SensitiveDetector");

    G4SDManager::GetSDMpointer()->AddNewDetector(sensDet);

    logicDetector->SetSensitiveDetector(sensDet);
}
