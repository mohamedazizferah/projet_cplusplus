#include "init.hpp"
#pragma once

void menu()
{
    int menuSwitch;
    int studentSwitch;
    int teacherSwitch;
    int matiereSwitch;
    int noteSwitch;
    int moduleSwitch;
    int groupeSwitch;
    int afficherSwitch;

    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    cout << "xxxxxxxxxxxxxxx   Bienvenue   xxxxxxxxxxxxxxx" << endl;
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;

MenuPrincipale:
    cout << endl;
    cout << "x Veuiller Choisir Une Option:              x" << endl;
    cout << "x  1- Gestion des Etudiants                 x" << endl;
    cout << "x  2- Gestion des Enseignants               x" << endl;
    cout << "x  3- Gestion des Matieres                  x" << endl;
    cout << "x  4- Gestion des Notes                     x" << endl;
    cout << "x  5- Gestion des Modules                   x" << endl;
    cout << "x  6- Gestion des Groupes                   x" << endl;
    cout << "x  7- Affichage                             x" << endl;
    cout << "x >> Tapez votre Choix:                     x";
    do
    {
        cin >> menuSwitch;
        cin.ignore();
    } while (menuSwitch < 0 || menuSwitch > 7);
    switch (menuSwitch)
    {
    case 0:
        exit(0);
        break;
    case 1:
        goto MenuGestionDesEtudiants;
        break;
    case 2:
        goto MenuGestionDesEnseignants;
        break;
    case 3:
        goto MenuGestionDesMatieres;
        break;
    case 4:
        goto MenuGestionDesNotes;
        break;
    case 5:
        goto MenuGestionDesModules;
        break;
    case 6:
        goto MenuGestionDesGroupes;
        break;
    case 7:
        goto Affichage;
        break;
    }

    goto MenuPrincipale;

MenuGestionDesEtudiants:
    cout << endl;
    cout << "x Menu Gestion des Etudiants                x" << endl;
    cout << "x  1- Ajouter un nouveau Etudiant           x" << endl;
    cout << "x  2- Modifier un Etudiant                  x" << endl;
    cout << "x  3- Supprimer un Etudiant                 x" << endl;
    cout << "x  4- Afficher tous les etudiants           x" << endl;
    cout << "x  5- Retour Menu Principal                 x" << endl;
    cout << "x >> Tapez votre Choix:                     x";
    do
    {
        cin >> studentSwitch;
        cin.ignore();
    } while (studentSwitch < 0 || studentSwitch > 5);
    switch (studentSwitch)
    {
    case 0:
        exit(0);
        break;
    case 1:
        ajoutEtudiant(listeDesEtudiants);
        break;
    case 2:
        modifierEtudiant(listeDesEtudiants);
        break;
    case 3:
        supprimerEtudiant(listeDesEtudiants);
        break;
    case 4:
        printAllStudents(listeDesEtudiants);
        break;
    case 5:
        goto MenuPrincipale;
        break;
    }

    goto MenuGestionDesEtudiants;

MenuGestionDesEnseignants:
    cout << endl;
    cout << "x Menu Gestion des Enseignants              x" << endl;
    cout << "x  1- Ajouter un nouveau Enseignant         x" << endl;
    cout << "x  2- Modifier un Enseignant                x" << endl;
    cout << "x  3- Supprimer un Enseignant               x" << endl;
    cout << "x  4- Afficher tous les Enseignants         x" << endl;
    cout << "x  5- Retour Menu Principal                 x" << endl;
    cout << "x >> Tapez votre Choix:                     x";
    do
    {
        cin >> teacherSwitch;
        cin.ignore();
    } while (teacherSwitch < 0 || teacherSwitch > 5);
    switch (teacherSwitch)
    {
    case 0:
        exit(0);
        break;
    case 1:
        ajoutEnseignant(listeDesEnseignant);
        break;
    case 2:
        modifierEnseignant(listeDesEnseignant);
        break;
    case 3:
        supprimerEnseignant(listeDesEnseignant);
        break;
    case 4:
        printAllTeachers(listeDesEnseignant);
        break;
    case 5:
        goto MenuPrincipale;
        break;
    }

    goto MenuGestionDesEnseignants;

MenuGestionDesMatieres:
    cout << endl;
    cout << "x Menu Gestion des Matieres                 x" << endl;
    cout << "x  1- Ajouter une nouvelle matiere          x" << endl;
    cout << "x  2- Modifier une matiere                  x" << endl;
    cout << "x  3- Supprimer ue matiere                  x" << endl;
    cout << "x  4- Afficher tous les matieres            x" << endl;
    cout << "x  5- Retour Menu Principal                 x" << endl;
    cout << "x >> Tapez votre Choix:                     x";
    do
    {
        cin >> matiereSwitch;
        cin.ignore();
    } while (matiereSwitch < 0 || matiereSwitch > 5);
    switch (matiereSwitch)
    {
    case 0:
        exit(0);
        break;
    case 1:
        ajouterMat(listDesMatiere, listeDesEnseignant);
        break;
    case 2:
        modifierMatiere(listDesMatiere, listeDesEnseignant);
        break;
    case 3:
        supprimerMatiere(listDesMatiere);
        break;
    case 4:
        printMatiere(listDesMatiere);
        break;
    case 5:
        goto MenuPrincipale;
        break;
    }

    goto MenuGestionDesMatieres;

MenuGestionDesNotes:
    cout << endl;
    cout << "x Gestion de Notes                          x" << endl;
    cout << "x  1- Ajout d'une nouvelle note             x" << endl;
    cout << "x  2- Modifier une note                     x" << endl;
    cout << "x  3- Suppression d'une note                x" << endl;
    cout << "x  4- Afficher tous les Notes               x" << endl;
    cout << "x  5- Retour Menu Principal                 x" << endl;
    cout << "x >> Tapez votre Choix:                     x";
    do
    {
        cin >> noteSwitch;
        cin.ignore();
    } while (noteSwitch < 0 || noteSwitch > 5);
    switch (noteSwitch)
    {
    case 0:
        exit(0);
        break;
    case 1:
        ajouterNote(listDesNotes, listeDesEtudiants, listDesMatiere);
        break;
    case 2:
        modifierNote(listDesNotes, listeDesEtudiants, listDesMatiere);
        break;
    case 3:
        supprimerNote(listDesNotes);
        break;
    case 4:
        printNote(listDesNotes);
        break;
    case 5:
        goto MenuPrincipale;
        break;
    }

    goto MenuGestionDesNotes;

MenuGestionDesModules:
    cout << endl;
    cout << "x Gestion de Modules                        x" << endl;
    cout << "x  1- Ajout d'un  nouveau Module            x" << endl;
    cout << "x  2- Modifier un  Module                   x" << endl;
    cout << "x  3- Suppression d'un Module               x" << endl;
    cout << "x  4- ajouter un matiere a un module        x" << endl;
    cout << "x  5- Supprimer un matiere d'un module      x" << endl;
    cout << "x  6- Afficher tous les Modules             x" << endl;
    cout << "x  7- Retour Menu Principal                 x" << endl;
    cout << "x >> Tapez votre Choix:                     x";
    do
    {
        cin >> moduleSwitch;
        cin.ignore();
    } while (moduleSwitch < 0 || moduleSwitch > 7);
    switch (moduleSwitch)
    {
    case 0:
        exit(0);
        break;
    case 1:
        ajouterGM(listDesModules, listDesMatiere);
        break;
    case 2:
        modifierGM(listDesModules, listDesMatiere);
        break;
    case 3:
        supprimerGM(listDesModules);
        break;
    case 4:
        AddMatInGM(listDesModules, listDesMatiere);
        break;
    case 5:
        DeleteMatFromGM(listDesModules);
        break;
    case 6:
        printGM(listDesModules);
        break;
    case 7:
        goto MenuPrincipale;
        break;
    }

    goto MenuGestionDesNotes;

MenuGestionDesGroupes:
    cout << endl;
    cout << "x Gestion des Groupes                       x" << endl;
    cout << "x  1- Ajout d'un  nouveau Groupe            x" << endl;
    cout << "x  2- Modifier un  Groupe                   x" << endl;
    cout << "x  3- Suppression d'un Groupe               x" << endl;
    cout << "x  4- ajouter un etudiant a un groupe       x" << endl;
    cout << "x  5- Supprimer un etudiant d'un groupe     x" << endl;
    cout << "x  6- ajouter un module a un groupe         x" << endl;
    cout << "x  7- Supprimer un module d'un groupe       x" << endl;
    cout << "x  8- Afficher tous les groupes             x" << endl;
    cout << "x  9- Retour Menu Principal                 x" << endl;
    cout << "x >> Tapez votre Choix:                     x";
    do
    {
        cin >> groupeSwitch;
        cin.ignore();
    } while (groupeSwitch < 0 || groupeSwitch > 9);
    switch (groupeSwitch)
    {
    case 0:
        exit(0);
        break;
    case 1:
        ajouterGRP(listGRP, listDesModules, listeDesEtudiants);
        break;
    case 2:
        modifierGRP(listGRP, listDesModules, listeDesEtudiants);
        break;
    case 3:
        supprimerGRP(listGRP);
        break;
    case 4:
        AddEtudInGRP(listGRP, listeDesEtudiants);
        break;
    case 5:
        DeleteEtudFromGRP(listGRP);
        break;
    case 6:
        AddGMInGRP(listGRP, listDesModules);
        break;
    case 7:
        DeleteGMFromGRP(listGRP);
        break;
    case 8:
        printGRP(listGRP);
        break;
    case 9:
        goto MenuPrincipale;
    }

    goto MenuGestionDesGroupes;

Affichage:
    cout << endl;
    cout << "x Affichage                                 x" << endl;
    cout << "x  1- Afficher les note d'un etudiant       x" << endl;
    cout << "x  2- Afficher les matiere d'un Module      x" << endl;
    cout << "x  3- Afficher les etudiants d'un groupe    x" << endl;
    cout << "x  4- Afficher les modules d'un groupe      x" << endl;
    cout << "x  5- Afficher PV                           x" << endl;
    cout << "x  6- Retour Menu Principal                 x" << endl;
    cout << "x >> Tapez votre Choix:                     x";
    do
    {
        cin >> afficherSwitch;
        cin.ignore();
    } while (afficherSwitch < 0 || afficherSwitch > 6);
    switch (afficherSwitch)
    {
    case 0:
        exit(0);
        break;
    case 1:
        StudentNotes(listDesNotes, listeDesEtudiants);
        break;
    case 2:
        MatiereDunModule(listDesModules);
        break;
    case 3:
        EtudDunGroupe(listGRP);
        break;
    case 4:
        GmDunGRP(listGRP);
        break;
    case 5:
        cout << "pv";
        break;
    case 6:
        goto MenuPrincipale;
    }
    goto Affichage;
}