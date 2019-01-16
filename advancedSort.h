#ifndef ADVANCED_SORT_H_INCLUDED
#define ADVANCED_SORT_H_INCLUDED

/**
 *  \file       advancedSort.h
 *  \brief      Fichier de spécifications des fonctions de tri
 *
 *  \date       24 Novembre 2018
 *  \author     Samir El Khattabi
 *  \version    1.0
 *
 */

/****************************************************************************/
/*      I N C L U D E(s)  S P E C I F I Q U E(s)                            */
/****************************************************************************/
#include "types.h"
#include "apo.h"

/****************************************************************************/
/*      P R O T O T Y P Es   D E   F O N C T I O Ns                         */
/****************************************************************************/

/**
 *  \fn         void triFusion  (elt_t T[], int n);
 *  \brief      Tri par fusion d'une table T de n éléments
 *  \param      T   la table à trier
 *  \param      n   le nombre d'éléments de la table T
 */
void triFusion     (elt_t T[], int n);

/**
 *  \fn         void triRapide  (elt_t T[], int n);
 *  \brief      Tri par la méthode du tri rapide d'une table T de n éléments
 *  \param      T   la table à trier
 *  \param      n   le nombre d'éléments de la table T
 */
void triRapidev0     (elt_t T[], int n);


void triRapidev1( elt_t T[], int n);



/**
 *  \fn         void triRapidev2  (elt_t T[], int n);
 *  \brief      Tri par la méthode du tri rapide d'une table T de n éléments
 *  \note       Version qui fait appel à la fonction standard qsort
 *  \param      T   la table à trier
 *  \param      n   le nombre d'éléments de la table T
 */
void triRapidev2   (elt_t T[], int n);

/**
 *  \fn         void triArbre  (elt_t T[], int n);
 *  \brief      Tri par la méthode du tri arbre d'une table T de n éléments
 *  \param      T   la table à trier
 *  \param      n   le nombre d'éléments de la table T
 */
void triArbre      (elt_t T[], int n);

#endif // ADVANCED_SORT_H_INCLUDED
