#!/bin/bash      

plot_stability=true
plot_multiplot_stability=false
plot_multi_comp_stability=true

    cd gnuplot_scripts/
    
#     this is for the individual stability plots         #
if [ "$plot_stability" = true ] ; then
    ./stability_plots.py
    echo 'plotting stability plots'
fi

#    for the multiplot showing a single comp over time   #
if [ "$plot_multiplot_stability" = true ] ; then
    #     ./multiplot_stability_plots.py
    echo 'plotting multitime stability plots'
fi


#    for multiplots showing both comp for a given time   #
if [ "$plot_multi_comp_stability" = true ] ; then
    ./multi_comp_stability_plots.py
    echo 'plotting multicomponent stability plots'
fi
    

if [ "$plot_stability" = true ] ; then    
#         The plotting scripts for the individual stability plots     #
        gnuplot stability_rad.gnuplot
        gnuplot stability_rad_profile.gnuplot
        gnuplot stability_phi.gnuplot
        gnuplot stability_theta.gnuplot

        #gnuplot vel_binned.gnuplot
        gnuplot vel_vs_r.gnuplot

        gnuplot vel_stability.gnuplot
        gnuplot vel_stability_phi.gnuplot
        gnuplot vel_stability_theta.gnuplot

        #gnuplot pots.gnuplot
        #gnuplot den.gnuplot
        #gnuplot rotation.gnuplot
        #gnuplot force.gnuplot
        
#         rm stability_rad.gnuplot
        rm stability_rad_profile.gnuplot
        rm stability_phi.gnuplot
        rm stability_theta.gnuplot
        
        rm vel_binned.gnuplot
        rm vel_vs_r.gnuplot
        
        rm vel_stability.gnuplot
        rm vel_stability_phi.gnuplot
        rm vel_stability_theta.gnuplot
        
        #rm pots.gnuplot
        #rm den.gnuplot
        #rm rotation.gnuplot
        #rm force.gnuplot
fi
    
if [ "$plot_multiplot_stability" = true ] ; then   
#     the plotting scipts for the single comp over time     #
        gnuplot multiplot_rad.gnuplot
        gnuplot multiplot_phi.gnuplot
        gnuplot multiplot_theta.gnuplot
        gnuplot multioplot_vel.gnuplot
        gnuplot multiplot_vel_theta.gnuplot
        gnuplot multiplot_vel_phi.gnuplot
        
        rm multiplot_rad.gnuplot
        rm multiplot_phi.gnuplot
        rm multiplot_theta.gnuplot
        rm multiplot_vel.gnuplot
        rm multiplot_vel_theta.gnuplot
        rm multiplot_vel_phi.gnuplot
    
fi

if [ "$plot_multi_comp_stability" = true ] ; then
#     the plotting scripts for the multi comp for a given tim    #
    gnuplot multi_comp_stability_rad.gnuplot
    gnuplot multi_comp_stability_pi.gnuplot
    gnuplot multi_comp_stability_theta.gnuplot
    gnuplot multi_comp_stability_vel.gnuplot
    gnuplot multi_comp_stability_vel_phi.gnuplot
    gnuplot multi_comp_stability_vel_theta.gnuplot
    
    rm multi_comp_stability_rad.gnuplot
    rm multi_comp_stability_pi.gnuplot
    rm multi_comp_stability_theta.gnuplot
    rm multi_comp_stability_vel.gnuplot
    rm multi_comp_stability_vel_phi.gnuplot
    rm multi_comp_stability_vel_theta.gnuplot 
fi