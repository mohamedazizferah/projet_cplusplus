#include "Etudiant.hpp"
#pragma once

Etudiant Etud;
vector<Etudiant> Et;
void remplirEtudiant(vector<Etudiant> &Et)
{
    int id;
    string nom;
    string prenom;
    string mail;
    int numinsc;
    Etudiant newStudent(id, nom, prenom, mail, numinsc);
    unsigned int size = Et.size();
    ifstream fin("Etudiant.txt");
    if (fin.is_open())
    {
        cout << "File open" << endl;
        while (fin >> id >> nom >> prenom >> mail >> numinsc)
        {
            newStudent.setId(id);
            newStudent.setNom(nom);
            newStudent.setPrenom(prenom);
            newStudent.setMail(mail);
            newStudent.setNumInsc(numinsc);
            Et.push_back(newStudent);
        }
    }
}

int EtudiantFound(vector<Etudiant> Et, int Id)
{
    vector<Etudiant>::iterator i;

    for (i = Et.begin(); i < Et.end(); i++)
    {
        if ((*i).Id == Id)
        {
            return 1;
        }
    }
    return -1;
}

void enregistrerEt()
{
    fstream fout("Etudiant.txt", ios::app);

    fout << Etud.Id << " "
         << Etud.Nom << " "
         << Etud.Prenom << " "
         << Etud.Mail << " "
         << Etud.NumInsc << endl;
}
void modifierEt(vector<Etudiant> Et)
{
    ofstream file;
    file.open("Etudiant.txt");
    vector<Etudiant>::iterator i;
    for (i = Et.begin(); i < Et.end(); ++i)
    {
        file << (*i).Id << " " << (*i).Nom << " " << (*i).Prenom << " " << (*i).Mail << " " << (*i).NumInsc << endl;
    }
    file.close();
}

void ajoutEtudiant(vector<Etudiant> &Et)
{
    int nbEtudiant = Et.size();
    Etud.AddId();
    if (EtudiantFound(Et, Etud.Id) == 1)
    {
        cout << " ID Already exist" << endl;
    }
    else
    {
        Etud.AddNom();
        Etud.AddPrenom();
        Etud.AddMail();
        Etud.AddNumInsc();
        Et.push_back(Etud);
        cout << "added successfully " << endl;
        enregistrerEt();
    }
}

void modifierEtudiant(vector<Etudiant> &Et)
{
    Etud.AddId();
    int id, numinsc;
    string nom, prenom, mail;
    vector<Etudiant>::iterator i;
    vector<Etudiant>::iterator pos;
    if (EtudiantFound(Et, Etud.Id) != 1)
    {
        cout << "Couln't find the student" << endl;
    }
    else
    {
        for (i = Et.begin(); i < Et.end(); i++)
        {
            if (Etud.Id == (*i).Id)
            {
                pos = i;
            }
        }
        cout << "Id : ";
        cin >> id;
        cout << "Nom : ";
        cin >> nom;
        cout << "Prenom : ";
        cin >> prenom;
        cout << "Mail : ";
        cin >> mail;
        cout << "Num_insc : ";
        cin >> numinsc;
        (*pos).setId(id);
        (*pos).setNom(nom);
        (*pos).setPrenom(prenom);
        (*pos).setMail(mail);
        (*pos).setNumInsc(numinsc);
        modifierEt(Et);
    }
}

void supprimerEtudiant(vector<Etudiant> &Et)
{
    Etud.AddId();
    vector<Etudiant>::iterator i;
    vector<Etudiant>::iterator pos;
    if (EtudiantFound(Et, Etud.Id) != 1)
    {
        cout << "Couln't find the student" << endl;
    }
    else
    {
        for (i = Et.begin(); i < Et.end(); i++)
        {
            if (Etud.Id == (*i).Id)
            {
                pos = i;
            }
        }
        Et.erase(pos);
        modifierEt(Et);
    }
}

void printAllStudents(vector<Etudiant> Et)
{
    vector<Etudiant>::iterator i;
    for (i = Et.begin(); i != Et.end(); i++)
    {
        cout << (*i);
    }
}