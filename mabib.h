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



// Prototype pour créer un nouveau client
void creerclient(CLIENT*);
// Prototype pour créer un nouveau compte bancaire
void creercompte(COMPTEBANCAIRE*);

// Prototype pour effectuer une transaction
void effectuertransaction(TRANSACTION*);

// Prototype pour afficher les informations d'un client
void afficherclient(CLIENT);
// Prototype pour afficher les informations d'un compte
void affichercompte(COMPTEBANCAIRE);
// Prototype pour afficher les informations d'une transaction
void affichertransaction(TRANSACTION);
//prototype pour modifier les informations d'un client
void modifclient(CLIENT*);
//allocation de memoire
void allouerclient(CLIENT***,int );
void allouercompte(COMPTEBANCAIRE***,int );
void allouertransaction(TRANSACTION***,int );
//remplissage de tableaux
void remplirtabcli(CLIENT***,int);
void remplirtabcomptes(COMPTEBANCAIRE***,int );
void remplirtabtrans(TRANSACTION*** ,int );
//affichage des tableaux
void affichertabcli(CLIENT**,int);
void affichertabcomptes(COMPTEBANCAIRE**,int);
void affichertabtrans(TRANSACTION**,int);
//fonction qui assure que le numero de telephone saisie est valide
void estunnombrevalide(int*);
//procedure qui fait la reallocation de memoire d'un tableau d'adresses de clients
void realloclient(CLIENT***  ,int ,int );
//procedure qui ajoute des cases a un tableau des clients
void tabcliajout(CLIENT***  ,int ,int );
#endif 

