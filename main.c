// Author: Victor De la Luz
// vdelaluz@enesmorelia.unam.mx
// GNU/GPL

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "numeric.h"
#include "model.h"
#include "physics.h"
#include "particle.h"

//MKS system
const int K = 1000;
const int M = 1000000;

void print_model_compact(Model* model) {
    for (int i = 0; i < model->i; i++) {
        Particle* p=&(model->particles[i]);
        printf("%lf %lf %lf\n", p->p[0], p->p[1], p->p[2]);
    }

}

int main(int argn, char **args){

    int N=3;
    double M=3e11; 
	
    //printf("%d\n", N);
    //printf("%lf\n", M);

    Model model = new_Model("System", N);

    srand((unsigned int)time(0));

    //earth
    add_Particle_to_Model(&model, new_Particle(5.9722e24, 147095000.0*K, 0, 0, 0, 29799.6861, 0));
    //moon
    add_Particle_to_Model(&model, new_Particle(7.4e22, 149597871000, 0, 384399861, 0, 29799.6861, 3683));
    //sun
    add_Particle_to_Model(&model, new_Particle(1.988e30, 0, 0, 0, 0, 0, 0));

    int second = 1;
    int minute = second * 60;
    int hour = minute * 60;
    int day = hour * 24;
    int year = day * 365;

    int STEP = hour/4;
    int LENGTH = year;
    int PRINTSTEP = (int)((LENGTH) / STEP * .005);

    //ENVVARS
    printf("%d %lf %d %d %d\n", model.i, M, STEP, LENGTH, PRINTSTEP);

    for (int i = 0; i < LENGTH/STEP; i++) {
        if ((i % PRINTSTEP) == 0) {
            //printf("#%i\n", i);
            //print_Model(model);
            print_model_compact(&model);
        }
        integrate(&model, STEP);
    }

    return 0;
}
