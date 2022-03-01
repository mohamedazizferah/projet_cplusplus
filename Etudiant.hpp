#ifndef ETUDIANT_H
#define ETUDIANT_H
#pragma once
#include "personne.hpp"

class Etudiant : public Personne
{
public:
    int NumInsc;
    Etudiant();
    Etudiant(int, string, string, string, int);
    void setNumInsc(int);
    void AddNumInsc();
    void afficher_ET();
    friend ostream &operator<<(ostream &, const Etudiant &);
};

Etudiant::Etudiant() : Personne()
{
    this->NumInsc = 0;
}

Etudiant::Etudiant(int id, string nom, string prenom, string mail, int NumInsc) : Personne(id, nom, prenom, mail)
{
    this->NumInsc = NumInsc;
}

void Etudiant::setNumInsc(int n)
{
    this->NumInsc = n;
}

void Etudiant::AddNumInsc()
{
    cout << "Num_insc : ";
    cin >> NumInsc;
}

void Etudiant::afficher_ET()
{
    Personne::afficher_P();
    cout << "NumInsc :" << NumInsc << endl;
}

ostream &operator<<(ostream &flux, const Etudiant &ET)
{
    flux << "id :" << ET.Id << endl
         << "nom : " << ET.Nom << endl
         << "prenom : " << ET.Prenom << endl
         << "Mail : " << ET.Mail << endl
         << "NumInsc : " << ET.NumInsc << endl;
    return flux;
}
#endif