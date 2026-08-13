#include "G4RunManager.hh"

#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "PrimaryGenerator.hh"

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"



int main(int argc, char** argv)
{


    // Crear el gestor de simulaci  n

    G4RunManager* runManager =
        new G4RunManager();



    // ==========================
    // Geometr  a del detector
    // ==========================
    runManager->SetUserInitialization(
        new DetectorConstruction()
    );



    // ==========================
    // Procesos f  sicos
    // ==========================

    runManager->SetUserInitialization(
        new PhysicsList()
    );



    // ==========================
    // Part  cula primaria
    // ==========================

    runManager->SetUserAction(
        new PrimaryGenerator()
    );



    // Inicializar Geant4

    runManager->Initialize();



    // ==========================
    // Visualizaci  n
    // ==========================

    G4VisManager* visManager =
        new G4VisExecutive();


    visManager->Initialize();



    G4UImanager* UImanager =
        G4UImanager::GetUIpointer();


    // ==========================
    // Modo gr  fico
    // ==========================

    if(argc == 1)
    {

        G4UIExecutive* ui =
            new G4UIExecutive(
                argc,
                argv
            );


        UImanager->ApplyCommand(
            "/control/execute vis.mac"
        );
        UImanager->ApplyCommand("/control/execute vis.mac");
        ui->SessionStart();


        delete ui;

    }


    // ==========================
    // Ejecutar macro desde consola
    // ==========================

    else
    {

         G4UIExecutive* ui =
            new G4UIExecutive(
                argc,
                argv
            );
        G4String command =
            "/control/execute ";


        G4String fileName =
            argv[1];


        UImanager->ApplyCommand(
            command + fileName
        );
        ui->SessionStart();

    }



    delete visManager;
    delete runManager;


    return 0;
}
