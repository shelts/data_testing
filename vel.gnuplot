reset
set terminal jpeg
set key on
set ylabel 'counts'
set xlabel 'radius (Mpc)'
set xrange[0:10]
set yrange[0:600]
set style fill transparent solid 0.5 
# noborder

set output "plots/vel_dist/binned_vs_theory/vel_distribution_light_0gy.jpeg"
set title 'Histogram of Light Matter Velocity Distribution After 0Gy'
plot "binned_data/light_matter_vel_bins_0gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark'
# , "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 


set output "plots/vel_dist/binned_vs_theory/vel_distribution_dark_0gy.jpeg"
set title 'Histogram of Dark Matter Velocity Distribution After 0Gy'
plot "binned_data/dark_matter_vel_bins_0gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark'
# , "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #


set output "plots/vel_dist/binned_vs_theory/vel_distribution_light_0p25gy.jpeg"
set title 'Histogram of Light Matter Velocity Distribution After .25Gy'
plot "binned_data/light_matter_vel_bins_p25gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 


set output "plots/vel_dist/binned_vs_theory/vel_distribution_dark_0p25gy.jpeg"
set title 'Histogram of Dark Matter Velocity Distribution After .25Gy'
plot "binned_data/dark_matter_vel_bins_p25gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

set output "plots/vel_dist/binned_vs_theory/vel_distribution_light_0p50gy.jpeg"
set title 'Histogram of Light Matter Velocity Distribution After .5Gy'
plot "binned_data/light_matter_vel_bins_p5gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 


set output "plots/vel_dist/binned_vs_theory/vel_distribution_dark_0p50gy.jpeg"
set title 'Histogram of Dark Matter Velocity Distribution After .5Gy'
plot "binned_data/dark_matter_vel_bins_p5gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
set output "plots/vel_dist/binned_vs_theory/vel_distribution_light_0p75gy.jpeg"
set title 'Histogram of Light Matter Velocity Distribution After .75Gy'
plot "binned_data/light_matter_vel_bins_p75gy.dat" using 2:1  with boxes title 'actual',   "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 

set output "plots/vel_dist/binned_vs_theory/vel_distribution_dark_0p75gy.jpeg"
set title 'Histogram of Dark Matter Velocity Distribution After .75Gy'
plot "binned_data/dark_matter_vel_bins_p75gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

set output "plots/vel_dist/binned_vs_theory/vel_distribution_light_1gy.jpeg"
set title 'Histogram of Light Matter Velocity Distribution After 1Gy'
plot "binned_data/light_matter_vel_bins_1gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 

set output "plots/vel_dist/binned_vs_theory/vel_distribution_dark_1gy.jpeg"
set title 'Histogram of Dark Matter Velocity Distribution After 1Gy'
plot "binned_data/dark_matter_vel_bins_1gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
set output "plots/vel_dist/binned_vs_theory/vel_distribution_light_2gy.jpeg"
set title 'Histogram of Light Matter Velocity Distribution After 2Gy'
plot "binned_data/light_matter_vel_bins_2gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 


set output "plots/vel_dist/binned_vs_theory/vel_distribution_dark_2gy.jpeg"
set title 'Histogram of Dark Matter Velocity Distribution After 2Gy'
plot "binned_data/dark_matter_vel_bins_2gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
set output "plots/vel_dist/binned_vs_theory/vel_distribution_light_3gy.jpeg"
set title 'Histogram of Light Matter Velocity Distribution After 3Gy'
plot "binned_data/light_matter_vel_bins_3gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 


set output "plots/vel_dist/binned_vs_theory/vel_distribution_dark_3gy.jpeg"
set title 'Histogram of Dark Matter Velocity Distribution After 3Gy'
plot "binned_data/dark_matter_vel_bins_3gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #


set output "plots/vel_dist/binned_vs_theory/vel_distribution_light_4gy.jpeg"
set title 'Histogram of Light Matter Velocity Distribution After 4Gy'
plot "binned_data/light_matter_vel_bins_4gy.dat" using 2:1  with boxes title 'actual',   "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 


set output "plots/vel_dist/binned_vs_theory/vel_distribution_dark_4gy.jpeg"
set title 'Histogram of Dark Matter Velocity Distribution After 4Gy'
plot "binned_data/dark_matter_vel_bins_4gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
