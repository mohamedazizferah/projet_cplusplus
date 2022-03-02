#ifndef GROUPEMODULE_H
#define GROUPEMODULE_H
#pragma once
#include "matiere.hpp"
#include <iostream>

class GroupeModule
{
public:
    string IdGM;
    string NomGM;
    float CoefGM;
    vector<Matiere> ListeMat;
    GroupeModule();
    GroupeModule(string, string, float, vector<Matiere>);
    void SetIdGM(string);
    void SetNomGM(string);
    void SetCoefGM(float);
    void SetListMat(vector<Matiere>);
    void AddIdGM();
    void AddNomGM();
    void AddCoefGM();
    void afficher_GM();
    friend ostream &operator<<(ostream &, const GroupeModule &);
};
GroupeModule::GroupeModule()
{
}

GroupeModule::GroupeModule(string IdGM, string NomGM, float CoefGM, vector<Matiere> ListeMat)
{
    this->IdGM = IdGM;
    this->NomGM = NomGM;
    this->CoefGM = CoefGM;
    this->ListeMat = ListeMat;
}

void GroupeModule::SetIdGM(string i)
{
    this->IdGM = i;
}

void GroupeModule::SetNomGM(string n)
{
    this->NomGM = n;
}

void GroupeModule::SetCoefGM(float c)
{
    this->CoefGM = c;
}
void GroupeModule::SetListMat(vector<Matiere> lm)
{
    this->ListeMat = lm;
}
void GroupeModule::AddIdGM()
{
    cout << "IdGM : ";
    getline(cin, IdGM);
}

void GroupeModule::AddNomGM()
{
    cout << "NomGM : ";
    getline(cin, NomGM);
}

void GroupeModule::AddCoefGM()
{
    cout << "CoefGM : ";
    cin >> CoefGM;
}

void GroupeModule::afficher_GM()
{
    cout << "id :" << IdGM << endl;
    cout << "nom : " << NomGM << endl;
    cout << "CoefGM : " << CoefGM << endl;
    for (int i = 0; i < ListeMat.size(); i++)
    {
        ListeMat[i].afficher_MAT();
    }
}

ostream &operator<<(ostream &flux, const GroupeModule &GM)
{

    flux << "id :" << GM.IdGM << endl
         << "nom : " << GM.NomGM << endl
         << "coef : " << GM.CoefGM << endl;
    for (int i = 0; i < GM.ListeMat.size(); i++)
    {
        flux << GM.ListeMat[i] << endl;
    }

    return flux;
}
#endif
