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


gnu_common_header = ["reset",
                     "set terminal png enhanced size 1300,700",
                     "set key on",
                     "set title font 'Times-Roman,20' ",
                     "set ylabel 'N' ",
                     ]

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##RADIUS
theory_den = "~/Desktop/research/data_testing/theory/theory_den.dat"
light      = "~/Desktop/research/data_testing/binned_data/light_matter_bins_"
dark       = "~/Desktop/research/data_testing/binned_data/dark_matter_bins_"
both       = "~/Desktop/research/data_testing/binned_data/both_matter_bins_"

f = open('multi_comp_stability_rad.gnuplot', 'w')

for j in range(0, len(gnu_common_header)):
    f.writelines(gnu_common_header[j] + "\n")

gnu_header = ["set xlabel 'Radius (kpc)'",
              "set xrange[0:4]",
              "set yrange[0:3500]\n",
              "set output \"~/Desktop/research/data_testing/plots/multi_comp_stability_rad.png\" ",
              "set multiplot layout 1,2 rowsfirst  title 'Initial Density Distributions' font 'Times-Roman,20'"
              ]
for j in range(0, len(gnu_header)):
        f.writelines(gnu_header[j] + "\n")

for i in range(M, N):
    p1 = light + sim_time[i] + "gy.dat"
    p2 = dark + sim_time[i] + "gy.dat"
    p3 = both + sim_time[i] + "gy.dat"
    #"set title '" + titles[i] + " Gyr'",
    gnu_args = [

                "plot '" + p1 + "' using 2:1  with boxes title 'baryon simulated', '" + theory_den + "' using 1:3 with lines title 'baryon theoretical'\n",
                "plot '" + p2 + "' using 2:1  with boxes title 'dark matter simulated', '" + theory_den + "' using 1:4 with lines title 'dark matter theoretical'\n",
                #"plot '" + p3 + "' using 2:1  with boxes title 'combined simulated', '" + theory_den + "' using 1:2 with lines title 'combined theoretical'\n"
                ]
    
    for j in range(0, len(gnu_args)):
        f.writelines(gnu_args[j] + "\n")
        
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

for j in range(0, len(gnu_common_header)):
    f.writelines(gnu_common_header[j] + "\n")


gnu_header = ["set xlabel '{/Symbol f} (rad)'",
              "set xrange[-3.5:3.5]",
              "set yrange[0:800]\n",
              "set output \"~/Desktop/research/data_testing/plots/multi_comp_stability_phi.png\" ",
              "set multiplot layout 1,3 rowsfirst title 'Initial Azimuthal Distribution' font 'Times-Roman,20'"
              ]
for j in range(0, len(gnu_header)):
        f.writelines(gnu_header[j] + "\n")
        
        
for i in range(M, N):
    p1 = light + sim_time[i] + "gy.dat"
    p2 = dark + sim_time[i] + "gy.dat"
    p3 = both + sim_time[i] + "gy.dat"
    #"set title '" + titles[i] + " Gyr'\n",
    gnu_args = [
                
                "plot '" + p1 + "' using 2:1  with boxes title 'baryons simulated', '" + theory_phi + "' using 1:3 with lines title 'baryons theoretical'\n",
                "plot '" + p2 + "' using 2:1  with boxes title 'dark matter simulated', '" + theory_phi + "' using 1:4 with lines title 'dark matter theoretical'\n",
                "plot '" + p3 + "' using 2:1  with boxes title 'combined simulated', '" + theory_phi + "' using 1:2 with lines title 'combined theoretical'\n"
                ]
    
    for j in range(0, len(gnu_args)):
        f.writelines(gnu_args[j] + "\n")
        
f.write("unset multiplot \n")
f.close()
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##RADIAL THETA
theory_theta   = "~/Desktop/research/data_testing/theory/theory_theta.dat"
light = "~/Desktop/research/data_testing/binned_data/theta_light_"
dark  = "~/Desktop/research/data_testing/binned_data/theta_dark_"
both  = "~/Desktop/research/data_testing/binned_data/theta_both_"

f = open('multi_comp_stability_theta.gnuplot', 'w')

for j in range(0, len(gnu_common_header)):
    f.writelines(gnu_common_header[j] + "\n")


gnu_header = ["set xlabel '{/Symbol q} (rad)'",
              "set xrange[0:3.5]",
              "set yrange[0:1200]\n",
              "set output \"~/Desktop/research/data_testing/plots/multi_comp_stability_theta.png\" ",
              "set multiplot layout 1,3 rowsfirst title 'Initial Polar Distribution' font 'Times-Roman,20'"
              ]
for j in range(0, len(gnu_header)):
        f.writelines(gnu_header[j] + "\n")
        
        
for i in range(M, N):
    p1 = light + sim_time[i] + "gy.dat"
    p2 = dark + sim_time[i] + "gy.dat"
    p3 = both + sim_time[i] + "gy.dat"
    #"set title '" + titles[i] + " Gyr'\n",
    gnu_args = [
                
                "plot '" + p1 + "' using 2:1  with boxes title 'baryon simulated', '" + theory_theta + "' using 1:3 with lines title 'baryon theoretical'\n",
                "plot '" + p2 + "' using 2:1  with boxes title 'dark matter simulated', '" + theory_theta + "' using 1:4 with lines title 'dark matter theoretical'\n",
                "plot '" + p3 + "' using 2:1  with boxes title 'combined simulated', '" + theory_theta + "' using 1:2 with lines title 'combined theoretical'\n"
                ]
    
    for j in range(0, len(gnu_args)):
        f.writelines(gnu_args[j] + "\n")
    
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

for j in range(0, len(gnu_common_header)):
    f.writelines(gnu_common_header[j] + "\n")

gnu_header = ["set xlabel 'Velocity (km/s)'",
              "set xrange[0:10]",
              "set yrange[0:1500]\n",
              "set output '~/Desktop/research/data_testing/plots/multi_comp_stability_vel.png' ",
              "set multiplot layout 1,2 rowsfirst title 'Initial Velocity Distribution' font 'Times-Roman,20'"
              ]
for j in range(0, len(gnu_header)):
        f.writelines(gnu_header[j] + "\n")


for i in range(M, N):
    p1 = light + sim_time[i] + "gy.dat"
    p2 = dark + sim_time[i] + "gy.dat"
    #"set title '" + titles[i] + " Gyr'\n",
    gnu_args = [
                
                "plot '" + p1 + "' using 2:1  with boxes title 'baryon simulated', '" + theory_light + "' using 2:1 with lines  title 'baryon theoretical'  lw 2\n",
                "plot '" + p2 + "' using 2:1  with boxes title 'dark matter simulated', '" + theory_dark + "' using 2:1 with lines  title 'dark matter theoretical'  lw 2\n",
                ]
    
    for j in range(0, len(gnu_args)):
        f.writelines(gnu_args[j] + "\n")
    
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

for j in range(0, len(gnu_common_header)):
    f.writelines(gnu_common_header[j] + "\n")


gnu_header = ["set xlabel 'Velocity {/Symbol f} (rad)'",
              "set xrange[-3.5:3.5]",
              "set yrange[0:800]\n",
              "set output '~/Desktop/research/data_testing/plots/multi_comp_stability_vel_phi.png' ",
              "set multiplot layout 1,3 rowsfirst title 'Initial Velocity Space Azimuthal Distribution' font 'Times-Roman,20' "
              ]
for j in range(0, len(gnu_header)):
        f.writelines(gnu_header[j] + "\n")

for i in range(M, N):
    p1 = light + sim_time[i] + "gy.dat"
    p2 = dark + sim_time[i] + "gy.dat"
    p3 = both + sim_time[i] + "gy.dat"
    #"set title '" + titles[i] + " Gyr'\n",
    gnu_args = [
                
                "plot '" + p1 + "' using 2:1  with boxes title 'baryon simulated','" + theory_phi + "' using 1:3 with lines title 'baryon theoretical'\n",
                "plot '" + p2 + "' using 2:1  with boxes title 'dark matter simulated','" + theory_phi + "' using 1:4 with lines title 'dark matter theoretical'\n",
                "plot '" + p3 + "' using 2:1  with boxes title 'combined simulated','" + theory_phi + "' using 1:2 with lines title 'combined theoretical'\n"
                ]
    
    for j in range(0, len(gnu_args)):
        f.writelines(gnu_args[j] + "\n")
        
f.write("unset multiplot \n")
f.close()



# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##VELOCITY THETA
theory_theta   = "~/Desktop/research/data_testing/theory/theory_theta.dat"
light = "~/Desktop/research/data_testing/binned_data/theta_vel_light_"
dark  = "~/Desktop/research/data_testing/binned_data/theta_vel_dark_"
both  = "~/Desktop/research/data_testing/binned_data/theta_vel_both_"

f = open('multi_comp_stability_vel_theta.gnuplot', 'w')

for j in range(0, len(gnu_common_header)):
    f.writelines(gnu_common_header[j] + "\n")

gnu_header = ["set xlabel 'Velocity {/Symbol q} (rad)'",
              "set xrange[0:3.5]",
              "set yrange[0:1200]\n",
              "set output '~/Desktop/research/data_testing/plots/multi_comp_stability_vel_theta.png' ",
              #"set title 'Initial Velocity Space Polar Distribution'\n",
              "set multiplot layout 1,3 rowsfirst title 'Initial Velocity Space Polar Distribution' font 'Times-Roman,20' \n"
              ]
for j in range(0, len(gnu_header)):
        f.writelines(gnu_header[j] + "\n")

for i in range(M, N):
    p1 = light + sim_time[i] + "gy.dat"
    p2 = dark + sim_time[i] + "gy.dat"
    p3 = both + sim_time[i] + "gy.dat"
    "set title '" + titles[i] + " Gyr'\n",
    gnu_args = [
                
                "plot '" + p1 + "' using 2:1  with boxes title 'baryon simulated', '" + theory_theta + "' using 1:3 with lines title 'baryon theoretical'\n",
                "plot '" + p2 + "' using 2:1  with boxes title 'dark matter simulated', '" + theory_theta + "' using 1:4 with lines title 'dark matter theoretical' \n",
                "plot '" + p3 + "' using 2:1  with boxes title 'combined simulated', '" + theory_theta + "' using 1:2 with lines title 'combined theoretical' \n"
                ]
    for j in range(0, len(gnu_args)):
        f.writelines(gnu_args[j] + "\n")
        
f.write("unset multiplot \n")
f.close()
