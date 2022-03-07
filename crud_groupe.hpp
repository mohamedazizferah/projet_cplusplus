#include "group.hpp"
#include "crud_GM.hpp"
#include "crud_etudiant.hpp"
#pragma once

Groupe g;

void remplirG(vector<Groupe> &GTab, vector<Etudiant> etudiant, vector<GroupeModule> groupemodule)
{
    string idgm, idg, idg2, idg3, nivg, dip, spec;
    int num, idEt;

    unsigned int size = MatTab.size();
    ifstream fin("Group.txt");
    ifstream fin2("GroupGMs.txt");
    ifstream fin3("GroupEts.txt");
    vector<GroupeModule>::iterator i;
    vector<Etudiant>::iterator j;
    if (fin.is_open())
    {
        while (fin >> idg >> nivg >> dip >> spec >> num)
        {
            vector<Etudiant> et;
            vector<GroupeModule> gm;
            Groupe newG;
            newG.SetIdGRP(idg);
            newG.SetNiveau(nivg);
            newG.SetDiplome(dip);
            newG.SetSpecialite(spec);
            newG.SetNum_G(num);
            if (fin2.is_open())
            {
                while (fin2 >> idg2 >> idgm)
                {
                    for (i = groupemodule.begin(); i < groupemodule.end(); i++)
                    {
                        if ((*i).IdGM == idgm && idg2 == idg)
                        {
                            gm.push_back(*i);
                        }
                    }
                }
            }
            if (fin3.is_open())
            {
                while (fin3 >> idg3 >> idEt)
                {
                    for (j = etudiant.begin(); j < etudiant.end(); j++)
                    {
                        if ((*j).Id == idEt && idg3 == idg)
                        {
                            et.push_back(*j);
                        }
                    }
                }
            }
            newG.SetEtudiant(et);
            newG.SetGM(gm);
            GTab.push_back(newG);
            fin2.clear();
            fin2.seekg(0);
            fin3.clear();
            fin3.seekg(0);
        }
    }
}

int GFound(vector<Groupe> &GTab, string id)
{
    vector<Groupe>::iterator i;
    for (i = GTab.begin(); i < GTab.end(); i++)
    {
        if ((*i).IdGRP == id)
        {
            return 1;
        }
    }
    return -1;
}

void enregistrerGRP()
{
    vector<GroupeModule>::iterator i;
    vector<Etudiant>::iterator j;
    fstream fout("Group.txt", ios::app);
    fout << g.IdGRP << " "
         << g.Niveau << " "
         << g.Diplome << " "
         << g.Specialite << " "
         << g.Num_G << endl;
    fstream fout2("GroupGMs.txt", ios::app);
    for (i = g.ListeModules.begin(); i < g.ListeModules.end(); i++)
    {
        fout2 << g.IdGRP << " " << (*i).IdGM << endl;
    }
    fstream fout3("GroupEts.txt", ios::app);
    for (j = g.ListeEtudiants.begin(); j < g.ListeEtudiants.end(); j++)
    {
        fout3 << g.IdGRP << " " << (*j).Id << endl;
    }
}

void modifierGRPList(vector<Groupe> G)
{
    ofstream file;
    file.open("Group.txt");
    ofstream file2;
    file2.open("GroupGMs.txt");
    ofstream file3;
    file3.open("GroupEts.txt");
    vector<Groupe>::iterator i;
    vector<GroupeModule>::iterator j;
    vector<Etudiant>::iterator f;
    for (i = G.begin(); i < G.end(); i++)
    {
        file << (*i).IdGRP << " " << (*i).Niveau << " " << (*i).Diplome << " " << (*i).Specialite << " " << (*i).Num_G << endl;
        for (j = (*i).ListeModules.begin(); j < (*i).ListeModules.end(); j++)
        {
            file2 << (*i).IdGRP << " " << (*j).IdGM << endl;
        }
        for (f = (*i).ListeEtudiants.begin(); f < (*i).ListeEtudiants.end(); f++)
        {
            file3 << (*i).IdGRP << " " << (*f).Id << endl;
        }
    }
    file.close();
    file2.close();
    file3.close();
}

void AddGMnET(vector<GroupeModule> gm, vector<Etudiant> etudiant, Groupe &Grp)
{
    string id;
    int idS;
    int found;
    int mods, ets, itergm, iteretud;
    found = 0;
    vector<GroupeModule>::iterator i;
    vector<Etudiant>::iterator j;
    cout << "how many GroupModules will you add : ";
    cin >> mods;
    for (itergm = 0; itergm < mods; itergm++)
    {
        cout << "IdGM : ";
        cin >> id;
        if (GMFound(gm, id) == -1)
        {
            cout << " 404 NOT FOUND " << endl;
        }
        else
        {
            found++;
            for (i = gm.begin(); i < gm.end(); i++)
            {
                if ((*i).IdGM == id)
                {
                    Grp.ListeModules.push_back(*i);
                }
            }
        }
    }
    cout << "how many Students will you add : ";
    cin >> ets;
    for (iteretud = 0; iteretud < ets; iteretud++)
    {
        cout << "Student ID : ";
        cin >> idS;
        cin.ignore();
        if (EtudiantFound(etudiant, idS) == -1)
        {
            cout << " 404 NOT FOUND " << endl;
        }
        else
        {
            found++;
            for (j = etudiant.begin(); j < etudiant.end(); j++)
            {
                if ((*j).Id == idS)
                {
                    Grp.ListeEtudiants.push_back(*j);
                }
            }
        }
    }
    if (found > 0)
    {
        enregistrerGRP();
    }
}

void ajouterGRP(vector<Groupe> &GTab, vector<GroupeModule> gm, vector<Etudiant> etudiant)
{
    g.AddIdGRP();
    if (GFound(GTab, g.IdGRP) == 1)
    {
        cout << " Groupe Already exist" << endl;
    }
    else
    {
        g.AddNiveau();
        g.AddDiplome();
        g.AddSpecialite();
        do
        {
            cout << "Num_G est 1,2 ou 3";
            g.AddNum_G();
        } while (g.Num_G < 1 || g.Num_G > 3);
        AddGMnET(gm, etudiant, g);
        GTab.push_back(g);
    }
}
void modifierGRP(vector<Groupe> &GTab, vector<GroupeModule> gm, vector<Etudiant> etudiant)
{
    g.AddIdGRP();
    int num;
    string idg, nivg, dip, spec;
    vector<Groupe>::iterator i;
    vector<Groupe>::iterator pos;
    if (GFound(GTab, g.IdGRP) != 1)
    {
        cout << "Couln't find the Groupe" << endl;
    }
    else
    {
        for (i = GTab.begin(); i < GTab.end(); i++)
        {
            if (g.IdGRP == (*i).IdGRP)
            {
                pos = i;
            }
        }
        cout << "IdGRP : ";
        cin >> idg;
        cout << "Niveau : ";
        cin >> nivg;
        cout << "Diplome : ";
        cin >> dip;
        cout << "Specialite : ";
        cin >> spec;
        do
        {
            cout << "Num_G (1,2,3) : ";
            cin >> num;
        } while (num < 1 || num > 3);
        (*pos).SetIdGRP(idg);
        (*pos).SetNiveau(nivg);
        (*pos).SetDiplome(dip);
        (*pos).SetSpecialite(spec);
        (*pos).SetNum_G(num);
        modifierGRPList(GTab);
    }
}

void supprimerGRP(vector<Groupe> &GTab)
{
    g.AddIdGRP();
    vector<Groupe>::iterator i;
    vector<Groupe>::iterator pos;
    if (GFound(GTab, g.IdGRP) != 1)
    {
        cout << "Couln't find the Groupe " << endl;
    }
    else
    {
        for (i = GTab.begin(); i < GTab.end(); i++)
        {
            if (g.IdGRP == (*i).IdGRP)
            {
                pos = i;
            }
        }
        GTab.erase(pos);
        modifierGRPList(GTab);
    }
}

void printGRP(vector<Groupe> GTab)
{
    vector<Groupe>::iterator i;

    for (i = GTab.begin(); i < GTab.end(); i++)
    {
        cout << (*i);
    }
}

void AddGMInGRP(vector<Groupe> &GTab, vector<GroupeModule> GMTab)
{

    string id;
    int found;
    int mats, iter;
    found = 0;
    vector<Groupe>::iterator i;
    vector<Groupe>::iterator pos;
    vector<GroupeModule>::iterator j;
    g.AddIdGRP();
    if (GFound(GTab, g.IdGRP) != 1)
    {
        cout << " Groupe does not exist" << endl;
    }
    else
    {
        for (i = GTab.begin(); i < GTab.end(); i++)
        {
            if (g.IdGRP == (*i).IdGRP)
            {
                pos = i;
            }
        }
        cout << "IdGM : ";
        cin >> id;
        cin.ignore();
        if (GMFound(GMTab, id) == -1)
        {
            cout << " 404 NOT FOUND " << endl;
        }
        else
        {
            if (GMFound((*pos).ListeModules, id) == 1)
            {
                cout << " Module already exists in your Groupe " << endl;
            }
            else
            {
                found++;
                for (j = GMTab.begin(); j < GMTab.end(); j++)
                {
                    if ((*j).IdGM == id)
                    {
                        (*pos).ListeModules.push_back(*j);
                    }
                }
            }
        }
    }
    if (found > 0)
    {
        modifierGRPList(GTab);
    }
}

void DeleteGMFromGRP(vector<Groupe> &GTab)
{
    g.AddIdGRP();
    string id;
    vector<Groupe>::iterator i;
    vector<Groupe>::iterator pos;
    vector<GroupeModule>::iterator j;
    vector<GroupeModule>::iterator posGM;
    if (GFound(GTab, g.IdGRP) != 1)
    {
        cout << "Couln't find the Groupe Module" << endl;
    }
    else
    {
        cout << "IdGM : ";
        cin >> id;
        for (i = GTab.begin(); i < GTab.end(); i++)
        {
            if (g.IdGRP == (*i).IdGRP)
            {
                pos = i;
            }
        }
        for (j = (*pos).ListeModules.begin(); j < (*pos).ListeModules.end(); j++)
        {
            if (id == (*j).IdGM)
            {
                posGM = j;
            }
        }
        (*pos).ListeModules.erase(posGM);
        modifierGRPList(GTab);
    }
}

void AddEtudInGRP(vector<Groupe> &GTab, vector<Etudiant> et)
{

    int id;
    int found;
    int mats, iter;
    found = 0;
    vector<Groupe>::iterator i;
    vector<Groupe>::iterator pos;
    vector<Etudiant>::iterator j;
    g.AddIdGRP();
    if (GFound(GTab, g.IdGRP) != 1)
    {
        cout << " Groupe does not exist" << endl;
    }
    else
    {
        for (i = GTab.begin(); i < GTab.end(); i++)
        {
            if (g.IdGRP == (*i).IdGRP)
            {
                pos = i;
            }
        }
        cout << "Student Id : ";
        cin >> id;
        cin.ignore();
        if (EtudiantFound(et, id) == -1)
        {
            cout << " 404 NOT FOUND " << endl;
        }
        else
        {
            if (EtudiantFound((*pos).ListeEtudiants, id) == 1)
            {
                cout << " Student already exists in your Groupe " << endl;
            }
            else
            {
                found++;
                for (j = et.begin(); j < et.end(); j++)
                {
                    if ((*j).Id == id)
                    {
                        (*pos).ListeEtudiants.push_back(*j);
                    }
                }
            }
        }
    }
    if (found > 0)
    {
        modifierGRPList(GTab);
    }
}

void DeleteEtudFromGRP(vector<Groupe> &GTab)
{
    g.AddIdGRP();
    int id;
    vector<Groupe>::iterator i;
    vector<Groupe>::iterator pos;
    vector<Etudiant>::iterator j;
    vector<Etudiant>::iterator posEt;
    if (GFound(GTab, g.IdGRP) != 1)
    {
        cout << "Couln't find the Groupe Module" << endl;
    }
    else
    {
        cout << "Student Id : ";
        cin >> id;
        for (i = GTab.begin(); i < GTab.end(); i++)
        {
            if (g.IdGRP == (*i).IdGRP)
            {
                pos = i;
            }
        }
        for (j = (*pos).ListeEtudiants.begin(); j < (*pos).ListeEtudiants.end(); j++)
        {
            if (id == (*j).Id)
            {
                posEt = j;
            }
        }
        (*pos).ListeEtudiants.erase(posEt);
        modifierGRPList(GTab);
    }
}

void EtudDunGroupe(vector<Groupe> GTab)
{
    string id;
    vector<Groupe>::iterator i;
    vector<Groupe>::iterator pos;
    vector<Etudiant>::iterator j;
    cout << "IdGRP : ";
    cin >> id;
    if (GFound(GTab, id) != 1)
    {
        cout << "Groupe does not exist";
    }
    else
    {
        for (i = GTab.begin(); i < GTab.end(); i++)
        {
            if ((*i).IdGRP == id)
            {
                pos = i;
            }
        }
        for (j = (*pos).ListeEtudiants.begin(); j < (*pos).ListeEtudiants.end(); j++)
        {
            cout << (*j);
        }
    }
}

void GmDunGRP(vector<Groupe> GTab)
{
    string id;
    vector<Groupe>::iterator i;
    vector<Groupe>::iterator pos;
    vector<GroupeModule>::iterator j;
    cout << "IdGRP : ";
    cin >> id;
    if (GFound(GTab, id) != 1)
    {
        cout << "Groupe does not exist";
    }
    else
    {
        for (i = GTab.begin(); i < GTab.end(); i++)
        {
            if ((*i).IdGRP == id)
            {
                pos = i;
            }
        }
        for (j = (*pos).ListeModules.begin(); j < (*pos).ListeModules.end(); j++)
        {
            cout << "nom module :" << (*j).NomGM << endl;
            cout << "coef module :" << (*j).CoefGM << endl;
        }
    }
}