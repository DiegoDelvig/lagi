#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "affichage.h"

#define RESET "\033[0m"
#define ROUGE "\033[1;31m"
#define BLEU "\033[1;34m"
#define CYAN "\033[1;36m"
#define JAUNE "\033[1;33m"
#define VERT "\033[1;32m"



void afficherBanniere(const char* titre) {
    printf("\n%s========================= %s =========================\n%s", BLEU, titre, RESET);
}


void afficherCY() {
     printf("\033[1;36m"); // Cyan clair
    printf("╔══════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                          ║\n");
    printf("║   ██████╗██╗   ██╗ ███████╗██╗ ██████╗██╗  ██╗████████╗███████╗██████╗   ║\n");
    printf("║  ██╔════╝╚██╗ ██╔╝██╔════╝██║██╔════╝██║  ██║╚══██╔══╝██╔════╝██╔══██╗   ║\n");
    printf("║  ██║      ╚████╔╝ █████╗  ██║██║     ███████║   ██║   █████╗  ██████╔╝   ║\n");
    printf("║  ██║       ╚██╔╝  ██╔══╝  ██║██║  ██║██╔══██║   ██║   ██╔══╝  ██╔══██╗   ║\n");
    printf("║  ╚██████╗   ██║   ██      ██║╚██████╗██║  ██║   ██║   ███████╗██║  ██║   ║\n");
    printf("║   ╚═════╝   ╚═╝   ╚═      ╚═╝ ╚═════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝   ║\n");
    printf("║                                                                          ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════╝\n");
   printf("\033[0m"); // Reset couleur

}

void afficherRegles(){
    // Titre des règles
    printf("\n\033[1;33m╔═══════════════════════════════════ 📜  RÈGLES DU JEU 📜 ═══════════════════════════╗\n");

    // Corps des règles avec un beau style et couleurs
    printf("\033[1;33m"); // Vert
    printf("║                                                                                    ║\n");
    printf("║    OBJECTIF :                                                                      ║\n");
    printf("║     → Éliminez tous les combattants de l'équipe ennemie.                           ║\n");
    printf("║                                                                                    ║\n");
    printf("║    ÉQUIPES :                                                                       ║\n");
    printf("║     → Chaque joueur choisit de 1 à 3 combattants.                                  ║\n");
    printf("║     → Chaque combattant a des statistiques uniques (attaque, vie, défense...).     ║\n");
    printf("║                                                                                    ║\n");
    printf("║ ⚔️ COMBAT TOUR PAR TOUR                                                             ║\n");
    printf("║     → L'ordre d'action dépend de la vitesse de chaque combattant.                  ║\n");
    printf("║     → Chaque tour, vous pouvez :                                                   ║\n");
    printf("║        1. Faire une attaque normale                                                ║\n");
    printf("║        2. Utiliser une technique spéciale                                          ║\n");
    printf("║                                                                                    ║\n");
    printf("║ 💥 TECHNIQUES SPÉCIALES :                                                          ║\n");
    printf("║     → Très puissantes, mais limitées par un temps d'attente.                       ║\n");
    printf("║     → Choisissez le bon moment pour les déclencher.                                ║\n");
    printf("║                                                                                    ║\n");
    printf("║ 🏆 VICTOIRE :                                                                      ║\n");
    printf("║     → L'équipe ayant au moins un combattant en vie remporte la partie !            ║\n");
    printf("║                                                                                    ║\n");
    printf("╚════════════════════════════════════════════════════════════════════════════════════╝\n");

    printf("\033[0m"); // Reset des couleurs
}


void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}


void afficherGameOver() {
    printf("\033[1;31m"); // Rouge clair

    printf("╔════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                                    ║\n");
    printf("║   ██████╗  █████╗ ███╗   ███╗███████╗     ██████╗ ██╗   ██╗███████╗██████╗         ║\n");
    printf("║  ██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ██╔═══██╗██║   ██║██╔════╝██╔══██╗        ║\n");
    printf("║  ██║  ███╗███████║██╔████╔██║█████╗      ██║   ██║██║   ██║█████╗  ██████╔╝        ║\n");
    printf("║  ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔═██║         ║\n");
    printf("║  ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ╚██████╔╝ ╚████╔╝ ███████╗██║ ██║         ║\n");
    printf("║   ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     ╚═════╝   ╚═══╝  ╚══════╝╚═╝ ╚═╝         ║\n");
    printf("║                                                                                    ║\n");
    printf("╚════════════════════════════════════════════════════════════════════════════════════╝\n");

    printf("\033[0m"); // Reset couleur
}
