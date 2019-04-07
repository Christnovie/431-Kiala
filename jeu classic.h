//
// Created by Christnovie.KIALA-BI on 22.03.2019.
//

#ifndef UNTITLED2_JEU_CLASSIC_H
#define UNTITLED2_JEU_CLASSIC_H

#endif //UNTITLED2_JEU_CLASSIC_H
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <mmsystem.h>
#pragma  execution_charater_set("utf-8")
#define BATEAUX5 5
#define BATEAUX4 4
#define BATEAUX3 3
#define BATEAUX2 2


#define GRILLESIZE 10

int tryAgains(int nbintro){
    while(nbintro > GRILLESIZE){
        printf("erreur valeur max est de %d",GRILLESIZE);
        printf("\nreintroduser la valeur: ");
        scanf("%d",&nbintro);
    }
    return nbintro;
}

void jeuClasic (int niveau) {
    system("color ");
    SetConsoleOutputCP(65001);
    int Zero = 0,vivant = 1;
    // initialization du tableau//
    int b5[BATEAUX5];
    int b4[BATEAUX4];
    int b3[BATEAUX3];
    int b2[BATEAUX2];
    int b22[BATEAUX2];

   int bateaux;
    int quitter ,lign,col,a,i,nbrand1,nbrand2,nbacrement = 0,placement,placeV,placeH,num;
    int nbcoup,choixMode,couler,batvie;
    int verif1,verif2;
    int nbvide,nbbateaux;
    int grille[GRILLESIZE][GRILLESIZE];
//initailisation du grille d'affichage//
    char grile[GRILLESIZE][GRILLESIZE];
    for (lign = 0;lign < GRILLESIZE;lign++){
        for(col = 0;col < GRILLESIZE;col++){
            grile[lign][col]=*"-";
        }
    }


    //création de la grille//
    do {
        //inizialisation des grille et proprieté de fonction//
        srand((unsigned) time(NULL));
        nbbateaux = 0;
        nbvide = 0;
        batvie = 2;
        bateaux = 2;
        for (lign = 0;lign < GRILLESIZE;lign++){
            for(col = 0;col < GRILLESIZE;col++){
                grille[lign][col]=Zero;
            }
        }
       // printf("col:%d  lign:%d nbvide:%d nbbateaux:%d",col,lign,nbvide,nbbateaux);

        nbrand1 = rand() % 9;
        nbrand2 = rand() % 9;
        placement = 1 + rand() % 2;
        placeH = nbrand1;
        placeV = nbrand2;


        if (placement == 1) {
            for (i = 0; i < BATEAUX2; i++) {
                grille[placeH][placeV] = batvie;
                placeH++;
            }

        } else {
            for (i = 0; i < BATEAUX2; i++) {
                grille[placeH][placeV] = batvie;
                placeV++;
            }
        }


//placement de bateau//


        for (a =0;a < 4;a++) {

            nbrand1 = rand() % 9;
            nbrand2 = rand() % 9;
            placement = 1 + rand() % 2;



            if (placement == 1) {
                for (i = 0; i < bateaux; i++) {
                    if (nbrand2 < 10) {
                        grille[nbrand1][nbrand2] = batvie;
                        nbrand2++;
                    }
                }

            } else {
                for (i = 0; i < bateaux; i++) {
                    if(nbrand1 < 10) {
                        grille[nbrand1][nbrand2] = batvie;
                        nbrand1++;
                    }

                }
            }
            bateaux++;
            batvie++;
        }
        //verification de la valeur de la case s'il y a un vie ou pas//
        for(a = 0;a< GRILLESIZE;a++){
            for(i = 0;i< GRILLESIZE;i++){
                if(grille[a][i]>Zero){
                    nbbateaux++;
                } else{
                    nbvide++;
                }
            }
        }

    }while (nbbateaux != 16);


//Choix de mode//
    system("cls");
    printf("Choisir le mode:\n1.Mode score\n2.Mode coup restant\n0.quitter");
    scanf("%d",&choixMode);

if(choixMode == 2){
    nbcoup = niveau;} else{
    if (choixMode < 2){
    nbcoup = 0;} else {
    }
}
//La boucle du jeu :affichage bateaux,sffichage score ,donnée du jeu ,tires, touché et raté,couler//
if(choixMode !=0) {
    do {
        placeV = 0;
        placeH = 0;
        num = 1;

        quitter = 0;
        printf("   coup restant: %d\n", nbcoup);
        printf("\n  1 2 3 4 5 6 7 8 9 10\n ");
        printf("_______________________\n ");
        for (a = 0; a < GRILLESIZE; a++) {
            printf("|");
            for (i = 0; i < GRILLESIZE; i++) {

                printf("%c|", grile[placeH][placeV]);

                placeV++;
            }
            printf("|%d\n ", num);

            num++;
        }
        printf("------------------------");
        printf("\n(entrer deux fois 0 de la grile  pour quitter)");
        printf("\nEntrer  la ligne:");
        scanf("%d", &lign);
        if(lign > GRILLESIZE){
            lign= tryAgains(lign);
        }
        printf("\nEntrer la colone:");
        scanf("%d", &col);
        if(col > GRILLESIZE){

            col = tryAgains(col);
        }
        col = col - 1;
        lign = lign - 1;


        while (grille[lign][col] == 2) {
            printf("La case a deja ete selectioner");
            printf("Try Again\n");
            printf("\nEntrer  la ligne:");
            scanf("%d", &lign);
            if(lign > GRILLESIZE){
                lign= tryAgains(lign);
            }
            printf("\nEntrer la colone:");
            scanf("%d", &col);
            if(col > GRILLESIZE){

                col = tryAgains(col);
            }
            col = col - 1;
            lign = lign - 1;
        }

        if (col == -1 && lign == -1) {
            quitter = 1;
        } else {
            if ((grille[lign][col] > 0)) {
                printf("Toucher\n");
                system("pause");
                grile[lign][col] = *"O";
                grille[lign][col] = 6;
                if((b5[0]==2)&&(b5[1]==2)&&(b5[2]==2)&&(b5[3]==2)&&(b5[4] == 2)){
                    printf("couler");
                    couler++;
                    nbbateaux--;
                }

            } else {
                printf("Rater\n");
                system("pause");
                grille[lign][col] = 2;
                grile[lign][col] = *"X";
            }


        }

        system("cls");
        if(choixMode == 1){
            nbcoup++;
        }else{
        nbcoup--;}
    } while ((quitter != 1) && (nbcoup != 0) && (nbbateaux != 0));

    if(nbcoup==0){
        printf("Partie perdu\n");

    } else{
        if(couler == 5){
            printf("Bravo partie gagné\n");
        }
    }
}


}

