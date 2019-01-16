#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

/**
 *  \file       types.h
 *  \brief      Fichier de spécifications des types/structures de données 
 *              utilisées : elt_t, result_t, ptrFctInt
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
/*      D E F I N I T I O Ns   D E     T Y P E S                            */
/****************************************************************************/

/**
 *  \typedef    elt_t
 *  \brief      Défintion du type des éléments à trier
 *  \note       Ici, ce sont de simples entiers
 */
typedef int elt_t;

/**
 *  \struct     result_t
 *  \brief      Définition du type de la structure servant à l'enregistrement
 *              des "performances" du tri effectué.
 */
typedef struct
{
    /**             le nombre de comparaisons effectuées                    */
    unsigned long long  nbComparaisons;
    /**             le nombre d'affectations (entre éléments de la table)   */
    unsigned long long  nbAffectations;
    /**             durée du tri en nombre de tops d'horloge                */
    clock_t             duree_en_clock_t;
} result_t;

/**
 *  \typedef    ptrFctInt
 *  \brief      Type pointeur de fonction retournant un entier et ayant
 *              deux pointeurs non typés en paramétres
 */
typedef int (*ptrFctInt)(const void *a, const void *b);

/****************************************************************************/
/*      D E F I N I T I O Ns  D Es  V A R I A B L Es    G L O B A L Es      */
/****************************************************************************/
extern result_t resultat;

#endif // TYPES_H_INCLUDED
