#! /usr/bin/python
import os
#from subprocess import call

args = [1, 0.5, 0.2, 30, 0.2]
sim_time        = [ "0", "p25", "p5", "p75", "1", "2", "3", "4"]
N               = 8
back_time       = (args[0])
r0              = (args[1])
light_r_ratio   = (args[2])
mass            = (args[3])
mass_ratio      = (args[4])

print "parameters: ", back_time, r0, light_r_ratio, mass, mass_ratio

#######################################################################
##Proper paramaters:
#rscale_l = str( r0 )
#rscale_d = str( r0 / light_r_ratio )
#mass_l   = str( mass * mass_ratio )
#mass_d   = str( mass * (1.0 - mass_ratio) )
#nbody    = str( 20000 )


##switched paramaters:
#rscale_l = str( r0 / light_r_ratio )
#rscale_d = str( r0 )
#mass_l   = str( mass * (1.0 - mass_ratio) )
#mass_d   = str( mass * mass_ratio )
#nbody    = str( 20000 )


##same paramaters as light
#rscale_l = str( r0 )
#rscale_d = str( r0 )
#mass_l   = str( mass * mass_ratio )
#mass_d   = str( mass * mass_ratio )
#nbody    = str( 20000 )

#same paramaters as dark
rscale_l = str( r0 / light_r_ratio )
rscale_d = str( r0 / light_r_ratio )
mass_l   = str( mass * (1.0 - mass_ratio) )
mass_d   = str( mass * (1.0 - mass_ratio) )
nbody    = str( 20000 )


#######################################################################


print "parsing data"
for i in range(0, N):
    os.system("python outputparser.py ./sim_outputs/output_" + sim_time[i] + "gy.out  " + sim_time[i] +"gy")
    
print "performing tests"
os.system("g++ -std=c++11 output_test.cpp -o output_test")
for i in range(0, N):
    os.system("./output_test " + sim_time[i] + " " + rscale_l + " " + rscale_d + " " + mass_l + " " + mass_d + " " + nbody)

os.system("g++ -std=c++11 virial_test.cpp -o virial_test")
for i in range(0, N):
    os.system("./virial_test " + sim_time[i] + " " + rscale_l + " " + rscale_d + " " + mass_l + " " + mass_d + " " + nbody)


print "making plots"
##radial distribution
os.system("gnuplot gnuplot_scripts/stability_plots.gnuplot") 

##radial angles
os.system("gnuplot gnuplot_scripts/theta.gnuplot")
os.system("gnuplot gnuplot_scripts/phi.gnuplot")

##vel distribution
os.system("gnuplot gnuplot_scripts/vel.gnuplot")
os.system("gnuplot gnuplot_scripts/v_vs_r.gnuplot")

#vel dist binned
os.system("gnuplot gnuplot_scripts/vel_theory_binned.gnuplot")

##vel angles
os.system("gnuplot gnuplot_scripts/vel_phi.gnuplot")
os.system("gnuplot gnuplot_scripts/vel_theta.gnuplot")
#xdg-open run1/plots/radii_distribution.jpeg



