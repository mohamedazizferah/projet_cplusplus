#include "crud_groupe.hpp"
#include "note.hpp"
#pragma once

Groupe groupeAffichage;

void tabEtud()
{
    vector<Etudiant>::iterator i;
    cout << " --------------------------------|" << endl;
    cout << "|       Liste des etudiants      |" << endl;
    cout << "|--------------------------------|" << endl;
    cout << "| Num_insc |    Nom   |  Prenom  |" << endl;
    cout << "|--------------------------------|" << endl;
    for (i = groupeAffichage.ListeEtudiants.begin(); i != groupeAffichage.ListeEtudiants.end(); i++)
    {
        cout << "| " << setw(7) << (*i).NumInsc << "  | " << setw(7) << (*i).Nom << "  | " << setw(8) << (*i).Prenom << " |" << endl;
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
