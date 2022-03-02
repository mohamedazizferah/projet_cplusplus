#include "matiere.hpp"
#include "crud_enseignant.hpp"
#pragma once

Matiere mat;
vector<Matiere> MatTab;

void remplirMatiere(vector<Matiere> &MatTab, vector<Enseignant> enss)
{
    string id;
    string nom;
    float coef;
    Enseignant ens;
    Matiere newMatiere(id, nom, coef, ens);
    unsigned int size = MatTab.size();
    ifstream fin("Matiere.txt");
    vector<Enseignant>::iterator i;
    if (fin.is_open())
    {
        while (fin >> id >> nom >> coef >> ens.Id)
        {
            newMatiere.SetIdMat(id);
            newMatiere.SetNomMat(nom);
            newMatiere.SetCoef(coef);
            newMatiere.Ens.setId(ens.Id);
            for (i = enss.begin(); i < enss.end(); i++)
            {
                if ((*i).Id == newMatiere.Ens.Id)
                {
                    newMatiere.SetEns(*i);
                }
            }
            MatTab.push_back(newMatiere);
        }
    }
}

int MatiereFound(vector<Matiere> &matTab, string id)
{
    vector<Matiere>::iterator i;
    for (i = matTab.begin(); i < matTab.end(); i++)
    {
        if ((*i).IdMat == id)
        {
            return 1;
        }
    }
    return -1;
}

void enregistrerMatiere()
{
    fstream fout("Matiere.txt", ios::app);

    fout << mat.IdMat << " "
         << mat.NomMat << " "
         << mat.Coef << " "
         << mat.Ens.Id << endl;
}

void modifierMat(vector<Matiere> Mat)
{
    ofstream file;
    file.open("Matiere.txt");
    vector<Matiere>::iterator i;
    for (i = Mat.begin(); i < Mat.end(); ++i)
    {
        file << (*i).IdMat << " " << (*i).NomMat << " " << (*i).Coef << " " << (*i).Ens.Id << endl;
    }
    file.close();
}

void AddEns(vector<Enseignant> ens, Matiere &mat)
{
    vector<Enseignant>::iterator i;
    if (EnseignantFound(ens, mat.Ens.Id) == -1)
    {
        cout << " 404 NOT FOUND " << endl;
    }
    else
    {
        for (i = ens.begin(); i < ens.end(); i++)
        {
            if ((*i).Id == mat.Ens.Id)
            {
                mat.SetEns((*i));
            }
        }
        enregistrerMatiere();
    }
}

void ajouterMat(vector<Matiere> &MatTab, vector<Enseignant> ens)
{

    mat.AddIdMat();

    if (MatiereFound(MatTab, mat.IdMat) == 1)
    {
        cout << " ID Already exist" << endl;
    }
    else
    {
        mat.AddNomMat();
        mat.AddCoef();
        AddEns(ens, mat);
        MatTab.push_back(mat);
        cout << " successfully added " << endl;
    }
}
void modifierMatiere(vector<Matiere> &MatTab, vector<Enseignant> ens)
{
    mat.AddIdMat();
    float coef;
    string idmat, nommat;
    vector<Matiere>::iterator i;
    vector<Matiere>::iterator pos;
    if (MatiereFound(MatTab, mat.IdMat) != 1)
    {
        cout << "Couln't find the Subject" << endl;
    }
    else
    {
        for (i = MatTab.begin(); i < MatTab.end(); i++)
        {
            if (mat.IdMat == (*i).IdMat)
            {
                pos = i;
            }
        }
        cout << "IdMat : ";
        cin >> idmat;
        cout << "NomMat : ";
        cin >> nommat;
        cout << "Coef : ";
        cin >> coef;
        cout << "EnsId : ";
        cin >> mat.Ens.Id;
        AddEns(ens, mat);
        (*pos).SetIdMat(idmat);
        (*pos).SetNomMat(nommat);
        (*pos).SetCoef(coef);
        (*pos).SetEns(mat.Ens);
        modifierMat(MatTab);
    }
}

void supprimerMatiere(vector<Matiere> &MatTab)
{
    mat.AddIdMat();
    vector<Matiere>::iterator i;
    vector<Matiere>::iterator pos;
    if (MatiereFound(MatTab, mat.IdMat) != 1)
    {
        cout << "Couln't find the student" << endl;
    }
    else
    {
        for (i = MatTab.begin(); i < MatTab.end(); i++)
        {
            if (mat.IdMat == (*i).IdMat)
            {
                pos = i;
            }
        }
        MatTab.erase(pos);
        modifierMat(MatTab);
    }
}

void printMatiere(vector<Matiere> matTab)
{
    vector<Matiere>::iterator i;

    for (i = matTab.begin(); i != matTab.end(); i++)
    {
        cout << (*i);
    }
}
