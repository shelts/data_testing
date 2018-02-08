#! /usr/bin/python
import os
from subprocess import call
import sys
args = sys.argv;


option = str(args[1])
s = str( args[2] )



if(option == 'save'):
    os.system("mkdir " + s)

    os.system("mv actual "      + s)
    os.system("mv binned_data " + s)
    os.system("mv plots "       + s)
    os.system("mv raw_data "    + s)
    os.system("mv sim_outputs " + s)
    os.system("mv test_output " + s)
    os.system("mv theory "      + s)
    
if(option == 'recall'):

    d = "./"
    os.system("mv " + s + "/actual "      + d)
    os.system("mv " + s + "/binned_data " + d)
    os.system("mv " + s + "/plots "       + d)
    os.system("mv " + s + "/raw_data "    + d)
    os.system("mv " + s + "/sim_outputs " + d)
    os.system("mv " + s + "/test_output " + d)
    os.system("mv " + s + "/theory "      + d)
