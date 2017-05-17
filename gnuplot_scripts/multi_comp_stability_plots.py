#! /usr/bin/python
import os

outputs = [ "0", "2", "4"]
sim_time = [ "0", "2", "4"]
titles   = [ "0.0", "2.0", "4.0"]
N        = 1
M        = 0


plot_dark = False
plot_light = True
plot_both = False
plot_theory = True
if(plot_light == True):
    print("plotting light")
if(plot_dark == True):
    print("plotting dark")
if(plot_both == True):
    print("plotting both")

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##RADIUS
theory_den = "~/Desktop/research/data_testing/theory/theory_den.dat"
light      = "~/Desktop/research/data_testing/binned_data/light_matter_bins_"
dark       = "~/Desktop/research/data_testing/binned_data/dark_matter_bins_"
both       = "~/Desktop/research/data_testing/binned_data/both_matter_bins_"

f = open('multi_comp_stability_rad.gnuplot', 'w')
f.write("reset\n")
f.write("set terminal png enhanced size 1300,700\n")
f.write("set key off\n")
f.write("set ylabel 'Counts'\n")
f.write("set xlabel 'Radius (kpc)'\n")
f.write("set xrange[0:8]\n")
f.write("set yrange[0:1500]\n\n\n")
f.write("set title font 'Times-Roman,20'\n")

f.write("set output \"~/Desktop/research/data_testing/plots/multi_comp_stability_rad.png\" \n")
f.write("set multiplot layout 1,3 rowsfirst\n")
for i in range(M, N):
    p = light + sim_time[i] + "gy.dat"
    f.write("set title '" + titles[i] + " Gyr'\n")
    f.write("plot '" + p + "' using 2:1  with boxes, '" + theory_den + "' using 1:3 with lines title 'light'\n\n") 
    
    p = dark + sim_time[i] + "gy.dat"
    f.write("set title '" + titles[i] + " Gyr'\n")
    f.write("plot '" + p + "' using 2:1  with boxes, '" + theory_den + "' using 1:4 with lines title 'dark'\n\n") 
    
    p = both + sim_time[i] + "gy.dat"
    f.write("set title '" + titles[i] + " Gyr'\n")
    f.write("plot '" + p + "' using 2:1  with boxes, '" + theory_den + "' using 1:2 with lines title 'both'\n\n") 
        
f.write("unset multiplot \n")
f.close()

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##RADIAL PHI
theory_phi   = "~/Desktop/research/data_testing/theory/theory_phi.dat"
light = "~/Desktop/research/data_testing/binned_data/phi_light_"
dark  = "~/Desktop/research/data_testing/binned_data/phi_dark_"
both  = "~/Desktop/research/data_testing/binned_data/phi_both_"

f = open('multi_comp_stability_phi.gnuplot', 'w')
f.write("reset\n")
f.write("set terminal png enhanced size 1300,700\n")
f.write("set key off\n")
f.write("set ylabel 'Counts'\n")
f.write("set xlabel '{/Symbol f} (rad)'\n")
f.write("set xrange[-3.5:3.5]\n")
f.write("set yrange[0:800]\n\n\n")
f.write("set title font 'Times-Roman,20'\n")

f.write("set output \"~/Desktop/research/data_testing/plots/multi_comp_stability_phi.png\" \n")
f.write("set multiplot layout 1,3 rowsfirst\n")
for i in range(M, N):
    p = light + sim_time[i] + "gy.dat"
    f.write("set title '" + titles[i] + " Gyr'\n")
    f.write("plot '" + p + "' using 2:1  with boxes, '" + theory_phi + "' using 1:3 with lines title 'light' \n\n") 
    
    p = dark + sim_time[i] + "gy.dat"
    f.write("set title '" + titles[i] + " Gyr'\n")
    f.write("plot '" + p + "' using 2:1  with boxes, '" + theory_phi + "' using 1:4 with lines title 'dark' \n\n") 
    
    p = both + sim_time[i] + "gy.dat"
    f.write("set title '" + titles[i] + " Gyr'\n")
    f.write("plot '" + p + "' using 2:1  with boxes, '" + theory_phi + "' using 1:2 with lines title 'both' \n\n") 
f.write("unset multiplot \n")
f.close()
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##RADIAL THETA
theory   = "~/Desktop/research/data_testing/theory/theory_theta.dat"
light = "~/Desktop/research/data_testing/binned_data/theta_light_"
dark  = "~/Desktop/research/data_testing/binned_data/theta_dark_"
both  = "~/Desktop/research/data_testing/binned_data/theta_both_"

f = open('multi_comp_stability_theta.gnuplot', 'w')
f.write("reset\n")
f.write("set terminal png enhanced size 1300,700\n")
f.write("set key on\n")
f.write("set ylabel 'Counts'\n")
f.write("set xlabel '{/Symbol q} (rad)'\n")
f.write("set xrange[0:3.5]\n")
f.write("set yrange[0:1200]\n\n\n")
f.write("set title font 'Times-Roman,20'\n")

f.write("set output \"~/Desktop/research/data_testing/plots/multi_comp_stability_theta.png\" \n")
f.write("set multiplot layout 1,3 rowsfirst\n")
for i in range(M, N):
    p = light + sim_time[i] + "gy.dat"
    f.write("set title '" + titles[i] + " Gyr' \n")
    f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory + "' using 1:3 with lines title 'light'\n\n") 
    
    p = dark + sim_time[i] + "gy.dat"
    f.write("set title '" + titles[i] + " Gyr' \n")
    f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory + "' using 1:4 with lines title 'dark'\n\n")
    
    p = both + sim_time[i] + "gy.dat"
    f.write("set title '" + titles[i] + " Gyr' \n")
    f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory + "' using 1:2 with lines title 'both'\n\n")
f.write("unset multiplot \n")
f.close()
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##Velocity
theory_light   = "~/Desktop/research/data_testing/binned_data/light_matter_theory_vel_bins.dat"
theory_dark   = "~/Desktop/research/data_testing/binned_data/dark_matter_theory_vel_bins.dat"
light = "~/Desktop/research/data_testing/binned_data/light_matter_vel_bins_"
dark  = "~/Desktop/research/data_testing/binned_data/dark_matter_vel_bins_"

f = open('multi_comp_stability_vel.gnuplot', 'w')
f.write("reset\n")
f.write("set terminal png enhanced size 1300,700\n")
f.write("set key off\n")
f.write("set ylabel 'Counts'\n")
f.write("set xlabel 'Velocity (km/s)'\n")
f.write("set xrange[0:10]\n")
f.write("set yrange[0:1500]\n")
f.write("set title font 'Times-Roman,20'\n")

f.write("set output '~/Desktop/research/data_testing/plots/multi_comp_stability_vel.png' \n")
f.write("set multiplot layout 1,2 rowsfirst\n")
for i in range(M, N):
    p = light + sim_time[i] + "gy.dat"
    f.write("set title '" + titles[i] + " Gyr' \n")
    f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory_light + "' using 2:1 with lines  title 'light theory'  lw 2   \n\n") 

    p = dark + sim_time[i] + "gy.dat"
    f.write("set title '" + titles[i] + " Gyr' \n")
    f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory_dark + "' using 2:1 with lines  title 'dark theory'  lw 2   \n\n")
    
    f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")
    f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")
f.write("unset multiplot \n")
f.close()


# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##VELOCITY PHI
theory_phi   = "~/Desktop/research/data_testing/theory/theory_phi.dat"
light = "~/Desktop/research/data_testing/binned_data/phi_vel_light_"
dark  = "~/Desktop/research/data_testing/binned_data/phi_vel_dark_"
both  = "~/Desktop/research/data_testing/binned_data/phi_vel_both_"

f = open('multi_comp_stability_vel_phi.gnuplot', 'w')
f.write("reset\n")
f.write("set terminal png enhanced size 1300,700\n")
f.write("set key off\n")
f.write("set ylabel 'Counts'\n")
f.write("set xlabel 'Velocity {/Symbol f} (rad)'\n")
f.write("set xrange[-3.5:3.5]\n")
f.write("set yrange[0:800]\n\n\n")
f.write("set title font 'Times-Roman,20'\n")

f.write("set output \"~/Desktop/research/data_testing/plots/multi_comp_stability_vel_phi.png\" \n")
f.write("set multiplot layout 1,3 rowsfirst\n")
for i in range(M, N):
    p = light + sim_time[i] + "gy.dat"
    f.write("set title '" + titles[i] + " Gyr' \n")
    f.write("plot '" + p + "' using 2:1  with boxes,'" + theory_phi + "' using 1:3 with lines title 'light'\n\n") 
    
    p = dark + sim_time[i] + "gy.dat"
    f.write("set title '" + titles[i] + " Gyr' \n")
    f.write("plot '" + p + "' using 2:1  with boxes,'" + theory_phi + "' using 1:4 with lines title 'dark'\n\n") 
    
    p = both + sim_time[i] + "gy.dat"
    f.write("set title '" + titles[i] + " Gyr' \n")
    f.write("plot '" + p + "' using 2:1  with boxes,'" + theory_phi + "' using 1:2 with lines title 'both'\n\n") 
f.write("unset multiplot \n")
f.close()



# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##VELOCITY THETA
theory   = "~/Desktop/research/data_testing/theory/theory_theta.dat"
light = "~/Desktop/research/data_testing/binned_data/theta_vel_light_"
dark  = "~/Desktop/research/data_testing/binned_data/theta_vel_dark_"
both  = "~/Desktop/research/data_testing/binned_data/theta_vel_both_"

f = open('multi_comp_stability_vel_theta.gnuplot', 'w')
f.write("reset\n")
f.write("set terminal png enhanced size 1300,700\n")
f.write("set key off\n")
f.write("set ylabel 'Counts'\n")
f.write("set xlabel 'Velocity {/Symbol q} (rad)'\n")
f.write("set xrange[0:3.5]\n")
f.write("set yrange[0:1200]\n\n\n")
f.write("set title font 'Times-Roman,20'\n")

f.write("set output \"~/Desktop/research/data_testing/plots/multi_comp_stability_vel_theta.png\" \n")
f.write("set multiplot layout 1,3 rowsfirst\n")
for i in range(M, N):
    p = light + sim_time[i] + "gy.dat"
    f.write("set title '" + titles[i] + " Gyr' \n")
    f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory + "' using 1:3 with lines title 'light' \n\n") 
    
    p = dark + sim_time[i] + "gy.dat"
    f.write("set title '" + titles[i] + " Gyr' \n")
    f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory + "' using 1:4 with lines title 'dark' \n\n")
    
    p = both + sim_time[i] + "gy.dat"
    f.write("set title '" + titles[i] + " Gyr' \n")
    f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory + "' using 1:2 with lines title 'both' \n\n")
f.write("unset multiplot \n")
f.close()
