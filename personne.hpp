#ifndef PERSONNE_H
#define PERSONNE_H
#pragma once
#include "bib.hpp"

class Personne
{
public:
    int Id;
    string Nom;
    string Prenom;
    string Mail;
    Personne();
    Personne(int, string, string, string);
    void setId(int Id);
    void setNom(string Nom);
    void setPrenom(string Prenom);
    void setMail(string Mail);
    void AddId();
    void AddNom();
    void AddPrenom();
    void AddMail();
    void afficher_P();
    friend ostream &operator<<(ostream &, const Personne &);
};

Personne::Personne()
{
    this->Id = 0;
    this->Nom = "";
    this->Prenom = "";
    this->Mail = "";
}

Personne::Personne(int i, string n, string p, string m)
{
    this->Id = i;
    this->Nom = n;
    this->Prenom = p;
    this->Mail = m;
}

void Personne::setId(int Id)
{
    this->Id = Id;
}

void Personne::setNom(string Nom)
{
    this->Nom = Nom;
}

void Personne::setPrenom(string Prenom)
{
    this->Prenom = Prenom;
}

void Personne::setMail(string Mail)
{
    this->Mail = Mail;
}

void Personne::AddId()
{
    cout << "Id : ";
    cin >> Id;
}

void Personne::AddNom()
{
    cout << "Nom : ";
    cin.ignore();
    getline(cin, Nom);
}

void Personne::AddPrenom()
{
    cout << "Prenom : ";
    getline(cin, Prenom);
}

void Personne::AddMail()
{
    cout << "mail : ";
    getline(cin, Mail);
}

void Personne::afficher_P()
{
    cout << "id :" << Id << endl;
    cout << "nom : " << Nom << endl;
    cout << "prenom : " << Prenom << endl;
    cout << "Mail : " << Mail << endl;
}

ostream &operator<<(ostream &flux, const Personne &P)
{
    flux << "id :" << P.Id << endl
         << "nom : " << P.Nom << endl
         << "prenom : " << P.Prenom << endl
         << "Mail : " << P.Mail << endl;
    return flux;
}
#endif