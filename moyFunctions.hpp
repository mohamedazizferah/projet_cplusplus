#include "crud_note.hpp"
#pragma once
float calcMoyMat(vector<NOTE> note, string id, vector<Etudiant> et)
{
    float res = 0;
    float resFInal;
    int nbStuds = 0;
    vector<NOTE>::iterator i;
    vector<Etudiant>::iterator j;
    for (i = note.begin(); i != note.end(); i++)
    {
        for (j = et.begin(); j != et.end(); j++)
        {
            if ((*i).Mat.IdMat == id && (*i).Etu.Id == (*j).Id)
            {
                nbStuds++;
                res = res + (*i).Note;
            }
        }
    }
    resFInal = res / nbStuds;
    return resFInal;
}

float CalcmoyOneMat(vector<NOTE> note, string idMatiere, int idEtudiant)
{
    float res = 0;
    float resFInal;
    int nbSNots = 0;
    vector<NOTE>::iterator i;
    for (i = note.begin(); i != note.end(); i++)
    {
        if ((*i).Mat.IdMat == idMatiere && (*i).Etu.Id == idEtudiant)
        {
            nbSNots++;
            res = res + (*i).Note;
        }
    }
    resFInal = res / nbSNots;
    return resFInal;
}