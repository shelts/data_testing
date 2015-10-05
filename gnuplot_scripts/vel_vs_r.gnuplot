reset
set terminal jpeg
set key on
set ylabel 'vel (km/s)'
set xlabel 'radius (Kpc)'
set xrange[0:15]
set yrange[0:6]


set output "~/Desktop/research/data_testing/plots/vel_dist/vel_vs_r/vel_vs_r_light_0gy.jpeg" 
set title 'Light Velocity as a function of Radius After 0Gy' 
plot '~/Desktop/research/data_testing/actual/light_matter_velocity_dist_0gy.dat' using 1:2  with dots title 'actual', '~/Desktop/research/data_testing/theory/theory_vel.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_vel.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_vel.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/vel_dist/vel_vs_r/vel_vs_r_light_0p25gy.jpeg" 
set title 'Light Velocity as a function of Radius After .25Gy' 
plot '~/Desktop/research/data_testing/actual/light_matter_velocity_dist_p25gy.dat' using 1:2  with dots title 'actual', '~/Desktop/research/data_testing/theory/theory_vel.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_vel.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_vel.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/vel_dist/vel_vs_r/vel_vs_r_light_0p50gy.jpeg" 
set title 'Light Velocity as a function of Radius After .5Gy' 
plot '~/Desktop/research/data_testing/actual/light_matter_velocity_dist_p50gy.dat' using 1:2  with dots title 'actual', '~/Desktop/research/data_testing/theory/theory_vel.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_vel.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_vel.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/vel_dist/vel_vs_r/vel_vs_r_light_0p75gy.jpeg" 
set title 'Light Velocity as a function of Radius After .75Gy' 
plot '~/Desktop/research/data_testing/actual/light_matter_velocity_dist_p75gy.dat' using 1:2  with dots title 'actual', '~/Desktop/research/data_testing/theory/theory_vel.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_vel.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_vel.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/vel_dist/vel_vs_r/vel_vs_r_light_1gy.jpeg" 
set title 'Light Velocity as a function of Radius After 1Gy' 
plot '~/Desktop/research/data_testing/actual/light_matter_velocity_dist_1gy.dat' using 1:2  with dots title 'actual', '~/Desktop/research/data_testing/theory/theory_vel.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_vel.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_vel.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/vel_dist/vel_vs_r/vel_vs_r_light_2gy.jpeg" 
set title 'Light Velocity as a function of Radius After 2Gy' 
plot '~/Desktop/research/data_testing/actual/light_matter_velocity_dist_2gy.dat' using 1:2  with dots title 'actual', '~/Desktop/research/data_testing/theory/theory_vel.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_vel.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_vel.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/vel_dist/vel_vs_r/vel_vs_r_light_3gy.jpeg" 
set title 'Light Velocity as a function of Radius After 3Gy' 
plot '~/Desktop/research/data_testing/actual/light_matter_velocity_dist_3gy.dat' using 1:2  with dots title 'actual', '~/Desktop/research/data_testing/theory/theory_vel.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_vel.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_vel.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/vel_dist/vel_vs_r/vel_vs_r_light_4gy.jpeg" 
set title 'Light Velocity as a function of Radius After 4Gy' 
plot '~/Desktop/research/data_testing/actual/light_matter_velocity_dist_4gy.dat' using 1:2  with dots title 'actual', '~/Desktop/research/data_testing/theory/theory_vel.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_vel.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_vel.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
