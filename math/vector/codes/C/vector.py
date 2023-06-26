#Python libraries for math and graphics
import numpy as np
import matplotlib.pyplot as plt
from numpy import linalg as LA
import math

#import sys                                          #for path to external scripts
#sys.path.insert(0,'/sdcard/vector')         #path to my scripts

#local imports
#from line.funcs import *
#from triangle.funcs import *
#from conics.funcs import circ_gen

#if using termux
import subprocess
import shlex
#end if


def circ_gen(O,r):
	len = 50
	theta = np.linspace(0,2*np.pi,len)
	x_circ = np.zeros((2,len))
	x_circ[0,:] = r*np.cos(theta)
	x_circ[1,:] = r*np.sin(theta)
	x_circ = (x_circ.T + O).T
	return x_circ

def line_gen(A,B):
  len =10
  dim = A.shape[0]
  x_AB = np.zeros((dim,len))
  lam_1 = np.linspace(0,1,len)
  for i in range(len):
    temp1 = A + lam_1[i]*(B-A)
    x_AB[:,i]= temp1.T
  return x_AB
#Input parameters
AB = np.loadtxt('c_len.dat',dtype='int')
CD = np.loadtxt('c_len.dat',dtype='int')
theta = np.loadtxt('theta.dat',dtype='int')
AD = np.loadtxt('r_len.dat',dtype='int')
DE = np.loadtxt('d_len.dat',dtype='int')
D = np.loadtxt('d.dat',dtype='int')
C = np.loadtxt('c.dat',dtype='int')
A = np.loadtxt('a.dat',dtype='int')
B = np.loadtxt('b.dat',dtype='int')
E = np.loadtxt('e.dat',dtype='int')
F = np.loadtxt('f.dat',dtype='int')



##Generating all lines
xAB = line_gen(A,B)
xBC = line_gen(B,C)
xCD = line_gen(C,D)
xDA = line_gen(D,A)

xCF = line_gen(C,F)
xAE = line_gen(A,E)



#Plotting all lines
plt.plot(xAB[0,:],xAB[1,:])
plt.plot(xBC[0,:],xBC[1,:])
plt.plot(xCD[0,:],xCD[1,:])
plt.plot(xDA[0,:],xDA[1,:])

plt.plot(xCF[0,:],xCF[1,:])
plt.plot(xAE[0,:],xAE[1,:])



#Labeling the coordinates
tri_coords = np.vstack((A,B,C,D,E,F)).T
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels = ['A','B','C','D','E','F']
for i, txt in enumerate(vert_labels):
    plt.annotate(txt, # this is the text
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(-5,10), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can be left, right or center



plt.xlabel('$x-axis$')
plt.ylabel('$y-axis$')
#plt.legend(loc='best')
plt.grid() # minor
plt.axis('equal')
plt.show()
plt.text(15, 8.25, '16 cm', fontsize = 11, color='Red')
plt.text(11, 1.5, '10 cm', fontsize = 11, color='Red', rotation=-30)
plt.text(10.25, 4.5, '8 cm', fontsize = 11, color='Red',rotation=90)

#plt.savefig('fig 1.jpeg')
plt.savefig('/sdcard/vectors/fig1.png')
#subprocess.run(shlex.split("termux-open '/sdcard/vectors/fig1.pdf'"))
