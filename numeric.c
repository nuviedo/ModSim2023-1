// Author: Victor De la Luz
// vdelaluz@enesmorelia.unam.mx
// GNU/Linux

#include <stdio.h>
#include <stdlib.h>
#include "numeric.h"
#include "model.h"
#include "physics.h"


void integrate(Model *model, double dt){
	double x1,y1,z1,x2,y2,z2,m1,m2;
	double r;
	vector3D u;
  

	for (int i=0; i< model->i;i++){
		m1 = model->particles[i].mass;
		x1 = model->particles[i].p[0];
		y1 = model->particles[i].p[1];
		z1 = model->particles[i].p[2];	

		for (int j=0; j< model->i;j++){
			if (i!=j){
				m2 = model->particles[j].mass;
				x2 = model->particles[j].p[0];
				y2 = model->particles[j].p[1];
				z2 = model->particles[j].p[2];

				r = R(x1,y1,z1,x2,y2,z2);
				u = U(x1,y1,z1,x2,y2,z2);

				model->particles[i].v[0] += E1D(m2,r,u.x)*dt;
				model->particles[i].v[1] += E1D(m2,r,u.y)*dt;
				model->particles[i].v[2] += E1D(m2,r,u.z)*dt;
			}	  
		}

		for (int i=0; i< model->i;i++){
			model->particles[i].p[0] += model->particles[i].v[0] * dt;
			model->particles[i].p[1] += model->particles[i].v[1] * dt;
			model->particles[i].p[2] += model->particles[i].v[2] * dt;		
		}
	}
}


double randd(double a, double b) {
	return a + (b - a) * ((double)rand() / (double)RAND_MAX);
}