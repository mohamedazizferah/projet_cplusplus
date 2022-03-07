#include "groupemodule.hpp"
#include "crud_matiere.hpp"
#pragma once

GroupeModule gm;

void remplirGM(vector<GroupeModule> &GMTab, vector<Matiere> matiere)
{
    string idgm, idgm2, nomgm, idmat;
    float coefgm;
    vector<Matiere> mat;
    unsigned int size = MatTab.size();
    ifstream fin("GM.txt");
    ifstream fin2("GmMats.txt");
    vector<Matiere>::iterator i, d, f;
    //     if (fin.is_open())
    //     {
    //         while (fin >> idgm >> nomgm >> coefgm)
    //         {
    //             newGM.SetIdGM(idgm);
    //             newGM.SetNomGM(nomgm);
    //             newGM.SetCoefGM(coefgm);
    //             if (fin2.is_open())
    //             {
    //                 while (fin2 >> idgm2 >> idmat)
    //                 {
    //                     mat.clear();
    //                     for (i = matiere.begin(); i < matiere.end(); i++)
    //                     {
    //                         if ((*i).IdMat == idmat && idgm2 == newGM.IdGM)
    //                         {
    //                             mat.push_back(*i);
    //                         }
    //                     }
    //                     newGM.SetListMat(mat);
    //                 }
    //             }
    //             // newGM.SetListMat(mat);
    //             GMTab.push_back(newGM);
    //         }
    //     }

    if (fin.is_open() && fin2.is_open())
    {
        while (fin >> idgm >> nomgm >> coefgm)
        {
            vector<Matiere> mmattab;
            GroupeModule newGM;
            newGM.SetIdGM(idgm);
            newGM.SetNomGM(nomgm);
            newGM.SetCoefGM(coefgm);

            while (fin2 >> idgm2 >> idmat)
            {

                d = matiere.begin();
                f = matiere.end();
                for (i = d; i < f; i++)
                {
                    if ((*i).IdMat == idmat && idgm2 == idgm)
                    {
                        mmattab.push_back(*i);
                    }
                }
            }
            newGM.SetListMat(mmattab);
            GMTab.push_back(newGM);
            fin2.clear();
            fin2.seekg(0);
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
    int found;
    int mats, iter;
    found = 0;
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
            found++;
            for (i = matiere.begin(); i < matiere.end(); i++)
            {
                if ((*i).IdMat == id)
                {
                    Gm.ListeMat.push_back(*i);
                }
            }
        }
    }
    if (found > 0)
    {
        enregistrerGM();
    }
}

void ajouterGM(vector<GroupeModule> &GmTab, vector<Matiere> mat)
{
    gm.AddIdGM();
    if (GMFound(GmTab, gm.IdGM) == 1)
    {
        cout << " Groupe Module Already exist" << endl;
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
        cout << "Couln't find the Groupe Module" << endl;
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

void AddMatInGM(vector<GroupeModule> &GMTab, vector<Matiere> mat)
{

    string id;
    int found;
    int mats, iter;
    found = 0;
    vector<GroupeModule>::iterator i;
    vector<GroupeModule>::iterator pos;
    vector<Matiere>::iterator j;
    gm.AddIdGM();
    if (GMFound(GMTab, gm.IdGM) != 1)
    {
        cout << " Groupe Module does not exist" << endl;
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
        cout << "IdMat : ";
        cin >> id;
        cin.ignore();
        if (MatiereFound(mat, id) == -1)
        {
            cout << " 404 NOT FOUND " << endl;
        }
        else
        {
            if (MatiereFound((*pos).ListeMat, id) == 1)
            {
                cout << " Subject already exists in your Groupe module " << endl;
            }
            else
            {
                found++;
                for (j = mat.begin(); j < mat.end(); j++)
                {
                    if ((*j).IdMat == id)
                    {
                        (*pos).ListeMat.push_back(*j);
                    }
                }
            }
        }
    }
    if (found > 0)
    {
        modifierGmList(GMTab);
    }
}

void DeleteMatFromGM(vector<GroupeModule> &GMTab)
{
    gm.AddIdGM();
    string id;
    vector<GroupeModule>::iterator i;
    vector<GroupeModule>::iterator pos;
    vector<Matiere>::iterator j;
    vector<Matiere>::iterator posMat;
    if (GMFound(GMTab, gm.IdGM) != 1)
    {
        cout << "Couln't find the Groupe Module" << endl;
    }
    else
    {
        cout << "IdMat : ";
        cin >> id;
        for (i = GMTab.begin(); i < GMTab.end(); i++)
        {
            if (gm.IdGM == (*i).IdGM)
            {
                pos = i;
            }
        }
        for (j = (*pos).ListeMat.begin(); j < (*pos).ListeMat.end(); j++)
        {
            if (id == (*j).IdMat)
            {
                posMat = j;
            }
        }
        (*pos).ListeMat.erase(posMat);
        modifierGmList(GMTab);
    }
}

void MatiereDunModule(vector<GroupeModule> &GMTab)
{
    string id;
    vector<GroupeModule>::iterator i;
    vector<GroupeModule>::iterator pos;
    vector<Matiere>::iterator j;
    cout << "IdGM : ";
    cin >> id;
    if (GMFound(GMTab, id) != 1)
    {
        cout << "Groupe Modules does not exist";
    }
    else
    {
        for (i = GMTab.begin(); i != GMTab.end(); i++)
        {
            if ((*i).IdGM == id)
            {
                pos = i;
            }
        }
        for (j = (*pos).ListeMat.begin(); j != (*pos).ListeMat.end(); j++)
        {
            cout << "nom matiere :" << (*j).NomMat << endl;
            cout << "coef matiere :" << (*j).Coef << endl;
            cout << "nom Enseignant :" << (*j).Ens.Nom << endl;
        }
    }
}
