#ifndef BASIC_SORT_H_INCLUDED
#define BASIC_SORT_H_INCLUDED

/**
 *  \file       basicSort.h
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

/****************************************************************************/
/*      P R O T O T Y P Es   D E   F O N C T I O Ns                         */
/****************************************************************************/

/**
 *  \fn         void triInsertion  (elt_t T[], int n);
 *  \brief      Tri par insertion d'une table T de n éléments
 *  \param      T   la table à trier
 *  \param      n   le nombre d'éléments de la table T
 */
void triInsertion  (elt_t T[], int n);

/**
 *  \fn         void triSelection  (elt_t T[], int n);
 *  \brief      Tri par séléection d'une table T de n éléments
 *  \param      T   la table à trier
 *  \param      n   le nombre d'éléments de la table T
 */
void triSelection  (elt_t T[], int n);

/**
 *  \fn         void triBulles  (elt_t T[], int n);
 *  \brief      Tri par la méthode du tri par bulles d'une table T de n éléments
 *  \param      T   la table à trier
 *  \param      n   le nombre d'éléments de la table T
 */
void triBulles     (elt_t T[], int n);

/**
 *  \fn         void triBull_Flag  (elt_t T[], int n);
 *  \brief      Tri par la méthode du tri par bulles avec drapeau d'une table
 *              T de n éléments
 *  \param      T   la table à trier
 *  \param      n   le nombre d'éléments de la table T
 */
void triBullesFlag  (elt_t T[], int n);

/**
 *  \fn         void triShell  (elt_t T[], int n);
 *  \brief      Tri par la méthode du tri Shell d'une table T de n éléments
 *  \param      T   la table à trier
 *  \param      n   le nombre d'éléments de la table T
 */
void triShell     (elt_t T[], int n);



#endif // BASIC_SORT_H_INCLUDED
