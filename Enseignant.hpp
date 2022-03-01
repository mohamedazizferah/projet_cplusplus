#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H
#pragma once
#include "personne.hpp"

class Enseignant : public Personne
{
public:
    int CNSS;
    Enseignant();
    Enseignant(int, string, string, string, int);
    void SetCNSS(int);
    void AddCNSS();
    void afficher_EN();
    friend ostream &operator<<(ostream &, const Enseignant &);
};

Enseignant::Enseignant() : Personne()
{
    this->CNSS = 0;
}

Enseignant::Enseignant(int id, string nom, string prenom, string mail, int CNSS) : Personne(id, nom, prenom, mail)
{
    this->CNSS = CNSS;
}

void Enseignant::SetCNSS(int c)
{
    this->CNSS = c;
}

void Enseignant::AddCNSS()
{
    cout << "CNSS : ";
    cin >> CNSS;
}

void Enseignant::afficher_EN()
{
    Personne::afficher_P();
    cout << "CNSS :" << CNSS << endl;
}

ostream &operator<<(ostream &flux, const Enseignant &EN)
{
    flux << "id :" << EN.Id << endl
         << "nom : " << EN.Nom << endl
         << "prenom : " << EN.Prenom << endl
         << "Mail : " << EN.Mail << endl
         << "CNSS : " << EN.CNSS << endl;
    return flux;
}
#endif