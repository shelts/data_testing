reset
set terminal jpeg
set key on
set ylabel 'counts'
set xlabel 'phi (rad)'
set xrange[-5:5]
set output "~/Desktop/research/data_testing/plots/vel_phi/phi_vel_light_0gy.jpeg" 
set title 'Histogram of Light Matter Velocity Phi Distribution After 0Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_vel_light_0gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/vel_phi/phi_vel_dark_0gy.jpeg" 
set title 'Histogram of Dark Matter Velocity Phi Distribution After 0Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_vel_dark_0gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/vel_phi/phi_vel_both_0gy.jpeg" 
set title 'Histogram of Combined Matter Velocity Phi Distribution After 0Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_vel_both_0gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/vel_phi/phi_vel_light_0p25gy.jpeg" 
set title 'Histogram of Light Matter Velocity Phi Distribution After .25Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_vel_light_p25gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/vel_phi/phi_vel_dark_0p25gy.jpeg" 
set title 'Histogram of Dark Matter Velocity Phi Distribution After .25Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_vel_dark_p25gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/vel_phi/phi_vel_both_0p25gy.jpeg" 
set title 'Histogram of Combined Matter Velocity Phi Distribution After .25Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_vel_both_p25gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/vel_phi/phi_vel_light_0p50gy.jpeg" 
set title 'Histogram of Light Matter Velocity Phi Distribution After .5Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_vel_light_p50gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/vel_phi/phi_vel_dark_0p50gy.jpeg" 
set title 'Histogram of Dark Matter Velocity Phi Distribution After .5Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_vel_dark_p50gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/vel_phi/phi_vel_both_0p50gy.jpeg" 
set title 'Histogram of Combined Matter Velocity Phi Distribution After .5Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_vel_both_p50gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/vel_phi/phi_vel_light_0p75gy.jpeg" 
set title 'Histogram of Light Matter Velocity Phi Distribution After .75Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_vel_light_p75gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/vel_phi/phi_vel_dark_0p75gy.jpeg" 
set title 'Histogram of Dark Matter Velocity Phi Distribution After .75Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_vel_dark_p75gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/vel_phi/phi_vel_both_0p75gy.jpeg" 
set title 'Histogram of Combined Matter Velocity Phi Distribution After .75Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_vel_both_p75gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/vel_phi/phi_vel_light_1gy.jpeg" 
set title 'Histogram of Light Matter Velocity Phi Distribution After 1Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_vel_light_1gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/vel_phi/phi_vel_dark_1gy.jpeg" 
set title 'Histogram of Dark Matter Velocity Phi Distribution After 1Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_vel_dark_1gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/vel_phi/phi_vel_both_1gy.jpeg" 
set title 'Histogram of Combined Matter Velocity Phi Distribution After 1Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_vel_both_1gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/vel_phi/phi_vel_light_2gy.jpeg" 
set title 'Histogram of Light Matter Velocity Phi Distribution After 2Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_vel_light_2gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/vel_phi/phi_vel_dark_2gy.jpeg" 
set title 'Histogram of Dark Matter Velocity Phi Distribution After 2Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_vel_dark_2gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/vel_phi/phi_vel_both_2gy.jpeg" 
set title 'Histogram of Combined Matter Velocity Phi Distribution After 2Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_vel_both_2gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/vel_phi/phi_vel_light_3gy.jpeg" 
set title 'Histogram of Light Matter Velocity Phi Distribution After 3Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_vel_light_3gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/vel_phi/phi_vel_dark_3gy.jpeg" 
set title 'Histogram of Dark Matter Velocity Phi Distribution After 3Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_vel_dark_3gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/vel_phi/phi_vel_both_3gy.jpeg" 
set title 'Histogram of Combined Matter Velocity Phi Distribution After 3Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_vel_both_3gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/vel_phi/phi_vel_light_4gy.jpeg" 
set title 'Histogram of Light Matter Velocity Phi Distribution After 4Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_vel_light_4gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/vel_phi/phi_vel_dark_4gy.jpeg" 
set title 'Histogram of Dark Matter Velocity Phi Distribution After 4Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_vel_dark_4gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/vel_phi/phi_vel_both_4gy.jpeg" 
set title 'Histogram of Combined Matter Velocity Phi Distribution After 4Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_vel_both_4gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
