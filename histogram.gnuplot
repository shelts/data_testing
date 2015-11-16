reset
set terminal jpeg
set key on
set xlabel 'lambda'
set xrange[40:-40]
set yrange[0:.15]


set output "~/Desktop/research/data_testing/plots/hist.jpeg" 
set title 'Histogram of Light Matter Distribution After 4 Gy' 
plot 'histograms/tidal_histogram.hist' u 2:4 w boxes t 'sim', 'histograms/none.hist' u 1:2 w boxes t 'data', 'histograms/none.hist' u 2:4 w boxes t 'data' 

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
