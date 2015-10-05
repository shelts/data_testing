reset
set terminal jpeg
set key on
set ylabel 'counts'
set xlabel 'radius (Kpc)'
set xrange[0:20]
set yrange[0:1500]


set output "~/Desktop/research/data_testing/plots/rad/radii_distribution_light_0gy.jpeg" 
set title 'Histogram of Light Matter Distribution After 0Gy' 
plot '~/Desktop/research/data_testing/binned_data/light_matter_bins_0gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/rad/radii_distribution_dark_0gy.jpeg" 
set title 'Histogram of Dark Matter Distribution After 0Gy' 
plot '~/Desktop/research/data_testing/binned_data/dark_matter_bins_0gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/rad/radii_distribution_both_0gy.jpeg" 
set title 'Histogram of Combined Matter Distribution After 0Gy' 
plot '~/Desktop/research/data_testing/binned_data/both_matter_bins_0gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/rad/radii_distribution_light_0p25gy.jpeg" 
set title 'Histogram of Light Matter Distribution After .25Gy' 
plot '~/Desktop/research/data_testing/binned_data/light_matter_bins_p25gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/rad/radii_distribution_dark_0p25gy.jpeg" 
set title 'Histogram of Dark Matter Distribution After .25Gy' 
plot '~/Desktop/research/data_testing/binned_data/dark_matter_bins_p25gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/rad/radii_distribution_both_0p25gy.jpeg" 
set title 'Histogram of Combined Matter Distribution After .25Gy' 
plot '~/Desktop/research/data_testing/binned_data/both_matter_bins_p25gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/rad/radii_distribution_light_0p50gy.jpeg" 
set title 'Histogram of Light Matter Distribution After .5Gy' 
plot '~/Desktop/research/data_testing/binned_data/light_matter_bins_p50gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/rad/radii_distribution_dark_0p50gy.jpeg" 
set title 'Histogram of Dark Matter Distribution After .5Gy' 
plot '~/Desktop/research/data_testing/binned_data/dark_matter_bins_p50gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/rad/radii_distribution_both_0p50gy.jpeg" 
set title 'Histogram of Combined Matter Distribution After .5Gy' 
plot '~/Desktop/research/data_testing/binned_data/both_matter_bins_p50gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/rad/radii_distribution_light_0p75gy.jpeg" 
set title 'Histogram of Light Matter Distribution After .75Gy' 
plot '~/Desktop/research/data_testing/binned_data/light_matter_bins_p75gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/rad/radii_distribution_dark_0p75gy.jpeg" 
set title 'Histogram of Dark Matter Distribution After .75Gy' 
plot '~/Desktop/research/data_testing/binned_data/dark_matter_bins_p75gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/rad/radii_distribution_both_0p75gy.jpeg" 
set title 'Histogram of Combined Matter Distribution After .75Gy' 
plot '~/Desktop/research/data_testing/binned_data/both_matter_bins_p75gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/rad/radii_distribution_light_1gy.jpeg" 
set title 'Histogram of Light Matter Distribution After 1Gy' 
plot '~/Desktop/research/data_testing/binned_data/light_matter_bins_1gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/rad/radii_distribution_dark_1gy.jpeg" 
set title 'Histogram of Dark Matter Distribution After 1Gy' 
plot '~/Desktop/research/data_testing/binned_data/dark_matter_bins_1gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/rad/radii_distribution_both_1gy.jpeg" 
set title 'Histogram of Combined Matter Distribution After 1Gy' 
plot '~/Desktop/research/data_testing/binned_data/both_matter_bins_1gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/rad/radii_distribution_light_2gy.jpeg" 
set title 'Histogram of Light Matter Distribution After 2Gy' 
plot '~/Desktop/research/data_testing/binned_data/light_matter_bins_2gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/rad/radii_distribution_dark_2gy.jpeg" 
set title 'Histogram of Dark Matter Distribution After 2Gy' 
plot '~/Desktop/research/data_testing/binned_data/dark_matter_bins_2gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/rad/radii_distribution_both_2gy.jpeg" 
set title 'Histogram of Combined Matter Distribution After 2Gy' 
plot '~/Desktop/research/data_testing/binned_data/both_matter_bins_2gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/rad/radii_distribution_light_3gy.jpeg" 
set title 'Histogram of Light Matter Distribution After 3Gy' 
plot '~/Desktop/research/data_testing/binned_data/light_matter_bins_3gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/rad/radii_distribution_dark_3gy.jpeg" 
set title 'Histogram of Dark Matter Distribution After 3Gy' 
plot '~/Desktop/research/data_testing/binned_data/dark_matter_bins_3gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/rad/radii_distribution_both_3gy.jpeg" 
set title 'Histogram of Combined Matter Distribution After 3Gy' 
plot '~/Desktop/research/data_testing/binned_data/both_matter_bins_3gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
set output "~/Desktop/research/data_testing/plots/rad/radii_distribution_light_4gy.jpeg" 
set title 'Histogram of Light Matter Distribution After 4Gy' 
plot '~/Desktop/research/data_testing/binned_data/light_matter_bins_4gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/rad/radii_distribution_dark_4gy.jpeg" 
set title 'Histogram of Dark Matter Distribution After 4Gy' 
plot '~/Desktop/research/data_testing/binned_data/dark_matter_bins_4gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:4 with lines title 'dark' 

set output "~/Desktop/research/data_testing/plots/rad/radii_distribution_both_4gy.jpeg" 
set title 'Histogram of Combined Matter Distribution After 4Gy' 
plot '~/Desktop/research/data_testing/binned_data/both_matter_bins_4gy.dat' using 2:1  with boxes title 'actual', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:2 with lines title 'both', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:3 with lines title 'light', '~/Desktop/research/data_testing/theory/theory_den.dat' using 1:4 with lines title 'dark' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
