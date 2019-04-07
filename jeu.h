//
// Created by Christnovie.KIALA-BI on 20.03.2019.
//

#ifndef UNTITLED2_JEU_H
#define UNTITLED2_JEU_H

#endif //UNTITLED2_JEU_H
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <mmsystem.h>
#pragma  execution_charater_set("utf-8")

#define GRILLESIZE 10

int tryAgain(int nbintro){
	while(nbintro > GRILLESIZE){
		printf("erreur valeur max est de %d",GRILLESIZE);
		printf("\nreintroduser la valeur: ");
		scanf("%d",&nbintro);
	}
	return nbintro;
}

 void jeu(int niveau,int nbBateau) {
system("color db");
    SetConsoleOutputCP(65001);
    int Zero = 0;
     int quitter ,lign,col,a = 0,i = 0,nbrand1,nbrand2,placeV,placeH,num,nbcoup;
     int grille[GRILLESIZE][GRILLESIZE];
     for (lign = 0;lign < GRILLESIZE;lign++){
         for(col = 0;col < GRILLESIZE;col++){
             grille[lign][col]=Zero;
         }
     }

     char grile[GRILLESIZE][GRILLESIZE];
     for (lign = 0;lign < GRILLESIZE;lign++){
         for(col = 0;col < GRILLESIZE;col++){
             grile[lign][col]=*"-";
         }
     }

    srand( (unsigned)time( NULL ) );



    for (i = 0; i < nbBateau ; i++) {
        nbrand1 =  rand() % 10;

        nbrand2 =  rand() % 10;

        grille[nbrand1][nbrand2] = 1;


    }
    if(niveau < 100){
        nbcoup = niveau;
    } else{
        nbcoup = 100;
    }

    printf("il y a au totale:%d\n",nbBateau);
    printf("Bonne chance\n\n");
    system("pause");
    system("cls");
    
    do {
    	placeV=0;
		placeH=0;
		num = 1;
        
        quitter = 0;
        printf("bateau restant:%d\n",nbBateau);
        printf("   coup restant: %d\n",nbcoup);
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
        tryAgain(lign);
        printf("\nEntrer la colone:");
        scanf("%d", &col);
        tryAgain(col);
        col = col - 1;
        lign = lign - 1;


        while (grille[lign][col] == 6) {
            printf("La case a deja ete selectioner");
            printf("Try Again\n");
            printf("\nEntrer  la ligne:");
            scanf("%d", &lign);
            tryAgain(lign);
            printf("\nEntrer la colone:");
            scanf("%d", &col);
            tryAgain(col);
            col = col - 1;
            lign = lign - 1;
        }

        if (col == -1 && lign == -1) {
            quitter = 1;
        } else {
            if (grille[lign][col] == 1) {
                printf("Toucher\n");
                system("pause");
                grile[lign][col] = *"O";
                grille[lign][col] = 6;
                nbBateau--;
            } else {
                printf("Rater\n");
                system("pause");
                grille[lign][col] = 6;
                grile[lign][col] = *"X";
            }


        }
        system("cls");
        if(nbcoup == 100){
        }else{
            nbcoup--;}

    }
    while ((quitter != 1) && (nbcoup != 0) && (nbBateau != 0) && (nbcoup >= nbBateau));

    if(nbcoup==0 || nbcoup < nbBateau){
        printf("Partie perdu\n");

    } else{
        if(nbBateau == 0){
            printf("Bravo partie gagné\n");
        }
    }
   system("pause");
}
