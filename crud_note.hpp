#include "note.hpp"
#include "crud_matiere.hpp"
#include "crud_etudiant.hpp"
#pragma once

NOTE nott;

void remplirNote(vector<NOTE> &NoteTab, vector<Etudiant> et, vector<Matiere> matiere)
{
    string type;
    float note;
    Etudiant etud;
    Matiere mat;
    NOTE newNote(mat, etud, note, type);
    unsigned int size = MatTab.size();
    ifstream fin("Note.txt");
    vector<Etudiant>::iterator i;
    vector<Matiere>::iterator j;
    if (fin.is_open())
    {
        while (fin >> note >> type >> etud.Id >> mat.IdMat)
        {
            newNote.SetNote(note);
            newNote.SetType(type);
            newNote.Etu.setId(etud.Id);
            newNote.Mat.SetIdMat(mat.IdMat);
            for (i = et.begin(); i < et.end(); i++)
            {
                if ((*i).Id == newNote.Etu.Id)
                    newNote.SetEtudiant(*i);
            }
            for (j = matiere.begin(); j < matiere.end(); j++)
            {
                if ((*j).IdMat == newNote.Mat.IdMat)
                    newNote.SetMatiere(*j);
            }
            NoteTab.push_back(newNote);
        }
    }
}

int NoteFound(vector<NOTE> &NoteTab, string type, Matiere m, Etudiant e)
{
    vector<NOTE>::iterator i;
    for (i = NoteTab.begin(); i < NoteTab.end(); i++)
    {
        if ((*i).Type == type && (*i).Mat.IdMat == m.IdMat && (*i).Etu.Id == e.Id)
        {
            return 1;
        }
    }
    return -1;
}

void enregistrerNote()
{
    fstream fout("Note.txt", ios::app);

    fout << nott.Note << " "
         << nott.Type << " "
         << nott.Etu.Id << " "
         << nott.Mat.IdMat << endl;
}

void modifierNot(vector<NOTE> Note)
{
    ofstream file;
    file.open("Note.txt");
    vector<NOTE>::iterator i;
    for (i = Note.begin(); i < Note.end(); ++i)
    {
        file << (*i).Note << " " << (*i).Type << " " << (*i).Etu.Id << " " << (*i).Mat.IdMat << endl;
    }
    file.close();
}

void AddEtudAndMat(vector<Matiere> matiere, vector<Etudiant> etdiant, NOTE &notee)
{
    vector<Etudiant>::iterator i;
    int Id;
    if (EtudiantFound(etdiant, notee.Etu.Id) == -1)
    {
        cout << " 404 NOT FOUND " << endl;
    }
    else
    {
        for (i = etdiant.begin(); i < etdiant.end(); i++)
        {
            if ((*i).Id == notee.Etu.Id)
            {
                notee.SetEtudiant(*i);
            }
        }
    }
    vector<Matiere>::iterator j;
    if (MatiereFound(matiere, notee.Mat.IdMat) == -1)
    {
        cout << " 404 NOT FOUND " << endl;
    }
    else
    {
        for (j = matiere.begin(); j < matiere.end(); j++)
        {
            if ((*j).IdMat == notee.Mat.IdMat)
            {
                notee.SetMatiere(*j);
            }
        }
        enregistrerNote();
        cout << " successfully added " << endl;
    }
}

void ajouterNote(vector<NOTE> &NoteTab, vector<Etudiant> et, vector<Matiere> mat)
{

    nott.AddType();
    nott.Etu.AddId();
    nott.Mat.AddIdMat();
    if (NoteFound(NoteTab, nott.Type, nott.Mat, nott.Etu) == 1)
    {
        cout << " NOTE Already exist" << endl;
    }
    else
    {
        nott.AddNote();
        AddEtudAndMat(mat, et, nott);
        NoteTab.push_back(nott);
    }
}
void modifierNote(vector<NOTE> &NoteTab, vector<Etudiant> et, vector<Matiere> mat)
{
    nott.AddType();
    nott.Mat.AddIdMat();
    nott.Etu.AddId();
    float note;
    string type;
    vector<NOTE>::iterator i;
    vector<NOTE>::iterator pos;
    if (NoteFound(NoteTab, nott.Type, nott.Mat, nott.Etu) != 1)
    {
        cout << "Couln't find the Subject" << endl;
    }
    else
    {
        for (i = NoteTab.begin(); i < NoteTab.end(); i++)
        {
            if (nott.Mat.IdMat == (*i).Mat.IdMat && nott.Etu.Id == (*i).Etu.Id && nott.Type == (*i).Type)
            {
                pos = i;
            }
        }
        (*pos).AddType();
        cout << "Note : ";
        cin >> note;
        cout << "Id Etudiant : ";
        cin >> nott.Etu.Id;
        cout << "Id Matiere : ";
        cin >> nott.Mat.IdMat;
        AddEtudAndMat(mat, et, nott);
        (*pos).SetNote(note);
        (*pos).SetEtudiant(nott.Etu);
        (*pos).SetMatiere(nott.Mat);
        modifierNot(NoteTab);
    }
}

void supprimerNote(vector<NOTE> &NoteTab)
{
    nott.AddType();
    nott.Etu.AddId();
    nott.Mat.AddIdMat();
    vector<NOTE>::iterator i;
    vector<NOTE>::iterator pos;
    if (NoteFound(NoteTab, nott.Type, nott.Mat, nott.Etu) != 1)
    {
        cout << "Couln't find the NOTE" << endl;
    }
    else
    {
        for (i = NoteTab.begin(); i < NoteTab.end(); i++)
        {
            if (nott.Mat.IdMat == (*i).Mat.IdMat && nott.Etu.Id == (*i).Etu.Id && nott.Type == (*i).Type)
            {
                pos = i;
            }
        }
        NoteTab.erase(pos);
        modifierNot(NoteTab);
    }
}

void printNote(vector<NOTE> NoteTab)
{
    vector<NOTE>::iterator i;

    for (i = NoteTab.begin(); i < NoteTab.end(); i++)
    {
        cout << (*i);
    }
}
void StudentNotes(vector<NOTE> NoteTab, vector<Etudiant> et)
{
    int id;
    cout << "Student ID : ";
    cin >> id;
    if (EtudiantFound(et, id) != 1)
    {
        cout << "Student does not exist";
    }
    else
    {
        vector<NOTE>::iterator i;
        for (i = NoteTab.begin(); i < NoteTab.end(); i++)
        {
            if ((*i).Etu.Id == id)
            {
                cout << "Note : " << (*i).Note << endl;
                cout << "Matiere : " << (*i).Mat.NomMat << endl;
                cout << "Type : " << (*i).Type << endl;
            }
        }
    }
}
