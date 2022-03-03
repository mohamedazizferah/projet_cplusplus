#include "crud_note.hpp"
#include "group.hpp"
#include "note.hpp"
#include "crud_groupe.hpp"
#pragma once;

vector<Etudiant> listeDesEtudiants;
vector<Enseignant> listeDesEnseignant;
vector<Matiere> listDesMatiere;
vector<NOTE> listDesNotes;
vector<GroupeModule> listDesModules;
vector<Groupe> listGRP;
void init()
{
    remplirEtudiant(listeDesEtudiants);
    remplirEnseignant(listeDesEnseignant);
    remplirMatiere(listDesMatiere, listeDesEnseignant);
    remplirNote(listDesNotes, listeDesEtudiants, listDesMatiere);
    remplirGM(listDesModules, listDesMatiere);
    remplirG(listGRP, listeDesEtudiants, listDesModules);
}