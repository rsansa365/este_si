#include "PhysicsList.hh"

#include "G4EmStandardPhysics.hh"
#include "G4DecayPhysics.hh"
#include "G4HadronPhysicsFTFP_BERT.hh"


PhysicsList::PhysicsList()
{

    // Procesos electromagn  ticos
    RegisterPhysics(
        new G4EmStandardPhysics()
    );


    // Decaimiento de part  culas inestables
    RegisterPhysics(
        new G4DecayPhysics()
    );


    // Interacciones hadr  nicas
    RegisterPhysics(
        new G4HadronPhysicsFTFP_BERT()
    );
}


PhysicsList::~PhysicsList()
{

}
