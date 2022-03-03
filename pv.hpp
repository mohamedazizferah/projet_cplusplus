#include "crud_groupe.hpp"
#include "note.hpp"
#include "moyFunctions.hpp"
#include "init.hpp"
#pragma once

Groupe groupeAffichage;

void tabEtud()
{
    int notes;
    float res = 0;
    float resfinal = 0;
    vector<GroupeModule>::iterator gmiter;
    vector<Matiere>::iterator matiter;
    vector<NOTE>::iterator notiter;
    vector<Etudiant>::iterator i;
    cout << "                                  ";
    for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
    {
        cout << " ---------------------------  ";
    }
    cout << " --------------  ----------  ------------";
    cout << endl;
    cout << "                                 |";
    for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
    {
        cout << setw(15) << (*gmiter).NomGM << setw(15) << "|";
    }
    cout << "    m          |     r     |      m      |";
    cout << endl;
    cout << "                                 |";
    for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
    {
        cout << setw(27) << "-----------------------------|";
    }
    cout << "    o          |     e     |      e      |";
    cout << endl;
    cout << "                                 |";
    for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
    {
        cout << setw(15) << (*gmiter).CoefGM << setw(15) << "|";
    }
    cout << "    y          |     s     |      n      |";
    cout << endl;
    cout << "                                 |";
    for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
    {
        cout << setw(27) << "-----------------------------|";
    }
    cout << "    e          |     u     |      t      |";
    cout << endl;
    cout << "                                 |";
    for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
    {
        for (matiter = (*gmiter).ListeMat.begin(); matiter != (*gmiter).ListeMat.end(); matiter++)
        {
            cout << setw(9) << left << (*matiter).NomMat << "|";
        }
    }
    cout << "    n          |     l     |      i      |";
    cout << endl;
    cout << " --------------------------------|";
    for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
    {
        cout << setw(27) << "-----------------------------|";
    }
    cout << "    n          |     t     |      o      |";
    cout << endl;

    cout << "|       Liste des etudiants      |    ";
    for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
    {
        for (matiter = (*gmiter).ListeMat.begin(); matiter != (*gmiter).ListeMat.end(); matiter++)
        {
            cout << setw(5) << (*matiter).Coef << setw(5) << "|";
        }
    }
    cout << left << "e          |           |      n      |";
    cout << endl;
    cout << "|--------------------------------|";
    for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
    {
        cout << setw(27) << "-----------------------------|";
    }
    cout << "---------------|-----------|-------------|";
    cout << endl;
    cout << "| Num_insc |    Nom   |  Prenom  |    ";
    for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
    {
        for (matiter = (*gmiter).ListeMat.begin(); matiter != (*gmiter).ListeMat.end(); matiter++)
        {
            cout << setw(5) << calcMoyMat(listDesNotes, (*matiter).IdMat, groupeAffichage.ListeEtudiants) << setw(5) << "|";
        }
    }
    cout << "           |           |             |";
    cout << endl;
    cout << "|--------------------------------|";
    for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
    {
        cout << setw(27) << "-----------------------------|";
    }
    cout << "---------------|-----------|-------------|";
    cout << endl;
    for (i = groupeAffichage.ListeEtudiants.begin(); i != groupeAffichage.ListeEtudiants.end(); i++)
    {
        cout << "| " << setw(7) << (*i).NumInsc << "  | " << setw(7) << (*i).Nom << "  | " << setw(8) << (*i).Prenom << " |    ";

        for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
        {
            for (matiter = (*gmiter).ListeMat.begin(); matiter != (*gmiter).ListeMat.end(); matiter++)
            {
                cout << setw(5) << CalcmoyOneMat(listDesNotes, (*matiter).IdMat, (*i).Id) << setw(5) << "|";
                notes++;
                if (CalcmoyOneMat(listDesNotes, (*matiter).IdMat, (*i).Id) > 0)
                {
                    res = res + CalcmoyOneMat(listDesNotes, (*matiter).IdMat, (*i).Id);
                }
            }
        }
        resfinal = res / notes;
        cout << setw(9) << resfinal << "  |  ";
        if (resfinal > 10)
        {
            cout << " Admis |  ";
        }
        else
        {
            cout << " Ajourne |  ";
        }

        if (resfinal > 10 && resfinal <= 12)
        {
            cout << setw(10) << " Passable |  ";
        }
        else if (resfinal > 12 && resfinal <= 14)
        {
            cout << setw(10) << " Assez Bien |  ";
        }
        else if (resfinal > 14 && resfinal <= 16)
        {
            cout << " Bien |  ";
        }
        else if (resfinal > 16 && resfinal <= 18)
        {
            cout << setw(10) << " Tres Bien |  ";
        }
        else if (resfinal > 18 && resfinal <= 20)
        {
            cout << setw(10) << " Excellent |  ";
        }
        else
        {
            cout << "           |";
        }
        cout << endl;
        cout << setw(27) << "|--------------------------------|";
        for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
        {
            cout << setw(27) << "-----------------------------|";
        }
        cout << "---------------|-----------|-------------|";
        cout << endl;
    }
}

void choixGRP(vector<Groupe> GRPTAB)
{
    vector<Groupe>::iterator i;
    groupeAffichage.AddIdGRP();
    if (GFound(GRPTAB, groupeAffichage.IdGRP) == 1)
    {
        for (i = GRPTAB.begin(); i != GRPTAB.end(); i++)
        {
            if ((*i).IdGRP == groupeAffichage.IdGRP)
            {
                groupeAffichage = (*i);
            }
        }
        tabEtud();
    }
    else
    {
        cout << "Groupe not found";
    }
}
