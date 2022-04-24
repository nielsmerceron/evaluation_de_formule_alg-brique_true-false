#include "eval.h"

/*---------------------------------------------------------*/
/*conversion d'une chaine de char en une liste de token*/

/*fonction qui alloue une liste de token*/
listeToken allocationliste()
{
    listeToken liste = malloc(sizeof(listeToken));
    if (liste == NULL)
    {
        fprintf(stderr, "\n mauvaise allocation de la liste de token \n");
        return (NULL);
    }

    return (liste);
}

/* fonction gérant la création de token et son allocation*/
token creer_token(int type_token, char *op, int val)
{
    token tiktok;
    tiktok = malloc(sizeof(struct token));
    if (tiktok == NULL)
    {
        fprintf(stderr, "Le malloc est pas fais\n");
        exit(0);
    }
    tiktok->type_token = type_token;
    tiktok->op = op;
    tiktok->val = val;
    tiktok->suiv = NULL;
    return tiktok;
}

/* */
token token_ajouter_fin_liste(token tiktok, token e)
{

    if (tiktok == NULL)
    {
        return e;
    }
    token tokd = tiktok;
    while (tiktok->suiv != NULL)
    {
        tiktok = tiktok->suiv;
    }
    tiktok->suiv = e;

    return tokd;
}

/*fonction convertissant les char d'une chaine en une liste de token */
listeToken string_to_token(char *string)
{
    int i = 0;
    token tok;
    token tiktok = malloc(sizeof(tiktok));
    listeToken tic = malloc(sizeof(listeToken));
    listeToken tac = malloc(sizeof(listeToken));

    if (tiktok == NULL)
    {
        exit(0);
    }
    if (tic == NULL)
    {
        exit(0);
    }
    if (tac == NULL)
    {
        exit(0);
    }

    while (string[i] != '\0')
    {
        if (string[i] == 46) // le point qui represente 'ET'
        {
            tok = creer_token(BIN_ET, ".", 0);
            tiktok = token_ajouter_fin_liste(tok, tiktok);
            tic->token = tiktok;
            tic->droite = malloc(sizeof(listeToken));
            if (tic->droite == NULL)
            {
                exit(0);
            }
            tac = tic;
            tic = tic->droite;
            tic->gauche = tac;

            i++;
        }
        else if (string[i] == 43) // le + qui represente 'OU'
        {
            tok = creer_token(BIN_OU, "+", 0);
            tiktok = token_ajouter_fin_liste(tok, tiktok);
            tic->token = tiktok;
            tic->droite = malloc(sizeof(listeToken));
            if (tic == NULL)
            {
                exit(0);
            }
            tac = tic;
            tic = tic->droite;
            tic->gauche = tac;

            i++;
        }
        else if ((string[i] == 78) && (string[i + 1] == 79) && (string[i + 2] == 78)) // NON
        {
            tok = creer_token(BIN_NON, "NON", 0);
            tiktok = token_ajouter_fin_liste(tok, tiktok);
            tic->token = tiktok;
            tic->droite = malloc(sizeof(listeToken));
            if (tic == NULL)
            {
                exit(0);
            }
            tac = tic;
            tic = tic->droite;
            tic->gauche = tac;

            
            i = i + 3;
        }
        else if ((string[i] == 61) && (string[i + 1] == 62)) // Implication
        {
            tok = creer_token(BIN_IMP, "=>", 0);
            tiktok = token_ajouter_fin_liste(tok, tiktok);
            tic->token = tiktok;
            tic->droite = malloc(sizeof(listeToken));
            if (tic == NULL)
            {
                exit(0);
            }
            tac = tic;
            tic = tic->droite;
            tic->gauche = tac;

            i = i + 2;
        }
        else if ((string[i] == 60) && (string[i + 1] == 61) && (string[i + 2] == 62)) // Equivalence
        {
            tok = creer_token(BIN_EQU, "<=>", 0);
            tiktok = token_ajouter_fin_liste(tok, tiktok);
            tic->token = tiktok;
            tic->droite = malloc(sizeof(listeToken));
            if (tic == NULL)
            {
                exit(0);
            }
            tac = tic;
            tic = tic->droite;
            tic->gauche = tac;

            i = i + 3;
        }
        else if (string[i] == 40) // Paranthèse ouvrante
        {
            tok = creer_token(BIN_PARO, "(", 0);
            tiktok = token_ajouter_fin_liste(tok, tiktok);
            tic->token = tiktok;
            tic->droite = malloc(sizeof(listeToken));
            if (tic == NULL)
            {
                exit(0);
            }
            tac = tic;
            tic = tic->droite;
            tic->gauche = tac;

            i++;
        }
        else if (string[i] == 41) // Paranthèse fermante
        {
            tok = creer_token(BIN_PARF, ")", 0);
            tiktok = token_ajouter_fin_liste(tok, tiktok);
            tic->token = tiktok;
            tic->droite = malloc(sizeof(listeToken));
            if (tic == NULL)
            {
                exit(0);
            }
            tac = tic;
            tic = tic->droite;
            tic->gauche = tac;

            i++;
        }
        else if (string[i] == 48) // Valeur 0
        {
            tok = creer_token(BIN_1_0, "0", 0);
            tiktok = token_ajouter_fin_liste(tok, tiktok);
            tic->token = tiktok;
            tic->droite = malloc(sizeof(listeToken));
            if (tic == NULL)
            {
                exit(0);
            }
            tac = tic;
            tic = tic->droite;
            tic->gauche = tac;

            i++;
        }
        else if (string[i] == 49) // Valeur 1
        {
            tok = creer_token(BIN_1_0, "1", 1);
            tiktok = token_ajouter_fin_liste(tok, tiktok);
            tic->token = tiktok;
            tic->droite = malloc(sizeof(listeToken));
            if (tic == NULL)
            {
                exit(0);
            }
            tac = tic;
            tic = tic->droite;
            tic->gauche = tac;

            i++;
        }
        else if (string[i] == 32) // Espace
        {
            i++;
        }
        else
        {
            fprintf(stderr, "la lettre : %c de l'expression n'est pas reconnue\n\n", string[i]);
            return (NULL);
            i++;
        }
    }

    return tic;
}

/* renvoie la taille de la chaine sans les parenthèses*/
int taille(listeToken liste)
{
    int i = 0;
    while (liste->droite != NULL)
    {
        if ((liste->token->type_token != BIN_PARO) && (liste->token->type_token != BIN_PARF))
        {
            i++;
        }
        liste = liste->droite;
    }
    while (liste->gauche)
    {
        liste = liste->gauche;
    }
    return (i);
}

/*---------------------------------------------------------*/
/*Automate de vérification du langage*/

/* fonction vérifiant que les expressions sont dans le langage*/
int alphabet(listeToken tok)
{

    int retour = 0;

    while (tok->droite != NULL)
    {
        if (tok->token->type_token == BIN_PARO)
        {

            retour = retour + 1;
            if (tok->droite->token == NULL)
            {
                break;
            }

            if ((tok->droite->token->type_token == BIN_NON) || (tok->droite->token->type_token == BIN_1_0) || (tok->droite->token->type_token == BIN_PARO))
            {

                tok = tok->droite;
            }
        }
        if (tok->token->type_token == BIN_NON)
        {
            if ((tok->droite->token == NULL) || (tok->droite->token->type_token == BIN_ET) || (tok->droite->token->type_token == BIN_OU) || (tok->droite->token->type_token == BIN_EQU) || (tok->droite->token->type_token == BIN_IMP))
            {
                retour = 1;
                break;
            }

            if ((tok->droite->token->type_token == BIN_NON) || (tok->droite->token->type_token == BIN_1_0) || (tok->droite->token->type_token == BIN_PARO))
            {

                tok = tok->droite;
            }
        }

        if (tok->token->type_token == BIN_1_0)
        {
            if (tok->droite->token == NULL)
            {
                break;
            }
            if (tok->droite->token->type_token == BIN_1_0)
            {
                retour = 1;
                break;
            }

            if ((tok->droite->token->type_token == BIN_ET) || (tok->droite->token->type_token == BIN_OU) || (tok->droite->token->type_token == BIN_EQU) || (tok->droite->token->type_token == BIN_IMP) || (tok->droite->token->type_token == BIN_PARF))
            {

                tok = tok->droite;
            }
        }

        if (tok->token->type_token == BIN_PARF)
        {
            retour = retour - 1;

            if ((tok->droite->token == NULL) || (tok->droite->token->type_token == BIN_1_0))
            {
                break;
            }

            if ((tok->droite->token->type_token == BIN_ET) || (tok->droite->token->type_token == BIN_OU) || (tok->droite->token->type_token == BIN_EQU) || (tok->droite->token->type_token == BIN_IMP) || (tok->droite->token->type_token == BIN_PARF))
            {
                tok = tok->droite;
            }
        }

        if ((tok->token->type_token == BIN_ET) || (tok->token->type_token == BIN_OU) || (tok->token->type_token == BIN_EQU) || (tok->token->type_token == BIN_IMP))
        {
            if ((tok->droite->token == NULL) || (tok->droite->token->type_token == BIN_ET) || (tok->droite->token->type_token == BIN_OU) || (tok->droite->token->type_token == BIN_EQU) || (tok->droite->token->type_token == BIN_IMP))
            {
                retour = 1;
                break;
            }

            if ((tok->droite->token->type_token == BIN_1_0) || (tok->droite->token->type_token == BIN_PARO) || (tok->droite->token->type_token == BIN_NON))
            {
                tok = tok->droite;
            }
        }
    }
    return retour;
}

/*---------------------------------------------------------*/
/*ABR TOKEN*/


/* fonction convertissant les tokens en une liste de token en notation polonaise inverse*/
tokabr *liste_polo(listeToken liste)
{
    if (liste == NULL)
    {
        fprintf(stderr, "la liste passé en argument est vide");
        return (NULL);
    }
    tokabr *listepolo1;
    listepolo1 = malloc(sizeof(struct tokabr) * taille(liste));

    if (listepolo1 == NULL)
    {
        fprintf(stderr, "\n erreur d'allocation de la liste polo 1\n");
        return (NULL);
    }
    tokabr *listepolo2;
    listepolo2 = malloc(sizeof(struct tokabr) * 50);
    if (listepolo2 == NULL)
    {
        fprintf(stderr, "\n erreur d'allocation de la liste polonaise 2\n");
        return (NULL);
    }
    int i = 0;
    int j = 0;

    while (liste->droite != NULL)
    {
        if (liste->token->type_token == BIN_1_0)
        {
            listepolo1[i].type = BIN_1_0;
            listepolo1[i].val = liste->token->val;
            i++;
        }

        if (liste->token->type_token == BIN_PARF)
        {
            while (listepolo2[j].type != BIN_PARO)
            {
                j = j - 1;
                if (listepolo2[j].type != BIN_PARO)
                {
                    listepolo1[i].type = listepolo2[j].type;

                    listepolo1[i].val = listepolo2[j].val;
                    i++;
                }
            }
            if (j != 0)
            {
                if (listepolo2[j - 1].type == BIN_NON)
                {
                    while ((j != 0) && (listepolo2[j - 1].type == BIN_NON))
                    {
                        j = j - 1;
                        if (listepolo2[j].type != BIN_PARO)
                        {
                            listepolo1[i].type = listepolo2[j].type;

                            listepolo1[i].val = listepolo2[j].val;
                            i++;
                        }
                    }
                }
            }
        }

        if ((liste->token->type_token != BIN_PARF) && (liste->token->type_token != BIN_1_0))
        {
            if ((listepolo2[j - 1].type == BIN_EQU) || (listepolo2[j - 1].type ==BIN_ET)||(listepolo2[j - 1].type == BIN_IMP) || (listepolo2[j - 1].type == BIN_OU))
            {
                listepolo1[i] = listepolo2[j - 1];
                listepolo2[j - 1].type = liste->token->type_token;
                listepolo2[j-1].val=liste->token->val;
                i++;
            }
            else
            {
                listepolo2[j].type = liste->token->type_token;
                listepolo2[j].val = liste->token->val;
                j++;
            }
        }

        liste = liste->droite;
    }
    while (j != 0)
    {
        j = j - 1;
        if (listepolo2[j].type != BIN_PARO)
        {
            listepolo1[i].type = listepolo2[j].type;

            listepolo1[i].val = listepolo2[j].val;
            i++;
        }
    }

    free(listepolo2);
    return (listepolo1);
}

/* creer un Noeud de l'abr */
ARBRE_TOKEN nouveaunoeud(tokabr tok)
{
    ARBRE_TOKEN noeud = malloc(sizeof(ARBRE_TOKEN) * 5);
    noeud->tok.type = tok.type;
    noeud->tok.val = tok.val;
    noeud->gauche = NULL;
    noeud->droite = NULL;

    return noeud;
}

/*fonction de regroupement des fonctions pour créer l'abr */
ARBRE_TOKEN arbre(tokabr *pile, int taille_pile)
{
    ARBRE_TOKEN racine = malloc(sizeof(ARBRE_TOKEN));
    racine = insert(racine, pile, &taille_pile);
    return (racine);
}

/* fonction faisant l'arbre en effectuant un parcours postfixe */
ARBRE_TOKEN insert(ARBRE_TOKEN noeud, tokabr *tok, int *taille_pile)
{
    if (taille_pile != 0)
    {
        *taille_pile = *taille_pile -1;

        noeud = nouveaunoeud(tok[*taille_pile]);

        if (noeud->tok.type == BIN_1_0)
        {
            return noeud;
        }

        noeud->droite = insert(noeud->droite, tok, taille_pile);
       
        if (*taille_pile < 0) 
        {
            *taille_pile = *taille_pile -1;
        }
        
        if (noeud->tok.type != BIN_NON)
        {
            noeud->gauche = insert(noeud->gauche, tok, taille_pile);
        }
    }
    return noeud;
}

/* fonction de free de l'arbre*/
void clean_tree(ARBRE_TOKEN tr)
{

    if (tr == NULL)
    {
        return;
    }

    //fprintf(stdout, "bonne suppr de l'arbre %d\n", tr->tok.type);
    clean_tree(tr->droite);
    clean_tree(tr->gauche);

    free(tr);
}

/*---------------------------------------------------------*/
/*Résolution*/

int porte_logique_ET(int A, int B)
{
    if ((A == 1) && (B == 1))
    {
        return (1);
    }
    return (0);
}

int porte_logique_OU(int A, int B)
{
    if ((A == 0) && (B == 0))
    {
        return (0);
    }
    return (1);
}

int porte_logique_NON(int A)
{
    if (A == 1)
    {
        return (0);
    }
    return (1);
}

int porte_logique_IMP(int A, int B)
{
    if ((A == 1) && (B == 0))
    {
        return (0);
    }
    return (1);
}

int porte_logique_EQU(int A, int B)
{
    if (A == B)
    {
        return (1);
    }
    return (0);
}

/* fonction de résolution de l'abr en utilisant un parcours préfixe*/
int resou(ARBRE_TOKEN tr)
{

    if (tr == NULL)
    {
        return (0);
    }
    int i;
    int j;

    if ((tr->gauche != NULL) && (tr->tok.type != BIN_NON))
    {
        i = resou(tr->gauche);
    }
    if (tr->droite != NULL)
    {
        j = resou(tr->droite);
    }
    if (tr->tok.type == BIN_1_0)
    {
        return (tr->tok.val);
    }

    if (tr->tok.type == BIN_OU)
    {
        return (porte_logique_OU(i, j));
    }

    if (tr->tok.type == BIN_ET)
    {
        return (porte_logique_ET(i, j));
    }

    if (tr->tok.type == BIN_EQU)
    {
        return (porte_logique_EQU(i, j));
    }

    if (tr->tok.type == BIN_IMP)
    {
        return (porte_logique_IMP(i, j));
    }

    if (tr->tok.type == BIN_NON)
    {

        if (tr->droite != NULL)
        {
            return (porte_logique_NON(j));
        }
    }

    return (tr->tok.val);
}

void affval(int eval)
{
    if (eval == 1)
    {
        fprintf(stdout, " VRAIE\n\n");
        return;
    }
    else
    {
        fprintf(stdout, " FAUX\n\n");
    }
}

void eval(char *argv)
{
    listeToken tok = allocationliste();

    char string[256];

    strcpy(string, argv);

    tok = string_to_token(string);

    if (tok != NULL)
    {
        while (tok->gauche != NULL)
        {

            tok = tok->gauche;
        }
        fprintf(stdout, "%s =", argv);

        if (alphabet(tok) == 0)
        {
            int tchaine = taille(tok);

            tokabr *listepolo = liste_polo(tok);
          
            free(tok);
            
            ARBRE_TOKEN abr = arbre(listepolo, tchaine);
            

            affval(resou(abr));

            free(listepolo);
            clean_tree(abr);
        }
        else if (alphabet(tok) != 0)
        {
            fprintf(stdout, " l'expression n'est pas dans le langage\n\n");
        }
    }
}
