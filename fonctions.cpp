#include"bib.h"
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
int recherchercli(CLIENT** cl, int nbcli, int numcin) {
    for (int i = 0; i < nbcli; i++) {
        if ((*(cl+i))->numcin ==numcin) {
            return i; // Retourne l'indice duclient s'il est trouvé
        }
    }
    return -1; // Retourne -1 si le client n'est pas trouvé
}

void modifclient(CLIENT*** cl,int nbcli){
    int numcin;
    printf("\ndonner le numero de CIN du client que vouz voulez modifier");
    scanf("%d",&numcin);
    int ind=recherchercli(*cl,nbcli,numcin);
    //verifie que le client existe dans le tableau en utilisant la fonction recherchercli
    if(ind!=-1){
        printf("\nentrer le nouveau numtel");
        scanf("%d",&(*(*cl+ind))->numtel);
        printf("\nentrer le nouveau numcompte");
        scanf("%d",&(*(*cl+ind))->numcompte);
    }
    else {
        printf("\nClient inexistant !!");
    }
}
void creerresultat(RESULTAT* resul){
    printf("\nnom:");
    scanf("%s",&resul->nom);
    printf("\nprenom:");
    scanf("%s",&resul->prenom);
    printf("\nCombien de transactions a ce client fait?:");
    scanf("%d",&resul->nbreTransactions);
    resul->montantTrans=(float*)malloc ((resul->nbreTransactions)*sizeof(float));
	if( ! (resul->montantTrans) ) exit(-2);
    printf("\n remplissage du tableau des montants des transactions \n");
	for(int i=0; i<(resul->nbreTransactions);i++){
		scanf("%f", resul->montantTrans+i );
    }

}
void afficheresultat(RESULTAT resul){
    printf("\nnom: %s",resul.nom);
    printf("\nnom: %s",resul.prenom);
    printf("\nnbres des transaction: %d",resul.nbreTransactions);
    printf("\n affichage du tableau des montants des transactions \n");
	for(int i=0; i<(resul.nbreTransactions);i++){
		printf("%.2f   ", *(resul.montantTrans+i) );
    }

}
void allouerresultat(RESULTAT*** resul,int nbres){
    *resul=(RESULTAT**)malloc(nbres*sizeof(RESULTAT*));
    if(!*resul) exit(-3);
}
void remplirtabresultat(RESULTAT*** resul ,int nbres){
    for (int i=0;i<nbres;i++){
        *(*resul+i)=(RESULTAT*)malloc(sizeof(RESULTAT));
        if(!*(*resul+i)) exit(-6);
        printf("entrer les info du RESULTAT n%d\n",i+1);
        creerresultat(*(*resul+i));

    }
}
void affichertabresultat(RESULTAT** resul,int nbres){
    for(int i=0;i<nbres;i++){
        printf("\nles info du RESULTAT numero %d sont:",i+1);
        afficheresultat(**(resul+i));

    }
}
RESULTAT saisir_res(){


RESULTAT res ;
printf("\n entrer le nom :\n");
scanf("%s" ,&res.nom);
printf("\n saisir le prenome : \n");
scanf("%s",&res.prenom);
printf("\entrer le nombre des transactions :\n");
scanf("%d",&res.nbreTransactions);
res.montantTrans=(float*)malloc(res.nbreTransactions*sizeof(float));
if(!res.montantTrans)exit(-1);
for (int i=0;i< res.nbreTransactions;i++){

    printf("montant numero %d",i);
    scanf("%f",&res.montantTrans+i);
}
return res ;}
void afficherResultat(RESULTAT res){


int i  ;
printf("\n le nom de client est : %s\n",res.nom);
printf("\n le prenom de client est : %s\n",res.prenom);
printf("_\n le nombre des transactions est : %d \n",res.nbreTransactions);
for (int i=0;i< res.nbreTransactions;i++)
{
    printf ("%f \n", res.montantTrans[i]);
}
}

/* ***************GESTION D UN FICHIER RESULTAT************************/

void ecrireresultatdansunfichier(FILE *fc,RESULTAT res){

fwrite(&res.nom, sizeof(char),15,fc);
fwrite(&res.prenom, sizeof(char),15,fc);
fwrite(&res.nbreTransactions,sizeof(int),1,fc);
fwrite(res.montantTrans,sizeof(float),res.nbreTransactions,fc);}
RESULTAT lire_une_resultat_du_fichier(FILE*fc)
{
    RESULTAT res;
    fread(&res.nom,sizeof(char),15,fc);
    fread(&res.prenom,sizeof(char),15,fc);
    fread(&res.nbreTransactions,sizeof(int),1,fc);

    res.montantTrans=(float*)malloc(res.nbreTransactions*sizeof(float));
    if(!res.montantTrans)exit(-1);
    fread(res.montantTrans,sizeof(float),res.nbreTransactions,fc);
    return res ;
}

void creer_fichier_resultat_index(FILE**fc,FILE**fi){

*fc=fopen("fichierresultat","wb+");
if(!*fc)exit(-1);
*fi=fopen("fichierresultatindex","wb+");
if(!*fi)exit(-1);

}
void remplir_fichier_resultat_index(FILE*fc,FILE*fi)
{
    int x ;
    RESULTAT res;
    do{

         res=saisir_res();
         if (res.nbreTransactions == 0) break;
          x=ftell(fc);
          fwrite(&x,sizeof(int),1,fi);
          (fc,res);


            }while (res.nbreTransactions!=0);
}
void afficher_fichier_resultat_index (FILE *fc, FILE*fi){

RESULTAT res;
int x ;
rewind(fc);rewind(fi);
printf("\n affichage du fichier index : \n");
while (1)
{
    fread(&x,sizeof(int),1,fi);
    if (feof(fi)) break ;
    printf("\n %d",x);

}
rewind(fi);
printf("\n affichage du fichier chambre \n");
while (1)
{
    fread(&x,sizeof(int),1,fi);
    if (feof(fi)) break ;
    fseek(fc,x,0);
    res=lire_une_resultat_du_fichier(fc);
    afficherResultat(res);
    printf("\n %d",x);

}
}


