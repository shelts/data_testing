reset
set terminal jpeg
set key on
set ylabel 'counts'
set xlabel 'radius (Mpc)'
set xrange[0:15]
set yrange[0:10]


set output "plots/vel/vel_vs_r_light_0gy.jpeg"
set title 'Light Velocity as a function of Radius After 0Gy'
plot "actual/light_matter_velocity_dist_0gy.dat" using 1:2  with dots title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark'
# , "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 


set output "plots/vel/vel_vs_r_dark_0gy.jpeg"
set title 'Dark Velocity as a function of Radius After 0Gy'
plot "actual/dark_matter_velocity_dist_0gy.dat" using 1:2  with dots title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark'
# , "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# 
# 
# set output "plots/vel/vel_vs_r_light_0p25gy.jpeg"
# set title 'Light Velocity as a function of Radius After .25Gy'
# plot "actual/light_matter_velocity_dist_p25gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# 
# set output "plots/vel/vel_vs_r_dark_0p25gy.jpeg"
# set title 'Dark Velocity as a function of Radius After .25Gy'
# plot "actual/dark_matter_velocity_dist_p25gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# 
# set output "plots/vel/vel_vs_r_light_0p50gy.jpeg"
# set title 'Light Velocity as a function of Radius After .5Gy'
# plot "actual/light_matter_velocity_dist_p5gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# 
# set output "plots/vel/vel_vs_r_dark_0p50gy.jpeg"
# set title 'Dark Velocity as a function of Radius After .5Gy'
# plot "actual/dark_matter_velocity_dist_p5gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# light_matter_vel_bins_0gy
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# set output "plots/vel/vel_vs_r_light_0p75gy.jpeg"
# set title 'Light Velocity as a function of Radius After .75Gy'
# plot "actual/light_matter_velocity_dist_p75gy.dat" using 2:1  with boxes title 'actual',   "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# set output "plots/vel/vel_vs_r_dark_0p75gy.jpeg"
# set title 'Dark Velocity as a function of Radius After .75Gy'
# plot "actual/dark_matter_velocity_dist_p75gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# 
# set output "plots/vel/vel_vs_r_light_1gy.jpeg"
# set title 'Light Velocity as a function of Radius After 1Gy'
# plot "actual/light_matter_velocity_dist_1gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# set output "plots/vel/vel_vs_r_dark_1gy.jpeg"
# set title 'Dark Velocity as a function of Radius After 1Gy'
# plot "actual/dark_matter_velocity_dist_1gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# set output "plots/vel/vel_vs_r_light_2gy.jpeg"
# set title 'Light Velocity as a function of Radius After 2Gy'
# plot "actual/light_matter_velocity_dist_2gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# 
# set output "plots/vel/vel_vs_r_dark_2gy.jpeg"
# set title 'Dark Velocity as a function of Radius After 2Gy'
# plot "actual/dark_matter_velocity_dist_2gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# set output "plots/vel/vel_vs_r_light_3gy.jpeg"
# set title 'Light Velocity as a function of Radius After 3Gy'
# plot "actual/light_matter_velocity_dist_3gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# 
# set output "plots/vel/vel_vs_r_dark_3gy.jpeg"
# set title 'Dark Velocity as a function of Radius After 3Gy'
# plot "actual/dark_matter_velocity_dist_3gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# 
# 
# set output "plots/vel/vel_vs_r_light_4gy.jpeg"
# set title 'Light Velocity as a function of Radius After 4Gy'
# plot "actual/light_matter_velocity_dist_4gy.dat" using 2:1  with boxes title 'actual',   "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# 
# set output "plots/vel/vel_vs_r_dark_4gy.jpeg"
# set title 'Dark Velocity as a function of Radius After 4Gy'
# plot "actual/dark_matter_velocity_dist_4gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_vel.dat"   using 1:2 with lines title 'light',  "theory/theory_vel.dat"   using 1:3 with lines title 'dark', "theory/theory_vel.dat"   using 1:4 with lines title 'both'' 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
