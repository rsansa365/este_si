#include "SensitiveDetector.hh"

#include "G4Step.hh"
#include "G4Track.hh"
#include "G4SystemOfUnits.hh"
#include "G4ios.hh"

SensitiveDetector::SensitiveDetector(G4String name)
: G4VSensitiveDetector(name)
{
}

SensitiveDetector::~SensitiveDetector()
{
}

G4bool SensitiveDetector::ProcessHits(G4Step* aStep,
                                     G4TouchableHistory*)
{
    static G4int contador = 0;

    contador++;

    G4Track* track = aStep->GetTrack();

    G4String particleName =
      track->GetDefinition()->GetParticleName();

    G4double particleEnergy =
        track->GetKineticEnergy();

    G4double edep =
        aStep->GetTotalEnergyDeposit();

    // Imprimir solo cada 100 part  culas
    if(contador % 100 == 0)
    {
        G4cout << G4endl;
        G4cout << "============================" << G4endl;
        G4cout << "Particula detectada N  : "
               << contador << G4endl;

        G4cout << "Tipo: "
               << particleName << G4endl;

        G4cout << "Energia de la particula: "
               << particleEnergy/MeV
               << " MeV" << G4endl;
        G4cout << "Energia depositada: "
               << edep/MeV
               << " MeV" << G4endl;

        G4cout << "============================"
               << G4endl;
    }

    return true;
}
