#include"body.h"
#include"nbodysystem.h"
#include"integrator.h"
#include"main.h"


int main() {
	printf("Initializing NBody simulation.\n");
	struct Integrator I=AllocateIntegrator(Trapezium, 0.0);
	struct NBodySystem M=AllocateNBodySystem(3,&I);

	struct Body Body1 = AllocateBody(3);
	Body1.p[0] = 0.0;
	Body1.p[1] = 1.0;
	Body1.p[2] = 2.0;
	Body1.v[0] = 2.0;
	Body1.v[1] = 1.0;
	Body1.v[2] = 0.0;
	Body1.a[0] = 0.0;
	Body1.a[1] = 1.0;
	Body1.a[2] = 2.0;

	struct Body Body2 = AllocateBody(3);
	Body2.p[0] = 0.0;
	Body2.p[1] = 0.0;
	Body2.p[2] = 0.0;
	Body2.v[0] = 0.0;
	Body2.v[1] = 0.0;
	Body2.v[2] = 0.0;
	Body2.a[0] = 0.0;
	Body2.a[1] = 0.0;
	Body2.a[2] = 0.0;

	NBodySystemAddParticle(&M, Body1);
	NBodySystemAddParticle(&M, Body2);

	NBodySystemPrint(&M);
	NBodySystemPrint(&M);

	printf("Finalizing NBody simulation.\n");
	return 0;
}