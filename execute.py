import subprocess

def optional_input(prompt,default):
    print(prompt,end=f" (DEFAULT {default}): ")
    x=input()
    try:
        x=float(x)
    except:
        x=default
    return x

#Bodies=optional_input("Number of bodies",15)
#M=optional_input("Cube side length",10000000)
#VMax=optional_input("Maximum initial velocity",100)
#Mass=optional_input("Particle mass",10000000000000000000000)
print("Running model")
#result=subprocess.run(f".\\x64\\Debug\\NobodyWIN64.exe {Bodies} {M} {VMax} {Mass} > result.bin",shell=True)
#result=subprocess.run(f".\\x64\\Debug\\NobodyWIN64.exe > result.bin",shell=True)
result=subprocess.run(f"./NobodyWIN64 > result.bin",shell=True)

subprocess.run(f"rm ./video/*",shell=True)
print("Generating frames")
#import visor3D
import v3d2

print("Joining frames")
subprocess.run(f"convert -delay 3 -loop 0 video/*.png nbody.gif",shell=True)
print("OK")
