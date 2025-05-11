#ifndef TECHNIQUE_H
#define TECHNIQUE_H

typedef struct {
    char nom[20];
    char description[100];
    int vieEffet;      
    int augmenteAttaque;    
    int augmenteDefense;    
    int augmenteAgilite;    
    int duree;         
    int tempsRecharge; 
    int attenteTech;   
} Technique;  

void coupEpeePuissant();
void afficherTechnique(Technique technique);
Technique* chargerTechniques(char *fileName, int nbTechniques);

#endif