# Solar System Simulation
### Affiliation
![fondo-web2-10A-ENES](https://user-images.githubusercontent.com/100146672/160222385-4576c60e-1005-4753-b34d-c5461658c11b.png)

Final Project for the Modelling & Simulation 2023-1 class, taught by Dr. Victor de la Luz at the _Universidad Nacional Autónoma de México_ (National Autonomous University of México | UNAM), in its _Escuela Nacional de Estudios Superiores Unidad Morelia_ Campus (National School of Superior-Level Studies, _Morelia_ Campus | ENES Morelia), as part of its _Licenciatura en Tecnologías para la Información en Ciencias_ career plan (Bs. in Information Technologies applied to Science | L.T.I.C.).

> Alexis Nuviedo ([@nuviedo](https://github.com/nuviedo))
> 
> Jadiel Zuñiga ([@jzrodriguez](https://github.com/jzrodriguez))
> 
> Mariela Arias ([@marielaariass](https://github.com/marielaariass))

The contents of this repository are licensed under the GNU General Public License version 3. Visit https://www.gnu.org/licenses/gpl-3.0.html for more information.

### Introduction
The following project details the design & implementation of an N-Body Simulation that describes the movement of the Solar System using initial conditions derived from the current day.
This came to our attention given the desire to experiment with the boundaries of N-Body Simulation for large scale bodies in class, alongside the difficulties in doing an accurate simulation.

An N-Body simulation is a numerical approximation to solving the problem that arises when attempting to simulate interconnected motion between more than two physical bodies, given that their interactions do not occur in any specific order.
This is done by numerically solving the gravitational force equation, as follows:
![image](https://user-images.githubusercontent.com/100146672/203605111-e581d76a-ac51-4af1-96f3-205f15b4a46b.png)


### Objective
The aim of this project is to produce a video of a graph which models the 3D positions in space of the Sun, the Earth and the Moon in Solar System over a specified period of time.


### Libraries
The project is expected to be developed making use of pure ANSI C, with just the standard library headers being imported.
The majority of the code was adapted from [Dr. Victor de la Luz' classwork](https://github.com/itztli/nobody2023-1), with heavy optimizations to permit a faster execution time on low delta t's.

### Methodology
The existing N-body simulator was partially rewritten to allow for faster integration by eliminating unnecessary decisions during particle initialization and integration. The initial condition values were hand-picked from the [NOAA's ESRL](https://www.esrl.noaa.gov/) database so to obtain specific information to work with, and then adapted to the model in hand.

### Run
To execute the model, simply run execute.py in the main folder.

### Results
The resulting object was made with a modified visor.py that displays the model rotating in 3D, as follows:
![nbody](https://user-images.githubusercontent.com/100146672/203606557-8eb96385-d7e9-4e15-9044-30482d9c38fc.gif)

It is easy to appreciate that the earth and moon remain in relative close proximity within expected parameters for their usual behavior.

### Conclusions
While modelling an N-body simulation is not the simplest task in the world, given the appropriate approach it is far from complex to obtain relatively accurate results to real life behavior.

### References
Real-Time, Real Data | NASA Solar system overview

https://solarsystem.nasa.gov/resources/2515/real-time-real-data/

