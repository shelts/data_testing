#!/bin/bash


clear_plots=true
clear_data=false
clear_sims=false


if $clear_data
then
    rm actual/*
  
    rm  raw_data/*
  
    rm binned_data/*
  
    rm test_output/*
  
    rm theory/*
fi


# if $clear_sims
# then
#     # rm -r sim_outputs
#     # mkdir sim_outputs
# fi


if $clear_plots
then
    rm plots/rad/*
    rm plots/theta/*
    rm plots/phi/*
    rm plots/vel/*
    rm plots/vel_theta/*
    rm plots/vel_phi/*
fi

