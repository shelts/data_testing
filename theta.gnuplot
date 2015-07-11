reset
set terminal jpeg
set key on
set ylabel 'counts'
set xlabel 'theta (rad)'
set xrange[0:4]
# set yrange[0:1000]



set output "plots/theta/theta_light_0gy.jpeg"
set title 'Histogram of Light Matter Theta Distribution After 0Gy'
plot "binned_data/theta_light_0gy.dat" using 2:1  with boxes title 'actual', "theory/theory_theta.dat"   using 1:2 with lines title 'both', "theory/theory_theta.dat"   using 1:3 with lines title 'light',  "theory/theory_theta.dat"   using 1:4 with lines title 'dark' 


set output "plots/theta/theta_dark_0gy.jpeg"
set title 'Histogram of Dark Matter Theta Distribution After 0Gy'
plot "binned_data/theta_dark_0gy.dat" using 2:1  with boxes title 'actual', "theory/theory_theta.dat"   using 1:2 with lines title 'both', "theory/theory_theta.dat"   using 1:3 with lines title 'light',  "theory/theory_theta.dat"   using 1:4 with lines title 'dark' 

set output "plots/theta/theta_both_0gy.jpeg"
set title 'Histogram of Total Theta Distribution After 0Gy'
plot "binned_data/theta_both_0gy.dat" using 2:1  with boxes title 'actual', "theory/theory_theta.dat"   using 1:2 with lines title 'both', "theory/theory_theta.dat"   using 1:3 with lines title 'light',  "theory/theory_theta.dat"   using 1:4 with lines title 'dark' 



# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "plots/theta/theta_light_0p25gy.jpeg"
set title 'Histogram of Light Matter Theta Distribution After .25Gy'
plot "binned_data/theta_light_p25gy.dat" using 2:1  with boxes title 'actual', "theory/theory_theta.dat"   using 1:2 with lines title 'both', "theory/theory_theta.dat"   using 1:3 with lines title 'light',  "theory/theory_theta.dat"   using 1:4 with lines title 'dark' 


set output "plots/theta/theta_dark_0p25gy.jpeg"
set title 'Histogram of Dark Matter Theta Distribution After .25Gy'
plot "binned_data/theta_dark_p25gy.dat" using 2:1  with boxes title 'actual', "theory/theory_theta.dat"   using 1:2 with lines title 'both', "theory/theory_theta.dat"   using 1:3 with lines title 'light',  "theory/theory_theta.dat"   using 1:4 with lines title 'dark' 

set output "plots/theta/theta_both_0p25gy.jpeg"
set title 'Histogram of Total Theta Distribution After .25Gy'
plot "binned_data/theta_both_0gy.dat" using 2:1  with boxes title 'actual', "theory/theory_theta.dat"   using 1:2 with lines title 'both', "theory/theory_theta.dat"   using 1:3 with lines title 'light',  "theory/theory_theta.dat"   using 1:4 with lines title 'dark' 



# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "plots/theta/theta_light_0p50gy.jpeg"
set title 'Histogram of Light Matter Theta Distribution After .5Gy'
plot "binned_data/theta_light_p5gy.dat" using 2:1  with boxes title 'actual', "theory/theory_theta.dat"   using 1:2 with lines title 'both', "theory/theory_theta.dat"   using 1:3 with lines title 'light',  "theory/theory_theta.dat"   using 1:4 with lines title 'dark' 


set output "plots/theta/theta_dark_0p50gy.jpeg"
set title 'Histogram of Dark Matter Theta Distribution After .5Gy'
plot "binned_data/theta_dark_p5gy.dat" using 2:1  with boxes title 'actual', "theory/theory_theta.dat"   using 1:2 with lines title 'both', "theory/theory_theta.dat"   using 1:3 with lines title 'light',  "theory/theory_theta.dat"   using 1:4 with lines title 'dark' 



set output "plots/theta/theta_both_0p50gy.jpeg"
set title 'Histogram of Total Theta Distribution After .50Gy'
plot "binned_data/theta_both_0gy.dat" using 2:1  with boxes title 'actual', "theory/theory_theta.dat"   using 1:2 with lines title 'both', "theory/theory_theta.dat"   using 1:3 with lines title 'light',  "theory/theory_theta.dat"   using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "plots/theta/theta_light_0p75gy.jpeg"
set title 'Histogram of Light Matter Theta Distribution After .75Gy'
plot "binned_data/theta_light_p75gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_theta.dat"   using 1:2 with lines title 'both', "theory/theory_theta.dat"   using 1:3 with lines title 'light',  "theory/theory_theta.dat"   using 1:4 with lines title 'dark' 


set output "plots/theta/theta_dark_0p75gy.jpeg"
set title 'Histogram of Dark Matter Theta Distribution After .75Gy'
plot "binned_data/theta_dark_p75gy.dat" using 2:1  with boxes title 'actual', "theory/theory_theta.dat"   using 1:2 with lines title 'both', "theory/theory_theta.dat"   using 1:3 with lines title 'light',  "theory/theory_theta.dat"   using 1:4 with lines title 'dark' 

set output "plots/theta/theta_both_0p75gy.jpeg"
set title 'Histogram of Total Theta Distribution After .75Gy'
plot "binned_data/theta_both_0gy.dat" using 2:1  with boxes title 'actual', "theory/theory_theta.dat"   using 1:2 with lines title 'both', "theory/theory_theta.dat"   using 1:3 with lines title 'light',  "theory/theory_theta.dat"   using 1:4 with lines title 'dark' 


# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 

set output "plots/theta/theta_light_1gy.jpeg"
set title 'Histogram of Light Matter Theta Distribution After 1Gy'
plot "binned_data/theta_light_1gy.dat" using 2:1  with boxes title 'actual', "theory/theory_theta.dat"   using 1:2 with lines title 'both', "theory/theory_theta.dat"   using 1:3 with lines title 'light',  "theory/theory_theta.dat"   using 1:4 with lines title 'dark' 


set output "plots/theta/theta_dark_1gy.jpeg"
set title 'Histogram of Dark Matter Theta Distribution After 1Gy'
plot "binned_data/theta_dark_1gy.dat" using 2:1  with boxes title 'actual', "theory/theory_theta.dat"   using 1:2 with lines title 'both', "theory/theory_theta.dat"   using 1:3 with lines title 'light',  "theory/theory_theta.dat"   using 1:4 with lines title 'dark' 

set output "plots/theta/theta_both_1gy.jpeg"
set title 'Histogram of Total Theta Distribution After 1Gy'
plot "binned_data/theta_both_0gy.dat" using 2:1  with boxes title 'actual', "theory/theory_theta.dat"   using 1:2 with lines title 'both', "theory/theory_theta.dat"   using 1:3 with lines title 'light',  "theory/theory_theta.dat"   using 1:4 with lines title 'dark' 


# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "plots/theta/theta_light_2gy.jpeg"
set title 'Histogram of Light Matter Theta Distribution After 2Gy'
plot "binned_data/theta_light_2gy.dat" using 2:1  with boxes title 'actual', "theory/theory_theta.dat"   using 1:2 with lines title 'both', "theory/theory_theta.dat"   using 1:3 with lines title 'light',  "theory/theory_theta.dat"   using 1:4 with lines title 'dark' 

set output "plots/theta/theta_dark_2gy.jpeg"
set title 'Histogram of Dark Matter Theta Distribution After 2Gy'
plot "binned_data/theta_dark_2gy.dat" using 2:1  with boxes title 'actual', "theory/theory_theta.dat"   using 1:2 with lines title 'both', "theory/theory_theta.dat"   using 1:3 with lines title 'light',  "theory/theory_theta.dat"   using 1:4 with lines title 'dark' 

set output "plots/theta/theta_both_2gy.jpeg"
set title 'Histogram of Total Theta Distribution After 2Gy'
plot "binned_data/theta_both_0gy.dat" using 2:1  with boxes title 'actual', "theory/theory_theta.dat"   using 1:2 with lines title 'both', "theory/theory_theta.dat"   using 1:3 with lines title 'light',  "theory/theory_theta.dat"   using 1:4 with lines title 'dark' 


# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "plots/theta/theta_light_3gy.jpeg"
set title 'Histogram of Light Matter Theta Distribution After 3Gy'
plot "binned_data/theta_light_3gy.dat" using 2:1  with boxes title 'actual', "theory/theory_theta.dat"   using 1:2 with lines title 'both', "theory/theory_theta.dat"   using 1:3 with lines title 'light',  "theory/theory_theta.dat"   using 1:4 with lines title 'dark' 


set output "plots/theta/theta_dark_3gy.jpeg"
set title 'Histogram of Dark Matter Theta Distribution After 3Gy'
plot "binned_data/theta_dark_3gy.dat" using 2:1  with boxes title 'actual', "theory/theory_theta.dat"   using 1:2 with lines title 'both', "theory/theory_theta.dat"   using 1:3 with lines title 'light',  "theory/theory_theta.dat"   using 1:4 with lines title 'dark' 


set output "plots/theta/theta_both_3gy.jpeg"
set title 'Histogram of Total Theta Distribution After 3Gy'
plot "binned_data/theta_both_0gy.dat" using 2:1  with boxes title 'actual', "theory/theory_theta.dat"   using 1:2 with lines title 'both', "theory/theory_theta.dat"   using 1:3 with lines title 'light',  "theory/theory_theta.dat"   using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 

set output "plots/theta/theta_light_4gy.jpeg"
set title 'Histogram of Light Matter Theta Distribution After 4Gy'
plot "binned_data/theta_light_4gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_theta.dat"   using 1:2 with lines title 'both', "theory/theory_theta.dat"   using 1:3 with lines title 'light',  "theory/theory_theta.dat"   using 1:4 with lines title 'dark' 


set output "plots/theta/theta_dark_4gy.jpeg"
set title 'Histogram of Dark Matter Theta Distribution After 4Gy'
plot "binned_data/theta_dark_4gy.dat" using 2:1  with boxes title 'actual', "theory/theory_theta.dat"   using 1:2 with lines title 'both', "theory/theory_theta.dat"   using 1:3 with lines title 'light',  "theory/theory_theta.dat"   using 1:4 with lines title 'dark' 


set output "plots/theta/theta_both_4gy.jpeg"
set title 'Histogram of Total Theta Distribution After 4Gy'
plot "binned_data/theta_both_0gy.dat" using 2:1  with boxes title 'actual', "theory/theory_theta.dat"   using 1:2 with lines title 'both', "theory/theory_theta.dat"   using 1:3 with lines title 'light',  "theory/theory_theta.dat"   using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 