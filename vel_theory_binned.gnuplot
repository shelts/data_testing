reset
set terminal jpeg
set key on
set ylabel 'counts'
set xlabel 'radius (Mpc)'
set xrange[0:20]
set yrange[0:600]


set output "plots/vel/vel_distribution_light_theory_0gy.jpeg"
set title 'Histogram of Light Matter Velocity Distribution After 0Gy'
plot "binned_data/light_matter_vel_bins_0gy.dat" using 2:1  with boxes title 'actual',  "binned_data/light_matter_theory_vel_bins.dat"   using 2:1 with lines title 'light',  "binned_data/dark_matter_theory_vel_bins.dat"   using 2:1 with boxes title 'dark'
# , "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 


set output "plots/vel/vel_distribution_dark_theory_0gy.jpeg"
set title 'Histogram of Dark Matter Velocity Distribution After 0Gy'
plot "binned_data/dark_matter_vel_bins_0gy.dat" using 2:1  with boxes title 'actual',  "binned_data/light_matter_theory_vel_bins.dat"   using 2:1 with lines title 'light',  "binned_data/dark_matter_theory_vel_bins.dat"   using 2:1 with boxes title 'dark'
# , "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# 
# 
# set output "plots/vel/vel_distribution_light_theory_0p25gy.jpeg"
# set title 'Histogram of Light Matter Velocity Distribution After .25Gy'
# plot "binned_data/light_matter_vel_bins_p25gy.dat" using 2:1  with boxes title 'actual',  "binned_data/light_matter_theory_vel_bins.dat"   using 2:1 with lines title 'light',  "binned_data/dark_matter_theory_vel_bins.dat"   using 2:1 with boxes title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# 
# set output "plots/vel/vel_distribution_dark_theory_0p25gy.jpeg"
# set title 'Histogram of Dark Matter Velocity Distribution After .25Gy'
# plot "binned_data/dark_matter_vel_bins_p25gy.dat" using 2:1  with boxes title 'actual',  "binned_data/light_matter_theory_vel_bins.dat"   using 2:1 with lines title 'light',  "binned_data/dark_matter_theory_vel_bins.dat"   using 2:1 with boxes title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# 
# set output "plots/vel/vel_distribution_light_theory_0p50gy.jpeg"
# set title 'Histogram of Light Matter Velocity Distribution After .5Gy'
# plot "binned_data/light_matter_vel_bins_p5gy.dat" using 2:1  with boxes title 'actual',  "binned_data/light_matter_theory_vel_bins.dat"   using 2:1 with lines title 'light',  "binned_data/dark_matter_theory_vel_bins.dat"   using 2:1 with boxes title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# 
# set output "plots/vel/vel_distribution_dark_theory_0p50gy.jpeg"
# set title 'Histogram of Dark Matter Velocity Distribution After .5Gy'
# plot "binned_data/dark_matter_vel_bins_p5gy.dat" using 2:1  with boxes title 'actual',  "binned_data/light_matter_theory_vel_bins.dat"   using 2:1 with lines title 'light',  "binned_data/dark_matter_theory_vel_bins.dat"   using 2:1 with boxes title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# light_matter_vel_bins_0gy
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# set output "plots/vel/vel_distribution_light_theory_0p75gy.jpeg"
# set title 'Histogram of Light Matter Velocity Distribution After .75Gy'
# plot "binned_data/light_matter_vel_bins_p75gy.dat" using 2:1  with boxes title 'actual',   "binned_data/light_matter_theory_vel_bins.dat"   using 2:1 with lines title 'light',  "binned_data/dark_matter_theory_vel_bins.dat"   using 2:1 with boxes title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# set output "plots/vel/vel_distribution_dark_theory_0p75gy.jpeg"
# set title 'Histogram of Dark Matter Velocity Distribution After .75Gy'
# plot "binned_data/dark_matter_vel_bins_p75gy.dat" using 2:1  with boxes title 'actual',  "binned_data/light_matter_theory_vel_bins.dat"   using 2:1 with lines title 'light',  "binned_data/dark_matter_theory_vel_bins.dat"   using 2:1 with boxes title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# 
# set output "plots/vel/vel_distribution_light_theory_1gy.jpeg"
# set title 'Histogram of Light Matter Velocity Distribution After 1Gy'
# plot "binned_data/light_matter_vel_bins_1gy.dat" using 2:1  with boxes title 'actual',  "binned_data/light_matter_theory_vel_bins.dat"   using 2:1 with lines title 'light',  "binned_data/dark_matter_theory_vel_bins.dat"   using 2:1 with boxes title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# set output "plots/vel/vel_distribution_dark_theory_1gy.jpeg"
# set title 'Histogram of Dark Matter Velocity Distribution After 1Gy'
# plot "binned_data/dark_matter_vel_bins_1gy.dat" using 2:1  with boxes title 'actual',  "binned_data/light_matter_theory_vel_bins.dat"   using 2:1 with lines title 'light',  "binned_data/dark_matter_theory_vel_bins.dat"   using 2:1 with boxes title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# set output "plots/vel/vel_distribution_light_theory_2gy.jpeg"
# set title 'Histogram of Light Matter Velocity Distribution After 2Gy'
# plot "binned_data/light_matter_vel_bins_2gy.dat" using 2:1  with boxes title 'actual',  "binned_data/light_matter_theory_vel_bins.dat"   using 2:1 with lines title 'light',  "binned_data/dark_matter_theory_vel_bins.dat"   using 2:1 with boxes title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# 
# set output "plots/vel/vel_distribution_dark_theory_2gy.jpeg"
# set title 'Histogram of Dark Matter Velocity Distribution After 2Gy'
# plot "binned_data/dark_matter_vel_bins_2gy.dat" using 2:1  with boxes title 'actual',  "binned_data/light_matter_theory_vel_bins.dat"   using 2:1 with lines title 'light',  "binned_data/dark_matter_theory_vel_bins.dat"   using 2:1 with boxes title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# set output "plots/vel/vel_distribution_light_theory_3gy.jpeg"
# set title 'Histogram of Light Matter Velocity Distribution After 3Gy'
# plot "binned_data/light_matter_vel_bins_3gy.dat" using 2:1  with boxes title 'actual',  "binned_data/light_matter_theory_vel_bins.dat"   using 2:1 with lines title 'light',  "binned_data/dark_matter_theory_vel_bins.dat"   using 2:1 with boxes title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# 
# set output "plots/vel/vel_distribution_dark_theory_3gy.jpeg"
# set title 'Histogram of Dark Matter Velocity Distribution After 3Gy'
# plot "binned_data/dark_matter_vel_bins_3gy.dat" using 2:1  with boxes title 'actual',  "binned_data/light_matter_theory_vel_bins.dat"   using 2:1 with lines title 'light',  "binned_data/dark_matter_theory_vel_bins.dat"   using 2:1 with boxes title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# 
# 
# set output "plots/vel/vel_distribution_light_theory_4gy.jpeg"
# set title 'Histogram of Light Matter Velocity Distribution After 4Gy'
# plot "binned_data/light_matter_vel_bins_4gy.dat" using 2:1  with boxes title 'actual',   "binned_data/light_matter_theory_vel_bins.dat"   using 2:1 with lines title 'light',  "binned_data/dark_matter_theory_vel_bins.dat"   using 2:1 with boxes title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# 
# set output "plots/vel/vel_distribution_dark_theory_4gy.jpeg"
# set title 'Histogram of Dark Matter Velocity Distribution After 4Gy'
# plot "binned_data/dark_matter_vel_bins_4gy.dat" using 2:1  with boxes title 'actual',  "binned_data/light_matter_theory_vel_bins.dat"   using 2:1 with lines title 'light',  "binned_data/dark_matter_theory_vel_bins.dat"   using 2:1 with boxes title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
