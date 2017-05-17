#/* Copyright (c) 2016 Siddhartha Shelton */
import sys
import numpy as np
import matplotlib.pyplot as plt





def get_start_number(file_name):
    g = open(file_name, 'r')
    num = 1
    for line in g:
        if (line.startswith("# ignore")):
            break
        else:
            num += 1
    g.close()
    
    return num


def parse_data(file_name, ext):
    g = open('./raw_data/light_matter_'+ ext +'.dat', 'w')
    f = open('./raw_data/dark_matter_' + ext +'.dat', 'w')
    lines = []
    lines = open(file_name).readlines() 
    start = get_start_number(file_name)
    lines = lines[start:len(lines)];

    for line in lines:
        tt = line.split(', ');
        #print(len(tt))
        isDark = int(tt[0]);
        if(len(tt) == 8):
            ty = float(tt[0])
            x  = float(tt[1])
            y  = float(tt[2])
            z  = float(tt[3])
            vx = float(tt[4])
            vy = float(tt[5])
            vz = float(tt[6])
            m  = float(tt[7])
        if(len(tt) == 12):
            ty = float(tt[0])
            x  = float(tt[1])
            y  = float(tt[2])
            z  = float(tt[3])
            l  = float(tt[4])
            b  = float(tt[5])
            r  = float(tt[6])
            vx = float(tt[7])
            vy = float(tt[8])
            vz = float(tt[9])
            m  = float(tt[10])
            vlos = float(tt[11])

        if(len(tt) == 8):
            if (isDark == 1):
                f.write("%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\n" % ( x, y, z, vx, vy, vz, m))
            else:
                g.write("%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\n" % ( x, y, z, vx, vy, vz, m))
        if(len(tt) == 12):
            if (isDark == 1):
                f.write("%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\n" % ( x, y, z, l, b, r, vx, vy, vz, m, vlos))
            else:
                g.write("%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\t%.15f\n" % ( x, y, z, l, b, r, vx, vy, vz, m, vlos))

def main():
    args = sys.argv;
    file_name = args[1];
    ext       = args[2];
    parse_data(file_name, ext)

main()