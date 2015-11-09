reset
set terminal jpeg
set key on
set ylabel 'counts'
set xlabel 'radius (Kpc)'
set xrange[-50:50]
set yrange[0:.15]


set output "~/Desktop/research/data_testing/plots/hist.jpeg" 
set title 'Histogram of Light Matter Distribution After 4 Gy' 
plot 'histograms/tidal_histogram.hist' using 2:4 with boxes title 'sim', 'histograms/Orphan_Data_September_2014.hist' using 2:4 with boxes title 'data' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
