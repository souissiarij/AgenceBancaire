#include <stdio.h>
#include<stdlib.h>
#include"Bib.h"


int main() {
    int option;
    int nbcli=0, nbcmpte=0, nbtrans=0;
    CLIENT **cli;
    COMPTEBANCAIRE **cmp;
    TRANSACTION **trans;
    CLIENT** reallocclient;
    int x,a,ajout=0;

    do {
        printf("--------------------MENU PRINCIPAL-----------------\n");
        printf("Que voulez vous faire ?  \n");
        printf("tapez 1 pour effectuer un remplissage  \n");
        printf("tapez 2 pour effectuer une transaction \n");
        printf("tapez 3 afficher les informations des clients , comptes ou transactions \n ");
        printf("tapez 4 pour modifier les informations d'un client  \n");
        printf("taper 5 pour quitter \n");

        scanf("%d", &option);
        switch (option) {
            case 1:
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
                    case 4:
                        break;
                }
                break;
            case 3:
                printf("tapez 1 pour afficher le tableau des clients \n");
                printf("tapez 2 pour afficher le tableau des comptes \n");
                printf("tapez 3 pour afficher le tableau des transactions \n");
                printf("taper 4 pour revenir au menu principal \n");
                scanf("%d", &x);
                switch (x)
                {
                case 1:

                    if((nbcli+ajout)>0){
                        printf("\n**affichage du tableau clients**");
                        affichertabcli(cli,(nbcli+ajout));

                    }
                    else{
                        printf("\nvous n'avez  encore saisi aucun client");
                    }
                    break;
                
                case 2:
                    if((nbcmpte)>0){
                        printf("\n**affichage du tableau comptes**");
                        affichertabcli(cli,(nbcmpte));

                    }
                    else{
                        printf("\nvous n'avez  encore saisi aucun compte");
                    }
                    break;
                case 3:
                    if((nbtrans)>0){
                        printf("\n**affichage du tableau transactions**");
                        affichertabcli(cli,(nbtrans));
                    }
                    else{
                        printf("\nvous n'avez  encore saisi aucune transaction");
                    }
                    break;
                
                case 4 :
                break;  


                }
                
                break;
            case 4:
                printf("444\n");
                break;
        }

    } while (option != 5);

    printf("--------fin-----\n");

    return 0;
}
