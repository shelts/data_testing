#! /usr/bin/python
#/* Copyright (c) 2017 Siddhartha Shelton */
import os
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.patches as mpatches
import math as mt

class bin_datas:
    def __init__(self, file_name):
        self.file_name = file_name
        self.counts = []
        self.bins = []
        
        self.get_data()
        
    def get_data(self):
        f = open(self.file_name, 'r')
        
        for line in f:
            line = line.split('\t')
            ns = float(line[0])
            bn = float(line[1])
            self.counts.append(ns)
            self.bins.append(bn)
        f.close()
        
class theory_data:
    def __init__(self, file_name, matter_type = None):
        self.file_name = file_name
        self.x_vals = []
        self.combined = []
        self.light = []
        self.dark = []
        self.matter_type = matter_type
        self.get_data()
        
    def get_data(self):
        f = open(self.file_name, 'r')
        for line in f:
            line = line.split('\t')
            if(len(line) > 2):#for the radial density files
                x = float(line[0])
                c = float(line[1])
                l = float(line[2])
                d = float(line[3])
                self.x_vals.append(x)
                self.combined.append(c)
                self.light.append(l)
                self.dark.append(d)
            elif(self.matter_type == 'light'):#for the vel files
                x = float(line[1])
                l = float(line[0])
                self.x_vals.append(x)
                self.light.append(l)
            elif(self.matter_type == 'dark'):
                x = float(line[1])
                l = float(line[0])
                self.x_vals.append(x)
                self.dark.append(l)    
                
        f.close()
