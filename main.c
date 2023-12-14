#include <stdio.h>
#include<stdlib.h>
#include"Bib.h"


int main() {
    //variables de commutation
    int option,x,a,y;
    //tailles des tableaux initialisés a zero au ca ou l'utilisateur n'a pas saisie d'informations 
    int nbcli=0, nbcmpte=0, nbtrans=0;
    //tableaux dynamiques d'adresses des structures   
    CLIENT **cli;
    COMPTEBANCAIRE **cmp;
    TRANSACTION **trans;
    CLIENT** reallocclient;
    //nombre des clients a ajouter si l'utilisateur souhite ajouter des clients
    int ajout=0;
    TRANSACTION nouvelletranstaction;
     // Déclaration d'un tableau dynamique d'adresses de RESULTAT
    RESULTAT ** tableauResultats;
    int nbResultats = 0; // Nombre initial d'éléments dans le tableau
    int capaciteResultats = 5; // Capacité initiale du tableau
    tableauResultats = (RESULTAT **)malloc(capaciteResultats * sizeof(RESULTAT *));
    int x,a,ajout=0;


    do {
        printf("\n--------------------MENU PRINCIPAL-----------------\n");
        printf("Que voulez vous faire ?  \n");
        printf("tapez 1 pour effectuer un remplissage  \n");
        printf("tapez 2 afficher les informations des clients , comptes ou transactions \n ");
        printf("tapez 3 pour modifier les informations d'un client  \n");
        printf("tapez 4 pour pour effectuer une transaction \n");
        printf("taper 5 pour quitter \n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                do{
                    printf("tapez 1 pour remplir le tableau des clients \n");
                    printf("tapez 2 pour remplir le tableau des comptes \n");
                    printf("tapez 3 pour remplir le tableau des transactions \n");
                    printf("taper 4 pour revenir au menu principal \n");
                    scanf("%d", &x);
                    switch (x) {
                        case 1:
                            printf("donner le nombre des clients");
                            scanf("%d", &nbcli);
                            // allocation de memoire
                            allouerclient(&cli, nbcli);
                            // remplissage tableau
                            printf("**remplissage du tableau**\n");
                            remplirtabcli(&cli, nbcli);
                            printf("\nvoulez vous ajoutez des clients au tableau? :tapez 1 pou oui 2 pour non");
                            scanf("%d",&a);
                            switch(a){
                                case 1:
                                printf("\ncombien de cases voulez vous ajoutez?");
                                scanf("%d",&ajout);
                                realloclient(&cli,nbcli,ajout);
                                tabcliajout(&cli,nbcli,ajout);
                                break;
                                case 2:
                                break;
                            }
                            break;
                        case 2:
                            printf("donner le nombre des comptes ");
                            scanf("%d", &nbcmpte);
                            // allocation de memoire
                            allouercompte(&cmp, nbcmpte);
                            // remplissage tableau
                            printf("**remplissage du tableau**\n");
                            remplirtabcomptes(&cmp, nbcmpte);
                            break;
                        case 3:
                            printf("donner le nombre des transactions ");
                            scanf("%d", &nbtrans);
                            // allocation de memoire
                            allouertransaction(&trans, nbtrans);
                           // remplissage tableau
                            printf("**remplissage du tableau**\n");
                            remplirtabtrans(&trans, nbtrans);
                            break;
                    }                   
                }while(x!=4); 
                break;         
            case 2:
                printf("tapez 1 pour afficher le tableau des clients \n");
                printf("tapez 2 pour afficher le tableau des comptes \n");
                printf("tapez 3 pour afficher le tableau des transactions \n");
                printf("taper 4 pour revenir au menu principal \n");
                scanf("%d", &y);
                switch (y)
                {
                case 1:
             //verifier que le tableau des clients n'est pas vide
                    if((nbcli+ajout)>0){
                        printf("\n**affichage du tableau clients**");
                        affichertabcli(cli,(nbcli+ajout));

                    }
                    else{
                        printf("\nvous n'avez  encore saisi aucun client");
                    }
                    break;
                
                case 2:
                //verifier que le tableau des comptes n'est pas vide
                    if((nbcmpte)>0){
                        printf("\n**affichage du tableau comptes**");
                        affichertabcomptes(cmp,(nbcmpte));

                    }
                    else{
                        printf("\nvous n'avez  encore saisi aucun compte");
                    }
                    break;
                case 3:
                //verifier que le tableau des transactions n'est pas vide
                    if((nbtrans)>0){
                        printf("\n**affichage du tableau transactions**");
                        affichertabtrans(trans,(nbtrans));
                    }
                    else{
                        printf("\nvous n'avez  encore saisi aucune transaction");
                    }
                    break;                                
                case 4 :
                break;  
                }                
                break;
            case 3:
            //verifie que le tableau des clients n'est pas vide
                if((nbcli+ajout)>0){
                    modifclient(&cli,(nbcli+ajout));
                }
                else{
                    printf("\nvous n'avez  encore saisi aucun client");
                }
                break; 
            case 4:
                effectuertransaction(&nouvelletranstaction);
        }
    } while (option != 5);
    printf("\n------Fin------");
    return 0;
}
