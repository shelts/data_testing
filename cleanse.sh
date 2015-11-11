#!/bin/bash

rm -r actual
rm -r raw_data
rm -r binned_data
rm -r plots
rm -r sim_outputs
rm -r test_output
rm -r theory

mkdir actual
mkdir binned_data

mkdir raw_data
mkdir sim_outputs
mkdir test_output
mkdir theory

mkdir plots
cd plots
mkdir energy
mkdir theta
mkdir phi
mkdir vel_theta
mkdir vel_phi
mkdir rad
mkdir pot

mkdir vel_dist
mkdir ./vel_dist/binned_vs_tbins
mkdir ./vel_dist/binned
mkdir ./vel_dist/vel_vs_r

