#! /usr/bin/python
import os
from subprocess import call
import numpy as np
import matplotlib.pyplot as plt

args = [0.6, 0.2, 0.2, 11, 0.2]

counts = [150, 0, 0, 0, 275, 150, 100, 75, 110, 110, 100, 110, 100, 120, 110, 150, 130, 75, 150, 100, 50, 50, 0, 20, 20]

sim_time      = "4"
back_time     = str(args[0])
r0            = str(args[1])
light_r_ratio = str(args[2])
mass          = str(args[3])
mass_ratio    = str(args[4])

#print "parameters: ", back_time, r0, light_r_ratio, mass, mass_ratio
run_nbody = True
run_nbody = False
plot_hist = True
make_data_hist = False

histogram = "tidal_histogram.hist"
histogram_single = "tidal_histogram_single_plummer.hist"
data2 = "Orphan_Data_September_2014.hist"
data = "data.hist"
blank = "none.hist"
#######################################################################

if(run_nbody == True):
    os.chdir("../")
    os.system("rm -r nbody_test")
    os.system("mkdir nbody_test")
    os.chdir("nbody_test")
    os.system("cmake -DCMAKE_BUILD_TYPE=Release  -DNBODY_GL=ON -DBOINC_APPLICATION=OFF -DSEPARATION=OFF -DNBODY_OPENMP=ON    ~/Desktop/research/milkywayathome_client/")
    os.system("make -j ")
    os.chdir("../")
    os.system("~/Desktop/research/nbody_test/bin/milkyway_nbody \
        -f ~/Desktop/research/lua/EMD_20k_isotropic_1_54.lua \
        -z ~/Desktop/research/data_testing/histograms/" + histogram + " \
        -n 8 -x -e 27744245 -i "+ (sim_time) + " " + back_time + " " + r0 + " " + light_r_ratio + " " + mass + " " + mass_ratio )
    os.chdir("data_testing")
    


if(make_data_hist == True):
    g = open("histograms/" + data, 'w')
    lamb = 32 + 5
    total = 0.0
    for i in range(0, len(counts)):
        total = total + counts[i]
    total = total * 5.0 / 222288.24  #each count is fturn off star which reps about a cluster of 5 solar masses
    for i in range(0, len(counts)):
        bodies = counts[i] * 5.0 / 222288.24
        g.write("%f \t %f\n" % (lamb, bodies / total ))
        lamb = lamb - 3
    g.close()

if(plot_hist == True):
    lines = []
    lines = open('histograms/' + histogram).readlines();
    lines = lines[40:len(lines)]
    sim_l = []
    sim_n = []
    for line in lines:
        tokens = line.split();
        if tokens: #tests to make sure tokens is not empty
            lda = float(tokens[1])
            cts = float(tokens[3])
            sim_l.append(lda)
            sim_n.append(cts)

    lines = []
    lines = open('histograms/' + data2).readlines();
    lines = lines[5:len(lines)]
    data_l = []
    data_n = []
    for line in lines:
        tokens = line.split()
        if tokens:
            dat_l = float(tokens[1])
            dat_n = float(tokens[3])
            data_l.append(dat_l)
            data_n.append(dat_n)
    
    
    #f, (f1, f2) = plt.subplots(2, sharex = True, sharey = True)
    plt.subplot(211)
    plt.bar(sim_l, sim_n, width=1, color='b')
    plt.legend("sim")
    plt.title('Histogram of Light Matter Distribution After 4 Gy')
    plt.xlim((40, -40))
    plt.ylim((0.0, 0.15))
    plt.ylabel('counts')
    
    plt.subplot(212)
    plt.bar(data_l, data_n, width=1, color='k')
    plt.legend("d")
    plt.xlim((40, -40))
    plt.ylim((0.0, 0.15))
    plt.xlabel('l')
    plt.ylabel('counts')
    #f.subplots_adjust(hspace=0)
    plt.savefig('plots/hist', format='png')
    #plt.show()
