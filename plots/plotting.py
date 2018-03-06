#! /usr/bin/python
#/* Copyright (c) 2018 Siddhartha Shelton */
from classes import *



#plot each radial component over time. first row plots of each component initial
#second row same but after some time:
def radial_components_over_time():
    sim_time = ['0', '4']
    
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
    
    params = {'legend.fontsize': 18,
          'legend.handlelength': 2}
    plt.rcParams.update(params)
    f, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, sharex='col', sharey='row')
    f.subplots_adjust(hspace=0)
    f.subplots_adjust(wspace=0)
    plt.figure(figsize=(20, 10))
    plt.subplot(231)
    plt.title('Baryonic Matter', fontsize=24)
    #plt.xlabel('Radius (Kpc)')
    plt.ylabel('N' , fontsize=18)
    plt.xlim(0, x)
    plt.ylim(0, y)
    plt.bar(light_0gy.bins, light_0gy.counts, width = w, color=c, alpha = alp,  label = 'Initial Distribution')
    plt.plot(theory.x_vals, theory.light, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
    plt.legend()
    
    plt.subplot(232)
    plt.title('Dark Matter', fontsize=24)
    #plt.xlabel('Radius (Kpc)')
    #plt.ylabel('N')
    plt.xlim(0, x)
    plt.ylim(0, y)
    plt.bar(dark_0gy.bins, dark_0gy.counts, width = w, color=c, alpha = alp, label = 'Initial Distribution')
    plt.plot(theory.x_vals, theory.dark, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
    plt.legend()
    
    plt.subplot(233)
    plt.title('Combined Matter',fontsize=24)
    #plt.xlabel('Radius (Kpc)')
    #plt.ylabel('N')
    plt.xlim(0, x)
    plt.ylim(0, 2*y)
    plt.bar(both_0gy.bins, both_0gy.counts, width = w, color=c, alpha = alp, label = 'Initial Distribution')
    plt.plot(theory.x_vals, theory.combined, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
    plt.legend()
    
    plt.subplot(234)
    plt.xlabel('Radius (Kpc)', fontsize=18)
    plt.ylabel('N', fontsize=18)
    plt.xlim(0, x)
    plt.ylim(0, y)
    plt.bar(light_4gy.bins, light_4gy.counts, width = w, color=c, alpha = alp, label = 'Distribution after 4 Gy')
    plt.plot(theory.x_vals, theory.light, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
    plt.legend()
    
    plt.subplot(235)
    plt.xlabel('Radius (Kpc)', fontsize=18)
    #plt.ylabel('N')
    plt.xlim(0, x)
    plt.ylim(0, y)
    plt.bar(dark_4gy.bins, dark_4gy.counts, width = w, color=c, alpha = alp, label = 'Distribution after 4 Gy')
    plt.plot(theory.x_vals, theory.dark, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
    plt.legend()
    
    plt.subplot(236)
    plt.xlabel('Radius (Kpc)', fontsize=18)
    #plt.ylabel('N')
    plt.xlim(0, x)
    plt.ylim(0, 2*y)
    plt.bar(both_4gy.bins, both_4gy.counts, width = w, color=c, alpha = alp, label = 'Distribution after 4 Gy')
    plt.plot(theory.x_vals, theory.combined, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
    plt.legend()
    
    
    
    plt.savefig("radial_components_over_time.eps", format='eps')
    


#plot each vel component over time. first row plots of each component initial
#second row same but after some time:
def vel_components_over_time():
    sim_time = ['0', '4']
    
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
    params = {'legend.fontsize': 20,
          'legend.handlelength': 2}
    plt.rcParams.update(params)
    f, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, sharex='col', sharey='row')
    f.subplots_adjust(hspace=0)
    f.subplots_adjust(wspace=0)
    plt.figure(figsize=(20, 10))
    plt.subplot(sbpt)
    plt.title('Baryonic Matter', fontsize=24)
    #plt.xlabel('Velocity (km/s)')
    plt.ylabel('N', fontsize=18)
    plt.xlim(0, x)
    plt.ylim(0, y)
    plt.bar(light_0gy.bins, light_0gy.counts, width = w, color=c, alpha = alp,  label = 'Initial Distribution')
    plt.plot(theory_light.x_vals, theory_light.light, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
    plt.legend()
    
    plt.subplot(sbpt + 1)
    plt.title('Dark Matter', fontsize=24)
    #plt.xlabel('Velocity (km/s)')
    #plt.ylabel('N')
    plt.xlim(0, x)
    plt.ylim(0, y)
    plt.bar(dark_0gy.bins, dark_0gy.counts, width = w, color=c, alpha = alp, label = 'Initial Distribution')
    plt.plot(theory_dark.x_vals, theory_dark.dark, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
    plt.legend()
    
    plt.subplot(sbpt + 2)
    plt.xlabel('Velocity (km/s)', fontsize=18)
    plt.ylabel('N', fontsize=18)
    plt.xlim(0, x)
    plt.ylim(0, y)
    plt.bar(light_4gy.bins, light_4gy.counts, width = w, color=c, alpha = alp, label = 'Distribution after 4 Gy')
    plt.plot(theory_light.x_vals, theory_light.light, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
    plt.legend()
    
    plt.subplot(sbpt + 3)
    plt.xlabel('Velocity (km/s)', fontsize=18)
    #plt.ylabel('N')
    plt.xlim(0, x)
    plt.ylim(0, y)
    plt.bar(dark_4gy.bins, dark_4gy.counts, width = w, color=c, alpha = alp, label = 'Distribution after 4 Gy')
    plt.plot(theory_dark.x_vals, theory_dark.dark, color = c2, linestyle = '-', linewidth = lw, label = 'Theoretical Distribution')
    plt.legend()
    
    
    
    plt.savefig("vel_components_over_time.eps", format='eps')
    
    
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
    
    y = 2000
    x = 3
    w = .04
    c = 'red'
    c2 = 'black'
    alp = 0.75
    lw = 5
    params = {'legend.fontsize': 24,
          'legend.handlelength': 2}
    plt.rcParams.update(params)
    plt.figure(figsize=(20, 10))
    plt.title('Radial Distribution', fontsize=28)
    plt.xlabel('Radius (Kpc)', fontsize=20)
    plt.ylabel('N', fontsize=20)
    plt.xlim(0, x)
    plt.ylim(0, y)
    plt.bar(light_0gy.bins, both_0gy.counts,  width = w, color='green', alpha = alp,  label = 'Simulated Combined Distribution')
    plt.bar(light_0gy.bins, light_0gy.counts, width = w, color='red', alpha = alp,  label = 'Simulated Baryonic Distribution')
    plt.bar(light_0gy.bins, dark_0gy.counts,  width = w, color='blue', alpha = alp,  label = 'Simulated Dark Matter Distribution')
    
    plt.plot(theory.x_vals, theory.light,    color = 'red', linestyle = '-', linewidth = lw, label = 'Theoretical Baryon Distribution')
    plt.plot(theory.x_vals, theory.dark,     color = 'blue', linestyle = '-', linewidth = lw, label = 'Theoretical Dark Matter Distribution')
    plt.plot(theory.x_vals, theory.combined, color = 'green', linestyle = '-', linewidth = lw, label = 'Theoretical Combined Distribution')
    plt.legend()

    plt.savefig("mixed_radial_values.png", format='png')   
    
    

def main():
    radial_components_over_time()
    mixed_radial_values()
    vel_components_over_time()
    
main()

