#include"main.h"
#include"integrator.h"
#include"body.h"
#include"nbodysystem.h"

struct Integrator AllocateIntegrator(enum IntegrationMethod method, double dt){
	struct Integrator I={method, dt};
	return I;
}

struct NBodySystem* IntegratorSolve(struct Integrator* I, struct NBodySystem* M) {

	return M;
}