#!/bin/bash      



    cd gnuplot_scripts/
    ./stability_plots.py
#     cd ..
    gnuplot stability_rad.gnuplot
    gnuplot stability_phi.gnuplot
    gnuplot stability_theta.gnuplot
    gnuplot vel_binned.gnuplot
    gnuplot v_vs_r.gnuplot
    gnuplot vel_stability.gnuplot
    gnuplot vel_stability_phi.gnuplot
    gnuplot vel_stability_theta.gnuplot