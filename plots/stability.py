#! /usr/bin/python
#/* Copyright (c) 2017 Siddhartha Shelton */
from classes import *
import time

sim_time = [ "0", "2", "4"]
#sim_time = [ "0"]


def radial():
    theory_path = "/home/sidd/Desktop/research/data_testing/theory/theory_den.dat"
    light_path      = "/home/sidd/Desktop/research/data_testing/binned_data/light_matter_bins_"
    dark_path       = "/home/sidd/Desktop/research/data_testing/binned_data/dark_matter_bins_"
    both_path       = "/home/sidd/Desktop/research/data_testing/binned_data/both_matter_bins_"

    print 'plotting radial'
    theory  = theory_data(theory_path)
    for i in range(0, len(sim_time)):
        ev = str(sim_time[i]) + "gy.dat"
        light = bin_datas(light_path + ev)
        dark  = bin_datas(dark_path  + ev)
        both  = bin_datas(both_path  + ev) 
        y = 1500
        x = 3
        w = .04
        c = 'red'
        c2 = 'black'
        alp = 0.8
        lw = 3
        
        params = {'legend.fontsize': 18,
            'legend.handlelength': 2}
        plt.rcParams.update(params)
        f, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, sharex='col', sharey='row')
        f.subplots_adjust(hspace=0)
        f.subplots_adjust(wspace=0)
        plt.figure(figsize=(20, 10))
        
        
        plt.subplot(221)
        plt.title('Baryonic Matter ' + str(sim_time[i]) + 'GY', fontsize=24)
        #plt.xlabel('Radius (Kpc)')
        plt.ylabel('N' , fontsize=18)
        plt.xlim(0, x)
        plt.ylim(0, y)
        plt.bar(light.bins, light.counts, width = w, color=c, alpha = alp,  label = 'Baryonic Distribution')
        plt.plot(theory.x_vals, theory.light, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
        plt.legend()
        
        
        plt.subplot(222)
        plt.title('Dark Matter ' + str(sim_time[i]) + 'GY', fontsize=24)
        #plt.xlabel('Radius (Kpc)')
        #plt.ylabel('N')
        plt.xlim(0, x)
        plt.ylim(0, y)
        plt.bar(dark.bins, dark.counts, width = w, color=c, alpha = alp, label = 'Dark Matter Distribution')
        plt.plot(theory.x_vals, theory.dark, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
        plt.legend()
        
        plt.subplot(223)
        #plt.title('Overlapping',fontsize=24)
        plt.xlabel('Radius (Kpc)' , fontsize=18)
        plt.ylabel('N' , fontsize=18)
        plt.xlim(0, x)
        plt.ylim(0, y)
        plt.bar(light.bins, light.counts, width = w, color=c, alpha = alp,  label = 'Baryonic Distribution')
        plt.bar(dark.bins, dark.counts, width = w, color='blue', alpha = alp, label = 'Dark Matter Distribution')
        plt.plot(theory.x_vals, theory.light, color = 'cyan', linestyle = '-', linewidth = lw, label = 'Baryonic Theoretical Distribution')
        plt.plot(theory.x_vals, theory.dark, color = c2, linestyle = '-', linewidth = lw, label = 'Dark Matter Theoretical Distribution')
        plt.legend()
        
        
        plt.subplot(224)
        #plt.title('Combined Matter' + sim_time[i] + 'GY',fontsize=24)
        plt.xlabel('Radius (Kpc)' , fontsize=18)
        #plt.ylabel('N')
        plt.xlim(0, x)
        plt.ylim(0, 2.0*y)
        plt.bar(both.bins, both.counts, width = w, color=c, alpha = alp, label = 'Combined Distribution')
        plt.plot(theory.x_vals, theory.combined, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
        plt.legend()
        
        plt.savefig("rad/rad_" + str(sim_time[i]) + "gy.png", format='png')
        plt.close()
        del light, dark, both
    del theory
    return 0

def radial_phi():
    theory_path = "/home/sidd/Desktop/research/data_testing/theory/theory_phi.dat"
    light_path  = "/home/sidd/Desktop/research/data_testing/binned_data/phi_light_"
    dark_path   = "/home/sidd/Desktop/research/data_testing/binned_data/phi_dark_"
    both_path   = "/home/sidd/Desktop/research/data_testing/binned_data/phi_both_"
    
    print 'plotting radial phi'
    theory  = theory_data(theory_path)
    for i in range(0, len(sim_time)):
        ev = str(sim_time[i]) + "gy.dat"
        light = bin_datas(light_path + ev)
        dark  = bin_datas(dark_path  + ev)
        both  = bin_datas(both_path  + ev) 
        y = 300
        x = 5
        w = .04
        c = 'red'
        c2 = 'black'
        alp = 0.8
        lw = 3
        
        params = {'legend.fontsize': 18,
            'legend.handlelength': 2}
        plt.rcParams.update(params)
        f, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, sharex='col', sharey='row')
        f.subplots_adjust(hspace=0)
        f.subplots_adjust(wspace=0)
        plt.figure(figsize=(20, 10))
        
        plt.subplot(221)
        plt.title(r'Baryonic Matter $\phi$ Distribution ' + str(sim_time[i]) + 'GY', fontsize=24)
        #plt.xlabel('Radius (Kpc)')
        plt.ylabel('N' , fontsize=18)
        plt.xlim(-x, x)
        plt.ylim(0, y)
        plt.bar(light.bins, light.counts, width = w, color=c, alpha = alp,  label = 'Baryonic Distribution')
        plt.plot(theory.x_vals, theory.light, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
        plt.legend()
        
        plt.subplot(222)
        plt.title(r'Dark Matter $\phi$ Distribution ' + str(sim_time[i]) + 'GY', fontsize=24)
        #plt.xlabel('Radius (Kpc)')
        #plt.ylabel('N')
        plt.xlim(-x, x)
        plt.ylim(0, y)
        plt.bar(dark.bins, dark.counts, width = w, color=c, alpha = alp, label = 'Dark Matter Distribution')
        plt.plot(theory.x_vals, theory.dark, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
        plt.legend()
        
        plt.subplot(223)
        #plt.title('Overlapping',fontsize=24)
        plt.xlabel(r'$\phi$' , fontsize=18)
        plt.ylabel('N' , fontsize=18)
        plt.xlim(-x, x)
        plt.ylim(0, y)
        plt.bar(light.bins, light.counts, width = w, color=c, alpha = alp,  label = 'Baryonic Distribution')
        plt.bar(dark.bins, dark.counts, width = w, color='blue', alpha = alp, label = 'Dark Matter Distribution')
        plt.plot(theory.x_vals, theory.light, color = 'cyan', linestyle = '-', linewidth = lw, label = 'Baryonic Theoretical Distribution')
        plt.plot(theory.x_vals, theory.dark, color = c2, linestyle = '-', linewidth = lw, label = 'Dark Matter Theoretical Distribution')
        plt.legend()
        
        plt.subplot(224)
        #plt.title('Combined Matter' + sim_time[i] + 'GY',fontsize=24)
        plt.xlabel(r'$\phi$' , fontsize=18)
        #plt.ylabel('N')
        plt.xlim(-x, x)
        plt.ylim(0, y)
        plt.bar(both.bins, both.counts, width = w, color=c, alpha = alp, label = 'Combined Distribution')
        plt.plot(theory.x_vals, theory.combined, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
        plt.legend()
        
        plt.savefig("phi/phi_" + str(sim_time[i]) + "gy.png", format='png')
        plt.close()
        del light, dark, both
    del theory
    return 0

def radial_theta():
    theory_path = "/home/sidd/Desktop/research/data_testing/theory/theory_theta.dat"
    light_path  = "/home/sidd/Desktop/research/data_testing/binned_data/theta_light_"
    dark_path   = "/home/sidd/Desktop/research/data_testing/binned_data/theta_dark_"
    both_path   = "/home/sidd/Desktop/research/data_testing/binned_data/theta_both_"
    
    print 'plotting radial theta'
    theory  = theory_data(theory_path)
    for i in range(0, len(sim_time)):
        ev = str(sim_time[i]) + "gy.dat"
        light = bin_datas(light_path + ev)
        dark  = bin_datas(dark_path  + ev)
        both  = bin_datas(both_path  + ev) 
        y = 300
        x = 5
        w = .04
        c = 'red'
        c2 = 'black'
        alp = 0.8
        lw = 3
        
        params = {'legend.fontsize': 18,
            'legend.handlelength': 2}
        plt.rcParams.update(params)
        f, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, sharex='col', sharey='row')
        f.subplots_adjust(hspace=0)
        f.subplots_adjust(wspace=0)
        plt.figure(figsize=(20, 10))
        
        plt.subplot(221)
        plt.title(r'Baryonic Matter $\theta$ Distribution ' + str(sim_time[i]) + 'GY', fontsize=24)
        #plt.xlabel('Radius (Kpc)')
        plt.ylabel('N' , fontsize=18)
        plt.xlim(-x, x)
        plt.ylim(0, y)
        plt.bar(light.bins, light.counts, width = w, color=c, alpha = alp,  label = 'Baryonic Distribution')
        plt.plot(theory.x_vals, theory.light, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
        plt.legend()
        
        plt.subplot(222)
        plt.title(r'Dark Matter $\theta$ Distribution ' + str(sim_time[i]) + 'GY', fontsize=24)
        #plt.xlabel('Radius (Kpc)')
        #plt.ylabel('N')
        plt.xlim(-x, x)
        plt.ylim(0, y)
        plt.bar(dark.bins, dark.counts, width = w, color=c, alpha = alp, label = 'Dark Matter Distribution')
        plt.plot(theory.x_vals, theory.dark, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
        plt.legend()
        
        plt.subplot(223)
        #plt.title('Overlapping',fontsize=24)
        plt.xlabel(r'$\theta$' , fontsize=18)
        plt.ylabel('N' , fontsize=18)
        plt.xlim(-x, x)
        plt.ylim(0, y)
        plt.bar(light.bins, light.counts, width = w, color=c, alpha = alp,  label = 'Baryonic Distribution')
        plt.bar(dark.bins, dark.counts, width = w, color='blue', alpha = alp, label = 'Dark Matter Distribution')
        plt.plot(theory.x_vals, theory.light, color = 'cyan', linestyle = '-', linewidth = lw, label = 'Baryonic Theoretical Distribution')
        plt.plot(theory.x_vals, theory.dark, color = c2, linestyle = '-', linewidth = lw, label = 'Dark Matter Theoretical Distribution')
        plt.legend()
        
        plt.subplot(224)
        #plt.title('Combined Matter' + sim_time[i] + 'GY',fontsize=24)
        plt.xlabel(r'$\theta$' , fontsize=18)
        #plt.ylabel('N')
        plt.xlim(-x, x)
        plt.ylim(0, 2*y)
        plt.bar(both.bins, both.counts, width = w, color=c, alpha = alp, label = 'Combined Distribution')
        plt.plot(theory.x_vals, theory.combined, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
        plt.legend()
        
        plt.savefig("theta/theta_" + str(sim_time[i]) + "gy.png", format='png')
        plt.close()
        del light, dark, both
    del theory
    return 0


def vel():
    theory_light   = "/home/sidd/Desktop/research/data_testing/binned_data/light_matter_theory_vel_bins.dat"
    theory_dark   = "/home/sidd/Desktop/research/data_testing/binned_data/dark_matter_theory_vel_bins.dat"
    light_path = "/home/sidd/Desktop/research/data_testing/binned_data/light_matter_vel_bins_"
    dark_path  = "/home/sidd/Desktop/research/data_testing/binned_data/dark_matter_vel_bins_"

    print 'plotting vel'
    theory_l = theory_data(theory_light, 'light')
    theory_d = theory_data(theory_dark, 'dark')
    for i in range(0, len(sim_time)):
        ev = str(sim_time[i]) + "gy.dat"
        light = bin_datas(light_path + ev)
        dark  = bin_datas(dark_path  + ev)
        y = 400
        x = 10
        w = .04
        c = 'red'
        c2 = 'black'
        alp = 0.8
        lw = 3
        params = {'legend.fontsize': 20,
            'legend.handlelength': 2}
        
        plt.rcParams.update(params)
        #f, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, sharex='col', sharey='row')
        #f.subplots_adjust(hspace=0)
        #f.subplots_adjust(wspace=0)
        plt.figure(figsize=(20, 10))
        
        plt.subplot(121)
        plt.title('Baryonic Matter ' + str(sim_time[i]) + 'GY', fontsize=24)
        plt.xlabel('Velocity (km/s)', fontsize=18)
        plt.xlim(0, x)
        plt.ylim(0, y)
        plt.bar(light.bins, light.counts, width = w, color=c, alpha = alp,  label = 'Baryonic Distribution')
        plt.plot(theory_l.x_vals, theory_l.light, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
        plt.legend()
        
        plt.subplot(122)
        plt.title('Dark Matter ' + str(sim_time[i]) + 'GY', fontsize=24)
        plt.xlabel('Velocity (km/s)', fontsize=18)
        plt.xlim(0, x)
        plt.ylim(0, y)
        plt.bar(dark.bins, dark.counts, width = w, color=c, alpha = alp, label = 'Dark Matter Distribution')
        plt.plot(theory_d.x_vals, theory_d.dark, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
        plt.legend()
        
        plt.savefig("vel/vel_" + str(sim_time[i]) + "gy.png", format='png')
        plt.close()
        del light, dark
    del theory_l, theory_d
    return 0

def vel_phi():
    theory_path = "/home/sidd/Desktop/research/data_testing/theory/theory_phi.dat"
    light_path  = "/home/sidd/Desktop/research/data_testing/binned_data/phi_vel_light_"
    dark_path   = "/home/sidd/Desktop/research/data_testing/binned_data/phi_vel_dark_"
    both_path   = "/home/sidd/Desktop/research/data_testing/binned_data/phi_vel_both_"
    
    print 'plotting vel phi'
    theory  = theory_data(theory_path)
    for i in range(0, len(sim_time)):
        ev = str(sim_time[i]) + "gy.dat"
        light = bin_datas(light_path + ev)
        dark  = bin_datas(dark_path  + ev)
        both  = bin_datas(both_path  + ev) 
        y = 300
        x = 5
        w = .04
        c = 'red'
        c2 = 'black'
        alp = 0.8
        lw = 3
        
        params = {'legend.fontsize': 18,
            'legend.handlelength': 2}
        plt.rcParams.update(params)
        f, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, sharex='col', sharey='row')
        f.subplots_adjust(hspace=0)
        f.subplots_adjust(wspace=0)
        plt.figure(figsize=(20, 10))
        
        plt.subplot(221)
        plt.title(r'Baryonic Matter $\phi$ Distribution ' + str(sim_time[i]) + 'GY', fontsize=24)
        #plt.xlabel('Radius (Kpc)')
        plt.ylabel('N' , fontsize=18)
        plt.xlim(-x, x)
        plt.ylim(0, y)
        plt.bar(light.bins, light.counts, width = w, color=c, alpha = alp,  label = 'Baryonic Distribution')
        plt.plot(theory.x_vals, theory.light, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
        plt.legend()
        
        plt.subplot(222)
        plt.title(r'Dark Matter $\phi$ Distribution ' + str(sim_time[i]) + 'GY', fontsize=24)
        #plt.xlabel('Radius (Kpc)')
        #plt.ylabel('N')
        plt.xlim(-x, x)
        plt.ylim(0, y)
        plt.bar(dark.bins, dark.counts, width = w, color=c, alpha = alp, label = 'Dark Matter Distribution')
        plt.plot(theory.x_vals, theory.dark, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
        plt.legend()
        
        plt.subplot(223)
        #plt.title('Overlapping',fontsize=24)
        plt.xlabel(r'$\phi$' , fontsize=18)
        plt.ylabel('N' , fontsize=18)
        plt.xlim(-x, x)
        plt.ylim(0, y)
        plt.bar(light.bins, light.counts, width = w, color=c, alpha = alp,  label = 'Baryonic Distribution')
        plt.bar(dark.bins, dark.counts, width = w, color='blue', alpha = alp, label = 'Dark Matter Distribution')
        plt.plot(theory.x_vals, theory.light, color = 'cyan', linestyle = '-', linewidth = lw, label = 'Baryonic Theoretical Distribution')
        plt.plot(theory.x_vals, theory.dark, color = c2, linestyle = '-', linewidth = lw, label = 'Dark Matter Theoretical Distribution')
        plt.legend()
        
        plt.subplot(224)
        #plt.title('Combined Matter' + sim_time[i] + 'GY',fontsize=24)
        plt.xlabel(r'$\phi$' , fontsize=18)
        #plt.ylabel('N')
        plt.xlim(-x, x)
        plt.ylim(0, y)
        plt.bar(both.bins, both.counts, width = w, color=c, alpha = alp, label = 'Combined Distribution')
        plt.plot(theory.x_vals, theory.combined, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
        plt.legend()
        
        plt.savefig("vel_phi/phi_vel_" + str(sim_time[i]) + "gy.png", format='png')
        plt.close()
        del light, dark, both
    del theory
    return 0

def vel_theta():
    theory_path = "/home/sidd/Desktop/research/data_testing/theory/theory_theta.dat"
    light_path  = "/home/sidd/Desktop/research/data_testing/binned_data/theta_vel_light_"
    dark_path   = "/home/sidd/Desktop/research/data_testing/binned_data/theta_vel_dark_"
    both_path   = "/home/sidd/Desktop/research/data_testing/binned_data/theta_vel_both_"
    
    print 'plotting vel theta'
    theory  = theory_data(theory_path)
    for i in range(0, len(sim_time)):
        ev = str(sim_time[i]) + "gy.dat"
        light = bin_datas(light_path + ev)
        dark  = bin_datas(dark_path  + ev)
        both  = bin_datas(both_path  + ev) 
        y = 300
        x = 5
        w = .04
        c = 'red'
        c2 = 'black'
        alp = 0.8
        lw = 3
        
        params = {'legend.fontsize': 18,
            'legend.handlelength': 2}
        plt.rcParams.update(params)
        f, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, sharex='col', sharey='row')
        f.subplots_adjust(hspace=0)
        f.subplots_adjust(wspace=0)
        plt.figure(figsize=(20, 10))
        
        plt.subplot(221)
        plt.title(r'Baryonic Matter $\theta$ Distribution ' + str(sim_time[i]) + 'GY', fontsize=24)
        #plt.xlabel('Radius (Kpc)')
        plt.ylabel('N' , fontsize=18)
        plt.xlim(-x, x)
        plt.ylim(0, y)
        plt.bar(light.bins, light.counts, width = w, color=c, alpha = alp,  label = 'Baryonic Distribution')
        plt.plot(theory.x_vals, theory.light, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
        plt.legend()
        
        plt.subplot(222)
        plt.title(r'Dark Matter $\theta$ Distribution ' + str(sim_time[i]) + 'GY', fontsize=24)
        #plt.xlabel('Radius (Kpc)')
        #plt.ylabel('N')
        plt.xlim(-x, x)
        plt.ylim(0, y)
        plt.bar(dark.bins, dark.counts, width = w, color=c, alpha = alp, label = 'Dark Matter Distribution')
        plt.plot(theory.x_vals, theory.dark, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
        plt.legend()
        
        plt.subplot(223)
        #plt.title('Overlapping',fontsize=24)
        plt.xlabel(r'$\theta$' , fontsize=18)
        plt.ylabel('N' , fontsize=18)
        plt.xlim(-x, x)
        plt.ylim(0, y)
        plt.bar(light.bins, light.counts, width = w, color=c, alpha = alp,  label = 'Baryonic Distribution')
        plt.bar(dark.bins, dark.counts, width = w, color='blue', alpha = alp, label = 'Dark Matter Distribution')
        plt.plot(theory.x_vals, theory.light, color = 'cyan', linestyle = '-', linewidth = lw, label = 'Baryonic Theoretical Distribution')
        plt.plot(theory.x_vals, theory.dark, color = c2, linestyle = '-', linewidth = lw, label = 'Dark Matter Theoretical Distribution')
        plt.legend()
        
        plt.subplot(224)
        #plt.title('Combined Matter' + sim_time[i] + 'GY',fontsize=24)
        plt.xlabel(r'$\theta$' , fontsize=18)
        #plt.ylabel('N')
        plt.xlim(-x, x)
        plt.ylim(0, 2*y)
        plt.bar(both.bins, both.counts, width = w, color=c, alpha = alp, label = 'Combined Distribution')
        plt.plot(theory.x_vals, theory.combined, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
        plt.legend()
        
        plt.savefig("vel_theta/theta_vel_" + str(sim_time[i]) + "gy.png", format='png')
        plt.close()
        del light, dark, both
    del theory
    return 0

def main():
    print 'plotting takes a bit. Go take a pee'
    t0 = time.time()
    radial()    
    t1 = time.time()
    print 'run time: ', t1-t0
    
    t0 = time.time()
    #radial_theta()
    t1 = time.time()
    print 'run time: ', t1-t0
    
    t0 = time.time()
    #radial_phi()
    t1 = time.time()
    print 'run time: ', t1-t0
    
    t0 = time.time()
    #vel()
    t1 = time.time()
    print 'run time: ', t1-t0
    
    t0 = time.time()
    #vel_theta()
    t1 = time.time()
    print 'run time: ', t1-t0
    
    t0 = time.time()
    vel_phi()
    #t1 = time.time()
    print 'run time: ', t1-t0
    
main()
    