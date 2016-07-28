#! /usr/bin/python
import os
from subprocess import call
import sys
args = sys.argv;

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
                #/# # # # # # # # # # # # # # \#
                #          CIRCUIT BOX         #
                #\# # # # # # # # # # # # # # /#
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# # # # # # # # # # # # # # # # #
#     LOGIC DIRECTORY           #
# # # # # # # # # # # # # # # # #
y = True                        #
n = False                       #
# # # # # # # # # # # # # # # # #

# # # # # # # # # # # # # # # # #
#     PARAMETER DIRECTORY       #
# # # # # # # # # # # # # # # # #
back_time     = float(args[1])  #
r_l           = float(args[2])  #
rad_ratio     = float(args[3])  #
m_l           = float(args[4])  #
mass_ratio    = float(args[5])  #
# # # # # # # # # # # # # # # # #

# # # # # # # # # # # # # # # # #
#     MODEL DIRECTORY           #
# # # # # # # # # # # # # # # # #
plummer  = 1                    #
NFW      = 2                    #
gen_hern = 3                    #
einasto  = 4                    #
# # # # # # # # # # # # # # # # #

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
                #/# # # # # # # # # # # # # # \#
                #          Control Panel       #
                #\# # # # # # # # # # # # # # /#
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#sim_time      = [ "0", "p25", "p50", "p75", "1", "2", "3", "4"]
sim_time      = [ "0", "2"]
N             = 1
M             = 0

print "parameters: ", back_time, r_l, rad_ratio, m_l, mass_ratio

number_of_components = 2
parse = True

# # # # # # # # # # # # # # # # #
#     CHOOSE YOUR MODELS        #
# # # # # # # # # # # # # # # # #
component1 = plummer
component2 = plummer
# # # # # # # # # # # # # # # # #



# # # # # # # # # # # # # # # # #
#     CHOOSE YOUR TESTS     #
# # # # # # # # # # # # # # # # # 
output         = y        #
# # # # # # # # # # # # # # # # #
tidal          = n        #
# # # # # # # # # # # # # # # # #
virial         = n        #
# # # # # # # # # # # # # # # # #
make_clean     = n        #
# # # # # # # # # # # # # # # # #
#         PLOTS?          #
make_plots = False        #
# # # # # # # # # # # # # # # # #
#         SAVE?           #
save_run = n              #
# # # # # # # # # # # # # # # # #
cleanse = False           #
# # # # # # # # # # # # # # # # #

folder_name = "orphan_parameters_2comp"
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
Nb  = 20000
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#for two component
if(number_of_components == 2):    
    #Proper paramaters:
    dwarfMass = m_l / mass_ratio
    rscale_t  = r_l / rad_ratio
    
    r_d = rscale_t  * (1.0 - rad_ratio)
    m_d = dwarfMass * (1.0 - mass_ratio)
    
    
    print(m_d, m_l)
    print(r_d, r_l)
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
    
#for one component
if(number_of_components == 1):
    #one component paramaters:
    rscale_t  = r_l / rad_ratio
    
    r_d = rscale_t  * (1.0 - rad_ratio)
    m_d = 0.0 


#we're all full of strings...
nbody    = str( Nb )
rscale_l = str( r_l )
rscale_d = str( r_d )
mass_l   = str( m_l )
mass_d   = str( m_d )

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
                #/# # # # # # # # # # # # # # \#
                #          Engine Room         #
                #\# # # # # # # # # # # # # # /#
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 


if(parse == True):
    print "parsing data"
    for i in range(M, N):
        os.system("python outputparser.py ./sim_outputs/output_" + sim_time[i] + "gy.out  " + sim_time[i] +"gy")

if(output == True):    
    print "performing tests"
    #os.system("g++ -std=c++11 output_test.cpp -o output_test")
    os.system("make all")
    for i in range(M, N):
        os.system("./output_test " + sim_time[i] + " " + rscale_l + " " + rscale_d + " " + mass_l + " " + mass_d + " " + component1 + " " + component2)
    
if(virial == True):
    #os.system("g++ -std=c++11 virial_test.cpp -o virial_test")
    os.system("make all")
    for i in range(M, N):
        os.system("./virial_test " + sim_time[i] + " " + rscale_l + " " + rscale_d + " " + mass_l + " " + mass_d + " " + component1 + " " + component2)
    

if(tidal == True):
    os.system("g++ -std=c++11 tidal_radius.cpp -o tidal_radius")
    os.system("./tidal_radius " + rscale_l + " " + rscale_d + " " + mass_l + " " + mass_d)

if(make_plots == True):
    print "making plots"
    os.system("./make_plots.sh 2>>piped_output.txt ")

if(save_run == True):
    os.system("./save_runs.py " + folder_name)
if(cleanse == True):
    os.system("./cleanse.sh")

if(make_clean == True):
    os.system("make clean")