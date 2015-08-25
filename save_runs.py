#! /usr/bin/python
import os
from subprocess import call
import sys
args = sys.argv;

def __main__(arg):

    s = str( args[1] )
    
    os.system("mkdir " + s)
    
    os.system("mv actual "      + s)
    os.system("mv binned_data " + s)
    os.system("mv plots "       + s)
    os.system("mv raw_data "    + s)
    os.system("mv sim_outputs " + s)
    os.system("mv test_output " + s)
    os.system("mv theory "      + s)



__main__(args);