#ifndef NOTE_H
#define NOTE_H
#pragma once
#include "etudiant.hpp"
#include "matiere.hpp"

class NOTE
{
public:
    Matiere Mat;
    Etudiant Etu;
    float Note;
    string Type;
    NOTE();
    NOTE(Matiere, Etudiant, float, string);
    void SetNote(float);
    void SetType(string);
    void SetEtudiant(Etudiant);
    void SetMatiere(Matiere);
    void AddNote();
    void AddType();
    void afficher_NOTE();
    friend ostream &operator<<(ostream &, const NOTE &);
};
NOTE::NOTE()
{
}

NOTE::NOTE(Matiere Mat, Etudiant Etu, float Note, string Type)
{
    this->Mat = Mat;
    this->Etu = Etu;
    this->Note = Note;
    this->Type = Type;
}

void NOTE::SetNote(float n)
{
    this->Note = n;
}

void NOTE::SetType(string t)
{
    this->Type = t;
}

void NOTE::SetEtudiant(Etudiant et)
{
    this->Etu = et;
}
void NOTE::SetMatiere(Matiere mat)
{
    this->Mat = mat;
}

void NOTE::AddNote()
{
    cout << "Note : ";
    cin >> Note;
}

void NOTE::AddType()
{
    int i;
    cout << "choisir Type : ";
    cout << "1- DS ";
    cout << "2- Examen ";
    cout << "3- TP";
    do
    {
        cin >> i;
        cin.ignore();
    } while (i < 1 || i > 3);
    switch (i)
    {
    case 1:
        this->Type = "DS";
        break;
    case 2:
        this->Type = "Examen";
        break;
    case 3:
        this->Type = "TP";
        break;
    }
}

void NOTE::afficher_NOTE()
{
    Mat.afficher_MAT();
    Etu.afficher_ET();
    cout << "Note :" << Note << endl;
    cout << "type : " << Type << endl;
}

ostream &operator<<(ostream &flux, const NOTE &N)
{
    flux << N.Mat << endl
         << N.Etu << endl
         << "Note : " << N.Note << endl
         << "Type : " << N.Type << endl;
    return flux;
}
#endif
