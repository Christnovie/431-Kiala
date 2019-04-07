//
// Created by Christnovie.KIALA-BI on 15.03.2019.
//

#ifndef UNTITLED2_REGLE_H
#define UNTITLED2_REGLE_H

#endif //UNTITLED2_REGLE_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <mmsystem.h>
void reglement(){

    int choix;
    system("cls");
    printf("__________AIDE___________\n");
    printf("Quelle aide voulez vous ?\n");
    printf("1.reglement \n 2.Jouabilité \n3.Quitter");
    scanf("%d", &choix);
    while (choix != 3){

        switch (choix) {
            case 1:
                printf("_____REGLEMENT______\n");
                printf("1.Le but du jeu est de couler tous les bateaux de l’adversaire. Pour cela, vous devez essayer de « tirer » sur ses navires en devinant leurs positions. Pour tirer, il faut citer les coordonnées d’un emplacement comprenant un chiffre de ligne et un chiffre de cologne. Par exemple : ligne 1 et cologne 5. Si le bateau se trouve à cette position alors il est touché si no c'est raté et vous pouvez rejouer Pour couler le navire, il faut le toucher entièrement. C’est-à-dire qu’un bateau prenant 5 cases doit être atteint en ses 5 cases pour être coulé.Il faut chavirer tous les navires pour gagner gagné.  ");
                system("pause");
                break;
            case 2:
                printf("_____JOUABILITE______\n");
                printf("1.Pour selectioner une option sevez-vous des chiffre et pas des lettres. \n2.Pour selectioner une case dans la grille entre la ligne au quel il se trouve en suite la cologne.\n");
                system("pause");
                break;
            default:
                break;

        }
        printf("Quelle aide voulez vous ?\n");
        printf("1.reglement \n 2.Jouabilité \n3.Quitter");
        scanf("%d", &choix);

    }

}

