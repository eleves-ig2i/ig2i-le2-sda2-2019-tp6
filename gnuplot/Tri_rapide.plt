#-----------------------------------------------+
# Fichier de commandes gnuplot : Tri_rapide.plt |
#-----------------------------------------------+
#
set style data  lines
set xlabel "Nombre d'éléments"
set ylabel "Nombre d'affectations"
set title  "TRI RAPIDE   "
set grid
plot 'Tri_rapide.dat' using 1:2 title ' ordonne ',\
     'Tri_rapide.dat' using 1:4 title 'aleatoire'  ,\
     'Tri_rapide.dat' using 1:6 title ' inverse '
set terminal png
set output 'Tri_rapide_aff.png'
replot
set terminal
pause -1 "Press return"
set ylabel "Nombre de comparaisons"
plot 'Tri_rapide.dat' using 1:3 title ' ordonne ',\
     'Tri_rapide.dat' using 1:5 title 'aleatoire'  ,\
     'Tri_rapide.dat' using 1:7 title ' inverse '
pause -1 "Press return"
set terminal png
set output 'Tri_rapide_cmp.png'
replot
quit
