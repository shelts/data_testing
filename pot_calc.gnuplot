reset
set terminal jpeg
set key on
set ylabel 'counts'
set xlabel 'potential'
set xrange[-15:0.0]
set yrange[0:250]

# set terminal wxt size

set output "plots/pot/pot_calc_light_0gy.jpeg"
set title 'Light Matter Potential Distribution After 0Gy'
plot "binned_data/pot_light_0gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_calc.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_calc.dat"   using 2:4 with lines title 'dark'
# ,  "theory/theory_pot_calc.dat"   using 1:2 with lines title 'both',

set output "plots/pot/pot_calc_dark_0gy.jpeg"
set title 'Dark Matter Potential Distribution After 0Gy'
plot "binned_data/pot_dark_0gy.dat" using 2:1  with boxes title 'actual',"theory/theory_pot_calc.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_calc.dat"   using 2:4 with lines title 'dark'
# ,  "theory/theory_pot_calc.dat"   using 1:2 with lines title 'both', 



# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# set output "plots/pot/pot_calc_light_0p25gy.jpeg"
# set title 'Light Matter Potential Distribution After .25Gy'
# plot "binned_data/pot_light_p25gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_int.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_int.dat"   using 2:4 with lines title 'dark' 
# 
# 
# set output "plots/pot/pot_calc_dark_0p25gy.jpeg"
# set title 'Dark Matter Potential Distribution After .25Gy'
# plot "binned_data/pot_dark_p25gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_int.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_int.dat"   using 2:4 with lines title 'dark' 
# 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# set output "plots/pot/pot_calc_light_0p50gy.jpeg"
# set title 'Light Matter Potential Distribution After .5Gy'
# plot "binned_data/pot_light_p5gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_int.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_int.dat"   using 2:4 with lines title 'dark' 
# 
# 
# set output "plots/pot/pot_calc_dark_0p50gy.jpeg"
# set title 'Dark Matter Potential Distribution After .5Gy'
# plot "binned_data/pot_dark_p5gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_int.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_int.dat"   using 2:4 with lines title 'dark' 
# 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# set output "plots/pot/pot_calc_light_0p75gy.jpeg"
# set title 'Light Matter Potential Distribution After .75Gy'
# plot "binned_data/pot_light_p75gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_pot_int.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_int.dat"   using 2:4 with lines title 'dark' 
# 
# 
# set output "plots/pot/pot_calc_dark_0p75gy.jpeg"
# set title 'Dark Matter Potential Distribution After .75Gy'
# plot "binned_data/pot_dark_p75gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_int.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_int.dat"   using 2:4 with lines title 'dark' 
# 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# 
# set output "plots/pot/pot_calc_light_1gy.jpeg"
# set title 'Light Matter Potential Distribution After 1Gy'
# plot "binned_data/pot_light_1gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_int.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_int.dat"   using 2:4 with lines title 'dark' 
# 
# 
# set output "plots/pot/pot_calc_dark_1gy.jpeg"
# set title 'Dark Matter Potential Distribution After 1Gy'
# plot "binned_data/pot_dark_1gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_int.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_int.dat"   using 2:4 with lines title 'dark' 
# 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# set output "plots/pot/pot_calc_light_2gy.jpeg"
# set title 'Light Matter Potential Distribution After 2Gy'
# plot "binned_data/pot_light_2gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_int.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_int.dat"   using 2:4 with lines title 'dark' 
# 
# set output "plots/pot/pot_calc_dark_2gy.jpeg"
# set title 'Dark Matter Potential Distribution After 2Gy'
# plot "binned_data/pot_dark_2gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_int.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_int.dat"   using 2:4 with lines title 'dark' 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# set output "plots/pot/pot_calc_light_3gy.jpeg"
# set title 'Light Matter Potential Distribution After 3Gy'
# plot "binned_data/pot_light_3gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_int.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_int.dat"   using 2:4 with lines title 'dark' 
# 
# 
# set output "plots/pot/pot_calc_dark_3gy.jpeg"
# set title 'Dark Matter Potential Distribution After 3Gy'
# plot "binned_data/pot_dark_3gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_int.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_int.dat"   using 2:4 with lines title 'dark' 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# 
# set output "plots/pot/pot_calc_light_4gy.jpeg"
# set title 'Light Matter Potential Distribution After 4Gy'
# plot "binned_data/pot_light_4gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_pot_int.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_int.dat"   using 2:4 with lines title 'dark' 
# 
# 
# set output "plots/pot/pot_calc_dark_4gy.jpeg"
# set title 'Dark Matter Potential Distribution After 4Gy'
# plot "binned_data/pot_dark_4gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_int.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_int.dat"   using 2:4 with lines title 'dark' 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 