#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED
struct Date {
    int jour;
    int mois;
    int annee;

};typedef struct Date DATE;
struct Client
{
    char nom[50];//nom du client
    char prenom [50];//prenom du 
    int numtel;//
    int numcin;//
    int numcompte;//
    
    
};
typedef struct Client CLIENT ;
struct CompteBancaire
{
    double solde;//solde du compte
    CLIENT* client;//pointeur sur la structure CLIENT
};
typedef struct CompteBancaire COMPTEBANCAIRE ;
struct Transaction {
    COMPTEBANCAIRE *compte;   // pointeur sur la structure COMPTEBANCAIRE
    double montant;           // montant de la transaction
    char type[20];            // type de transaction (retrait, dépôt, etc.)
    DATE* date;            // date de la transaction
    int numeroTransaction;    // numéro unique de la transaction
    
};
typedef struct Transaction TRANSACTION;
struct Resultat {
    char nom[50];
    char prenom [50];
    int nbreTransactions;
    float* montantTrans;
};
typedef struct Resultat RESULTAT;
