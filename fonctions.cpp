#include"Bib.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void creerclient(CLIENT* nouveauClient) {
    printf("Saisir les informations du client :\n");
    printf("\nNom : ");
    scanf("%s", nouveauClient->nom);
    printf("\nPrenom : ");
    scanf("%s", nouveauClient->prenom);
    printf("\nNumero de telephone : ");
    estunnombrevalide(&nouveauClient->numtel);
    printf("\nNumero de CIN : ");
    scanf("%d",&nouveauClient->numcin);
    printf("\nNumero de compte : ");
    scanf("%d", &nouveauClient->numcompte);
}
void creercompte(COMPTEBANCAIRE* nouveauCompte) {
    nouveauCompte->client = (CLIENT*)malloc(sizeof(CLIENT));
    if(!nouveauCompte) exit(-1);
    printf("saisir les info du compte\n");
    creerclient(nouveauCompte->client);
    printf("\nSolde du compte : ");
    scanf("%lf", &nouveauCompte->solde);
}
void effectuertransaction(TRANSACTION* nouvelleTransaction) {
    printf("\nMontant de la transaction : ");
    scanf("%lf", &nouvelleTransaction->montant);

    printf("\nType de transaction (retrait, depot) : ");
    scanf("%s",&nouvelleTransaction->type);
    nouvelleTransaction->date = (DATE*)malloc(sizeof(DATE));
    if(!nouvelleTransaction->date) exit(-10);
    printf("\nDate de la transaction : ");
    printf("jour:");
    scanf("%d",&nouvelleTransaction->date->jour);
    printf("mois:");
    scanf("%d",&nouvelleTransaction->date->mois);
    printf("annee:");
    scanf("%d",&nouvelleTransaction->date->annee);
    printf("\nNumero unique de la transaction : ");
    scanf("%d", &nouvelleTransaction->numeroTransaction);

    nouvelleTransaction->compte = (COMPTEBANCAIRE*)malloc(sizeof(COMPTEBANCAIRE));

    if (!nouvelleTransaction) exit(-2);

    creercompte(nouvelleTransaction->compte);
}
void afficherclient(CLIENT client) {
    printf("\nInformations du client :\n");
    printf("Nom : %s\n", client.nom);
    printf("Prenom : %s\n", client.prenom);
    printf("Numero de téléphone : %d\n", client.numtel);
    printf("Numero de CIN : %d\n", client.numcin);
    printf("Numero de compte : %d\n", client.numcompte);
}
void affichercompte(COMPTEBANCAIRE compte) {
    printf("\nInformations du compte bancaire :\n");
    printf("Solde du compte : %.2lf\n", compte.solde);
    afficherclient(*(compte.client)); 
}
void affichertransaction(TRANSACTION transaction) {
    printf("\nInformations de la transaction :\n");
    printf("Montant de la transaction : %.2lf\n", transaction.montant);
    printf("Type de transaction : %s\n", transaction.type);
    printf("Date de la transaction : %d/%d/%d\n",(transaction.date)->jour,(transaction.date)->mois,(transaction.date)->annee);
    printf("Numero unique de la transaction : %d\n", transaction.numeroTransaction);
    affichercompte(*(transaction.compte)); 
}
void allouerclient(CLIENT*** clients,int nbrclients){
    *clients=(CLIENT**)malloc(nbrclients*sizeof(CLIENT*));
    if(!*clients) exit(-3);
}
void allouercompte(COMPTEBANCAIRE*** comptes,int nbrcomptes){
    *comptes=(COMPTEBANCAIRE**)malloc(nbrcomptes*sizeof(COMPTEBANCAIRE*));
    if(!*comptes) exit(-4);
}
void allouertransaction(TRANSACTION*** transactions,int nbrtrans){
    *transactions=(TRANSACTION**)malloc(nbrtrans*sizeof(TRANSACTION*));
    if(!*transactions) exit(-5);
}
void remplirtabcli(CLIENT*** clients ,int nbreclients){
    for (int i=0;i<nbreclients;i++){
        *(*clients+i)=(CLIENT*)malloc(sizeof(CLIENT));
        if(!*(*clients+i)) exit(-6);
        printf("entrer les info du client n%d\n",i+1);
        creerclient(*(*clients+i));

    }
}
void remplirtabcomptes(COMPTEBANCAIRE***comptes,int nbrecomptes){
    for(int i=0;i<nbrecomptes;i++){
        *(*comptes+i)=(COMPTEBANCAIRE*)malloc(sizeof(COMPTEBANCAIRE));
        if(!*(*comptes+i)) exit(-7);
        printf("entrer les info du compte n%d\n",i+1);
        creercompte(*(*comptes+i));

    }
    

}
void remplirtabtrans(TRANSACTION*** transactions,int nbretrans){
    for (int i=0;i<nbretrans;i++){
        *(*transactions+i)=(TRANSACTION*)malloc(sizeof(TRANSACTION));
        if(!*(*transactions+i)) exit(-7);
        printf("entrer les info de la transaction n%d\n",i+1);
        effectuertransaction(*(*transactions+i));
    }
}
void affichertabcli(CLIENT** clients,int nbreclients){
    for(int i=0;i<nbreclients;i++){
        printf("\nles info du client numero %d sont:",i+1);
        afficherclient(**(clients+i));
    }

}

void affichertabcomptes(COMPTEBANCAIRE**compte,int nbrecomptes){
    for(int i=0;i<nbrecomptes;i++){
        printf("\nles info du compte numero %d sont: ",i+1);
        affichercompte(**(compte+i));
        
    }
}

void affichertabtrans(TRANSACTION** transction,int nbrecomptes){
    for(int i=0;i<nbrecomptes;i++){
        printf("\nles info de la transction numero %d :",i+1);
        affichertransaction(**(transction+i));
        
    }

}
void estunnombrevalide(int* x) {
    do {
        scanf("%d", x) ;
        if (*x >= 10000000 && *x <= 99999999) {
            int firstDigit = *x / 10000000;
            if (firstDigit == 9 || firstDigit == 5 || firstDigit == 2 || firstDigit == 4) {
                break; 
            } 
            else {printf("Num tel invalide. svp entrer un nombre commencant avec 9,5,2 ou 4.\n");
            }        
        } else {
            printf("Num tel invalide. svp saisir un entier de 8 chiffres.\n");
        }
    } while (1); 
}
void realloclient(CLIENT*** clients ,int nbreclients,int nbreajoute){
    *clients=(CLIENT**)realloc(*clients,(nbreclients+nbreajoute)*sizeof(CLIENT*));
    if (!(*clients)) exit(-10);
    


}
void tabcliajout(CLIENT*** clients ,int nbreclients,int ajout){
    for (int i=nbreclients;i<(nbreclients+ajout);i++){
        *(*clients+i)=(CLIENT*)malloc(sizeof(CLIENT));
        if(!*(*clients+i)) exit(-6);
        printf("entrer les info du client n%d\n",i+1);
        creerclient(*(*clients+i));

    }
}
