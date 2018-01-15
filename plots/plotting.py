#! /usr/bin/python
#/* Copyright (c) 2017 Siddhartha Shelton */
import os
import subprocess
from subprocess import call
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.patches as mpatches
import math as mt


class bin_datas:
    def __init__(self, file_name):
        self.file_name = file_name
        self.counts = []
        self.bins = []
        
        self.get_data()
        
    def get_data(self):
        f = open(self.file_name, 'r')
        
        for line in f:
            line = line.split('\t')
            ns = float(line[0])
            bn = float(line[1])
            self.counts.append(ns)
            self.bins.append(bn)
        f.close()
        
class theory_data:
    def __init__(self, file_name, matter_type = None):
        self.file_name = file_name
        self.x_vals = []
        self.combined = []
        self.light = []
        self.dark = []
        self.matter_type = matter_type
        self.get_data()
        
    def get_data(self):
        f = open(self.file_name, 'r')
        for line in f:
            line = line.split('\t')
            if(len(line) > 2):#for the radial density files
                x = float(line[0])
                c = float(line[1])
                l = float(line[2])
                d = float(line[3])
                self.x_vals.append(x)
                self.combined.append(c)
                self.light.append(l)
                self.dark.append(d)
            elif(self.matter_type == 'light'):#for the vel files
                x = float(line[1])
                l = float(line[0])
                self.x_vals.append(x)
                self.light.append(l)
            elif(self.matter_type == 'dark'):
                x = float(line[1])
                l = float(line[0])
                self.x_vals.append(x)
                self.dark.append(l)    
                
        f.close()





#plot each radial component over time. 
#first row plots of each component initial
#second row same but after some time:
def radial_components_over_time():
    sim_time = ['0', '0']
    
    theory_den = "/home/sidd/Desktop/research/data_testing/theory/theory_den.dat"
    light      = "/home/sidd/Desktop/research/data_testing/binned_data/light_matter_bins_"
    dark       = "/home/sidd/Desktop/research/data_testing/binned_data/dark_matter_bins_"
    both       = "/home/sidd/Desktop/research/data_testing/binned_data/both_matter_bins_"
    
    ev_0gy = sim_time[0] + "gy.dat"
    #ev_2gy = sim_time[1] + "gy.dat"
    ev_4gy = sim_time[1] + "gy.dat"
    
    light_0gy = bin_datas(light + ev_0gy)
    #light_2gy = bin_datas(light + ev_2gy)
    light_4gy = bin_datas(light + ev_4gy)
    
    dark_0gy = bin_datas(dark + ev_0gy)
    #dark_2gy = bin_datas(dark + ev_2gy)
    dark_4gy = bin_datas(dark + ev_4gy)
    
    both_0gy = bin_datas(both + ev_0gy) 
    both_4gy = bin_datas(both + ev_4gy)
    
    theory = theory_data(theory_den)
    y = 1500
    x = 3
    w = .04
    c = 'red'
    c2 = 'black'
    alp = 0.8
    lw = 3
    plt.figure(figsize=(20, 10))
    plt.subplot(231)
    plt.title('Baryonic Matter')
    plt.xlabel('Radius (Kpc)')
    plt.ylabel('N')
    plt.xlim(0, x)
    plt.ylim(0, y)
    plt.bar(light_0gy.bins, light_0gy.counts, width = w, color=c, alpha = alp,  label = 'Baryon Counts')
    plt.plot(theory.x_vals, theory.light, color = c2, linestyle = '-', linewidth = lw, label = 'Baryon Theory')
    plt.legend()
    
    plt.subplot(232)
    plt.title('Dark Matter')
    plt.xlabel('Radius (Kpc)')
    plt.ylabel('N')
    plt.xlim(0, x)
    plt.ylim(0, y)
    plt.bar(dark_0gy.bins, dark_0gy.counts, width = w, color=c, alpha = alp, label = 'Dark Matter Counts')
    plt.plot(theory.x_vals, theory.dark, color = c2, linestyle = '-', linewidth = lw, label = 'Dark Matter Theory')
    plt.legend()
    
    plt.subplot(233)
    plt.title('Combined Matter')
    plt.xlabel('Radius (Kpc)')
    plt.ylabel('N')
    plt.xlim(0, x)
    plt.ylim(0, 2*y)
    plt.bar(both_0gy.bins, both_0gy.counts, width = w, color=c, alpha = alp, label = 'Dark Matter Counts')
    plt.plot(theory.x_vals, theory.combined, color = c2, linestyle = '-', linewidth = lw, label = 'Dark Matter Theory')
    plt.legend()
    
    plt.subplot(234)
    plt.xlabel('Radius (Kpc)')
    plt.ylabel('N')
    plt.xlim(0, x)
    plt.ylim(0, y)
    plt.bar(light_0gy.bins, light_0gy.counts, width = w, color=c, alpha = alp, label = 'Baryon Counts')
    plt.plot(theory.x_vals, theory.light, color = c2, linestyle = '-', linewidth = lw, label = 'Baryon Theory')
    plt.legend()
    
    plt.subplot(235)
    plt.xlabel('Radius (Kpc)')
    plt.ylabel('N')
    plt.xlim(0, x)
    plt.ylim(0, y)
    plt.bar(dark_0gy.bins, dark_0gy.counts, width = w, color=c, alpha = alp, label = 'Dark Matter Counts')
    plt.plot(theory.x_vals, theory.dark, color = c2, linestyle = '-', linewidth = lw, label = 'Dark Matter Theory')
    plt.legend()
    
    plt.subplot(236)
    plt.xlabel('Radius (Kpc)')
    plt.ylabel('N')
    plt.xlim(0, x)
    plt.ylim(0, 2*y)
    plt.bar(both_0gy.bins, both_0gy.counts, width = w, color=c, alpha = alp, label = 'Dark Matter Counts')
    plt.plot(theory.x_vals, theory.combined, color = c2, linestyle = '-', linewidth = lw, label = 'Dark Matter Theory')
    plt.legend()
    
    
    
    plt.savefig("radial_components_over_time", format='png')
    


#plot each vel component over time. 
#first row plots of each component initial
#second row same but after some time:
def vel_components_over_time():
    sim_time = ['0', '0']
    
    theory_light   = "/home/sidd/Desktop/research/data_testing/binned_data/light_matter_theory_vel_bins.dat"
    theory_dark   = "/home/sidd/Desktop/research/data_testing/binned_data/dark_matter_theory_vel_bins.dat"
    light = "/home/sidd/Desktop/research/data_testing/binned_data/light_matter_vel_bins_"
    dark  = "/home/sidd/Desktop/research/data_testing/binned_data/dark_matter_vel_bins_"
    
    ev_0gy = sim_time[0] + "gy.dat"
    #ev_2gy = sim_time[1] + "gy.dat"
    ev_4gy = sim_time[1] + "gy.dat"
    
    light_0gy = bin_datas(light + ev_0gy)
    #light_2gy = bin_datas(light + ev_2gy)
    light_4gy = bin_datas(light + ev_4gy)
    
    dark_0gy = bin_datas(dark + ev_0gy)
    #dark_2gy = bin_datas(dark + ev_2gy)
    dark_4gy = bin_datas(dark + ev_4gy)
    
    theory_light = theory_data(theory_light, 'light')
    theory_dark  = theory_data(theory_dark, 'dark')
    #print theory_light.light
    y = 400
    x = 10
    w = .04
    c = 'red'
    c2 = 'black'
    alp = 0.8
    lw = 3
    sbpt = 221
    
    plt.figure(figsize=(20, 10))
    plt.subplot(sbpt)
    plt.title('Baryonic Matter')
    plt.xlabel('Velocity (km/s)')
    plt.ylabel('N')
    plt.xlim(0, x)
    plt.ylim(0, y)
    plt.bar(light_0gy.bins, light_0gy.counts, width = w, color=c, alpha = alp,  label = 'Baryon Counts')
    plt.plot(theory_light.x_vals, theory_light.light, color = c2, linestyle = '-', linewidth = lw, label = 'Baryon Theory')
    plt.legend()
    
    plt.subplot(sbpt + 1)
    plt.title('Dark Matter')
    plt.xlabel('Velocity (km/s)')
    plt.ylabel('N')
    plt.xlim(0, x)
    plt.ylim(0, y)
    plt.bar(dark_0gy.bins, dark_0gy.counts, width = w, color=c, alpha = alp, label = 'Dark Matter Counts')
    plt.plot(theory_dark.x_vals, theory_dark.dark, color = c2, linestyle = '-', linewidth = lw, label = 'Dark Matter Theory')
    plt.legend()
    
    plt.subplot(sbpt + 2)
    plt.xlabel('Velocity (km/s)')
    plt.ylabel('N')
    plt.xlim(0, x)
    plt.ylim(0, y)
    plt.bar(light_0gy.bins, light_0gy.counts, width = w, color=c, alpha = alp, label = 'Baryon Counts')
    plt.plot(theory_light.x_vals, theory_light.light, color = c2, linestyle = '-', linewidth = lw, label = 'Baryon Theory')
    plt.legend()
    
    plt.subplot(sbpt + 3)
    plt.xlabel('Velocity (km/s)')
    plt.ylabel('N')
    plt.xlim(0, x)
    plt.ylim(0, y)
    plt.bar(dark_0gy.bins, dark_0gy.counts, width = w, color=c, alpha = alp, label = 'Dark Matter Counts')
    plt.plot(theory_dark.x_vals, theory_dark.dark, color = c2, linestyle = '-', linewidth = lw, label = 'Dark Matter Theory')
    plt.legend()
    
    
    
    plt.savefig("vel_components_over_time", format='png')
    
    
#for creating a single plot with the two components having different distribution values
def mixed_radial_values():
    sim_time = ['0', '0']
    
    theory_den = "/home/sidd/Desktop/research/data_testing/theory/theory_den.dat"
    light      = "/home/sidd/Desktop/research/data_testing/binned_data/light_matter_bins_"
    dark       = "/home/sidd/Desktop/research/data_testing/binned_data/dark_matter_bins_"
    both       = "/home/sidd/Desktop/research/data_testing/binned_data/both_matter_bins_"
    
    ev_0gy = sim_time[0] + "gy.dat"
    #ev_2gy = sim_time[1] + "gy.dat"
    #ev_4gy = sim_time[1] + "gy.dat"
    
    light_0gy = bin_datas(light + ev_0gy)
    #light_2gy = bin_datas(light + ev_2gy)
    #light_4gy = bin_datas(light + ev_4gy)
    
    dark_0gy = bin_datas(dark + ev_0gy)
    #dark_2gy = bin_datas(dark + ev_2gy)
    #dark_4gy = bin_datas(dark + ev_4gy)
    
    both_0gy = bin_datas(both + ev_0gy) 
    
    theory = theory_data(theory_den)
    
    y = 3500
    x = 3
    w = .04
    c = 'red'
    c2 = 'black'
    alp = 0.5
    lw = 3
    plt.figure(figsize=(20, 10))
    plt.title('Radial Distribution')
    plt.xlabel('Radius (Kpc)')
    plt.ylabel('N')
    plt.xlim(0, x)
    plt.ylim(0, y)
    plt.bar(light_0gy.bins, light_0gy.counts, width = w, color='red', alpha = alp,  label = 'Baryon Counts')
    plt.bar(light_0gy.bins, dark_0gy.counts,  width = w, color='blue', alpha = alp,  label = 'Dark Matter Counts')
    plt.bar(light_0gy.bins, both_0gy.counts,  width = w, color='green', alpha = alp,  label = 'Combined Counts')
    
    plt.plot(theory.x_vals, theory.light,    color = 'red', linestyle = '-', linewidth = lw, label = 'Baryon Theory')
    plt.plot(theory.x_vals, theory.dark,     color = 'blue', linestyle = '-', linewidth = lw, label = 'Dark Matter Theory')
    plt.plot(theory.x_vals, theory.combined, color = 'green', linestyle = '-', linewidth = lw, label = 'Combined Theory')
    plt.legend()

    plt.savefig("mixed_radial_values", format='png')   
    
    

def main():
    
    #radial_components_over_time()
    #mixed_radial_values()
    vel_components_over_time()
    
main()

