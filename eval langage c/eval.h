#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*---------------------------------------------------------*/
/*conversion d'une chaine de char en une liste de token*/

enum type_token
{
    BIN_ET,
    BIN_OU,
    BIN_NON,
    BIN_IMP,
    BIN_EQU,
    BIN_1_0,
    BIN_PARO,
    BIN_PARF,
};

struct token
{
    enum type_token type_token;
    char *op;
    int val;
    struct token *suiv;
};
typedef struct token *token;

struct listeToken
{
    token token;
    struct listeToken *droite;
    struct listeToken *gauche;
};
typedef struct listeToken *listeToken;

listeToken allocationliste();
token creer_token(int type_token, char *op, int val);
token token_ajouter_fin_liste(token tiktok, token e);
listeToken string_to_token(char *string);
int taille(listeToken);


/*---------------------------------------------------------*/
/*Automate de vérification du langage*/

int alphabet(listeToken tok);

/*---------------------------------------------------------*/
/*ABR TOKEN*/
typedef struct tokabr
{
    enum type_token type;
    int val;

}tokabr;


struct arbre_token{
    tokabr tok;
    struct arbre_token *gauche;
    struct arbre_token *droite;
};typedef struct arbre_token * ARBRE_TOKEN;

tokabr * liste_polo(listeToken liste);


ARBRE_TOKEN nouveaunoeud(tokabr tok);
ARBRE_TOKEN arbre(tokabr* pile,int taille_pile);
ARBRE_TOKEN insert(ARBRE_TOKEN noeud,tokabr* tok,int *taille_pile);

void clean_tree(ARBRE_TOKEN tr);

/*---------------------------------------------------------*/
/*Résolution*/

int porte_logique_OU(int A, int B);
int porte_logique_ET(int A, int B);
int porte_logique_NON(int A);
int porte_logique_IMP(int A, int B);
int porte_logique_EQU(int A, int B);

int resou(ARBRE_TOKEN abr);
void affval(int eval);

void eval(char* argv);
