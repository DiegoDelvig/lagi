#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "combattants.h"
#include "technique.h"

#define MAX_NOM 50
#define NB_TECHNIQUES 5

void attaqueNormale(Combattant attaquant, Combattant *pcible) {

    int degats = attaquant.attaque * (1 - (*pcible).defense/100.0);

    if ((*pcible).agilite > rand() % 100) {
        // L'attaque est esquivée
        printf("%s a esquivé l'attaque de %s !\n", (*pcible).nom, attaquant.nom);
        degats = 0;
    }

    (*pcible).pointvie -= degats;
    
    printf("%s attaque %s et inflige %d dégâts !\n", attaquant.nom, (*pcible).nom, degats);
    printf("%s a maintenant %d points de vie.\n", (*pcible).nom, (*pcible).pointvie);
}

void gererCombatParEquipe(Combattant *equipeAttaque, char *nomEquipeAttaque, Combattant *equipeCible, char *nomEquipeCible, int nbCombattantsEquipe) {
    printf("\n\033[1;33mC'est au tour de l'équipe %s...\n\033[0m", nomEquipeAttaque);

    for (int i = 0; i < nbCombattantsEquipe; i++) {
        printf("%s de l'équipe %s : \n", equipeAttaque[i].nom, nomEquipeAttaque);

        printf("Quel attaque voulez-vous faire ?\n");
        printf("1. Attaque normale\n");
        printf("2. Technique spéciale\n");

        int choixAttaque;
        do {
            printf("Choix d'attaque (1 ou 2) : ");
            scanf("%d", &choixAttaque);
        } while (choixAttaque != 1 && choixAttaque != 2);

        if (choixAttaque == 1) {
            printf("Vous avez choisi l'attaque normale ! \n");
            // Logique de l'attaque normale ici
            int numCible;

            
            printf("EQUIPE %s :\n", nomEquipeCible);
            for (int j = 0; j < nbCombattantsEquipe; j++) {
                printf("%d: %s\n",j+1, equipeCible[j].nom);
            }
            
            printf("Choisissez le combattant de l'équipe 2 à attaquer (1 à %d) : ", nbCombattantsEquipe);
            scanf("%d", &numCible);
            attaqueNormale(equipeAttaque[i], &equipeCible[numCible - 1]);
            afficherCombattant(equipeCible[numCible - 1]);

        } else if (choixAttaque == 2) {
            printf("Vous avez choisi la technique spéciale ! \n");
            // Logique de la technique spéciale ici
            Technique *techniques = chargerTechniques("techniquespeciales.txt", NB_TECHNIQUES);

            for (int j = 0; j < NB_TECHNIQUES; j++) {
                printf("%d. \n", j + 1);
                afficherTechnique(techniques[j]);
            }

            int choixTechnique;
            do {
                printf("Choix de la technique spéciale (1 à %d) : ", NB_TECHNIQUES);
                scanf("%d", &choixTechnique);
            } while (choixTechnique < 1 || choixTechnique > NB_TECHNIQUES);

            switch(choixTechnique) {
                case 1:
                    // Appliquer la technique spéciale 1
                    printf("Vous avez utilisé la technique :  %s!\n", techniques[0].nom);
                    coupEpeePuissant();
                    break;
                case 2:
                    // Appliquer la technique spéciale 2
                    printf("Vous avez utilisé la technique :  %s!\n", techniques[1].nom);
                    break;
                case 3:
                    // Appliquer la technique spéciale 3
                    printf("Vous avez utilisé la technique :  %s!\n", techniques[2].nom);
                    break;
                case 4:
                    // Appliquer la technique spéciale 4
                    printf("Vous avez utilisé la technique :  %s!\n", techniques[3].nom);
                    break;
                case 5:
                    // Appliquer la technique spéciale 5
                    printf("Vous avez utilisé la technique :  %s!\n", techniques[4].nom);
                    break;
            }

            
        } else {
            printf("Choix invalide, essayez à nouveau.\n");
            i--; // Répéter le tour
        }
    }

}

Combattant* choisirEquipe(Combattant* combattants, int nbCombattants, Combattant *equipe, int nbCombattantsEquipe) {
    for (int i = 0; i < nbCombattantsEquipe; i++) {
        printf("Choisissez le combattant %d : ", i + 1);
        int choixCombattant;
        scanf("%d", &choixCombattant);
        if (choixCombattant < 0 || choixCombattant >= nbCombattants) {
            printf("Choix invalide, essayez à nouveau.\n");
            i--; // Répéter le choix
        } else {
            equipe[i] = combattants[choixCombattant - 1];
            printf("Vous avez choisi le combattant %s\n", combattants[choixCombattant - 1].nom);
        }
    }

    return equipe;
}

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