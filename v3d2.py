#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D

with open('result.bin') as f:
    lines = f.readlines()

data = []
header_line=[float(x) for x in lines[0].split()]
lines.pop(0)
N, M, STEP, LENGTH, PRINTSTEP=header_line
N=int(N)

plt.style.use('dark_background')
fig = plt.figure()

k=0
while(lines):
    ax = fig.add_subplot()#projection='3d')
    #ax.view_init(20,k)
    
    ax.set_xlabel('X Label')
    ax.set_ylabel('Y Label')
    #ax.set_zlabel('Z Label')
    plt.xlim([-M, M])
    plt.ylim([-M, M])
    #ax.set_zlim([-M, M])
    ax.set_xlabel('X axis')
    ax.set_ylabel('Y axis')
    #ax.set_zlabel('Z axis')
    
    X=np.zeros(N)
    Y=np.zeros(N)
    Z=np.zeros(N)
    for i in range(N):
        line=lines[0]
        lines.pop(0)
        x,y,z=[float(x) for x in line.split()]
        X[i]=x
        Y[i]=y
        Z[i]=z
    
    ax.scatter(X,Y)
    plt.savefig(f"video/f_{k:03d}.png")
    plt.clf()
    
    k+=1
    if(k%10==0):
        print(f"f_{k:03d}.png")
    
    
