#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "affichage.h"
#include "combattants.h"

#define NB_COMBATTANTS 8

int main() {
    srand(time(NULL)); // Initialisation de la graine pour rand()
    // Affichage de la bannière
    afficherCY();
    printf("\n\033[1;33mAppuyez sur Entrée pour afficher les règles du jeu...\n\033[0m");
    getchar(); 
    afficherRegles();

    // Message pour continuer
    printf("\n\033[1;33mAppuyez sur Entrée pour commencer à jouer...\n\033[0m");
    getchar();

    // Ici vous pouvez mettre la suite de votre jeu
    printf("\n\033[1;32m========================================\n");
    printf("|                                      |\n");
    printf("|    🎮  LE JEU COMMENCE !  🎮         |\n"); 
    printf("|                                      |\n");
    printf("========================================\033[0m\n\n");
    printf("Choisir le mode de jeu :\n");
    printf("1. Mode Solo\n");
    printf("2. Mode Multijoueur\n");

    int modeJeu;
    do {
        printf("Mode de jeu (1 solo, 2 multijoueur) : ");
        scanf("%d", &modeJeu);
    } while (modeJeu != 1 && modeJeu != 2);

    int nbCombattantsEquipe;
    do {
        printf("Combien de combattants par équipe ? (1 à 3) : ");
        scanf("%d", &nbCombattantsEquipe);
    } while (nbCombattantsEquipe < 1 || nbCombattantsEquipe > 3);

    // Afficher les combattants
    printf("\n\033[1;33mVoici les combattants disponibles :\n\033[0m");
    void afficherCombattants();

    // Charger les combattants
    Combattant* combattants = chargerCombattants("combattants.txt", NB_COMBATTANTS);

    // Afficher les combattants
    for (int i = 0; i < NB_COMBATTANTS; i++) {
        printf("num combattant %d \n", i + 1);
        afficherCombattant(combattants[i]);
    }

    // Choisir les combattants de l'équipe 1
    Combattant* equipe1 = malloc(nbCombattantsEquipe * sizeof(Combattant));
    for (int i = 0; i < nbCombattantsEquipe; i++) {
        printf("Choisissez le combattant %d : ", i + 1);
        int choixCombattant;
        scanf("%d", &choixCombattant);
        if (choixCombattant < 0 || choixCombattant >= NB_COMBATTANTS) {
            printf("Choix invalide, essayez à nouveau.\n");
            i--; // Répéter le choix
        } else {
            equipe1[i] = combattants[choixCombattant - 1];
            printf("Vous avez choisi le combattant %s\n", combattants[choixCombattant - 1].nom);
        }
    }

    for (int i = 0; i < nbCombattantsEquipe; i++) {
        printf("Combattant %d de l'équipe 1 :\n", i + 1);
        afficherCombattant(equipe1[i]);
    }

    // Choisir les combattants de l'équipe 2
    if (modeJeu == 1) {
        printf("\n\033[1;33mL'IA choisit ses combattants...\n\033[0m");
        Combattant* equipe2 = malloc(nbCombattantsEquipe * sizeof(Combattant));
        for (int i = 0; i < nbCombattantsEquipe; i++) {
            int choixIA = rand() % NB_COMBATTANTS;
            equipe2[i] = combattants[choixIA];
            printf("L'IA a choisi le combattant %s\n", combattants[choixIA].nom);
        }
    } else {
        printf("\n\033[1;33mChoisissez les combattants de l'équipe 2 :\n\033[0m");
        Combattant* equipe2 = malloc(nbCombattantsEquipe * sizeof(Combattant));
        for (int i = 0; i < nbCombattantsEquipe; i++) {
            printf("Choisissez le combattant %d : ", i + 1);
            int choixCombattant;
            scanf("%d", &choixCombattant);
            if (choixCombattant < 0 || choixCombattant >= NB_COMBATTANTS) {
                printf("Choix invalide, essayez à nouveau.\n");
                i--; // Répéter le choix
            } else {
                equipe2[i] = combattants[choixCombattant - 1];
                printf("Vous avez choisi le combattant %s\n", combattants[choixCombattant - 1].nom);
            }
        }
    }

    return 0;
}