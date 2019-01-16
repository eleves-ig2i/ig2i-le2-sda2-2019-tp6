/**
 *  \file           advancedSort.c
 *  \brief          Module d'implémentation de fonctions de tri avancés
 *                  <ul>
 *                      <li> tri fusion</li>
 *                      <li> tri rapide</li>
 *                      <li> tri arbre</li>
 *                  </ul>
 *  \author         Samir El Khattabi
 *  \date           24 Novembre 2018
 *  \version        1.0
 */

/****************************************************************************/
/*      I N C L U D Es  S P E C I F I Q U Es                                */
/****************************************************************************/
#include "advancedSort.h"
#include "types.h"
#include <stdlib.h>

void fusionner(elt_t T[], int a, int m, int b);
void _triFusion(elt_t T[], int a, int b);


elt_t * aux;

/**
 *  \fn         void triFusion  (elt_t T[], int n);
 *  \brief      Tri par fusion d'une table T de n éléments
 *  \param      T   la table à trier
 *  \param      n   le nombre d'éléments de la table T
 */
void triFusion(elt_t t[], int n)
{
    aux = (elt_t *)malloc (n * sizeof(elt_t));
    _triFusion(t, 0, n-1);
    free(aux);
}


void _triFusion(elt_t T[], int a, int b)
{
    int m;

    if (a < b)
    {
        m = (a + b)/2;
        _triFusion(T,     a, m);
        _triFusion(T, m + 1, b);
        fusionner(T, a, m, b);
    }
}

void fusionner(elt_t T[], int a, int m, int b)
{
    int i, j, k;

    for (i = 0; i + a <= b; i++) {
        aux[i] = T[i + a];
        resultat.nbAffectations++;
    }

    i = 0;
    j = m - a + 1;
    k = a;
    while (i <= m - a && j <= b - a)
    {
//        if (aux[i] <= aux[j])
        resultat.nbComparaisons++;
        resultat.nbAffectations++;
        if (aux[i] >= aux[j])
            T[k++] = aux[i++];
        else
            T[k++] = aux[j++];
    }

    for (; i <= m - a; T[k++] = aux[i++])
    {
        resultat.nbAffectations++;
    }
    for (; j <= b - a; T[k++] = aux[j++])
    {
        resultat.nbAffectations++;
    }
}

/**
 * \fn void swap(elt_t t[], int a, int b)
 * \brief Echange 2 valeurs dans un tableau.
 * \param t Le tableau où l'on doit effectuer l'échange.
 * \param a Indice d'un élément.
 * \param b Indice d'un autre élément.
 */
void swap(elt_t t[], int a, int b)
{
    elt_t eltAnnexe = t[a];
    t[a] = t[b];
    t[b] = eltAnnexe;
    resultat.nbAffectations += 3;
}

#include <stdio.h>
/**
 *
 * @param t
 * @param g
 * @param d
 * @return l'indice du pivot.
 */
int partitionnement(elt_t t [], int g, int d)
{
    // V0 : le pivot est au milieu
    int iPivotTempo = (g+d)/2;
    swap(t,iPivotTempo,d);  // on place le pivot en fin de tableau.
    int i = g, j = d-1;     // i et j sont les "pointeurs itératifs" du tableau de gauche et du tableau de droite
    while( i < j)
    {
        while(i < j && t[i] <= t[d]) {
            i++;
            resultat.nbComparaisons++;
        }
        while(i < j && t[j] >t[d]) {
            j--;
            resultat.nbComparaisons++;
        }
        if( i < j) {
            swap(t, i, j);
            j--;
            i++;
        }
    }

    resultat.nbComparaisons++;
    if ( i > j || ( t[i] >= t[d] && i == j ))
    {
        iPivotTempo = i;
    }
    else
    {
        iPivotTempo = i+1;
    }
    swap(t,iPivotTempo,d);    // on replace le pivot de façon à respecter la propriété des éléments des 2 ss tableaux
    return iPivotTempo;
}


/**
 * \fn void quickSort (elt_t t [], int g, int d)
 * \brief Tri par la méthode du tri rapide d'une table T de d-g+1 éléments
 * \param t Le tableau à trier.
 * \param g L'indice du 1er élément.
 * \param d L'indice du dernier élément.
 */
void quickSort (elt_t t [], int g, int d) {
    int iPivot; /* indice de l’élément pivot */
    if (d > g) {
        iPivot = partitionnement(t, g, d);
        /* L’élément t[iPivot] est à sa place définitive */
        /* Les éléments t[g] à t[iPivot-1] sont <= t[iPivot] */
        /* Les éléments t[iPivot+1] à t[d] sont >= t[iPivot] */
        quickSort(t, g, iPivot- 1);
        quickSort(t, iPivot + 1, d);
    }
}


void quickSortv1 (elt_t t [], int g, int d) {
    int iPivot; /* indice de l’élément pivot */
    while(d > g) {
        iPivot = partitionnement(t, g, d);
        /* L’élément t[iPivot] est à sa place définitive */
        /* Les éléments t[g] à t[iPivot-1] sont <= t[iPivot] */
        /* Les éléments t[iPivot+1] à t[d] sont >= t[iPivot] */
        quickSort(t, g, iPivot- 1);
        //quickSort(t, iPivot + 1, d);
        g = iPivot + 1;
    }
}


/**
 *  \fn         void triRapide  (elt_t T[], int n);
 *  \brief      Tri par la méthode du tri rapide d'une table T de n éléments
 *  \param      T   la table à trier
 *  \param      n   le nombre d'éléments de la table T
 */
void triRapidev0     (elt_t T[], int n)
{
    quickSort(T,0,n-1);
}


/**
 *  \fn         void triRapidev1  (elt_t T[], int n);
 *  \brief      Tri par la méthode du tri rapide d'une table T de n éléments
 *  \param      T   la table à trier
 *  \param      n   le nombre d'éléments de la table T
 */
void triRapidev1( elt_t T[], int n )
{
    quickSortv1(T,0,n-1);
}


/**
 *  \fn         void triRapidev2  (elt_t T[], int n);
 *  \brief      Tri par la méthode du tri rapide d'une table T de n éléments
 *  \note       Version qui fait appel à la fonction standard qsort
 *  \param      T   la table à trier
 *  \param      n   le nombre d'éléments de la table T
 */
void triRapidev2   (elt_t T[], int n)
{
    /*          A C O M P L E T E R                                         */
}

/**
 *  \fn         void triArbre  (elt_t T[], int n);
 *  \brief      Tri par la méthode du tri arbre d'une table T de n éléments
 *  \param      T   la table à trier
 *  \param      n   le nombre d'éléments de la table T
 */
void triArbre(elt_t *table, int n)
{
    transfEnMinimier(table,n);

    for(int i = n -1; i > 0; i--)
    {
        permuter(table,0,i);
        descendreMinimier(table,0,i-1);
    }

}

