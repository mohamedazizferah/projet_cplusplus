#include "crud_groupe.hpp"
#include "note.hpp"
#include "moyFunctions.hpp"
#include "init.hpp"
#pragma once

Groupe groupeAffichage;

void tabEtud()
{
    int notes;
    float res = 0.0;
    float resfinal = 0.0;
    Matiere matvid;
    vector<GroupeModule>::iterator gmiter;
    vector<Matiere>::iterator matiter;
    vector<NOTE>::iterator notiter;
    vector<Etudiant>::iterator i;
    cout << "                                  ";
    for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
    {
        cout << " ---------------------------  ";
    }
    cout << "----------  ----------  ------------";
    cout << endl;
    cout << "                                 |";
    for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
    {
        cout << left << setw(29) << (*gmiter).NomGM << "|";
    }
    cout << "    m     |     r     |      m      |";
    cout << endl;
    cout << "                                 |";
    for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
    {
        cout << setw(27) << "-----------------------------|";
    }
    cout << "    o     |     e     |      e      |";
    cout << endl;
    cout << "                                 |";
    for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
    {
        cout << left << setw(29) << (*gmiter).CoefGM << "|";
    }
    cout << "    y     |     s     |      n      |";
    cout << endl;
    cout << "                                 |";
    for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
    {
        cout << setw(27) << "-----------------------------|";
    }
    cout << "    e     |     u     |      t      |";
    cout << endl;
    cout << "                                 |";
    for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
    {
        if ((*gmiter).ListeMat.empty())
        {
            cout << "         |         |         |";
        }
        else
        {
            for (matiter = (*gmiter).ListeMat.begin(); matiter != (*gmiter).ListeMat.end(); matiter++)
            {

                cout << setw(9) << left << (*matiter).NomMat << "|";

                notes++;
            }
            if ((*gmiter).ListeMat.size() == 2)
            {
                cout << "         |";
            }
            else if ((*gmiter).ListeMat.size() == 1)
                cout << "         |         |";
        }
    }
    cout << "    n     |     l     |      i      |";
    cout << endl;
    cout << " --------------------------------|";
    for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
    {

        cout << setw(27) << "-----------------------------|";
    }
    cout << "    n     |     t     |      o      |";
    cout << endl;

    cout << "|       Liste des etudiants      |";
    for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
    {
        if ((*gmiter).ListeMat.empty())
        {
            cout << "         |         |         |";
        }
        else
        {
            for (matiter = (*gmiter).ListeMat.begin(); matiter != (*gmiter).ListeMat.end(); matiter++)
            {
                cout << setw(9) << (*matiter).Coef << "|";
            }
            if ((*gmiter).ListeMat.size() == 2)
            {
                cout << "         |";
            }
            else if ((*gmiter).ListeMat.size() == 1)
                cout << "         |         |";
        }
    }
    cout << left << "    e     |           |      n      |";
    cout << endl;
    cout << "|--------------------------------|";
    for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
    {
        cout << setw(27) << "-----------------------------|";
    }
    cout << "----------|-----------|-------------|";
    cout << endl;
    cout << "| Num_insc |    Nom   |  Prenom  |";
    for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
    {
        if ((*gmiter).ListeMat.empty())
        {
            cout << "          |         |         |";
        }
        else
        {
            for (matiter = (*gmiter).ListeMat.begin(); matiter != (*gmiter).ListeMat.end(); matiter++)
            {
                cout << setw(9) << setprecision(2) << calcMoyMat(listDesNotes, (*matiter).IdMat, groupeAffichage.ListeEtudiants) << "|";
            }
            if ((*gmiter).ListeMat.size() == 2)
            {
                cout << "         |";
            }
            else if ((*gmiter).ListeMat.size() == 1)
                cout << "         |         |";
        }
    }
    cout << "          |           |             |";
    cout << endl;
    cout << "|--------------------------------|";
    for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
    {
        cout << setw(27) << "-----------------------------|";
    }
    cout << "----------|-----------|-------------|";
    cout << endl;
    for (i = groupeAffichage.ListeEtudiants.begin(); i != groupeAffichage.ListeEtudiants.end(); i++)
    {
        cout << "| " << left << setw(7) << (*i).NumInsc << "  |" << setw(8) << (*i).Nom << "  | " << setw(8) << (*i).Prenom << " |";

        for (gmiter = groupeAffichage.ListeModules.begin(); gmiter != groupeAffichage.ListeModules.end(); gmiter++)
        {
            if ((*gmiter).ListeMat.empty())
            {
                cout << "         |         |         |";
            }
            else
            {
                for (matiter = (*gmiter).ListeMat.begin(); matiter != (*gmiter).ListeMat.end(); matiter++)
                {
                    cout << setw(9) << setprecision(2) << CalcmoyOneMat(listDesNotes, (*matiter).IdMat, (*i).Id) << "|";

                    if (CalcmoyOneMat(listDesNotes, (*matiter).IdMat, (*i).Id) > 0)
                    {
                        res = res + CalcmoyOneMat(listDesNotes, (*matiter).IdMat, (*i).Id);
                    }
                }
                if ((*gmiter).ListeMat.size() == 2)
                {
                    cout << "         |";
                }
                else if ((*gmiter).ListeMat.size() == 1)
                    cout << "         |         |";
            }
        }
        resfinal = res / notes;
        cout << setw(10) << resfinal << "|  ";
        if (resfinal > 10)
        {
            cout << " Admis   | ";
        }
        else
        {
            cout << " Ajourne | ";
        }

        if (resfinal > 10 && resfinal <= 12)
        {
            cout << setw(10) << " Passable   | ";
        }
        else if (resfinal > 12 && resfinal <= 14)
        {
            cout << left << setw(10) << " Assez Bien |  ";
        }
        else if (resfinal > 14 && resfinal <= 16)
        {
            cout << " Bien       |  ";
        }
        else if (resfinal > 16 && resfinal <= 18)
        {
            cout << setw(10) << " Tres Bien    |  ";
        }
        else if (resfinal > 18 && resfinal <= 20)
        {
            cout << setw(10) << " Excellent    |  ";
        }
        else
        {
            cout << "              |";
        }
        cout << endl;
        cout << setw(27) << "|--------------------------------|";
        for (int a = 0; a != groupeAffichage.ListeModules.size(); a++)
        {
            cout << setw(27) << "-----------------------------|";
        }
        cout << "----------|-----------|-------------|";
        cout << endl;
        res = 0;
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
