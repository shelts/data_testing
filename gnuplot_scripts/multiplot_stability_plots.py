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
                     "set terminal png enhanced",
                     "set key off",
                     "set title font 'Times-Roman,20' ",
                     "set ylabel 'Counts' ",
                     "set multiplot layout 1,2 rowsfirst"
                     ]


# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##RADIUS
theory_den = "~/Desktop/research/data_testing/theory/theory_den.dat"
light      = "~/Desktop/research/data_testing/binned_data/light_matter_bins_"
dark       = "~/Desktop/research/data_testing/binned_data/dark_matter_bins_"
both       = "~/Desktop/research/data_testing/binned_data/both_matter_bins_"

f = open('stability_rad_multiplot.gnuplot', 'w')

for j in range(0, len(gnu_common_header)):
    f.writelines(gnu_common_header[j] + "\n")

gnu_header = ["set terminal png enhanced size 1300,700",
              "set xlabel 'Radius (kpc)'",
              "set xrange[0:8]",
              "set yrange[0:1500]\n",
              "set multiplot layout 1,3 rowsfirst\n",
              "set output '~/Desktop/research/data_testing/plots/radii_distribution_multiplot.png' "
              ]
for j in range(0, len(gnu_header)):
        f.writelines(gnu_header[j] + "\n")

for i in range(M, N):
    if(plot_light == True):
        p = light + sim_time[i] + "gy.dat"
        gnu_args = ["set title '" + titles[i] + " Gyr'\n",
                    "plot '" + p + "' using 2:1  with boxes, '" + theory_den + "' using 1:3 with lines title 'light'\n"
                    ]
        for j in range(0, len(gnu_args)):
            f.writelines(gnu_args[j] + "\n")    
        
f.write("unset multiplot \n")
f.close()

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##RADIAL PHI
sim_time = [ "0","4"]
titles   = [ "0.0", "4.0"]
N        = 2
M        = 0

theory_phi   = "~/Desktop/research/data_testing/theory/theory_phi.dat"
light = "~/Desktop/research/data_testing/binned_data/phi_light_"

f = open('multiplot_phi.gnuplot', 'w')
for j in range(0, len(gnu_common_header)):
    f.writelines(gnu_common_header[j] + "\n")

gnu_header = ["set xlabel '{/Symbol f} (rad)'",
              "set xrange[-3.5:3.5]",
              "set yrange[0:800]\n",
              "set output '~/Desktop/research/data_testing/plots/phi_distribution_multiplot.png' "
              ]

for j in range(0, len(gnu_header)):
        f.writelines(gnu_header[j] + "\n")

for i in range(M, N):
    if(plot_light == True):
        p = light + sim_time[i] + "gy.dat"
        gnu_args = ["set title '" + titles[i] + " Gyr'\n",
                    "plot '" + p + "' using 2:1  with boxes, '" + theory_phi + "' using 1:3 with lines title 'light' \n",
                    ]
        for j in range(0, len(gnu_args)):
            f.writelines(gnu_args[j] + "\n")
            
f.write("unset multiplot \n")
f.close()
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##RADIAL THETA
sim_time = [ "0","4"]
titles   = [ "0.0", "4.0"]
N        = 2
M        = 0
theory_theta   = "~/Desktop/research/data_testing/theory/theory_theta.dat"
light = "~/Desktop/research/data_testing/binned_data/theta_light_"

f = open('multiplot_theta.gnuplot', 'w')
for j in range(0, len(gnu_common_header)):
    f.writelines(gnu_common_header[j] + "\n")

gnu_header = ["set xlabel '{/Symbol q} (rad)'",
              "set xrange[0:3.5]",
              "set yrange[0:1200]\n",
              "set output '~/Desktop/research/data_testing/plots/theta_distribution_multiplot.png' "
              ]
for j in range(0, len(gnu_header)):
        f.writelines(gnu_header[j] + "\n")
        
for i in range(M, N):
    if(plot_light == True):
        p = light + sim_time[i] + "gy.dat"
        gnu_args = ["set title '" + titles[i] + " Gyr'\n",
                    "plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory_theta + "' using 1:3 with lines title 'light' \n",
                    ]
        for j in range(0, len(gnu_args)):
            f.writelines(gnu_args[j] + "\n")
        
f.write("unset multiplot \n")
f.close()
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##Velocity
outputs = [ "0", "2", "4"]
sim_time = [ "0", "2", "4"]
titles   = [ "0.0", "2.0", "4.0"]
N        = 3
M        = 0

theory_light   = "~/Desktop/research/data_testing/binned_data/light_matter_theory_vel_bins.dat"
light = "~/Desktop/research/data_testing/binned_data/light_matter_vel_bins_"

f = open('stability_vel_multiplot.gnuplot', 'w')
for j in range(0, len(gnu_common_header)):
    f.writelines(gnu_common_header[j] + "\n")

gnu_header = ["set terminal png enhanced size 1300,700",
              "set xlabel 'Velocity (km/s)'",
              "set xrange[0:10]",
              "set yrange[0:1500]\n",
              "set multiplot layout 1,3 rowsfirst\n",
              "set output '~/Desktop/research/data_testing/plots/vel_distribution_multiplot.png' "
              ]
for j in range(0, len(gnu_header)):
        f.writelines(gnu_header[j] + "\n")

for i in range(M, N):
    if(plot_light == True):
        p = light + sim_time[i] + "gy.dat"
        gnu_args = ["set title '" + titles[i] + " Gyr'\n",
                    "plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory_light + "' using 2:1 with lines  title 'light theory'  lw 2   \n"
                    ]
        for j in range(0, len(gnu_args)):
            f.writelines(gnu_args[j] + "\n")    

f.write("unset multiplot \n")
f.close()


# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##VELOCITY PHI
sim_time = [ "0","4"]
titles   = [ "0.0", "4.0"]
N        = 2
M        = 0

theory_phi   = "~/Desktop/research/data_testing/theory/theory_phi.dat"
light = "~/Desktop/research/data_testing/binned_data/phi_vel_light_"

f = open('multiplot_vel_phi.gnuplot', 'w')
for j in range(0, len(gnu_common_header)):
    f.writelines(gnu_common_header[j] + "\n")

gnu_header = ["set xlabel 'Velocity {/Symbol f} (rad)'",
              "set xrange[-3.5:3.5]",
              "set yrange[0:800]\n",
              "set output '~/Desktop/research/data_testing/plots/vel_phi_distribution_multiplot.png' "
              ]

for j in range(0, len(gnu_header)):
        f.writelines(gnu_header[j] + "\n")

for i in range(M, N):
    if(plot_light == True):
        p = light + sim_time[i] + "gy.dat"
        gnu_args = ["set title '" + titles[i] + " Gyr'\n",
                    "plot '" + p + "' using 2:1  with boxes,'" + theory_phi + "' using 1:3 with lines title 'light' \n",
                    ]
        for j in range(0, len(gnu_args)):
            f.writelines(gnu_args[j] + "\n")

f.write("unset multiplot \n")
f.close()



# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
##VELOCITY THETA
sim_time = [ "0","4"]
titles   = [ "0.0", "4.0"]
N        = 2
M        = 0
theory   = "~/Desktop/research/data_testing/theory/theory_theta.dat"
light = "~/Desktop/research/data_testing/binned_data/theta_vel_light_"

f = open('multiplot_vel_theta.gnuplot', 'w')
for j in range(0, len(gnu_common_header)):
    f.writelines(gnu_common_header[j] + "\n")

gnu_header = ["set xlabel 'Velocity {/Symbol q} (rad)'",
              "set xrange[0:3.5]",
              "set yrange[0:1200]\n",
              "set output '~/Desktop/research/data_testing/plots/vel_theta_distribution_multiplot.png' "
              ]
for j in range(0, len(gnu_header)):
        f.writelines(gnu_header[j] + "\n")
        
for i in range(M, N):
    if(plot_light == True):
        p = light + sim_time[i] + "gy.dat"
        gnu_args = ["set title '" + titles[i] + " Gyr'\n",
                    "plot '" + p + "' using 2:1  with boxes title 'actual', '" + theory + "' using 1:3 with lines title 'light' \n",
                    ]
        for j in range(0, len(gnu_args)):
            f.writelines(gnu_args[j] + "\n")


f.write("unset multiplot \n")
f.close()
