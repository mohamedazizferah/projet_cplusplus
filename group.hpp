#ifndef GROUPE_H
#define GROUPE_H
#pragma once
#include "groupemodule.hpp"
#include "Etudiant.hpp"
class Groupe
{
public:
    string IdGRP;
    string Niveau;
    string Diplome;
    string Specialite;
    int Num_G;
    vector<GroupeModule> ListeModules;
    vector<Etudiant> ListeEtudiants;
    Groupe();
    Groupe(string, string, string, string, int, vector<GroupeModule>, vector<Etudiant>);
    void SetIdGRP(string);
    void SetNiveau(string);
    void SetDiplome(string);
    void SetSpecialite(string);
    void SetGM(vector<GroupeModule>);
    void SetEtudiant(vector<Etudiant>);
    void SetNum_G(int);
    void AddIdGRP();
    void AddNiveau();
    void AddDiplome();
    void AddSpecialite();
    void AddNum_G();
    void afficher_G();
    friend ostream &operator<<(ostream &, const Groupe &);
};
Groupe::Groupe()
{
}

Groupe::Groupe(string IdGRP, string Niveau, string Diplome, string Specialite, int Num_G, vector<GroupeModule> ListeModules, vector<Etudiant> ListeEtudiants)
{
    this->IdGRP = IdGRP;
    this->Niveau = Niveau;
    this->Diplome = Diplome;
    this->Specialite = Specialite;
    this->Num_G = Num_G;
    this->ListeModules = ListeModules;
    this->ListeEtudiants = ListeEtudiants;
}

void Groupe::SetIdGRP(string i)
{
    this->IdGRP = i;
}

void Groupe::SetNiveau(string n)
{
    this->Niveau = n;
}

void Groupe::SetDiplome(string d)
{
    this->Diplome = d;
}

void Groupe::SetSpecialite(string s)
{
    this->Specialite = s;
}

void Groupe::SetGM(vector<GroupeModule> gm)
{
    this->ListeModules = gm;
}

void Groupe::SetEtudiant(vector<Etudiant> et)
{
    this->ListeEtudiants = et;
}
void Groupe::SetNum_G(int n)
{
    this->Num_G = n;
}

void Groupe::AddIdGRP()
{
    cout << "IdGRP : ";
    getline(cin, IdGRP);
}

void Groupe::AddNiveau()
{
    cout << "Niveau : ";
    getline(cin, Niveau);
}

void Groupe::AddDiplome()
{
    cout << "Diplome : ";
    getline(cin, Diplome);
}

void Groupe::AddSpecialite()
{
    cout << "Specialite : ";
    getline(cin, Specialite);
}

void Groupe::AddNum_G()
{
    cout << "Num_G : ";
    cin >> Num_G;
}

void Groupe::afficher_G()
{
    cout << "id :" << IdGRP << endl;
    cout << "nom : " << Niveau << endl;
    cout << "Diplome : " << Diplome << endl;
    cout << "Specialite : " << Specialite << endl;
    cout << "Num_G : " << Num_G << endl;
    for (int i = 0; i < ListeModules.size(); i++)
    {
        ListeModules[i].afficher_GM();
    }
    for (int j = 0; j < ListeEtudiants.size(); j++)
    {
        ListeEtudiants[j].afficher_ET();
    }
}

ostream &operator<<(ostream &flux, const Groupe &G)
{

    flux << "id :" << G.IdGRP << endl
         << "niveau : " << G.Niveau << endl
         << "Diplome : " << G.Diplome << endl
         << "Specialite : " << G.Specialite << endl
         << "Num_G : " << G.Num_G << endl;
    for (int i = 0; i < G.ListeModules.size(); i++)
    {
        flux << G.ListeModules[i] << endl;
    }
    for (int j = 0; j < G.ListeEtudiants.size(); j++)
    {
        flux << G.ListeEtudiants[j] << endl;
    }

    return flux;
}
#endif
