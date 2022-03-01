#include "Enseignant.hpp"

Enseignant Ens;
vector<Enseignant> En;

void remplirEnseignant(vector<Enseignant> &En)
{
    int id;
    string nom;
    string prenom;
    string mail;
    int cnss;
    Enseignant newStudent(id, nom, prenom, mail, cnss);
    unsigned int size = En.size();
    ifstream fin("Enseignant.txt");
    if (fin.is_open())
    {
        cout << "File open" << endl;
        while (fin >> id >> nom >> prenom >> mail >> cnss)
        {
            newStudent.setId(id);
            newStudent.setNom(nom);
            newStudent.setPrenom(prenom);
            newStudent.setMail(mail);
            newStudent.SetCNSS(cnss);
            En.push_back(newStudent);
        }
    }
}

int EnseignantFound(vector<Enseignant> En, int Id)
{
    vector<Enseignant>::iterator i;

    for (i = En.begin(); i < En.end(); i++)
    {
        if ((*i).Id == Id)
        {
            return 1;
        }
    }
    return -1;
}

void enregistrerEn()
{
    fstream fout("Enseignant.txt", ios::app);

    fout << Ens.Id << " "
         << Ens.Nom << " "
         << Ens.Prenom << " "
         << Ens.Mail << " "
         << Ens.CNSS << endl;
}
void modifierEn(vector<Enseignant> En)
{
    ofstream file;
    file.open("Enseignant.txt");
    vector<Enseignant>::iterator i;
    for (i = En.begin(); i < En.end(); ++i)
    {
        file << (*i).Id << " " << (*i).Nom << " " << (*i).Prenom << " " << (*i).Mail << " " << (*i).CNSS << endl;
    }
    file.close();
}

void ajoutEnseignant(vector<Enseignant> &En)
{
    int nbEnseignant = En.size();
    Ens.AddId();
    if (EnseignantFound(En, Ens.Id) == 1)
    {
        cout << " ID Already exist" << endl;
    }
    else
    {
        Ens.AddNom();
        Ens.AddPrenom();
        Ens.AddMail();
        Ens.AddCNSS();
        En.push_back(Ens);
        cout << "successfully added " << endl;
        enregistrerEn();
    }
}

void modifierEnseignant(vector<Enseignant> &En)
{
    Ens.AddId();
    int id, cnss;
    string nom, prenom, mail;
    vector<Enseignant>::iterator i;
    vector<Enseignant>::iterator pos;
    if (EnseignantFound(En, Ens.Id) != 1)
    {
        cout << "Couln't find the student" << endl;
    }
    else
    {
        for (i = En.begin(); i < En.end(); i++)
        {
            if (Ens.Id == (*i).Id)
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
        cout << "CNSS : ";
        cin >> cnss;
        (*pos).setId(id);
        (*pos).setNom(nom);
        (*pos).setPrenom(prenom);
        (*pos).setMail(mail);
        (*pos).SetCNSS(cnss);
        modifierEn(En);
    }
}

void supprimerEnseignant(vector<Enseignant> &En)
{
    Ens.AddId();
    vector<Enseignant>::iterator i;
    vector<Enseignant>::iterator pos;
    if (EnseignantFound(En, Ens.Id) != 1)
    {
        cout << "Couln't find the student" << endl;
    }
    else
    {
        for (i = En.begin(); i < En.end(); i++)
        {
            if (Ens.Id == (*i).Id)
            {
                pos = i;
            }
        }
        En.erase(pos);
        modifierEn(En);
    }
}

void printAllTeachers(vector<Enseignant> En)
{
    vector<Enseignant>::iterator i;
    for (i = En.begin(); i != En.end(); i++)
    {
        cout << (*i);
    }
}