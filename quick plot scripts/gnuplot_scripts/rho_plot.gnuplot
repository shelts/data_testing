# Theory:
reset
set terminal png 
# wxt persist
set output "../quick_plots/rho_vs_r.png"
# set key off
set title 'r^2 Rho vs r'
set xlabel 'r'
set ylabel 'r^2*rho'
# set zlabel 'Likelihood'
# set xrange[0:2.5]
# set yrange[0.3:.5]

plot "../quick_plots/rho.txt"   using 2:1 with lines title 'light', ''  using 2:3 with lines title 'dark', '' using 2:4 with lines title 'both'


# #actual:
# reset
# set terminal png 
# # wxt persist
# set output "../quick_plots/rho_vs_r2.png"
# # set key off
# set title 'r^2 Rho vs r'
# set xlabel 'r'
# set ylabel 'r^2*rho'
# # set zlabel 'Likelihood'
# # set yrange[0:.3]
# # set xrange[-10:10]
# 
# plot "../quick_plots/rho2.txt"   using 2:1 with dots 
# 
# #############################################################