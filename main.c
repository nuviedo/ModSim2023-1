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

int main(int argn, char **args){

    int N=3;
    double M=2e11; 
	
    printf("%d\n", N);
    printf("%lf\n", M);

    Model model = new_Model("System", N);

    srand((unsigned int)time(0));

    //earth
    add_Particle_to_Model(&model, new_Particle(5.9722e24, 149597871000, 0, 0, 0, 29799.6861, 0));
    //moon
    add_Particle_to_Model(&model, new_Particle(7.4e22, 149597871000, 0, 384399861, 0, 29799.6861, 3683));
    //sun
    add_Particle_to_Model(&model, new_Particle(1.988e30, 0, 0, 0, 0, 0, 0));

    for (int i = 0; i < 20000; i++) {
        if ((i % 50) == 0) {
            printf("#%i\n", i);
            print_Model(model);
        }
        integrate(&model, 1.0*60);
    }

    return 0;
}
