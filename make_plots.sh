#!/bin/bash      



    cd gnuplot_scripts/
    ./stability_plots.py
    ./multiplot_stability_plots.py
    

    gnuplot stability_rad.gnuplot
    gnuplot stability_rad_profile.gnuplot
    gnuplot stability_phi.gnuplot
    gnuplot stability_theta.gnuplot
    gnuplot vel_binned.gnuplot
    gnuplot vel_vs_r.gnuplot
    gnuplot vel_stability.gnuplot
    gnuplot vel_stability_phi.gnuplot
    gnuplot vel_stability_theta.gnuplot
    gnuplot pots.gnuplot
    gnuplot den.gnuplot
    gnuplot rotation.gnuplot
    gnuplot force.gnuplot
    
    rm stability_rad.gnuplot
    rm stability_rad_profile.gnuplot
    rm stability_phi.gnuplot
    rm stability_theta.gnuplot
    rm vel_binned.gnuplot
    rm vel_vs_r.gnuplot
    rm vel_stability.gnuplot
    rm vel_stability_phi.gnuplot
    rm vel_stability_theta.gnuplot
    rm pots.gnuplot
    rm den.gnuplot
    rm rotation.gnuplot
    rm force.gnuplot

    
    gnuplot stability_rad_multiplot.gnuplot
    gnuplot multiplot_phi.gnuplot
    gnuplot multiplot_theta.gnuplot
    
    gnuplot stability_vel_multiplot.gnuplot
    gnuplot multiplot_vel_theta.gnuplot
    gnuplot multiplot_vel_phi.gnuplot
    
    rm stability_rad_multiplot.gnuplot
    rm multiplot_phi.gnuplot
    rm multiplot_theta.gnuplot
    rm stability_vel_multiplot.gnuplot
    rm multiplot_vel_theta.gnuplot
    rm multiplot_vel_phi.gnuplot