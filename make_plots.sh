#!/bin/bash      

    gnuplot gnuplot_scripts/stability_plots.gnuplot 
    gnuplot gnuplot_scripts/theta.gnuplot
    gnuplot gnuplot_scripts/phi.gnuplot
    gnuplot gnuplot_scripts/vel.gnuplot
    gnuplot gnuplot_scripts/v_vs_r.gnuplot
    gnuplot gnuplot_scripts/vel_theory_binned.gnuplot
    gnuplot gnuplot_scripts/vel_phi.gnuplot
    gnuplot gnuplot_scripts/vel_theta.gnuplot
#       xdg-open run1/plots/radii_distribution.jpeg