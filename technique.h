#ifndef COMBATTANTS_H
#define COMBATTANTS_H

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
} TechniqueSpeciale;  

#endif