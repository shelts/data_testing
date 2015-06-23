#!/bin/bash

# same_masses=0
# diff_masses=1

# 	  cp  ~/Desktop/research/nbody_test/bin/output_test.out ./sim_outputs
# 	  python outputparser.py ./sim_outputs/output_test.out  test0gy
	  g++ -std=c++11 virial_test.cpp -o virial_test
# 	  rm virial_output.txt
	   ./virial_test 0 1  0.5 0.2 30.0 0.2 1
# 	   ./virial_test p25 1  0.5 0.2 30.0 0.2 1
# 	   ./virial_test p5 1  0.5 0.2 30.0 0.2 1
# 	   ./virial_test p75 1  0.5 0.2 30.0 0.2 1
# 	   ./virial_test 1 1  0.5 0.2 30.0 0.2 1
# 	   ./virial_test 2 1  0.5 0.2 30.0 0.2 1
# 	   ./virial_test 3 1  0.5 0.2 30.0 0.2 1
# 	   ./virial_test 4 1  0.5 0.2 30.0 0.2 1
	   
	   
# 	   
#            ./virial_test 0 1  0.5 0.2 30.0 0.2 0
#            ./virial_test p25 1  0.5 0.2 30.0 0.2 0
#            ./virial_test p5 1  0.5 0.2 30.0 0.2 0
#            ./virial_test p75 1  0.5 0.2 30.0 0.2 0
#            ./virial_test 1 1  0.5 0.2 30.0 0.2 0
#            ./virial_test 2 1  0.5 0.2 30.0 0.2 0
#            ./virial_test 3 1  0.5 0.2 30.0 0.2 0
#            ./virial_test 4 1  0.5 0.2 30.0 0.2 0
	  
# 	  gnuplot virial.gnuplot
	  
	  
# 	  g++ -std=c++11 component_virial_test.cpp -o component_virial_test
# # 	  rm virial_output.txt
# 	   ./component_virial_test 0 1  0.5 0.2 30.0 0.2 1
# 	   ./component_virial_test 1 1  0.5 0.2 30.0 0.2 1
# 	   ./component_virial_test 2 1  0.5 0.2 30.0 0.2 1
# 	   ./component_virial_test 3 1  0.5 0.2 30.0 0.2 1
# 	   ./component_virial_test 4 1  0.5 0.2 30.0 0.2 1


# 	    g++ -std=c++11 rho_test.cpp -o rho_test
# 	    ./rho_test 0 1  0.5 0.2 30.0 0.2 1
	    
	    gnuplot virial.gnuplot