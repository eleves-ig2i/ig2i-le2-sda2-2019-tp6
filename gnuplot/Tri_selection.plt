#--------------------------------------------------+
# Fichier de commandes gnuplot : Tri_selection.plt |
#--------------------------------------------------+
#
set style data  lines
set xlabel "Nombre d'éléments"
set ylabel "Nombre d'affectations"
set title  "TRI SELECTION"
set grid
plot 'Tri_selection.dat' using 1:2 title ' ordonne ',\
     'Tri_selection.dat' using 1:4 title 'aleatoire'  ,\
     'Tri_selection.dat' using 1:6 title ' inverse '
set terminal png
set output 'Tri_selection_aff.png'
replot
set terminal
pause -1 "Press return"
set ylabel "Nombre de comparaisons"
plot 'Tri_selection.dat' using 1:3 title ' ordonne ',\
     'Tri_selection.dat' using 1:5 title 'aleatoire'  ,\
     'Tri_selection.dat' using 1:7 title ' inverse '
pause -1 "Press return"
set terminal png
set output 'Tri_selection_cmp.png'
replot
quit
