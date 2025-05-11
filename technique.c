#include <stdio.h>
#include <stdlib.h>

#include "technique.h"
#include "combattants.h"

void coupEpeePuissant(Combattant attaquant, Combattant *pcible) {

    printf("Vous avez utilisé le coup d'épée puissant !\n");


}

void afficherTechnique(Technique technique) {
    printf("Nom: %s\n", technique.nom);
    printf("Description: %s\n", technique.description);
    printf("Vie effet: %d\n", technique.vieEffet);
    printf("Augmente attaque: %d\n", technique.augmenteAttaque);
    printf("Augmente defense: %d\n", technique.augmenteDefense);
    printf("Augmente agilite: %d\n", technique.augmenteAgilite);
    printf("Durée: %d\n", technique.duree);
    printf("Temps recharge: %d\n", technique.tempsRecharge);
    printf("Attente technique: %d\n", technique.attenteTech);
    printf("\n");
}


Technique* chargerTechniques(char *fileName, int nbTechniques) {
    FILE *fichier = fopen(fileName, "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s\n", fileName);
        return NULL;
    }

    Technique *techniques = malloc(nbTechniques * sizeof(Technique));
    if (techniques == NULL) {
        printf("Erreur d'allocation mémoire\n");
        fclose(fichier);
        return NULL;
    }

    for (int i = 0; i < nbTechniques; i++) {
        if (fscanf(fichier, "%19s", techniques[i].nom) != 1) break;  // Limite à 49 caractères (+1 pour '\0')
        if (fscanf(fichier, "%99s", techniques[i].description) != 1) break;
        if (fscanf(fichier, "%d", &techniques[i].vieEffet) != 1) break;
        if (fscanf(fichier, "%d", &techniques[i].augmenteAttaque) != 1) break;
        if (fscanf(fichier, "%d", &techniques[i].augmenteDefense) != 1) break;
        if (fscanf(fichier, "%d", &techniques[i].augmenteAgilite) != 1) break;
        if (fscanf(fichier, "%d", &techniques[i].duree) != 1) break;
        if (fscanf(fichier, "%d", &techniques[i].tempsRecharge) != 1) break;
        if (fscanf(fichier, "%d", &techniques[i].attenteTech) != 1) break;

        // Ignore la ligne vide après chaque combattant
        while (fgetc(fichier) != '\n' && !feof(fichier));
    }

    fclose(fichier);
    return techniques;
}