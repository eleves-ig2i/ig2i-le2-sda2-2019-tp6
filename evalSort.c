
//pour modifier le PATH :
//PATH=%PATH%;C:\Program Files\gnuplot\bin


/**
 *  \file       evalSort.c
 *  \brief      Evaluation  de plusieurs méthodes de tri par comparaisons
 *              Sont comptabilisées:
 *              <ol>
 *                  <li>le nombre de comparaisons</li>
 *                  <li>le nombre d'affectations</li>
 *                  <li>la durée d'exécution en (tops d'horloge)</li>
 *              </ol>
 *
 *  \date       19 Novembre 2018
 *  \author     Samir El Khattabi
 *  \version    1.0
 *
 */


/****************************************************************************/
/*      I N C L U D E(s)  S T A N D A R D(s)                                */
/****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/****************************************************************************/
/*      I N C L U D E(s)  S P E C I F I Q U E(s)                            */
/****************************************************************************/
#include "types.h"
#include "basicSort.h"
#include "advancedSort.h"
#include "utilSort.h"

/****************************************************************************/
/*      C O N S T A N T E S   S Y M B O L I Q U E S                         */
/****************************************************************************/
/**
 *  \def        MAX_ELT
 *  \brief      Nombre maximal d'éléments de la table à trier
 */
#define MAX_ELT                 2090000

/****************************************************************************/
/*      D E F I N I T I O N S    D E     T Y P E S                          */
/****************************************************************************/

/**
 *  \typedef    ptrFctTestSort
 *  \brief      Type pointeur sur une fonction de tri
 */
typedef void (*ptrFctTestSort) ( elt_t [], int );

/**
 *  \struct    sortMethod_t
 *  \brief      Structure définissant une méthode de tri
 */
typedef struct
{
    /**             le nom de la méthode de tri                     */
    char *nom;
    
    /**             le pointeur sur la fonction de tri              */
    ptrFctTestSort sortFct;
    
    /**             le nombre maximal d'élements qu'elle peut trier
     *              dans un temps raisonnable
     */
    unsigned int limite;
} sortMethod_t;

/****************************************************************************/
/*      M A C R O - F O N C T I O N S                                       */
/****************************************************************************/

/* Néant */

/****************************************************************************/
/*      P R O T O T Y P E S   D E   F O N C T I O N S                       */
/****************************************************************************/

/* Néant */

/****************************************************************************/
/*      V A R I A B L E S    G L O B A L E S                                */
/****************************************************************************/

/**
 *  \var        const char *modes[]
 *  \brief      modes de génération des éléments à trier
 *  \note       Cette table est initialisée une fois pour toutes et ne
 *              peut plus être modifiée par la suite
 */
const char * modes[] =
{
    " ordonne ",
    "aleatoire",
    " inverse "
};

/**
 *  \var        const int nbElements[]
 *  \brief      table contenant la liste des tailles de table à trier
 *  \note       Cette table est initialisée une fois pour toutes et ne
 *              peut plus être modifiée par la suite
 */
const int nbElements[]=
{
    1000  ,   2500,    5000,      10000,
    25000 ,  50000,   75000,     100000,
    150000, 200000, MAX_ELT, MAX_ELT +1,
};

/**
 *  \var        result_t resultat
 *  \brief      sert à enregistrer les résultats du tri effectué
 *  \note       doit être réinitialisée à 0 avant chaque tri à effectuer
 */
result_t resultat =
{
    0,  /* Nombre de comparaisons */
    0,  /* Nombre d'affectations  */
    0   /* Durée en nombre de tops d'horloges */
};


/****************************************************************************/
/*      F O N C T I O N     P R I N C I P A L E                             */
/****************************************************************************/
/**
 *  \fn         int main(int argc, char *argv[])
 *  \brief      Programme principal. Il exécute diverses méthodes de tri
 *              sur une table dont le nombre d'éléments et le mode de
 *              génération des valeurs sont variables.
 *              <ul>
 *                  <li>La fonction test1tri produit un tableau de résultats</li>
 *                  <li>La fonction test1triV2 produit les graphes d'évolution
 *              de grandeurs significatives du tri à l'aide de GnuPlot</li>
 *              </ul>
 *  \param      argc    nombre de termes présents sur la ligne de commande
 *  \param      argv    table des termes présents sur la ligne de commande
 *  \return     0 pour signaler la bonne terminaison du programme
 */
int main(int argc, char *argv[])
{
    printf("EVALUATION EXPERIMENTALE DES TRIS\n");
    elt_t tableElts [MAX_ELT];
    unsigned int i;
    
    sortMethod_t    methodes[] =
    {
        /* Fonctions de la 1ére partie */
        //{"TRI INSERTION", triInsertion, MAX_ELT / 10},
        //{"TRI SELECTION", triSelection, MAX_ELT / 10},
        //{"TRI BULLES   ", triBulles   , MAX_ELT / 10},
        //{"TRI BULLES DRAPEAU", triBullesFlag, MAX_ELT / 10},
        //{"TRI SHELL    ", triShell    , MAX_ELT / 10},
        
        /* Fonctions de la 2nde partie */
        //{"TRI FUSION   ", triFusion   , MAX_ELT},
        //{"TRI RAPIDE v0", triRapidev0 , MAX_ELT},
        {"TRI RAPIDE v1", triRapidev1, MAX_ELT},
        //{"TRI RAPIDE v2", triRapidev2 , MAX_ELT},
        //{"TRI ARBRE    ", triArbre    , MAX_ELT},
    };
    
    /* Initialisation du générateur de nombres pseudo-aléatoires */
    srand((unsigned int)time(NULL));
    
    /*  Test de chaque méthode de tri  */
    for (i = 0; i < sizeof methodes / sizeof methodes[0]; i++)
        tester1Tri(methodes[i].nom, methodes[i].sortFct, tableElts, methodes[i].limite);
    
    /*  2e Test de chaque méthode de tri  */
    for (i = 0; i < sizeof methodes / sizeof methodes[0]; i++)
        tester1TriV2(methodes[i].nom, methodes[i].sortFct, tableElts, 512);
    
    system("pause");
    
    return EXIT_SUCCESS;
}
