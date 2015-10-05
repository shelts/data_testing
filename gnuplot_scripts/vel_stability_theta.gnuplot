reset
set terminal jpeg
set key on
set ylabel 'counts'
set xlabel 'theta (rad)'
set xrange[0:4]
set output "~/Desktop/research/data_testing/plots/vel_theta/theta_vel_light_0gy.jpeg" 
set title 'Histogram of Light Matter Velocity Theta Distribution After 0Gy' 
plot '~/Desktop/research/data_testing/binned_data/theta_vel_light_0gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_theta.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_theta.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_theta.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/vel_theta/theta_vel_light_0p25gy.jpeg" 
set title 'Histogram of Light Matter Velocity Theta Distribution After .25Gy' 
plot '~/Desktop/research/data_testing/binned_data/theta_vel_light_p25gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_theta.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_theta.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_theta.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/vel_theta/theta_vel_light_0p50gy.jpeg" 
set title 'Histogram of Light Matter Velocity Theta Distribution After .5Gy' 
plot '~/Desktop/research/data_testing/binned_data/theta_vel_light_p50gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_theta.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_theta.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_theta.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/vel_theta/theta_vel_light_0p75gy.jpeg" 
set title 'Histogram of Light Matter Velocity Theta Distribution After .75Gy' 
plot '~/Desktop/research/data_testing/binned_data/theta_vel_light_p75gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_theta.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_theta.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_theta.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/vel_theta/theta_vel_light_1gy.jpeg" 
set title 'Histogram of Light Matter Velocity Theta Distribution After 1Gy' 
plot '~/Desktop/research/data_testing/binned_data/theta_vel_light_1gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_theta.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_theta.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_theta.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/vel_theta/theta_vel_light_2gy.jpeg" 
set title 'Histogram of Light Matter Velocity Theta Distribution After 2Gy' 
plot '~/Desktop/research/data_testing/binned_data/theta_vel_light_2gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_theta.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_theta.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_theta.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/vel_theta/theta_vel_light_3gy.jpeg" 
set title 'Histogram of Light Matter Velocity Theta Distribution After 3Gy' 
plot '~/Desktop/research/data_testing/binned_data/theta_vel_light_3gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_theta.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_theta.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_theta.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/vel_theta/theta_vel_light_4gy.jpeg" 
set title 'Histogram of Light Matter Velocity Theta Distribution After 4Gy' 
plot '~/Desktop/research/data_testing/binned_data/theta_vel_light_4gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_theta.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_theta.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_theta.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
