#! /usr/bin/python
import os
from subprocess import call

args = [1, 0.2, 0.2, 11, 0.2]

sim_time      = [ "0", "p25", "p50", "p75", "1", "2", "3", "4"]
#sim_time      = [ "0", "4"]
N             = 8
M             = 0
back_time     = (args[0])
r0            = (args[1])
light_r_ratio = (args[2])
mass          = (args[3])
mass_ratio    = (args[4])

print "parameters: ", back_time, r0, light_r_ratio, mass, mass_ratio
parse = False
output = False
tidal = True
virial = False
#######################################################################
#Proper paramaters:
r_d = ( r0 / light_r_ratio )
r_l = ( r0 )
m_d = ( mass * (1.0 - mass_ratio) )
m_l = ( mass * mass_ratio )

#r_d = ( r0 / light_r_ratio )
#r_l = 1.0
#m_d = 0.0 #( mass * (1.0 - mass_ratio) )
#m_l = 30.0

Nb  = 20000

#for one component
masspd  = m_d / ( Nb);
masspl  = m_l / ( Nb);

#for two component
#masspl   = m_l / (0.5 * Nb);
#masspd   = m_d / (0.5 * Nb);


nbody    = str( Nb )
rscale_l = str( r_l )
rscale_d = str( r_d )
mass_l   = str( m_l )
mass_d   = str( m_d )
mass_per_particle_light = str( masspl )
mass_per_particle_dark  = str( masspd )

#######################################################################
###name of folder to which your results will be saved
folder_name = "orphan_parameters_2comp"

if(parse == True):
    print "parsing data"
    for i in range(M, N):
        os.system("python outputparser.py ./sim_outputs/output_" + sim_time[i] + "gy.out  " + sim_time[i] +"gy")

if(output == True):    
    print "performing tests"
    os.system("g++ -std=c++11 output_test.cpp -o output_test")
    for i in range(M, N):
        os.system("./output_test " + sim_time[i] + " " + rscale_l + " " + rscale_d + " " + mass_l + " " + mass_d + " " + mass_per_particle_light + " " + mass_per_particle_dark)
    
if(virial == True):
    os.system("g++ -std=c++11 virial_test.cpp -o virial_test")
    for i in range(M, N):
        os.system("./virial_test " + sim_time[i] + " " + rscale_l + " " + rscale_d + " " + mass_l + " " + mass_d + " " + mass_per_particle_light + " " + mass_per_particle_dark)

if(tidal == True):
    os.system("g++ -std=c++11 tidal_radius.cpp -o tidal_radius")
    os.system("./tidal_radius " + rscale_l + " " + rscale_d + " " + mass_l + " " + mass_d)

#print "making plots"
#os.system("./make_plots.sh 2>>piped_output.txt ")

#os.system("./save_runs.py " + folder_name)
#os.system("./cleanse.sh")