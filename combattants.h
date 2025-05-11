#ifndef COMBATTANTS_H
#define COMBATTANTS_H



typedef struct {
    char nom[50];
    char emoji[20];
    int pointvie;
    int pointvie_max;
    int attaque;
    int attaqueBase;
    int defense;
    int defenseBase;
    int agilite;
    int agiliteBase;
    int vitesse;
    // TechniqueSpeciale techniques[MAX_TECH];
    int nbTechniques;
    // EffetSpecial effets[MAX_EFFETS];
    int effetCompte; // nombre d'effets actifs
    int equipe; // 1 (joueur) ou 2 (IA)
}Combattant;

void attaqueNormale(Combattant attaquant, Combattant *pcible);
void gererCombatParEquipe(Combattant *equipeAttaque, char *nomEquipeAttaque, Combattant *equipeCible, char *nomEquipeCible, int nbCombattantsEquipe);
Combattant* choisirEquipe(Combattant* combattants, int nbCombattants, Combattant *equipe, int nbCombattantsEquipe);
void afficherCombattant(Combattant combattant);
Combattant* chargerCombattants(char *fileName, int nbCombattantsEquipe);

#endif
