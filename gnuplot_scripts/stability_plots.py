#! /usr/bin/python
import os

outputs = [ "0", "0p25", "0p50", "0p75", "1", "2", "3", "4"]
sim_time = [ "0", "p25", "p50", "p75", "1", "2", "3", "4"]
titles   = [ "0.0", "0.25" , "0.5" , "0.75" , "1.0", "2.0", "3.0", "4.0"]

#outputs = [ "0", "2"]
#sim_time = [ "0", "2"]
#titles   = [ "0.0", "2"]#aaff00
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


gnu_common_header = ["reset",
                     "set terminal png enhanced size 1300,700",
                     "set key off",
                     "set title font 'Times-Roman,20' ",
                     "set ylabel 'Counts' "]
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##RADIUS binned
theory_den = "~/Desktop/research/data_testing/theory/theory_den.dat"
light      = "~/Desktop/research/data_testing/binned_data/light_matter_bins_"
dark       = "~/Desktop/research/data_testing/binned_data/dark_matter_bins_"
both       = "~/Desktop/research/data_testing/binned_data/both_matter_bins_"

###

f = open('stability_rad.gnuplot', 'w')

for j in range(0, len(gnu_common_header)):
    f.writelines(gnu_common_header[j] + "\n")

gnu_header = ["set xlabel 'Radius (kpc)'",
              "set xrange[0:10]",
              "set yrange[0:2000]\n"
              ]

for j in range(0, len(gnu_header)):
        f.writelines(gnu_header[j] + "\n")

for i in range(M, N):
    if(plot_light):
        p = light + sim_time[i] + "gy.dat"
        f.write("set output '~/Desktop/research/data_testing/plots/rad/radii_distribution_light_" + outputs[i] + "gy.jpeg' \n")
        f.write("set title 'Histogram of Light Matter Distribution After " + titles[i] + "Gy' \n")
        f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory_den + "' using 1:2 with lines title 'both', '" + theory_den + "' using 1:3 with lines title 'light', '" + theory_den + "' using 1:4 with lines title 'dark' \n\n") 

    if(plot_dark):
        p = dark + sim_time[i] + "gy.dat"
        f.write("set output '~/Desktop/research/data_testing/plots/rad/radii_distribution_dark_" + outputs[i] + "gy.jpeg' \n")
        f.write("set title 'Histogram of Dark Matter Distribution After " + titles[i] + "Gy' \n")
        f.write("plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory_den + "' using 1:2 with lines title 'both', '" + theory_den + "' using 1:3 with lines title 'light', '" + theory_den + "' using 1:4 with lines title 'dark' \n\n") 

    if(plot_both):
        p = both + sim_time[i] + "gy.dat"
        f.write("set output '~/Desktop/research/data_testing/plots/rad/radii_distribution_both_" + outputs[i] + "gy.jpeg' \n")
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

for j in range(0, len(gnu_common_header)):
    f.writelines(gnu_common_header[j] + "\n")

gnu_header = ["set xlabel 'Radius (kpc)'",
              "set xrange[0:30]",
              "set yrange[0:1.8]\n"
              ]

for j in range(0, len(gnu_header)):
        f.writelines(gnu_header[j] + "\n")
        

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

for j in range(0, len(gnu_common_header)):
    f.writelines(gnu_common_header[j] + "\n")

gnu_header = ["set xlabel 'phi (rad)'",
              "set xrange[-5:5]",
              "set yrange[0:1200]\n"
              ]

for j in range(0, len(gnu_header)):
        f.writelines(gnu_header[j] + "\n")


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

for j in range(0, len(gnu_common_header)):
    f.writelines(gnu_common_header[j] + "\n")

gnu_header = ["set xlabel 'theta (rad)'",
              "set xrange[0:4]",
              "set yrange[0:1200]\n"
              ]

for j in range(0, len(gnu_header)):
        f.writelines(gnu_header[j] + "\n")
        
        
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

for j in range(0, len(gnu_common_header)):
    f.writelines(gnu_common_header[j] + "\n")

gnu_header = ["set xlabel 'vel (km/s)'",
              "set xrange[0:20]",
              "set yrange[0:500]\n",
              "set style fill transparent solid 0.2"
              ]

for j in range(0, len(gnu_header)):
        f.writelines(gnu_header[j] + "\n")


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

for j in range(0, len(gnu_common_header)):
    f.writelines(gnu_common_header[j] + "\n")

gnu_header = ["set xlabel 'phi (vel)'",
              "set xrange[-5:5]",
              "set yrange[0:1200]\n"
              ]

for j in range(0, len(gnu_header)):
        f.writelines(gnu_header[j] + "\n")
        

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

for j in range(0, len(gnu_common_header)):
    f.writelines(gnu_common_header[j] + "\n")

gnu_header = ["set xlabel 'theta (vel)'",
              "set xrange[0:4]",
              "set yrange[0:1200]\n"
              ]

for j in range(0, len(gnu_header)):
        f.writelines(gnu_header[j] + "\n")
        

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

for j in range(0, len(gnu_common_header)):
    f.writelines(gnu_common_header[j] + "\n")

gnu_header = ["set xlabel 'radius (kpc)'",
              "set ylabel 'vel (km/s)'",
              "set xrange[0:15]",
              "set yrange[0:6]\n"
              ]

for j in range(0, len(gnu_header)):
        f.writelines(gnu_header[j] + "\n")


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
