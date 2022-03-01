#include "crud_note.hpp"
#include "groupemodule.hpp"
#include "group.hpp"
#include "note.hpp"

int main()
{
    vector<NOTE> listn;
    vector<Matiere> listmatt;
    vector<Matiere> listmatt2;
    vector<Etudiant> listetudd;
    vector<Enseignant> listens;
    vector<GroupeModule> listgm;
    vector<Matiere> listmatt3;
    Personne new_P(2, "aziz", "ferah", "aaa");
    Etudiant e(12, "aziz", "ferah", "adr", 21284);
    Etudiant e2(13, "aziz", "ferah", "adr", 21284);
    Etudiant e3(114, "aziz", "ferah", "adr", 21284);
    Enseignant en(12, "aziz", "ferah", "adr", 21284);
    Personne p;
    Matiere mat;
    Matiere mat2("18", "math", 1.5, en);
    listmatt.push_back(mat2);
    listmatt2.push_back(mat);
    listmatt2.push_back(mat2);
    GroupeModule gm("18", "math", 1.5, listmatt);
    GroupeModule gm2("19", "infoet", 0.5, listmatt2);
    // listetudd.push_back(e);
    // listetudd.push_back(e2);
    // listetudd.push_back(e3);
    listgm.push_back(gm);
    listgm.push_back(gm2);
    Groupe g("10", "2eme", "IRM", "info", 5, listgm, listetudd);
    NOTE n(mat2, e, 18.6, "DS");
    // mat2.afficher_MAT();
    // mat.afficher_MAT();
    // en.afficher_EN();
    // e.afficher_ET();
    // new_P.afficher_P();
    // gm.afficher_GM();
    // g.afficher_G();
    // n.afficher_NOTE();
    // cout << g;
    // Groupe g2;
    // g2.AddIdGRP();
    // g2.AddNiveau();
    // g2.AddDiplome();
    // cout << g2;
    remplirEtudiant(listetudd);
    // printAllStudents(listetudd);
    // // ajoutEtudiant(listetudd);
    // // printAllStudents(listetudd);
    // modifierEtudiant(listetudd);
    // supprimerEtudiant(listetudd);
    remplirEnseignant(listens);
    // ajoutEnseignant(listens);
    // ajoutEnseignant(listens);
    // modifierEnseignant(listens);
    // supprimerEnseignant(listens);
    // ajouterMat(listmatt3, listens);
    remplirMatiere(listmatt3, listens);
    // ajouterMat(listmatt3, listens);
    // printMatiere(listmatt3);
    // modifierMatiere(listmatt3, listens);
    // supprimerMatiere(listmatt3);
    remplirNote(listn, listetudd, listmatt3);
    // ajouterNote(listn, listetudd, listmatt3);
    // printNote(listn);
    // modifierNote(listn, listetudd, listmatt3);
    supprimerNote(listn);
}