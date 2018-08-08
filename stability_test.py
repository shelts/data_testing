#! /usr/bin/python
#/* Copyright (c) 2016 Siddhartha Shelton */
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
r_l           = float(args[1])  #
rad_ratio     = float(args[2])  #
m_l           = float(args[3])  #
mass_ratio    = float(args[4])  #
# # # # # # # # # # # # # # # # #

# # # # # # # # # # # # # # # # #
#     MODEL DIRECTORY           #
# # # # # # # # # # # # # # # # #
plummer  = 2                    #
nfw      = 3                    #
gen_hern = 4                    #
einasto  = 5                    #
# # # # # # # # # # # # # # # # #

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
                #/# # # # # # # # # # # # # # \#
                #          Control Panel       #
                #\# # # # # # # # # # # # # # /#
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#sim_time      = [ "0", "p25", "p50", "p75", "1", "2", "3", "4"]
sim_time      = [ "0", "2", "4"]
N             = 3
M             = 0
#ext = "gy.out"
ext = "gy_same.out"#if you want to parse two different types of files. EX, initial plum with same and different parameters
#ext = "gy_diff.out"
print "parameters: ", r_l, rad_ratio, m_l, mass_ratio

number_of_components = 2
parse = True

# # # # # # # # # # # # # # # # #
#     CHOOSE YOUR MODELS        #
# # # # # # # # # # # # # # # # #
component1 = plummer
component2 = plummer

if(component1 == plummer):
    name1 = "plummer"
elif(component1 == nfw):
    name1 = "nfw"
elif(component1 == gen_hern):
    name1 = "hern"
elif(component1 == einasto):
    name1 = "einasto"
    
if(component2 == plummer):
    name2 = "plummer"
elif(component2 == nfw):
    name2 = "nfw"
elif(component2 == gen_hern):
    name2 = "hern"
elif(component2 == einasto):
    name2 = "einasto"
# # # # # # # # # # # # # # # # #



# # # # # # # # # # # # # # # # #
#     CHOOSE YOUR TESTS     #
# # # # # # # # # # # # # # # # # 
output         = y        #
# # # # # # # # # # # # # # # # #
tidal          = n        #
# # # # # # # # # # # # # # # # #
virial         = y        #
# # # # # # # # # # # # # # # # #
make_clean     = n        #
# # # # # # # # # # # # # # # # #
#         PLOTS?          #
make_plots     = y        #
# # # # # # # # # # # # # # # # #
#         SAVE?           #
save_run       = n        #
# # # # # # # # # # # # # # # # #
cleanse        = False    #
# # # # # # # # # # # # # # # # #

folder_name = "orphan_parameters_2comp"
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
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
rscale_l = str( r_l )
rscale_d = str( r_d )
mass_l   = str( m_l )
mass_d   = str( m_d )
comp1    = str(component1)
comp2    = str(component2)
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
                #/# # # # # # # # # # # # # # \#
                #          Engine Room         #
                #\# # # # # # # # # # # # # # /#
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 

#for i in range(M,N):
    #os.system("mv ../quick_plots/outputs/output_" + name1 + "_" + name2 + "_" + sim_time[i] + "gy.out ./sim_outputs")
    
if(parse):
    print "parsing data"
    for i in range(M, N):
        os.system("./outputparser.py ./sim_outputs/output_" + name1 + "_" + name2 + "_" + sim_time[i] + ext + "  " + sim_time[i] +"gy")

if(output):    
    print "performing tests"
    #os.system("g++ -std=c++11 output_test.cpp -o output_test")
    os.system("make all")
    for i in range(M, N):
        os.system("./output_test " + sim_time[i] + " " + rscale_l + " " + rscale_d + " " + mass_l + " " + mass_d + " " + comp1 + " " + comp2)
    
if(virial):
    #os.system("g++ -std=c++11 virial_test.cpp -o virial_test")
    #os.system("make all")
    for i in range(M, N):
        os.system("./virial_test " + sim_time[i] + " " + rscale_l + " " + rscale_d + " " + mass_l + " " + mass_d + " " + comp1 + " " + comp2)

if(make_plots):
    print "making plots"
    os.chdir("plots")
    os.system("./plotting.py ")
    #os.system("./stability.py")

if(save_run):
    os.system("./save_runs.py 'save' " + folder_name)
if(cleanse):
    os.system("./cleanse.sh")

if(make_clean):
    os.system("make clean")