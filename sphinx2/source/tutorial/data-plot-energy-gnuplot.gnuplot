#!/usr/bin/env gnuplot
#
set term wxt 0 persist
set xlabel ' t=S.time'
set grid
set datafile missing 'nan'
set ylabel 'elast,grav,kinetic,nonviscDamp,$\sum$energy=S.energy.total()'
set y2label 'relative error=S.energy.relErr()'
set y2tics
