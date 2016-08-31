#! /usr/bin/python
import os

outputs = [ "0", "0p25", "0p50", "0p75", "1", "2", "3", "4"]
sim_time = [ "0", "p25", "p50", "p75", "1", "2", "3", "4"]
titles   = [ "0.0", "0.25" , "0.5" , "0.75" , "1.0", "2.0", "3.0", "4.0"]

outputs = [ "0", "2"]
sim_time = [ "0", "2"]
titles   = [ "0.0", "2"]
N        = 1
M        = 0
plot_dark = True
plot_light = True
plot_both = True
plot_theory = True
if(plot_light == True):
    print("plotting light")
if(plot_dark == True):
    print("plotting dark")
if(plot_both == True):
    print("plotting both")

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##RADIUS binned
theory_den = "~/Desktop/research/data_testing/theory/theory_den.dat"
light      = "~/Desktop/research/data_testing/binned_data/light_matter_bins_"
dark       = "~/Desktop/research/data_testing/binned_data/dark_matter_bins_"
both       = "~/Desktop/research/data_testing/binned_data/both_matter_bins_"

###
f = open('stability_rad_multiplot.gnuplot', 'w')
f.write("reset\n")
f.write("set terminal jpeg size 6000,2000\n")
f.write("set key off\n")
f.write("set ylabel 'counts'\n")
f.write("set xlabel 'radius (kpc)'\n")
f.write("set xrange[0:0.1]\n")
f.write("set yrange[0:6500]\n\n\n")

f.write("set output \"~/Desktop/research/data_testing/plots/rad/radii_distribution_multiplot.jpeg\" \n")
f.write("set multiplot layout 2,4 rowsfirst\n")
for i in range(M, N):
    if(plot_light == True):
        p = light + sim_time[i] + "gy.dat"
        f.write("set title '" + titles[i] + "Gy \n")
        f.write("plot '" + p + "' using 2:1  with boxes, '" + theory_den + "' using 1:3 with lines title 'light'\n\n") 
        
f.write("unset multiplot \n")
f.close()
###

f = open('stability_rad.gnuplot', 'w')
f.write("reset\n")
f.write("set terminal jpeg\n")
f.write("set key on\n")
f.write("set ylabel 'counts'\n")
f.write("set xlabel 'radius (kpc)'\n")
f.write("set xrange[0:30]\n")
f.write("set yrange[0:1000]\n\n\n")

for i in range(M, N):
    if(plot_light == True):
        p = light + sim_time[i] + "gy.dat"
        f.write("set output \"~/Desktop/research/data_testing/plots/rad/radii_distribution_light_" + outputs[i] + "gy.jpeg\" \n")
        f.write("set title 'Histogram of Light Matter Distribution After " + titles[i] + "Gy' \n")
        f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory_den + "' using 1:2 with lines title 'both', '" + theory_den + "' using 1:3 with lines title 'light', '" + theory_den + "' using 1:4 with lines title 'dark' \n\n") 

    if(plot_dark == True):
        p = dark + sim_time[i] + "gy.dat"
        f.write("set output \"~/Desktop/research/data_testing/plots/rad/radii_distribution_dark_" + outputs[i] + "gy.jpeg\" \n")
        f.write("set title 'Histogram of Dark Matter Distribution After " + titles[i] + "Gy' \n")
        f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory_den + "' using 1:2 with lines title 'both', '" + theory_den + "' using 1:3 with lines title 'light', '" + theory_den + "' using 1:4 with lines title 'dark' \n\n") 

    if(plot_both == True):
        p = both + sim_time[i] + "gy.dat"
        f.write("set output \"~/Desktop/research/data_testing/plots/rad/radii_distribution_both_" + outputs[i] + "gy.jpeg\" \n")
        f.write("set title 'Histogram of Combined Matter Distribution After " + titles[i] + "Gy' \n")
        f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory_den + "' using 1:2 with lines title 'both', '" + theory_den + "' using 1:3 with lines title 'light', '" + theory_den + "' using 1:4 with lines title 'dark' \n\n") 

    f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")
    f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")

f.close()


##RADIUS density profile
theory_den = "~/Desktop/research/data_testing/theory/theory_den.dat"
light      = "~/Desktop/research/data_testing/binned_data/light_matter_bins_"
dark       = "~/Desktop/research/data_testing/binned_data/dark_matter_bins_"
both       = "~/Desktop/research/data_testing/binned_data/both_matter_bins_"

f = open('stability_rad_profile.gnuplot', 'w')
f.write("reset\n")
f.write("set terminal jpeg\n")
f.write("set key on\n")
f.write("set ylabel 'counts'\n")
f.write("set xlabel 'radius (kpc)'\n")
f.write("set xrange[0:30]\n")
f.write("set yrange[0:1.8]\n\n\n")

for i in range(M, N):
    if(plot_light == True):
        p = light + sim_time[i] + "gy.dat"
        f.write("set output \"~/Desktop/research/data_testing/plots/rad_profile/radii_distribution_light_profile.jpeg\" \n")
        f.write("set title 'Histogram of Light Matter Density Profile\n")
        f.write("plot '" + theory_den + "' using 1:5 with lines title 'both', '" + theory_den + "' using 1:6 with lines title 'light', '" + theory_den + "' using 1:7 with lines title 'dark' \n\n") 

    if(plot_dark == True):
        p = dark + sim_time[i] + "gy.dat"
        f.write("set output \"~/Desktop/research/data_testing/plots/rad_profile/radii_distribution_dark_profile.jpeg\" \n")
        f.write("set title 'Histogram of Light Matter Density Profile\n")
        f.write("plot '" + theory_den + "' using 1:5 with lines title 'both', '" + theory_den + "' using 1:6 with lines title 'light', '" + theory_den + "' using 1:7 with lines title 'dark' \n\n") 

    if(plot_both == True):
        p = both + sim_time[i] + "gy.dat"
        f.write("set output \"~/Desktop/research/data_testing/plots/rad_profile/radii_distribution_both_profile.jpeg\" \n")
        f.write("set title 'Histogram of Light Matter Density Profile\n")
        f.write("plot '" + theory_den + "' using 1:5 with lines title 'both', '" + theory_den + "' using 1:6 with lines title 'light', '" + theory_den + "' using 1:7 with lines title 'dark' \n\n") 

    f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")
    f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")

f.close()

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##RADIAL PHI
theory_phi   = "~/Desktop/research/data_testing/theory/theory_phi.dat"
light = "~/Desktop/research/data_testing/binned_data/phi_light_"
dark  = "~/Desktop/research/data_testing/binned_data/phi_dark_"
both  = "~/Desktop/research/data_testing/binned_data/phi_both_"

f = open('stability_phi.gnuplot', 'w')
f.write("reset\n")
f.write("set terminal jpeg\n")
f.write("set key on\n")
f.write("set ylabel 'counts'\n")
f.write("set xlabel 'phi (rad)'\n")
f.write("set xrange[-5:5]\n")
f.write("set yrange[0:1200]\n\n\n")

for i in range(M, N):
    if(plot_light == True):
        p = light + sim_time[i] + "gy.dat"
        f.write("set output \"~/Desktop/research/data_testing/plots/phi/phi_light_" + outputs[i] + "gy.jpeg\" \n")
        f.write("set title 'Histogram of Light Matter Phi Distribution After " + titles[i] + "Gy' \n")
        f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory_phi + "' using 1:2 with lines title 'both', '" + theory_phi + "' using 1:3 with lines title 'light', '" + theory_phi + "' using 1:4 with lines title 'dark' \n\n") 

    if(plot_dark == True):
        p = dark + sim_time[i] + "gy.dat"
        f.write("set output \"~/Desktop/research/data_testing/plots/phi/phi_dark_" + outputs[i] + "gy.jpeg\" \n")
        f.write("set title 'Histogram of Dark Matter Phi Distribution After " + titles[i] + "Gy' \n")
        f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory_phi + "' using 1:2 with lines title 'both', '" + theory_phi + "' using 1:3 with lines title 'light', '" + theory_phi + "' using 1:4 with lines title 'dark' \n\n") 

    if(plot_both == True):
        p = both + sim_time[i] + "gy.dat"
        f.write("set output \"~/Desktop/research/data_testing/plots/phi/phi_both_" + outputs[i] + "gy.jpeg\" \n")
        f.write("set title 'Histogram of Combined Matter Phi Distribution After " + titles[i] + "Gy' \n")
        f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory_phi + "' using 1:2 with lines title 'both', '" + theory_phi + "' using 1:3 with lines title 'light', '" + theory_phi + "' using 1:4 with lines title 'dark' \n\n") 

    f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")
    f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")

f.close()

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##RADIAL THETA
theory   = "~/Desktop/research/data_testing/theory/theory_theta.dat"
light = "~/Desktop/research/data_testing/binned_data/theta_light_"
dark  = "~/Desktop/research/data_testing/binned_data/theta_dark_"
both  = "~/Desktop/research/data_testing/binned_data/theta_both_"

f = open('stability_theta.gnuplot', 'w')
f.write("reset\n")
f.write("set terminal jpeg\n")
f.write("set key on\n")
f.write("set ylabel 'counts'\n")
f.write("set xlabel 'theta (rad)'\n")
f.write("set xrange[0:4]\n")
f.write("set yrange[0:1200]\n\n\n")

for i in range(M, N):
    if(plot_light == True):
        p = light + sim_time[i] + "gy.dat"
        f.write("set output \"~/Desktop/research/data_testing/plots/theta/theta_light_" + outputs[i] + "gy.jpeg\" \n")
        f.write("set title 'Histogram of Light Matter Theta Distribution After " + titles[i] + "Gy' \n")
        f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory + "' using 1:2 with lines title 'both', '" + theory + "' using 1:3 with lines title 'light', '" + theory + "' using 1:4 with lines title 'dark' \n\n") 

    if(plot_dark == True):
        p = dark + sim_time[i] + "gy.dat"
        f.write("set output \"~/Desktop/research/data_testing/plots/theta/theta_dark_" + outputs[i] + "gy.jpeg\" \n")
        f.write("set title 'Histogram of Dark Matter Theta Distribution After " + titles[i] + "Gy' \n")
        f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory + "' using 1:2 with lines title 'both', '" + theory + "' using 1:3 with lines title 'light', '" + theory + "' using 1:4 with lines title 'dark' \n\n") 

    if(plot_both == True):
        p = both + sim_time[i] + "gy.dat"
        f.write("set output \"~/Desktop/research/data_testing/plots/theta/theta_both_" + outputs[i] + "gy.jpeg\" \n")
        f.write("set title 'Histogram of Combined Matter Theta Distribution After " + titles[i] + "Gy' \n")
        f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory + "' using 1:2 with lines title 'both', '" + theory + "' using 1:3 with lines title 'light', '" + theory + "' using 1:4 with lines title 'dark' \n\n") 

    f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")
    f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")

f.close()

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##VELOCITY VS THEORY
theory_light   = "~/Desktop/research/data_testing/binned_data/light_matter_theory_vel_bins.dat"
theory_dark   = "~/Desktop/research/data_testing/binned_data/dark_matter_theory_vel_bins.dat"
light = "~/Desktop/research/data_testing/binned_data/light_matter_vel_bins_"
dark  = "~/Desktop/research/data_testing/binned_data/dark_matter_vel_bins_"

f = open('vel_stability.gnuplot', 'w')
f.write("reset\n")
f.write("set terminal jpeg\n")
f.write("set key off\n")
f.write("set ylabel 'counts'\n")
f.write("set xlabel 'vel (km/s)'\n")
f.write("set xrange[0:20]\n")
f.write("set yrange[0:500]\n")
f.write("set style fill transparent solid 0.2\n\n\n")


for i in range(M, N):
    if(plot_light == True):
        p = light + sim_time[i] + "gy.dat"
        f.write("set output \"~/Desktop/research/data_testing/plots/vel_dist/binned_vs_tbins/vel_distribution_light_theory_" + outputs[i] + "gy.jpeg\" \n")
        f.write("set title 'Histogram of Light Matter Velocity Distribution After " + titles[i] + "Gy' \n")
        f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory_light + "' using 2:1 with lines  title 'light theory'  lw 2   \n\n") 

    if(plot_dark == True):
        p = dark + sim_time[i] + "gy.dat"
        f.write("set output \"~/Desktop/research/data_testing/plots/vel_dist/binned_vs_tbins/vel_distribution_dark_theory_" + outputs[i] + "gy.jpeg\" \n")
        f.write("set title 'Histogram of Dark Matter Velocity Distribution After " + titles[i] + "Gy' \n")
        f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory_dark + "' using 2:1 with lines title 'dark theory' lw 2  \n\n") 


    f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")
    f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")

f.close()


# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##VELOCITY PHI
theory_phi   = "~/Desktop/research/data_testing/theory/theory_phi.dat"
light = "~/Desktop/research/data_testing/binned_data/phi_vel_light_"
dark  = "~/Desktop/research/data_testing/binned_data/phi_vel_dark_"
both  = "~/Desktop/research/data_testing/binned_data/phi_vel_both_"

f = open('vel_stability_phi.gnuplot', 'w')
f.write("reset\n")
f.write("set terminal jpeg\n")
f.write("set key on\n")
f.write("set ylabel 'counts'\n")
f.write("set xlabel 'phi (rad)'\n")
f.write("set xrange[-5:5]\n")
f.write("set yrange[0:1200]\n\n\n")

for i in range(M, N):
    if(plot_light == True):
        p = light + sim_time[i] + "gy.dat"
        f.write("set output \"~/Desktop/research/data_testing/plots/vel_phi/phi_vel_light_" + outputs[i] + "gy.jpeg\" \n")
        f.write("set title 'Histogram of Light Matter Velocity Phi Distribution After " + titles[i] + "Gy' \n")
        f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory_phi + "' using 1:2 with lines title 'both', '" + theory_phi + "' using 1:3 with lines title 'light', '" + theory_phi + "' using 1:4 with lines title 'dark' \n\n") 

    if(plot_dark == True):
        p = dark + sim_time[i] + "gy.dat"
        f.write("set output \"~/Desktop/research/data_testing/plots/vel_phi/phi_vel_dark_" + outputs[i] + "gy.jpeg\" \n")
        f.write("set title 'Histogram of Dark Matter Velocity Phi Distribution After " + titles[i] + "Gy' \n")
        f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory_phi + "' using 1:2 with lines title 'both', '" + theory_phi + "' using 1:3 with lines title 'light', '" + theory_phi + "' using 1:4 with lines title 'dark' \n\n") 

    if(plot_both == True):
        p = both + sim_time[i] + "gy.dat"
        f.write("set output \"~/Desktop/research/data_testing/plots/vel_phi/phi_vel_both_" + outputs[i] + "gy.jpeg\" \n")
        f.write("set title 'Histogram of Combined Matter Velocity Phi Distribution After " + titles[i] + "Gy' \n")
        f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory_phi + "' using 1:2 with lines title 'both', '" + theory_phi + "' using 1:3 with lines title 'light', '" + theory_phi + "' using 1:4 with lines title 'dark' \n\n") 

    f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")
    f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")

f.close()



# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##VELOCITY THETA
theory   = "~/Desktop/research/data_testing/theory/theory_theta.dat"
light = "~/Desktop/research/data_testing/binned_data/theta_vel_light_"
dark  = "~/Desktop/research/data_testing/binned_data/theta_vel_dark_"
both  = "~/Desktop/research/data_testing/binned_data/theta_vel_both_"

f = open('vel_stability_theta.gnuplot', 'w')
f.write("reset\n")
f.write("set terminal jpeg\n")
f.write("set key on\n")
f.write("set ylabel 'counts'\n")
f.write("set xlabel 'theta (rad)'\n")
f.write("set xrange[0:4]\n")
f.write("set yrange[0:1200]\n\n\n")

for i in range(M, N):
    if(plot_light == True):
        p = light + sim_time[i] + "gy.dat"
        f.write("set output \"~/Desktop/research/data_testing/plots/vel_theta/theta_vel_light_" + outputs[i] + "gy.jpeg\" \n")
        f.write("set title 'Histogram of Light Matter Velocity Theta Distribution After " + titles[i] + "Gy' \n")
        f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory + "' using 1:2 with lines title 'both', '" + theory + "' using 1:3 with lines title 'light', '" + theory + "' using 1:4 with lines title 'dark' \n\n") 

    if(plot_dark == True):
        p = dark + sim_time[i] + "gy.dat"
        f.write("set output \"~/Desktop/research/data_testing/plots/vel_theta/theta_vel_dark_" + outputs[i] + "gy.jpeg\" \n")
        f.write("set title 'Histogram of Dark Matter Velocity Theta Distribution After " + titles[i] + "Gy' \n")
        f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory + "' using 1:2 with lines title 'both', '" + theory + "' using 1:3 with lines title 'light', '" + theory + "' using 1:4 with lines title 'dark' \n\n") 

    if(plot_both == True):
        p = both + sim_time[i] + "gy.dat"
        f.write("set output \"~/Desktop/research/data_testing/plots/vel_theta/theta_vel_both_" + outputs[i] + "gy.jpeg\" \n")
        f.write("set title 'Histogram of Combined Matter Velocity Theta Distribution After " + titles[i] + "Gy' \n")
        f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory + "' using 1:2 with lines title 'both', '" + theory + "' using 1:3 with lines title 'light', '" + theory + "' using 1:4 with lines title 'dark' \n\n") 

    f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")
    f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")

f.close()



# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##VELOCITY VS RADIUS
theory   = "~/Desktop/research/data_testing/theory/theory_vel.dat"
light = "~/Desktop/research/data_testing/actual/light_matter_velocity_dist_"
dark  = "~/Desktop/research/data_testing/actual/dark_matter_velocity_dist_"

f = open('vel_vs_r.gnuplot', 'w')
f.write("reset\n")
f.write("set terminal jpeg\n")
f.write("set key on\n")
f.write("set ylabel 'vel (km/s)'\n")
f.write("set xlabel 'radius (kpc)'\n")
f.write("set xrange[0:15]\n")
f.write("set yrange[0:6]\n\n\n")

for i in range(M, N):
    if(plot_light == True):
        p = light + sim_time[i] + "gy.dat"
        f.write("set output \"~/Desktop/research/data_testing/plots/vel_dist/vel_vs_r/vel_vs_r_light_" + outputs[i] + "gy.jpeg\" \n")
        f.write("set title 'Light Velocity as a function of Radius After " + titles[i] + "Gy' \n")
        #f.write("plot '" + p + "' using 1:2  with dots title 'actual', '" + theory + "' using 1:2 with lines title 'both', '" + theory + "' using 1:3 with lines title 'light', '" + theory + "' using 1:4 with lines title 'dark' \n\n")
        f.write("plot '" + p + "' using 1:2  with dots title 'actual' \n\n", )

    if(plot_dark == True):
        p = dark + sim_time[i] + "gy.dat"
        f.write("set output \"~/Desktop/research/data_testing/plots/vel_dist/vel_vs_r/vel_vs_r_dark_" + outputs[i] + "gy.jpeg\" \n")
        f.write("set title 'Dark Velocity as a function of Radius After " + titles[i] + "Gy' \n")
        #f.write("plot '" + p + "' using 1:2  with dots title 'actual', '" + theory + "' using 1:2 with lines title 'both', '" + theory + "' using 1:3 with lines title 'light', '" + theory + "' using 1:4 with lines title 'dark' \n\n")
        f.write("plot '" + p + "' using 1:2  with dots title 'actual'\n\n", )


    f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")
    f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")

f.close()





# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
###VELOCITY DISTRIBUTION
###This is the one without theory
#theory   = "~/Desktop/research/data_testing/theory/theory_vel.dat"
#light = "~/Desktop/research/data_testing/binned_data/light_matter_norm_vel_bins_"
#dark  = "~/Desktop/research/data_testing/binned_data/dark_matter_norm_vel_bins_"

#f = open('vel_binned.gnuplot', 'w')
#f.write("reset\n")
#f.write("set terminal jpeg\n")
#f.write("set key on\n")
#f.write("set ylabel 'counts'\n")
#f.write("set xlabel 'velocity (km/s)'\n")
#f.write("set xrange[0:1]\n")
#f.write("set yrange[0:400]\n")
#f.write("set style fill transparent solid 0.2\n\n\n")


#for i in range(M, N):
    #if(plot_light == True):
        #p = light + sim_time[i] + "gy.dat"
        #f.write("set output \"~/Desktop/research/data_testing/plots/vel_dist/binned/vel_distribution_light_" + outputs[i] + "gy.jpeg\" \n")
        #f.write("set title 'Histogram of Light Matter Velocity Distribution After " + titles[i] + "Gy' \n")
        #f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory + "' using 1:2 with lines  title 'light dist'  lw 2   \n\n", )

    #if(plot_dark == True):
        #p = dark + sim_time[i] + "gy.dat"
        #f.write("set output \"~/Desktop/research/data_testing/plots/vel_dist/binned/vel_distribution_dark_" + outputs[i] + "gy.jpeg\" \n")
        #f.write("set title 'Histogram of Dark Matter Velocity Distribution After " + titles[i] + "Gy' \n")
        #f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory + "' using 1:2 with lines  title 'dark dist'  lw 2   \n\n") 
        


    #f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")
    #f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")

#f.close()



# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#pot  = "~/Desktop/research/data_testing/theory/pots.dat"
#f = open('pots.gnuplot', 'w')
#f.write("reset\n")
#f.write("set terminal jpeg\n")
#f.write("set key on\n")
#f.write("set ylabel 'pot'\n")
#f.write("set xlabel 'radius (kpc)'\n")
##f.write("set xrange[0:10]\n")
#f.write("set yrange[-50000:0]\n\n\n")

#if(plot_theory == True):
    #f.write("set output \"~/Desktop/research/data_testing/plots/pots.jpeg\" \n")
    #f.write("set title 'Pot vs r' \n")
    #f.write("plot '" + pot + "' u 1:2  w l title 'plum', '' u 1:3 w l title 'mn', '' u 1:4 w l title 'sphere', '' u 1:5 w l title 'log' \n\n", )

#f.close()

#den  = "~/Desktop/research/data_testing/theory/den.dat"

#f = open('den.gnuplot', 'w')
#f.write("reset\n")
#f.write("set terminal jpeg\n")
#f.write("set key on\n")
#f.write("set ylabel 'den'\n")
#f.write("set xlabel 'radius (kpc)'\n")
#f.write("set xrange[0:100]\n")
#f.write("set yrange[0:10]\n\n\n")
#if(plot_theory == True):
    #f.write("set output \"~/Desktop/research/data_testing/plots/den.jpeg\" \n")
    #f.write("set title 'den vs r' \n")
    #f.write("plot '" + den + "' u 1:2  w l title 'plum', '' u 1:3 w l title 'mn', '' u 1:4 w l title 'sphere', '' u 1:5 w l title 'log' \n\n", )



#f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")
#f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")

#f.close()
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#rot  = "~/Desktop/research/data_testing/theory/rotation.dat"

#f = open('rotation.gnuplot', 'w')
#f.write("reset\n")
#f.write("set terminal jpeg\n")
#f.write("set key on\n")
#f.write("set ylabel 'vel'\n")
#f.write("set xlabel 'radius (kpc)'\n")
#f.write("set xrange[0:500]\n")
#f.write("set yrange[0:400]\n\n\n")
#if(plot_theory == True):
    #f.write("set output \"~/Desktop/research/data_testing/plots/rotation.jpeg\" \n")
    #f.write("set title 'v vs r' \n")
    #f.write("plot '" + rot + "' u 1:2  w l title 'mn', '' u 1:3 w l title 'sph', '' u 1:4 w l title 'log', '' u 1:5 w l title 'sum' \n\n", )



#f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")
#f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")

#f.close()

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#force  = "~/Desktop/research/data_testing/theory/force.dat"

#f = open('force.gnuplot', 'w')
#f.write("reset\n")
#f.write("set terminal jpeg\n")
#f.write("set key on\n")
#f.write("set ylabel 'force'\n")
#f.write("set xlabel 'radius (kpc)'\n")
#f.write("set xrange[0:1000]\n")
#f.write("set yrange[-500:1]\n\n\n")
#if(plot_theory == True):
    #f.write("set output \"~/Desktop/research/data_testing/plots/force.jpeg\" \n")
    #f.write("set title 'force vs r' \n")
    #f.write("plot '" + force + "' u 1:2  w l title 'force' \n\n", )



#f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")
#f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")

#f.close()
