#ifndef UTIL_SORT_H_INCLUDED
#define UTIL_SORT_H_INCLUDED


/**
 *  \file       utilSort.h
 *  \brief      Fichier de spécifications des fonctions utilisés pour
 *              le programme d'évaluation de diverses méthodes de tri
 *
 *  \date       24 Novembre 2018
 *  \author     Samir El Khattabi
 *  \version    1.0
 *
 */

/****************************************************************************/
/*      I N C L U D Es  S T A N D A R Ds                                    */
/****************************************************************************/
#include <time.h>

/****************************************************************************/
/*      C O N S T A N T E S   S Y M B O L I Q U E S                         */
/****************************************************************************/

/**
 *  \def        NB_PER_LINE
 *  \brief      Nombre de valeurs affichées par ligne
 *  \note       l'affichage du tableau à trier ou qui
 *              a été trié, ne doit être fait qu'en mode
 *              test avec des tableaux de petite dimension
 */
#define NB_PER_LINE             10

/**
 *  \def        CMDLINE_MAX
 *  \brief      Longueur maximale de la ligne de commande construite pour
 *              appeler GnuPlot
 */
#define CMDLINE_MAX             64

/**
 *  \def        SUFFIXE_DATA
 *  \brief      Suffixe du fichier contenantles résultats des tris effecués
 */
#define SUFFIXE_DATA            ".dat"

/**
 *  \def        SUFFIXE_GNUPLOT
 *  \brief      Suffixe du fichier de commande GnuPlot
 */
#define SUFFIXE_GNUPLOT         ".plt"

/**
 *  \def        SUFFIXE_AFFECTATIONS
 *  \brief      Suffixe du graphe d'évolution du nombre d'affectations
 */
#define SUFFIXE_AFFECTATIONS    "_aff.png"

/**
 *  \def        SUFFIXE_COMPARAISONS
 *  \brief      Suffixe du graphe d'évolution du nombre de comparaisons
 */
#define SUFFIXE_COMPARAISONS    "_cmp.png"


/**
 *  \def        GNUPLOT
 *  \brief      définition du nom de l'apllication GnuPlot
 */
#ifdef _WIN32
#define GNUPLOT                 "wgnuplot"
#else
#define GNUPLOT                 "gnuplot"
#endif


/****************************************************************************/
/*      D E F I N I T I O N S    D E     T Y P E S                          */
/****************************************************************************/

/* Néant */

/****************************************************************************/
/*      M A C R O - F O N C T I O N S                                       */
/****************************************************************************/
/**
 *  \def    RaZ(r)
 *  \brief  Remet à 0 la variable r
 */
#define RaZ(r) memset(&(r), 0, sizeof(r))

/****************************************************************************/
/*      P R O T O T Y P E S   D E   F O N C T I O N S                       */
/****************************************************************************/

/**
 *  \fn             void afficher       (elt_t T[], int n);
 *  \brief          Affiche les valeurs des n premiers éléments de T
 *  \param          T   la table d'éléments
 *  \param          n   le nombre d'éléments à afficher
 */
void afficher       (elt_t T[], int n);

/**
 *  \fn             int  estOrdonne     (elt_t T[], int n, int strict);
 *  \brief          Permet de contrôler que les n premiers éléments de T
 *                  sont bien ordonnés de façon non décroissante (strict = 0),
 *                  strictement croissnate (strict = 1)
 *  \param          T   la table
 *  \param          n   le nombre d'éléments de T à contrôler
 *  \param          strict  mode de contrôle
 *                  <ul>
 *                      <li>strict = 1 --> strictement croissant<\/i>
 *                      <li>strict = 0 --> non décroissante </li>
 *                  </ul>
 *  \return         1 si est ordonné, 0 sinon
 */
int  estOrdonne     (elt_t T[], int n, int strict);

/**
 *  \fn             void initialiser    (elt_t T[], int n, int mode);
 *  \brief          Initialise les n premiers éléments de T dans le
 *                  mode 'mode'
 *  \param          T       la table d'éléments
 *  \param          n       le nombre d'élémemts
 *  \param          mode    le mode d'initialisation :
 *                  <ul>
 *                      <li>mode = 0    --> initialisation 'directe' (déjà ordonnée) </li>
 *                      <li>mode = 1    --> initialisation aléatoire </li>
 *                      <li>mode = 2    --> initialisation inverse </li>
 *                  </ul>
 */
void initialiser    (elt_t T[], int n, int mode);


/**
 *  \fn             void tester1Tri(const char * nom,  void (*tri)(elt_t [], int),
 *                   elt_t Table[], int nmax);
 *  \brief          Exécute une méthode de tri, pour différentes
 *                  tailles de tables, et différents modes
 *                  d'initialisation de la table à trier
 *                  <p>Les résultats sont affichés sous forme de tableaux sur l'écran
 *                  </p>
 *  \param          nom     nom de la méthode
 *  \param          tri     pointeur sur la fonction de tri
 *  \param          Table   la table à trier
 *  \param          nmax    nombre maximal d'éléments à trier
 *
 *  \note           utilise, sans modifer, les variables globales
 *                  "nbElements" et "modes", et met à jour la variable globale
 *                  "resultat".
 * \warning
 *                  L'implémentation incorrecte de l'affichage d'entiers
 *                  "long long" avec le compilateur MinGW (gcc pour
 *                  Windows) conduit à des traitements spécifiques
 *
 */
void tester1Tri     (const char * nom,  void (*tri)(elt_t [], int),
                     elt_t Table[], int nmax);


/**
 *  \fn             void tester1TriV2(const char * nom,  void (*tri)(elt_t [], int),
 *                   elt_t Table[], int nmax);
 *  \brief          2e version qui exécute une méthode de tri, pour différentes
 *                  tailles de tables, et différents modes
 *                  d'initialisation de la table à trier
 *                  <p>Les résultats sont affichés sous forme de graphes sur l'écran
 *                  </p>
 *  \param          nom     nom de la méthode
 *  \param          tri     pointeur sur la fonction de tri
 *  \param          Table   la table à trier
 *  \param          nmax    nombre maximal d'éléments à trier
 *
 *  \note           utilise, sans modifer, les variables globales
 *                  "nbElements" et "modes", et met à jour la variable globale
 *                  "resultat".
 *  \remarks        L'affichage graphique est réalisé à l'aide
 *                  de <a href="http://www.gnuplot.info/"> Gnuplot </a>
 *
 */
void tester1TriV2     (const char * nom,  void (*tri)(elt_t [], int),
                     elt_t Table[], int nmax);

/****************************************************************************/
/*      V A R I A B L E S    G L O B A L E S                                */
/****************************************************************************/
extern const char * modes[];
extern const int nbElements[];



#endif // UTIL_SORT_H_INCLUDED
