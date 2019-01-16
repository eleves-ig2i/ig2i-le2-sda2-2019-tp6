/* ------------------------------------------------------------------------ */
/**
 *  \file       apo.h
 *  \brief      Sp�cification d'un module de gestion d'arbres
 *				partiellement ordonn� et de tri par tas
 *
 *  \date       10 D�cembre 2018
 *  \author     Samir El Khattabi
 *  \version    1.0
 *
 */
/* ------------------------------------------------------------------------ */

#ifndef _APO_H_
#define _APO_H_

#include "types.h"

/*#ifdef MAXIMIER
int compare(elt_t e1, elt_t e2) { return 0;}
#else
//int compare(elt_t e1, elt_t e2) { return 0;}
#endif*/

/* ------------------------------------------------------------------------ */
/*      M A C R O - F O N C T I O N S                                       */
/* ------------------------------------------------------------------------ */
#define Pere(i)     ( (i-1) >> 1 )            // indice du p�re du noeud rang� � l�indice i
#define FilsG(i)    ( 2*i+1 ) 			// indice du fils gauche du noeud rang� � l�indice i
#define FilsD(i)    ( 2*(i+1) ) 			// indice du fils droit du noeud rang� � l�indice i
#define existePere(i)   (i > 0)		// indique si le noeud d�indice i a un p�re
#define existeFilsG(i , n)  ( 2*i < n-1 ) 	// indique si le noeud d�indice i a un fils gauche dans un tas de n �l�ments
#define existeFilsD(i , n)  ( 2*i < n-2 ) 	// indique si le noeud d�indice i a un fils droit dans un tas de n �l�ments
/* ------------------------------------------------------------------------ */

/* ------------------------------------------------------------------------ */
/*      P R O T O T Y P E S   D E   F O N C T I O N S                       */
/* ------------------------------------------------------------------------ */
int		est1Minimier(elt_t *table, int n);
void	remonterMinimier(elt_t *table, int k);
void	descendreMinimier(elt_t *table, int iDebut, int iFin);
void	transfEnMinimier(elt_t *table, int n);
void	transfEnMinimierV2(elt_t *table, int n);
void    permuter(elt_t *t, int a, int b);
/* ------------------------------------------------------------------------ */
#endif
/* ------------------------------------------------------------- THE END -- */
