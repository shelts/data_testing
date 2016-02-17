#! /usr/bin/python
import os
from subprocess import call
import sys
args = sys.argv;

s = str( args[1] )
d = "./"
os.system("mv " + s + "/actual "      + d)
os.system("mv " + s + "/binned_data " + d)
os.system("mv " + s + "/plots "       + d)
os.system("mv " + s + "/raw_data "    + d)
os.system("mv " + s + "/sim_outputs " + d)
os.system("mv " + s + "/test_output " + d)
os.system("mv " + s + "/theory "      + d)
