reset
set terminal jpeg
set key on
set ylabel 'potential'
set xlabel 'radius (Mpc)'
set xrange[0:15]
# set yrange[0:1000]



set output "plots/pot/pot_calc_light_0gy.jpeg"
set title 'Light Matter Potential Distribution After 0Gy'
plot "actual/light_potential_0gy.dat" using 1:2  with dots title 'actual', "theory/theory_pot_calc.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_calc.dat"   using 1:4 with lines title 'dark'
# ,  "theory/theory_pot_calc.dat"   using 1:2 with lines title 'both',

set output "plots/pot/pot_calc_dark_0gy.jpeg"
set title 'Dark Matter Potential Distribution After 0Gy'
plot "actual/dark_potential_0gy.dat" using 1:2  with dots title 'actual',"theory/theory_pot_calc.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_calc.dat"   using 1:4 with lines title 'dark'
# ,  "theory/theory_pot_calc.dat"   using 1:2 with lines title 'both', 



# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# set output "plots/pot/pot_calc_light_0p25gy.jpeg"
# set title 'Light Matter Potential Distribution After .25Gy'
# plot "actual/light_potential_p25gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_calc.dat"   using 1:2 with lines title 'both', "theory/theory_pot_calc.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_calc.dat"   using 1:4 with lines title 'dark' 
# 
# 
# set output "plots/pot/pot_calc_dark_0p25gy.jpeg"
# set title 'Dark Matter Potential Distribution After .25Gy'
# plot "actual/dark_potential_p25gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_calc.dat"   using 1:2 with lines title 'both', "theory/theory_pot_calc.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_calc.dat"   using 1:4 with lines title 'dark' 
# 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# set output "plots/pot/pot_calc_light_0p50gy.jpeg"
# set title 'Light Matter Potential Distribution After .5Gy'
# plot "actual/light_potential_p5gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_calc.dat"   using 1:2 with lines title 'both', "theory/theory_pot_calc.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_calc.dat"   using 1:4 with lines title 'dark' 
# 
# 
# set output "plots/pot/pot_calc_dark_0p50gy.jpeg"
# set title 'Dark Matter Potential Distribution After .5Gy'
# plot "actual/dark_potential_p5gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_calc.dat"   using 1:2 with lines title 'both', "theory/theory_pot_calc.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_calc.dat"   using 1:4 with lines title 'dark' 
# 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# set output "plots/pot/pot_calc_light_0p75gy.jpeg"
# set title 'Light Matter Potential Distribution After .75Gy'
# plot "actual/light_potential_p75gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_pot_calc.dat"   using 1:2 with lines title 'both', "theory/theory_pot_calc.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_calc.dat"   using 1:4 with lines title 'dark' 
# 
# 
# set output "plots/pot/pot_calc_dark_0p75gy.jpeg"
# set title 'Dark Matter Potential Distribution After .75Gy'
# plot "actual/dark_potential_p75gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_calc.dat"   using 1:2 with lines title 'both', "theory/theory_pot_calc.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_calc.dat"   using 1:4 with lines title 'dark' 
# 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# 
# set output "plots/pot/pot_calc_light_1gy.jpeg"
# set title 'Light Matter Potential Distribution After 1Gy'
# plot "actual/light_potential_1gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_calc.dat"   using 1:2 with lines title 'both', "theory/theory_pot_calc.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_calc.dat"   using 1:4 with lines title 'dark' 
# 
# 
# set output "plots/pot/pot_calc_dark_1gy.jpeg"
# set title 'Dark Matter Potential Distribution After 1Gy'
# plot "actual/dark_potential_1gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_calc.dat"   using 1:2 with lines title 'both', "theory/theory_pot_calc.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_calc.dat"   using 1:4 with lines title 'dark' 
# 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# set output "plots/pot/pot_calc_light_2gy.jpeg"
# set title 'Light Matter Potential Distribution After 2Gy'
# plot "actual/light_potential_2gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_calc.dat"   using 1:2 with lines title 'both', "theory/theory_pot_calc.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_calc.dat"   using 1:4 with lines title 'dark' 
# 
# set output "plots/pot/pot_calc_dark_2gy.jpeg"
# set title 'Dark Matter Potential Distribution After 2Gy'
# plot "actual/dark_potential_2gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_calc.dat"   using 1:2 with lines title 'both', "theory/theory_pot_calc.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_calc.dat"   using 1:4 with lines title 'dark' 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# set output "plots/pot/pot_calc_light_3gy.jpeg"
# set title 'Light Matter Potential Distribution After 3Gy'
# plot "actual/light_potential_3gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_calc.dat"   using 1:2 with lines title 'both', "theory/theory_pot_calc.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_calc.dat"   using 1:4 with lines title 'dark' 
# 
# 
# set output "plots/pot/pot_calc_dark_3gy.jpeg"
# set title 'Dark Matter Potential Distribution After 3Gy'
# plot "actual/dark_potential_3gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_calc.dat"   using 1:2 with lines title 'both', "theory/theory_pot_calc.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_calc.dat"   using 1:4 with lines title 'dark' 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# 
# set output "plots/pot/pot_calc_light_4gy.jpeg"
# set title 'Light Matter Potential Distribution After 4Gy'
# plot "actual/light_potential_4gy.dat" using 2:1  with boxes title 'actual',  "theory/theory_pot_calc.dat"   using 1:2 with lines title 'both', "theory/theory_pot_calc.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_calc.dat"   using 1:4 with lines title 'dark' 
# 
# 
# set output "plots/pot/pot_calc_dark_4gy.jpeg"
# set title 'Dark Matter Potential Distribution After 4Gy'
# plot "actual/dark_potential_4gy.dat" using 2:1  with boxes title 'actual', "theory/theory_pot_calc.dat"   using 1:2 with lines title 'both', "theory/theory_pot_calc.dat"   using 1:3 with lines title 'light',  "theory/theory_pot_calc.dat"   using 1:4 with lines title 'dark' 
# 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 