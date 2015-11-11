#! /usr/bin/python
import os
from subprocess import call

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
make_data_hist = True

histogram = "tidal_histogram.hist"
data2 = "Orphan_Data_September_2014.hist"
data = "data.hist"
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
    f = open('histogram.gnuplot', 'w')
    f.write("reset\n")
    f.write("set terminal jpeg\n")
    f.write("set key on\n")
    f.write("set ylabel 'counts'\n")
    f.write("set xlabel 'radius (Kpc)'\n")
    f.write("set xrange[-50:50]\n")
    f.write("set yrange[0:.15]\n\n\n")

    f.write("set output \"~/Desktop/research/data_testing/plots/hist.jpeg\" \n")
    f.write("set title 'Histogram of Light Matter Distribution After 4 Gy' \n")
    f.write("plot 'histograms/" + histogram + "' using 2:4 with boxes title 'sim', 'histograms/" + data + "' using 1:2 with boxes title 'data' \n\n") 


    f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")
    f.write("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n")

    f.close()

    os.system("gnuplot histogram.gnuplot")
    #os.system("rm histogram.gnuplot")
