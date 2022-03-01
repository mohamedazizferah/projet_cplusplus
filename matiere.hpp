#ifndef MATIERE_H
#define MATIERE_H
#pragma once
#include "enseignant.hpp"

class Matiere
{
public:
    string IdMat;
    string NomMat;
    float Coef;
    Enseignant Ens;
    Matiere();
    Matiere(string, string, float, Enseignant);
    void SetIdMat(string);
    void SetNomMat(string);
    void SetCoef(float);
    void SetEns(Enseignant);
    void AddIdMat();
    void AddNomMat();
    void AddCoef();
    void afficher_MAT();
    friend ostream &operator<<(ostream &, const Matiere &);
};
Matiere::Matiere()
{
}

Matiere::Matiere(string IdMat, string NomMat, float Coef, Enseignant Ens)
{
    this->IdMat = IdMat;
    this->NomMat = NomMat;
    this->Coef = Coef;
    this->Ens = Ens;
}

void Matiere::SetIdMat(string i)
{
    this->IdMat = i;
}

void Matiere::SetNomMat(string n)
{
    this->NomMat = n;
}

void Matiere::SetCoef(float n)
{
    this->Coef = n;
}

void Matiere::SetEns(Enseignant e)
{
    this->Ens = e;
}

void Matiere::AddIdMat()
{
    cout << "IdMat : ";
    // getline(cin, IdMat);
    cin >> IdMat;
}

void Matiere::AddNomMat()
{
    cout << "NomMat : ";
    getline(cin, NomMat);
}

void Matiere::AddCoef()
{
    cout << "Coef : ";
    cin >> Coef;
}

void Matiere::afficher_MAT()
{
    cout << "id :" << IdMat << endl;
    cout << "nom : " << NomMat << endl;
    cout << "Coef : " << Coef << endl;
    Ens.afficher_EN();
}

ostream &operator<<(ostream &flux, const Matiere &M)
{
    flux << "id :" << M.IdMat << endl
         << "nom : " << M.NomMat << endl
         << "Coef : " << M.Coef << endl
         << M.Ens;
    return flux;
}
#endif
