#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "combattants.h"

#define MAX_NOM 50

void afficherCombattant(Combattant combattant) {
    printf("Nom: %s\n", combattant.nom);
    printf("Emoji: %s\n", combattant.emoji);
    printf("VieMax: %d\n", combattant.pointvie_max);
    printf("Vie: %d\n", combattant.pointvie);
    printf("Attaque: %d\n", combattant.attaque);
    printf("Defense: %d\n", combattant.defense);
    printf("Agilite: %d\n", combattant.agilite);
    printf("Vitesse: %d\n", combattant.vitesse);
    printf("NbTechniques: %d\n", combattant.nbTechniques);
    printf("\n");
}

Combattant* chargerCombattants(char *fileName, int nbCombattants) {
    FILE *fichier = fopen(fileName, "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s\n", fileName);
        return NULL;
    }

    Combattant *combattants = malloc(nbCombattants * sizeof(Combattant));
    if (combattants == NULL) {
        printf("Erreur d'allocation mémoire\n");
        fclose(fichier);
        return NULL;
    }

    for (int i = 0; i < nbCombattants; i++) {
        if (fscanf(fichier, "%49s", combattants[i].nom) != 1) break;  // Limite à 49 caractères (+1 pour '\0')
        if (fscanf(fichier, "%49s", combattants[i].emoji) != 1) break; // Même chose pour emoji
        if (fscanf(fichier, "%d", &combattants[i].pointvie_max) != 1) break;
        if (fscanf(fichier, "%d", &combattants[i].pointvie) != 1) break;
        if (fscanf(fichier, "%d", &combattants[i].attaque) != 1) break;
        if (fscanf(fichier, "%d", &combattants[i].defense) != 1) break;
        if (fscanf(fichier, "%d", &combattants[i].agilite) != 1) break;
        if (fscanf(fichier, "%d", &combattants[i].vitesse) != 1) break;
        if (fscanf(fichier, "%d", &combattants[i].nbTechniques) != 1) break;

        // Ignore la ligne vide après chaque combattant
        while (fgetc(fichier) != '\n' && !feof(fichier));
    }

    fclose(fichier);
    return combattants;
}