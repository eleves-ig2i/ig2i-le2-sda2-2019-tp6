/**
 *  \file       utilSort.c
 *  \brief      Fichier d'implémentation des fonctions utilisées pour
 *              le programme d'évaluation de diverses méthodes de tri
 *
 *  \date       24 Novembre 2018
 *  \author     Samir El khattabi
 *  \version    1.0
 *
 *//****************************************************************************/
/*      I N C L U D E(s)  S T A N D A R D(s)                                */
/****************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

/****************************************************************************/
/*      I N C L U D E(s)  S P E C I F I Q U E(s)                            */
/****************************************************************************/
#include "types.h"
#include "utilSort.h"

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
void tester1Tri ( const char * nom,  void (*tri)(elt_t [], int),
               elt_t Table[], int nmax)
{
    int i;
    int mode;
    clock_t start, stop;
    unsigned long nbH;
    
    
    printf("+-------------------------+\n");
    printf("|   %15s       |\n", nom);
    printf("+-----------+-------------+----------------+----------------"
           "+----------------+\n");
    printf("| %8s  | %10s  |  %12s  |  %12s  |  %12s  |\n",
           "Taille","  Mode  ", "Nb compar. ",  "Nb affect. ", "  Duree (ms)");
    printf("+-----------+-------------+----------------+----------------"
           "+----------------+\n");
    
    for (mode = 0; mode <= 2; mode ++)
    {
        for (i = 0; nbElements[i] <= nmax; i++)
        {
            initialiser(Table, nbElements[i], mode);
            RaZ(resultat);
            start = clock();
            (*tri)(Table, nbElements[i]);
            stop = clock();
            if (!estOrdonne(Table, nbElements[i], mode == 0 || mode == 2))
                printf("Cette table n'est pas ordonnee\n");
            else
            {
                printf("|  %6d   | %10s  |",
                       nbElements[i] ,
                       modes[mode]);
                nbH = (unsigned long)(resultat.nbComparaisons/1000000);
                if (nbH > 0)
                    printf("  %6lu%06lu  |", nbH,
                           (unsigned long)(resultat.nbComparaisons%1000000));
                else
                    printf("  %6s%6lu  |", " ",
                           (unsigned long)(resultat.nbComparaisons%1000000));
                nbH = (unsigned long)(resultat.nbAffectations/1000000);
                if (nbH > 0)
                    printf("  %6lu%06lu  |", nbH,
                           (unsigned long)(resultat.nbAffectations%1000000));
                else
                    printf("  %6s%6lu  |", " ",
                           (unsigned long)(resultat.nbAffectations%1000000));
                
                resultat.duree_en_clock_t = stop - start;
                printf("  %10.0f    |\n",
                       1000.*resultat.duree_en_clock_t/CLOCKS_PER_SEC);
            }
        }
        printf("+-----------+-------------+----------------+----------------"
               "+----------------+\n");
    }
    printf("\n\n");
}

/**
 *  \fn             void creerFichiers(const char *nom, char *Filename_log, char *Filename_plt)
 *  \brief          Création du fichier de commande Gnuplot permettant l'affichage des courbes
 *                  d'évolution des nombres de comparaisons et d'affectations.
 *                  <p>Construit le nom du fichier de résultat </p>
 *  \param          nom     nom de la méthode de tri
 *  \param          Filename_log    Nom du fichier de données de Gnuplot
 *  \param          Filename_plt    Nom du fichier de commande Gnuplot
 *  \note           ArrÍt du programme si la construction du fichier
 *                  de commandes échoue
 */
void creerFichiers(const char *nom, char *Filename_log, char *Filename_plt)
{
    char Filename_aff[FILENAME_MAX + 1]; /* Fichier graph. des affectations */
    char Filename_cmp[FILENAME_MAX + 1]; /* Fichier graph. des compar. */
    FILE *fp;
    int i;
    
    /*  Constructions des noms de fichiers */
    for (i = 0; i < strlen(nom); i++)
        if (i == 0)
            Filename_log [i] = nom[i];
        else
            Filename_log [i] = nom[i] == ' ' ? '_' : tolower(nom[i]);
    for (i--; Filename_log[i] == '_'; i--);
    Filename_log [i+1] = '\0';
    strcpy(Filename_plt, Filename_log);
    strcpy(Filename_aff, Filename_log);
    strcpy(Filename_cmp, Filename_log);
    
    strcat(Filename_log, SUFFIXE_DATA);
    strcat(Filename_plt, SUFFIXE_GNUPLOT);
    strcat(Filename_aff, SUFFIXE_AFFECTATIONS);
    strcat(Filename_cmp, SUFFIXE_COMPARAISONS);
    
    /* Création du fichier de commandes Gnuplot */
    if ( (fp =fopen(Filename_plt, "wt")) == NULL)
    {
        perror(Filename_plt);
        exit(-1);
    }
    fprintf(fp, "#--------------------------------");
    for (i= 0; i < strlen(Filename_plt); i++)
        fprintf(fp,"-");
    fprintf(fp, "-+\n");
    fprintf(fp, "# Fichier de commandes gnuplot : %s |\n", Filename_plt);
    fprintf(fp, "#--------------------------------");
    for (i= 0; i < strlen(Filename_plt); i++)
        fprintf(fp,"-");
    fprintf(fp, "-+\n");
    fprintf(fp, "#\n");
    
    fprintf(fp, "set style data  lines\n");
    fprintf(fp, "set xlabel \"Nombre d'éléments\"\n");
    fprintf(fp, "set ylabel \"Nombre d'affectations\"\n");
    fprintf(fp, "set title  \"%s\"\n", nom);
    fprintf(fp, "set grid\n");
    fprintf(fp, "plot '%s' using 1:2 title '%s',\\\n",  Filename_log, modes[0]);
    fprintf(fp, "     '%s' using 1:4 title '%s'  ,\\\n",Filename_log, modes[1]);
    fprintf(fp, "     '%s' using 1:6 title '%s'\n",     Filename_log, modes[2]);
    fprintf(fp, "set terminal png\n");
    fprintf(fp, "set output '%s'\n", Filename_aff);
    fprintf(fp, "replot\n");
    fprintf(fp, "set terminal\n");
    fprintf(fp, "pause -1 \"Press return\"\n");
    fprintf(fp, "set ylabel \"Nombre de comparaisons\"\n");
    fprintf(fp, "plot '%s' using 1:3 title '%s',\\\n",  Filename_log, modes[0]);
    fprintf(fp, "     '%s' using 1:5 title '%s'  ,\\\n",Filename_log, modes[1]);
    fprintf(fp, "     '%s' using 1:7 title '%s'\n",     Filename_log, modes[2]);
    fprintf(fp, "pause -1 \"Press return\"\n");
    fprintf(fp, "set terminal png\n");
    fprintf(fp, "set output '%s'\n", Filename_cmp);
    fprintf(fp, "replot\n");
    fprintf(fp, "quit\n");
    fclose(fp);
}

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
void tester1TriV2 ( const char * nom,  void (*tri)(elt_t [], int),
                 elt_t Table[], int nmax)
{
    int i;
    int mode;
    clock_t start, stop;
    unsigned long nbH;
    char CmdLine[CMDLINE_MAX +1];
    FILE *fp;
    char Filename_log[FILENAME_MAX + 1];
    char Filename_plt[FILENAME_MAX + 1];
    
    creerFichiers(nom, Filename_log, Filename_plt);
    
    if ((fp = fopen(Filename_log, "wt")) == NULL)
    {
        perror(Filename_log);
        exit(-1);
    }
    
    fprintf(fp, "#--");
    for (i= 0; i < strlen(nom); i++)
        fprintf(fp,"-");
    fprintf(fp, "--+\n");
    fprintf(fp, "#  %s  |\n", nom);
    fprintf(fp, "#--");
    for (i= 0; i < strlen(nom); i++)
        fprintf(fp,"-");
    fprintf(fp, "--+\n");
    fprintf(fp, "#\n");
    
    
    fprintf(fp,"#+--------+-----------------------------+-----------------------------+-----------------------------+\n");
    fprintf(fp,"#|        |           Ordonné           |          Aleatoire          |           Inverse           |\n");
    fprintf(fp,"#| Taille | Affectations   Comparaisons | Affectations   Comparaisons | Affectations   Comparaisons |\n");
    fprintf(fp,"#+ -------+--------------+--------------+--------------+--------------+--------------+--------------+\n");
    
    for (i = 1; i <= nmax; i++)
    {
        fprintf(fp,"%8d   ", i);
        for (mode = 0; mode <= 2; mode ++)
        {
            initialiser(Table, i, mode);
            RaZ(resultat);
            start = clock();
            (*tri)(Table, i);
            stop = clock();
            if (!estOrdonne(Table, i, mode == 0 || mode == 2))
                printf("Cette table n'est pas ordonnee\n");
            else
            {
                nbH = (unsigned long)(resultat.nbAffectations/1000000);
                if (nbH > 0)
                    fprintf(fp, "%6lu%06lu    ", nbH,
                            (unsigned long)(resultat.nbAffectations%1000000));
                else
                    fprintf(fp, "%6s%6lu    ", " ",
                            (unsigned long)(resultat.nbAffectations%1000000));
                
                nbH = (unsigned long)(resultat.nbComparaisons/1000000);
                if (nbH > 0)
                    fprintf(fp,"%6lu%06lu  ", nbH,
                            (unsigned long)(resultat.nbComparaisons%1000000));
                else
                    fprintf(fp, "%6s%6lu  ", " ",
                            (unsigned long)(resultat.nbComparaisons%1000000));
            }
        }
        fprintf(fp, "\n");
    }
    fprintf(fp,"#+ -------+--------------+--------------+--------------+--------------+--------------+--------------+\n");
    fclose(fp);
    sprintf(CmdLine,"%s %s\n", GNUPLOT, Filename_plt);
    system(CmdLine);
}

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
void initialiser (elt_t T[], int n, int mode)
{
    int i;
    
    
    for (i = 0; i < n; i++)
        switch (mode)
    {
        case 0 :        // Ordonné
            T[i] = i;
            break;
        case 1 :        //  Aléatoire
            T[i] = ((double) rand() / ((double)RAND_MAX +1)) * n;
            break;
        case 2 :        // Inverse
            T[i] = n - i - 1;
            break;
    }
}

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
int estOrdonne (elt_t T[], int n, int strict)
{
    int i;
    if (strict)
        
        for (i = 1; i < n && T[i] > T[i-1]; i++);
    else
        for (i = 1; i < n && T[i] >= T[i-1]; i++);

    
    return i == n;

    //return 1;
}

/**
 *  \fn             void afficher       (elt_t T[], int n);
 *  \brief          Affiche les valeurs des n premiers éléments de t
 *  \param          T   la table d'éléments
 *  \param          n   le nombre d'éléments à afficher
 */
void afficher(elt_t T[], int n)
{
    int i;
    
    printf("\n");
    for (i = 1; i <=  (n > NB_PER_LINE ? NB_PER_LINE : n); i++)
        printf("------");
    printf("\n");
    
    for (i = 0; i < n; i++)
    {
        printf("%5d", T[i]);
        if ((i + 1) % NB_PER_LINE == 0)
            printf("\n");
        else
            printf(" ");
    }
    printf("\n");
    for (i = 1; i <=  (n > NB_PER_LINE ? NB_PER_LINE : n); i++)
        printf("------");
    printf("\n");
}
