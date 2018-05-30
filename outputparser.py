#! /usr/bin/python
#/* Copyright (c) 2016 Siddhartha Shelton */
# A quick parsing script for nbody outputs #
import sys
import os

def parse_data(file_name, ext):
    #os.system("ls " + file_name)
    g = open('./raw_data/light_matter_'+ ext +'.dat', 'w')
    f = open('./raw_data/dark_matter_' + ext +'.dat', 'w')
    data = open(file_name, 'r')

    read_data = False
    for line in data:
        if(line.startswith("# ignore")):
            read_data = True
            continue
        if(line.startswith("</bodies>")):
            break
        if(read_data):
            tt = line.split(', ');
            isDark = int(tt[0]);
            if(len(tt) == 9):
                ty = float(tt[0])
                x  = float(tt[1])
                y  = float(tt[2])
                z  = float(tt[3])
                
                vx = float(tt[4])
                vy = float(tt[5])
                vz = float(tt[6])
                
                m  = float(tt[7])
            if(len(tt) == 13):
                ty = float(tt[0])
                x  = float(tt[2])
                y  = float(tt[3])
                z  = float(tt[4])
                
                l  = float(tt[5])
                b  = float(tt[6])
                r  = float(tt[7])
                
                vx = float(tt[8])
                vy = float(tt[9])
                vz = float(tt[10])
                
                m  = float(tt[11])
                vlos = float(tt[12])

            if(len(tt) == 9):
                if (isDark == 1):
                    f.write("%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\n" % ( x, y, z, vx, vy, vz, m))
                else:
                    g.write("%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\n" % ( x, y, z, vx, vy, vz, m))
            if(len(tt) == 13):
                if (isDark == 1):
                    f.write("%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\n" % ( x, y, z, l, b, r, vx, vy, vz, m, vlos))
                else:
                    g.write("%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\n" % ( x, y, z, l, b, r, vx, vy, vz, m, vlos))


    f.close()
    g.close()
    
def main():
    args = sys.argv;
    file_name = args[1];
    ext       = args[2];
    parse_data(file_name, ext)

main()