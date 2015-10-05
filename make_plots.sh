#!/bin/bash      



    cd gnuplot_scripts/
    ./stability_plots.py
#     cd ..
    gnuplot stability_rad.gnuplot
    gnuplot stability_phi.gnuplot
    gnuplot stability_theta.gnuplot
    gnuplot vel_binned.gnuplot
    gnuplot vel_vs_r.gnuplot
    gnuplot vel_stability.gnuplot
    gnuplot vel_stability_phi.gnuplot
    gnuplot vel_stability_theta.gnuplot
    
#     rm stability_rad.gnuplot
#     rm stability_phi.gnuplot
#     rm stability_theta.gnuplot
#     rm vel_binned.gnuplot
#     rm vel_vs_r.gnuplot
#     rm vel_stability.gnuplot
#     rm vel_stability_phi.gnuplot
#     rm vel_stability_theta.gnuplot