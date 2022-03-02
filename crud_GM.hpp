#include "groupemodule.hpp"
#include "crud_matiere.hpp"
#pragma once

GroupeModule gm;

void remplirGM(vector<GroupeModule> &GMTab, vector<Matiere> matiere)
{
    string idgm, idgm2, nomgm, idmat;
    float coefgm;
    vector<Matiere> mat;
    GroupeModule newGM(idgm, nomgm, coefgm, mat);
    unsigned int size = MatTab.size();
    ifstream fin("GM.txt");
    ifstream fin2("GmMats.txt");
    vector<Matiere>::iterator i;
    if (fin.is_open())
    {
        while (fin >> idgm >> nomgm >> coefgm)
        {
            newGM.SetIdGM(idgm);
            newGM.SetNomGM(nomgm);
            newGM.SetCoefGM(coefgm);
            if (fin2.is_open())
            {
                while (fin2 >> idgm2 >> idmat)
                {
                    for (i = matiere.begin(); i < matiere.end(); i++)
                    {
                        if ((*i).IdMat == idmat && idgm2 == idgm)
                        {
                            mat.push_back(*i);
                        }
                    }
                }
            }
            newGM.SetListMat(mat);
            GMTab.push_back(newGM);
        }
    }
}

int GMFound(vector<GroupeModule> &GMTab, string id)
{
    vector<GroupeModule>::iterator i;
    for (i = GMTab.begin(); i < GMTab.end(); i++)
    {
        if ((*i).IdGM == id)
        {
            return 1;
        }
    }
    return -1;
}

void enregistrerGM()
{

    vector<Matiere>::iterator i;
    fstream fout("GM.txt", ios::app);
    fout << gm.IdGM << " "
         << gm.NomGM << " "
         << gm.CoefGM << endl;
    fstream fout2("GmMats.txt", ios::app);
    for (i = gm.ListeMat.begin(); i < gm.ListeMat.end(); i++)
    {
        fout2 << gm.IdGM << " " << (*i).IdMat << endl;
    }
}

void modifierGmList(vector<GroupeModule> GM)
{
    ofstream file;
    file.open("GM.txt");
    ofstream file2;
    file2.open("GmMats.txt");
    vector<GroupeModule>::iterator i;
    vector<Matiere>::iterator j;
    for (i = GM.begin(); i < GM.end(); i++)
    {
        file << (*i).IdGM << " " << (*i).NomGM << " " << (*i).CoefGM << endl;
        for (j = (*i).ListeMat.begin(); j < (*i).ListeMat.end(); j++)
        {
            file2 << (*i).IdGM << " " << (*j).IdMat << endl;
        }
    }
    file.close();
    file2.close();
}

void AddMat(vector<Matiere> matiere, GroupeModule &Gm)
{
    string id;
    int mats, iter;
    vector<Matiere>::iterator i;
    cout << "how many subjects will you add : ";
    cin >> mats;
    for (iter = 0; iter < mats; iter++)
    {
        cout << "IdMat : ";
        cin >> id;
        if (MatiereFound(matiere, id) == -1)
        {
            cout << " 404 NOT FOUND " << endl;
        }
        else
        {
            for (i = matiere.begin(); i < matiere.end(); i++)
            {
                if ((*i).IdMat == id)
                {
                    Gm.ListeMat.push_back(*i);
                }
            }
            enregistrerGM();
        }
    }
}

void ajouterGM(vector<GroupeModule> &GmTab, vector<Matiere> mat)
{
    gm.AddIdGM();
    if (GMFound(GmTab, gm.IdGM) == 1)
    {
        cout << " NOTE Already exist" << endl;
    }
    else
    {
        gm.AddNomGM();
        gm.AddCoefGM();
        AddMat(mat, gm);
        GmTab.push_back(gm);
    }
}
void modifierGM(vector<GroupeModule> &GMTab, vector<Matiere> mat)
{
    gm.AddIdGM();
    float coef;
    string idgm, nomgm;
    vector<GroupeModule>::iterator i;
    vector<GroupeModule>::iterator pos;
    if (GMFound(GMTab, gm.IdGM) != 1)
    {
        cout << "Couln't find the Group Module" << endl;
    }
    else
    {
        for (i = GMTab.begin(); i < GMTab.end(); i++)
        {
            if (gm.IdGM == (*i).IdGM)
            {
                pos = i;
            }
        }
        cout << "IdGM : ";
        cin >> idgm;
        cout << "NomGM : ";
        cin >> nomgm;
        cout << "CoefGM : ";
        cin >> coef;
        (*pos).SetIdGM(idgm);
        (*pos).SetNomGM(nomgm);
        (*pos).SetCoefGM(coef);
        AddMat(mat, gm);
        (*pos).SetListMat(gm.ListeMat);
        modifierGmList(GMTab);
    }
}

void supprimerGM(vector<GroupeModule> &GMTab)
{
    gm.AddIdGM();
    vector<GroupeModule>::iterator i;
    vector<GroupeModule>::iterator pos;
    if (GMFound(GMTab, gm.IdGM) != 1)
    {
        cout << "Couln't find the student" << endl;
    }
    else
    {
        for (i = GMTab.begin(); i < GMTab.end(); i++)
        {
            if (gm.IdGM == (*i).IdGM)
            {
                pos = i;
            }
        }
        GMTab.erase(pos);
        modifierGmList(GMTab);
    }
}

void printGM(vector<GroupeModule> GMTab)
{
    vector<GroupeModule>::iterator i;

    for (i = GMTab.begin(); i < GMTab.end(); i++)
    {
        cout << (*i);
    }
}
