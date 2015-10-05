reset
set terminal jpeg
set key on
set ylabel 'counts'
set xlabel 'phi (rad)'
set xrange[-5:5]
set output "~/Desktop/research/data_testing/plots/phi/phi_light_0gy.jpeg" 
set title 'Histogram of Light Matter Phi Distribution After 0Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_light_0gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/phi/phi_light_0p25gy.jpeg" 
set title 'Histogram of Light Matter Phi Distribution After .25Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_light_p25gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/phi/phi_light_0p50gy.jpeg" 
set title 'Histogram of Light Matter Phi Distribution After .5Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_light_p50gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/phi/phi_light_0p75gy.jpeg" 
set title 'Histogram of Light Matter Phi Distribution After .75Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_light_p75gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/phi/phi_light_1gy.jpeg" 
set title 'Histogram of Light Matter Phi Distribution After 1Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_light_1gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/phi/phi_light_2gy.jpeg" 
set title 'Histogram of Light Matter Phi Distribution After 2Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_light_2gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/phi/phi_light_3gy.jpeg" 
set title 'Histogram of Light Matter Phi Distribution After 3Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_light_3gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/phi/phi_light_4gy.jpeg" 
set title 'Histogram of Light Matter Phi Distribution After 4Gy' 
plot '~/Desktop/research/data_testing/binned_data/phi_light_4gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_phi.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
