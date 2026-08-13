#include "PrimaryGenerator.hh"

#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"



PrimaryGenerator::PrimaryGenerator()
{

    fParticleGun =
        new G4ParticleGun(1);



    // Tabla de part  culas de Geant4

    G4ParticleTable* particleTable =
        G4ParticleTable::GetParticleTable();



    // Part  cula primaria: prot  n c  smico
 G4ParticleDefinition* particle =
        particleTable->FindParticle("proton");



    fParticleGun->SetParticleDefinition(
        particle
    );



    // Energ  a inicial

    fParticleGun->SetParticleEnergy(
        100*GeV
    );
  // Posici  n inicial:
    // arriba de la atm  sfera

    fParticleGun->SetParticlePosition(
        G4ThreeVector(
            0,
            0,
            35*m
        )
    );
    // Direcci  n hacia el detector

    fParticleGun->SetParticleMomentumDirection(
        G4ThreeVector(
            0,
            0,
            -1
        )
    );

}



PrimaryGenerator::~PrimaryGenerator()
{

    delete fParticleGun;

}
void PrimaryGenerator::GeneratePrimaries(
    G4Event* anEvent
)
{

    fParticleGun
        ->GeneratePrimaryVertex(
            anEvent
        );

}
