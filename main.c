//cartouche//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <mmsystem.h>
#include "regle.h"
#include "jeu.h"
#include "Dessin bateau.h"
#include "jeu classic.h"

#pragma execution_charater_set("utf-8")
#define MENUDIFFICULTE 4
int converter(char intro[]){
    int conver;
    conver = atoi(intro);
    return conver;
}
int main() {
    system("color b");

    int choix, oui = 10, difficulte, bateau;
    char nomJoueur[50], casting[50];
    SetConsoleOutputCP(65001);
    BoatDraw();
    printf("Votre nom capitaine:");
    scanf("%s", nomJoueur);
    FILE *score;

    while (oui > 1) {
        system("color b");
        system("cls");
        printf("--------BATAILLE NAVALE MENU--------");

        printf("\n1. Jouer\n2. Aide\n3. Score\n4. Quitter");
        scanf("%s", casting);
        choix = atoi(casting);

        while ((choix > 4) || (choix < 1)) {
            system("cls");
            printf("--------BATAILLE NAVALE MENU--------");

            printf("\n1. Jouer\n2. Aide\n3. Score\n4. Quitter");

            scanf("%s", casting);
            choix = atoi(casting);


        }

        switch (choix) {

            case 1 :
                system("cls");
                printf("Choisissez votre mode:\n");
                printf("1.Bataille Navalle classic\n2.Bataille Navalle Evenement soliste\n3.Retour");
                scanf("%s", casting);
                choix = atoi(casting);

                while ((choix > 3) || (choix < 1)) {
                    system("cls");
                    printf("--------BATAILLE NAVALE MENU--------");

                    printf("Choisissez votre mode:\n");
                    printf("1.Bataille Navalle classic\n2.Bataille Navalle Evenement soliste\n3.Retour");

                    scanf("%s", casting);
                    choix = atoi(casting);
                    system("cls");
                }
                switch (choix) {
                    case 1:
                        printf("Choisir le niveau de difficulté:\n");
                        printf("1.Difficile\n2.Moyen\n3.Facile\n4.Entrainement\n0.quitter");
                        scanf("%d", &choix);
                        while (choix > MENUDIFFICULTE) {
                            printf("Cette option n'existe pas\nréessayer");
                            scanf("%d", &choix);
                        }
                        if (choix == 1) {
                            difficulte = 3;

                        } else {
                            if (choix == 2) {
                                difficulte = 35;
                            } else {
                                if (choix == 3) {
                                    difficulte = 60;
                                } else {
                                    difficulte = 100;
                                }
                            }
                        }
                        system("cls");
                        if (choix > 0) {
                            jeuClasic(difficulte);
                        }

                        system("pause");
                        break;
                    case 2:
                        printf("Choisir le niveau de difficulté:\n");
                        printf("1.Difficile\n2.Moyen\n3.Facile\n4.Entrainement\n0.quitter");
                        scanf("%d", &choix);
                        while (choix > MENUDIFFICULTE) {
                            printf("Cette option n'existe pas\nréessayer");
                            scanf("%d", &choix);
                        }
                        if (choix == 1) {
                            difficulte = 3;
                            bateau = 2;
                        } else {
                            if (choix == 2) {
                                difficulte = 40;
                                bateau = 20;
                            } else {
                                if (choix == 3) {
                                    difficulte = 60;
                                    bateau = 25;
                                } else {
                                    difficulte = 100;
                                    bateau = 28;
                                }
                            }
                        }
                        system("cls");
                        if (choix > 0) {
                            jeu(difficulte, bateau);
                        }


                        system("cls");
                        break;
                    default:

                        break;
                }


                break;
            case 2 :
                reglement();

                break;
            case 3:
                score = fopen("P:\\Bataille nav officiel\\Bnav\\score.txt", "w");


                fprintf(score, "%s %s", "nom:", &nomJoueur);
                fclose(score);

                break;
            default :
                printf("vous voulez vraiment quitter le jeu?\n 1.oui autre.non");
                scanf("%d", &oui);
                if (oui == 1) {
                    return 0;
                }
                break;

        }

    }

}