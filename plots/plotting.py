#! /usr/bin/python
#/* Copyright (c) 2018 Siddhartha Shelton */
from classes import *



#plot each radial component over time. first row plots of each component initial
#second row same but after some time:
def radial_components_over_time():
    sim_time = ['0', '4']
    
    theory_den = "/home/sidd/Desktop/research/data_testing/theory/theory_den.dat"
    light_path      = "/home/sidd/Desktop/research/data_testing/binned_data/light_matter_bins_"
    dark_path       = "/home/sidd/Desktop/research/data_testing/binned_data/dark_matter_bins_"
    both_path       = "/home/sidd/Desktop/research/data_testing/binned_data/both_matter_bins_"
    
    labels = ['Initial', '4 Gy']
    f, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, sharex='col', sharey='row', figsize=(20, 10))
    f.subplots_adjust(hspace=0)
    f.subplots_adjust(wspace=0.25)
    #plt.figure(figsize=(20, 10))
    
    for i in range(len(sim_time)):
        ev = sim_time[i] + "gy.dat"
        light = bin_datas(light_path + ev)
        dark = bin_datas(dark_path + ev)
        both = bin_datas(both_path + ev) 
        theory = theory_data(theory_den)
        
        
        y = 1500
        x = 3
        w = .04
        c = 'red'
        c2 = 'black'
        alp = 0.8
        lw = 3
        
        params = {'legend.fontsize': 22,
            'legend.handlelength': 1}
        plt.rcParams.update(params)
        sub_i = 231 + 3 * i
        plt.subplot(sub_i)
        plt.tick_params(axis='y', which='major', labelsize=22)
        plt.tick_params(axis='x', which='major', labelsize=22)

        if(i == 0):
            plt.title('Baryonic Matter', fontsize=28)
            plt.xticks([])
        elif(i == len(sim_time) - 1):
            plt.xlabel('Radius (kpc)', fontsize=24)
            
        plt.ylabel('N' , fontsize=24)
        plt.xlim(0, x)
        plt.ylim(0, y)
        plt.bar(light.bins, light.counts, width = w, color=c, alpha = alp,  label = labels[i])
        plt.plot(theory.x_vals, theory.light, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical ')
        plt.legend()
        
        plt.subplot(sub_i + 1)
        plt.tick_params(axis='y', which='major', labelsize=22)
        plt.tick_params(axis='x', which='major', labelsize=22)
        
        if(i == 0):
            plt.title('Dark Matter', fontsize=28)
            plt.xticks([])
        elif(i == len(sim_time) - 1):
            plt.xlabel('Radius (kpc)', fontsize=24)

        plt.xlim(0, x)
        plt.ylim(0, y)
        plt.bar(dark.bins, dark.counts, width = w, color=c, alpha = alp, label = labels[i])
        plt.plot(theory.x_vals, theory.dark, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical ')
        plt.legend()
        
        plt.subplot(sub_i + 2)
        plt.tick_params(axis='y', which='major', labelsize=22)
        plt.tick_params(axis='x', which='major', labelsize=22)
        
        if(i == 0):
            plt.title('Combined Matter',fontsize=28)
            plt.xticks([])
        elif(i == len(sim_time) - 1):
            plt.xlabel('Radius (kpc)', fontsize=24)
            
        plt.xlim(0, x)
        plt.ylim(0, 2*y)
        plt.bar(both.bins, both.counts, width = w, color=c, alpha = alp, label = labels[i])
        plt.plot(theory.x_vals, theory.combined, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical ')
        plt.legend()
        
    plt.savefig("radial_components_over_time.png", format='png', bbox_inches='tight')
    plt.savefig("radial_components_over_time.pdf", format='pdf', bbox_inches='tight')
    


#plot each vel component over time. first row plots of each component initial
#second row same but after some time:
def vel_components_over_time():
    sim_time = ['0', '4']
    
    theory_light_path   = "/home/sidd/Desktop/research/data_testing/binned_data/light_matter_theory_vel_bins.dat"
    theory_dark_path   = "/home/sidd/Desktop/research/data_testing/binned_data/dark_matter_theory_vel_bins.dat"
    light_path = "/home/sidd/Desktop/research/data_testing/binned_data/light_matter_vel_bins_"
    dark_path  = "/home/sidd/Desktop/research/data_testing/binned_data/dark_matter_vel_bins_"
    
    
    labels = ['Initial', '4 Gy']
    f, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, sharex='col', sharey='row', figsize=(20, 10))
    f.subplots_adjust(hspace=0)
    #f.subplots_adjust(wspace=0)
    #plt.figure(figsize=(20, 10))
    
    for i in range(len(sim_time)):
        ev = sim_time[i] + "gy.dat"
        
        light = bin_datas(light_path + ev)
        dark  = bin_datas(dark_path + ev)
        theory_light = theory_data(theory_light_path, 'light')
        theory_dark  = theory_data(theory_dark_path, 'dark')

        #print theory_light.light
        y = 400
        x = 10
        w = .04
        #w = .2
        c = 'red'
        c2 = 'black'
        alp = 0.8
        lw = 3
        sub_i = 221 + 2 * i
        params = {'legend.fontsize': 22,
            'legend.handlelength': 1}
        
        plt.rcParams.update(params)
        
        plt.subplot(sub_i)
        if(i == 0):
            plt.title('Baryonic Matter', fontsize=28)
            plt.xticks([])
        elif(i == len(sim_time) - 1):
            plt.xlabel('Velocity (km/s)', fontsize=24)
        
        plt.tick_params(axis='y', which='major', labelsize=22)
        plt.tick_params(axis='x', which='major', labelsize=22)
        
        plt.ylabel('N', fontsize=24)
        plt.xlim(0, x)
        plt.ylim(0, y)
        plt.bar(light.bins, light.counts, width = w, color=c, alpha = alp,  label = labels[i])
        plt.plot(theory_light.x_vals, theory_light.light, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical')
        plt.legend()
        
        plt.subplot(sub_i + 1)
        
        if(i == 0):
            plt.title('Dark Matter', fontsize=24)
            plt.xticks([])
        elif(i == len(sim_time) - 1):
            plt.xlabel('Velocity (km/s)', fontsize=24)
            
        plt.tick_params(axis='y', which='major', labelsize=22)
        plt.tick_params(axis='x', which='major', labelsize=22)
        
        plt.xlim(0, x)
        plt.ylim(0, y)
        plt.bar(dark.bins, dark.counts, width = w, color=c, alpha = alp, label = labels[i])
        plt.plot(theory_dark.x_vals, theory_dark.dark, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical')
        plt.legend()
        
    plt.savefig("vel_components_over_time.png", format='png', bbox_inches='tight')
    plt.savefig("vel_components_over_time.pdf", format='pdf', bbox_inches='tight')
    
#for creating a single plot with the two components having different distribution values
def mixed_radial_values():
    sim_time = ['0', '4']
    sim_time = ['0']
    theory_den = "/home/sidd/Desktop/research/data_testing/theory_mixed/theory_den.dat"
    light_path      = "/home/sidd/Desktop/research/data_testing/binned_data_mixed/light_matter_bins_"
    dark_path       = "/home/sidd/Desktop/research/data_testing/binned_data_mixed/dark_matter_bins_"
    both_path       = "/home/sidd/Desktop/research/data_testing/binned_data_mixed/both_matter_bins_"
    
    plt.figure(figsize=(20, 10))
    for i in range(0, len(sim_time)):
        ev = sim_time[i] + "gy.dat"
        
        light = bin_datas(light_path + ev)
        dark  = bin_datas(dark_path + ev)
        both  = bin_datas(both_path + ev) 
        
        theory = theory_data(theory_den)
        
        y = 2000
        x = 3
        w = .04
        c = 'red'
        c2 = 'black'
        alp = 0.75
        lw = 5
        params = {'legend.fontsize': 24,
            'legend.handlelength': 1}
        #sub_i = 211 + i
        #plt.subplot(sub_i)
        plt.rcParams.update(params)
        plt.tick_params(axis='y', which='major', labelsize=20)
        plt.tick_params(axis='x', which='major', labelsize=20)
        plt.title('Radial Distribution', fontsize=30)
        plt.xlabel('Radius (Kpc)', fontsize=28)
        plt.ylabel('N', fontsize=28)
        plt.xlim(0, x)
        plt.ylim(0, y)
        plt.bar(both.bins, both.counts,   width = w, color='w', alpha = 1, edgecolor = 'darkgreen', hatch="xxx",  linewidth = 2, label = 'Simulated Combined Distribution')
        plt.bar(light.bins, light.counts, width = w, color='w', alpha = 1, edgecolor = 'red', hatch="//",     linewidth = 2,  label = 'Simulated Baryonic Distribution')
        plt.bar(dark.bins, dark.counts,   width = w, color='w', alpha = 1, edgecolor = 'blue', hatch="\\\\",  linewidth = 2,  label = 'Simulated Dark Matter Distribution')
        
        plt.plot(theory.x_vals, theory.light,    color = 'k', linestyle = 'dashed', linewidth = lw, label = 'Theoretical Baryon Distribution')
        plt.plot(theory.x_vals, theory.dark,     color = 'k', linestyle = 'dotted', linewidth = lw, label = 'Theoretical Dark Matter Distribution')
        plt.plot(theory.x_vals, theory.combined, color = 'k', linestyle = 'solid', linewidth = lw, label = 'Theoretical Combined Distribution')
        plt.legend()

    plt.savefig("mixed_radial_values.pdf", format='pdf', bbox_inches='tight')   
    plt.savefig("mixed_radial_values.png", format='png', bbox_inches='tight')   
    

def radial_angulars_over_time():
    sim_time = ['0', '4']
    
    theory_path_theta = "/home/sidd/Desktop/research/data_testing/theory/theory_theta.dat"
    both_path_theta   = "/home/sidd/Desktop/research/data_testing/binned_data/theta_both_"
    theory_path_phi = "/home/sidd/Desktop/research/data_testing/theory/theory_phi.dat"
    both_path_phi   = "/home/sidd/Desktop/research/data_testing/binned_data/phi_both_"
    
    labels = ['Initial', '4 gy']
    f, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, sharex='col', sharey='row', figsize=(20, 10))
    f.subplots_adjust(hspace=0)
    #f.subplots_adjust(wspace=0)
    #plt.figure(figsize=(20, 10))
    for i in range(0,len(sim_time)):
        
        theta = bin_datas(both_path_theta + sim_time[i] + "gy.dat")
        phi   = bin_datas(both_path_phi + sim_time[i] + "gy.dat")
        
        theory_theta  = theory_data(theory_path_theta)
        theory_phi    = theory_data(theory_path_phi)
        
        
        y = 300
        #y = 3000
        x = 4
        w = .04
        #w = .2
        c = 'red'
        c2 = 'black'
        alp = 0.8
        lw = 3
        print 'plotting theta phi'
        
        params = {'legend.fontsize': 22,
            'legend.handlelength': 1}
        
        plt.rcParams.update(params)
        plt.tick_params(axis='y', which='major', labelsize=22)
        plt.tick_params(axis='x', which='major', labelsize=22)
        
        sub_i = 221 + 2 * i 
        #print sub_i
        plt.subplot(sub_i)
        plt.tick_params(axis='y', which='major', labelsize=22)
        plt.tick_params(axis='x', which='major', labelsize=22)
        
        if(i == 0):
            plt.title(r'Combined Matter $\theta$ Distribution',fontsize=28)
            plt.xticks([])
            
        if(i == len(sim_time) - 1):
            plt.xlabel(r'$\theta$', fontsize=24)
            
        plt.ylabel('N', fontsize=24)
        plt.xlim(0, x)
        plt.ylim(0, 2*y)
        plt.bar(theta.bins, theta.counts, width = w, color=c, alpha = alp, label = labels[i])
        plt.plot(theory_theta.x_vals, theory_theta.combined, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical')
        plt.legend()
        
        
        plt.subplot(sub_i + 1)
        plt.tick_params(axis='y', which='major', labelsize=22)
        plt.tick_params(axis='x', which='major', labelsize=22)
        
        if(i == 0):
            plt.title(r'Combined Matter $\phi$ Distribution',fontsize=28)
            plt.xticks([])
            
        if(i == len(sim_time) - 1):
            plt.xlabel(r'$\phi$', fontsize=24)
            
        plt.xlim(-x, x)
        plt.ylim(0, 2*y)
        plt.bar(phi.bins, phi.counts, width = w, color=c, alpha = alp, label = labels[i])
        plt.plot(theory_phi.x_vals, theory_phi.combined, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical')
        plt.legend()
        
    plt.savefig("radial_theta_phi.png", format='png', bbox_inches='tight')   
    plt.savefig("radial_theta_phi.pdf", format='pdf', bbox_inches='tight') 
    plt.close()
    return 0
    

def velocity_angulars_over_time():
    sim_time = ['0', '4']
    
    theory_path_theta = "/home/sidd/Desktop/research/data_testing/theory/theory_theta.dat"
    both_path_theta   = "/home/sidd/Desktop/research/data_testing/binned_data/theta_vel_both_"
    
    theory_path_phi = "/home/sidd/Desktop/research/data_testing/theory/theory_phi.dat"
    both_path_phi   = "/home/sidd/Desktop/research/data_testing/binned_data/phi_vel_both_"

    labels = ['Initial', '4 gy']
    f, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, sharex='col', sharey='row', figsize=(20, 10))
    f.subplots_adjust(hspace=0)
    #f.subplots_adjust(wspace=0)
    #plt.figure(figsize=(20, 10))

    for i in range(0,len(sim_time)):
        theta = bin_datas(both_path_theta + sim_time[i] + "gy.dat")
        phi   = bin_datas(both_path_phi + sim_time[i] + "gy.dat")
        
        theory_theta  = theory_data(theory_path_theta)
        theory_phi    = theory_data(theory_path_phi)
        
        y = 300
        #y = 3000
        x = 4
        w = .04
        #w = .2
        c = 'red'
        c2 = 'black'
        alp = 0.8
        lw = 3
        print 'plotting theta phi'
        
        params = {'legend.fontsize': 22,
            'legend.handlelength': 1}
        
        plt.rcParams.update(params)
        plt.tick_params(axis='y', which='major', labelsize=22)
        plt.tick_params(axis='x', which='major', labelsize=22)
        
        sub_i = 221 + 2 * i 
        #print sub_i
        plt.subplot(sub_i)
        plt.tick_params(axis='y', which='major', labelsize=22)
        plt.tick_params(axis='x', which='major', labelsize=22)
        if(i == 0):
            plt.title(r'Combined Matter $\theta$ Distribution',fontsize=28)
            plt.xticks([])
            
        if(i == len(sim_time) - 1):
            plt.xlabel(r'$\theta$', fontsize=24)
            
        plt.ylabel('N', fontsize=24)
        plt.xlim(0, x)
        plt.ylim(0, 2*y)
        plt.bar(theta.bins, theta.counts, width = w, color=c, alpha = alp, label = labels[i])
        plt.plot(theory_theta.x_vals, theory_theta.combined, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical')
        plt.legend()
        
        
        plt.subplot(sub_i + 1)
        plt.tick_params(axis='y', which='major', labelsize=22)
        plt.tick_params(axis='x', which='major', labelsize=22)
        
        if(i == 0):
            plt.title(r'Combined Matter $\phi$ Distribution',fontsize=28)
            plt.xticks([])

        if(i == len(sim_time) - 1):
            plt.xlabel(r'$\phi$', fontsize=24)
            
        plt.xlim(-x, x)
        plt.ylim(0, 2*y)
        plt.bar(phi.bins, phi.counts, width = w, color=c, alpha = alp, label = labels[i])
        plt.plot(theory_phi.x_vals, theory_phi.combined, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical')
        plt.legend()
    
    plt.savefig("vel_theta_phi.png", format='png', bbox_inches='tight')   
    plt.savefig("vel_theta_phi.pdf", format='pdf', bbox_inches='tight')  
    plt.close()
    return 0


def main():
    radial_components_over_time()
    #mixed_radial_values()
    vel_components_over_time()
    radial_angulars_over_time()
    velocity_angulars_over_time()
main()

