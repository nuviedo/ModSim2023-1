#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D

with open('result.bin') as f:
    lines = f.readlines()

data = []

for line in lines:
    if line[0] != '#':
        data.append(line)

n_particles = int(data[0])
M = float(data[1])
data.pop(1)
print("Rendering frames")

N = len(data)
a = b = k = 0



plt.style.use('dark_background')
fig = plt.figure()
while True:
    a = 1 + n_particles*k
    b = n_particles*(k+1)
    if b >= N:
        break
    #print(b,N)
    k = k + 1
    ax = fig.add_subplot()#projection='3d')
    #ax.view_init(20,k)
    subset = np.arange(a,b+1,1)
    ax.set_xlabel('X Label')
    ax.set_ylabel('Y Label')
    #ax.set_zlabel('Z Label')
    plt.xlim([-M, M])
    plt.ylim([-M, M])
    #ax.set_zlim([-M, M])
    ax.set_xlabel('X axis')
    ax.set_ylabel('Y axis')
    #ax.set_zlabel('Z axis')
    
    for p in subset:
        ms,xs,ys,zs,vxs,vys,vzs = data[p].split()
        m = float(ms)
        x = float(xs)
        y = float(ys)
        z = float(zs)
        vx = float(vxs)
        vy = float(vys)
        vz = float(vzs)
        #print(x,y,z)   
        ax.scatter(x, y)#, z)
    plt.savefig(f"video/f_{k:03d}.png")
    plt.clf()
    if(k%10==0):
        print(f"f_{k:03d}.png")
    

