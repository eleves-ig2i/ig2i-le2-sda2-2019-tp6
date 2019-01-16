/**
 *  \file           basicSort.c
 *  \brief          Module d'implémentation de fonctions de tri basiques
 *                  <ul>
 *                      <li> tri par insertion</li>
 *                      <li> tri par sélection</li>
 *                      <li> tri par permutations (tri à bulles)</li>
 *                  </ul>
 *  \author         Samir El Khattabi
 *  \date           24 Novembre 2018
 *  \version        1.0
 */

/****************************************************************************/
/*      I N C L U D Es  S P E C I F I Q U Es                                */
/****************************************************************************/
#include "basicSort.h"
#include "types.h"

/**
 *  \fn         void triInsertion  (elt_t T[], int n);
 *  \brief      Tri par insertion d'une table T de n éléments
 *  \param      T   la table à trier
 *  \param      n   le nombre d'éléments de la table T
 *  \note       Cette fonction met à jour la variable globale "resultat"
 *              en comptabilisant les comparaisons et affectations
 *              entre éléments du tableau.
 *              <p>La déclaration de la variable globale "resultat" se
 *              trouve dans	"sort.h" </p>
 */
void triInsertion  (elt_t T[], int n)
{
    int i, j;
    elt_t aux;
    
    for (i = 1; i < n; i++)
    {
        aux = T[i];
        resultat.nbAffectations ++;
        
        for (j = i - 1; j >= 0 && T[j] > aux; j--)
        {
            T[j+1] = T[j];
            resultat.nbComparaisons ++;
            resultat.nbAffectations ++;
        }
        if (j >= 0)
            resultat.nbComparaisons ++;
        
        T[j+1] = aux;
        resultat.nbAffectations ++;
    }
}

/**
 *  \fn         void triSelection  (elt_t T[], int n);
 *  \brief      Tri par sélection d'une table T de n éléments
 *  \param      T   la table à trier
 *  \param      n   le nombre d'éléments de la table T
 *  \note       Cette fonction met à jour la variable globale "resultat"
 *              en comptabilisant les comparaisons et affectations
 *              entre éléments du tableau.
 *              <p>La déclaration de la variable globale "resultat" se
 *              trouve dans	"sort.h" </p>
 */
void triSelection  (elt_t T[], int n)
{
    int iMin;
    for(int i = 0; i < n-1;i++)
    {
        iMin = i;
        for(int j = i+1; j < n; j++)
        {
            resultat.nbComparaisons++;
            if( T[j] < T[iMin] )
            {
                iMin = j;
            }
        }
        if( iMin != i)
        {
            // echanger T[i] et T[iMin]
            resultat.nbAffectations += 3;
            elt_t eltAnnexe;
            eltAnnexe = T[iMin];
            T[iMin] = T[i];
            T[i] = eltAnnexe;
        }
    }
}

/**
 *  \fn         void triBulles  (elt_t T[], int n);
 *  \brief      Tri par bulles d'une table T de n éléments
 *  \param      T   la table à trier
 *  \param      n   le nombre d'éléments de la table T
 *  \note       Cette fonction met à jour la variable globale "resultat"
 *              en comptabilisant les comparaisons et affectations
 *              entre éléments du tableau.
 *              <p>La déclaration de la variable globale "resultat" se
 *              trouve dans	"sort.h" </p>
 */
void triBulles     (elt_t T[], int n)
{
    short tableauTrie = 0, i;
    elt_t variableAux;

    while (!tableauTrie) {
        tableauTrie = 1;
        for (i = 0; i < n - 1; i++) {
            resultat.nbComparaisons++;
            if (T[i] > T[i + 1]) {
                resultat.nbAffectations += 3;
                variableAux = T[i];
                T[i] = T[i + 1];
                T[i + 1] = variableAux;
                tableauTrie = 0;
            }
        }
        n--;
    }
}

/**
 *  \fn         void triBull_Flag  (elt_t T[], int n);
 *  \brief      Tri par la méthode du tri par bulles avec drapeau d'une table
 *              T de n éléments
 *  \param      T   la table à trier
 *  \param      n   le nombre d'éléments de la table T
 */
void triBullesFlag  (elt_t T[], int n)
{
    /*          A C O M P L E T E R                                         */
}

/**
 *  \fn         void triShell  (elt_t T[], int n);
 *  \brief      Tri par la méthode du tri Shell d'une table T de n éléments
 *  \param      T   la table à trier
 *  \param      n   le nombre d'éléments de la table T
 */
void triShell     (elt_t T[], int n)
{
    /*          A C O M P L E T E R                                         */
}
