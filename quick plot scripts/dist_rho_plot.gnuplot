reset
set terminal png 
# wxt persist
set output "quick_plots/rho_vs_r.png"
# set key off
set title 'r^2 Rho vs r'
set xlabel 'r'
set ylabel 'r^2*rho'
# set zlabel 'Likelihood'
# set xrange[0:2.5]
# set yrange[0.3:.5]

plot "./quick_plots/rho.txt"   using 2:1 with lines title 'light', ''  using 2:3 with lines title 'dark', '' using 2:4 with lines title 'both'

reset
set terminal png 
# wxt persist
set output "quick_plots/rho_vs_r2.png"
# set key off
set title 'r^2 Rho vs r'
set xlabel 'r'
set ylabel 'r^2*rho'
# set zlabel 'Likelihood'
# set yrange[0:.3]
# set xrange[-10:10]

plot "./quick_plots/rho2.txt"   using 2:1 with dots 

#############################################################
reset
set terminal png 
# wxt persist
set output "quick_plots/dist_vs_r.png"
set key off
set title 'v^2*f vs r'
set xlabel 'r'
set ylabel 'v^2*dist'
# set zlabel 'Likelihood'
# set xrange[0:30]
# set yrange[0:1.8]

plot "./quick_plots/dist.txt"   using 2:1 with dots


reset
set terminal png 
# wxt persist
set output "quick_plots/dist_vs_v.png"
set key off
set title 'v^2*f vs v'
set xlabel 'v'
set ylabel 'v^2*dist'
# set zlabel 'Likelihood'
# set xrange[0:3.5]
# set yrange[0:0.6]

plot "./quick_plots/dist.txt"   using 3:1 with dots


reset
set terminal png 
# wxt persist
set output "quick_plots/v_vs_r.png"
set key off
set title 'v vs r'
set xlabel 'r'
set ylabel 'v'
# set zlabel 'Likelihood'
# set xrange[0:30]
# set yrange[0:5]

plot "./quick_plots/dist.txt"   using 2:3 with dots


#############################################################
# 
reset
set terminal png 
# wxt persist
set output "quick_plots/dist_vs_r_theory.png"
set key off
set title 'v^2*f vs r'
set xlabel 'r'
set ylabel 'v^2*dist'
# set zlabel 'Likelihood'
# set xrange[0:30]
# set yrange[0:1.8]

plot "./quick_plots/dist_1.txt"   using 2:1 with dots


reset
set terminal png 
# wxt persist
set output "quick_plots/dist_vs_v_theory.png"
set key off
set title 'v^2*f vs v'
set xlabel 'v'
set ylabel 'v^2*dist'
# set zlabel 'Likelihood'
# set xrange[0:3.5]
# set yrange[0:0.6]

plot "./quick_plots/dist_1.txt"   using 3:1 with dots


reset
set terminal png 
# wxt persist
set output "quick_plots/v_vs_r_theory.png"
set key off
set title 'v vs r'
set xlabel 'r'
set ylabel 'v'
# set zlabel 'Likelihood'
# set xrange[0:30]
# set yrange[0:5]
plot "./quick_plots/dist_1.txt"   using 2:3 with dots



# # reset
# # set terminal png 
# # # wxt persist
# # set output "quick_plots/dist_3d_theory.png"
# # set key off
# # set title 'v^2*f vs v'
# # set xlabel 'v'
# # set ylabel 'v^2*dist'
# # # set zlabel 'Likelihood'
# # # set xrange[0:3]
# # # set yrange[0:1.8]
# # 
# # splot "./quick_plots/dist_1.txt"   using 3:2:1 with dots