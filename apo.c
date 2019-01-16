/* ------------------------------------------------------------------------ */
/**
 *  \file       apo.c
 *  \brief      Impl�mentation d'un module de gestion d'arbre
 *				partiellement ordonn� et de tri par tas
 *
 *  \date       10 D�cembre 2018
 *  \author     Samir El Khattabi
 *  \version    1.0
 *
 */


/* ------------------------------------------------------------------------ */
/*				I N C L U D E(s)  S T A N D A R D(s)                        */
/* ------------------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* ------------------------------------------------------------------------ */
/*				I N C L U D E(s)  S P E C I F I Q U E(s)                    */
/* ------------------------------------------------------------------------ */
#include "apo.h"
#include "types.h"

elt_t *aux;


/* ------------------------------------------------------------------------ */
int est1Minimier(elt_t *table, int n)
{
    for(int i = n-1; existePere(i); i--)
    {
        resultat.nbComparaisons++;
        if( table[Pere(i)] > table[i] ) return 0;
    }
    return 1;
}

/* ------------------------------------------------------------------------ */
void	remonterMinimier(elt_t *table, int k)
{
    while( existePere(k) && ( table[Pere(k)] > table[k] ) )
    {
        resultat.nbComparaisons++;
        permuter(table,k,Pere(k));
        k = Pere(k);
    }

    if( resultat.nbComparaisons != 0)
        resultat.nbComparaisons--;
}

/* ------------------------------------------------------------------------ */
void	descendreMinimier(elt_t *table, int iDebut, int iFin)
{
    int i;
    while( existeFilsG(iDebut,iFin+1) )
    {
        i = FilsG(iDebut);
        if( existeFilsD(iDebut,iFin+1) && ( table[ FilsG(iDebut) ] > table[ FilsD(iDebut) ]  ) )
            i = FilsD(iDebut);

        if( existeFilsD(iDebut,iFin+1) )
            resultat.nbComparaisons++;

        resultat.nbComparaisons++;
        if( table[i] < table[iDebut] )
        {
            permuter(table,i,iDebut);
            iDebut = i;
        }
        else
            break;
    }
}

/* ------------------------------------------------------------------------ */
void	transfEnMinimierV2(elt_t *table, int n)
{
    for(int i = n/2; i >= 0; --i)
    {
        descendreMinimier(table,i,n-1);
    }
}

/* ------------------------------------------------------------------------ */
void	transfEnMinimier(elt_t *table, int n)
{
    for(int i = 1; i < n; i++)
    {
        remonterMinimier(table,i);
    }
}
/* ------------------------------------------------------------- THE END -- */


void permuter(elt_t *t, int a, int b)
{
    resultat.nbAffectations += 3;
    elt_t aux = t[a];
    t[a] = t[b];
    t[b] = aux;

}
