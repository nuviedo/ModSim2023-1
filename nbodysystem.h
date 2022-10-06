#pragma once
#include"main.h"
#include"integrator.h"
#include"body.h"

struct NBodySystem {
	int body_count;
	struct Body* bodies;
	int _next_body_to_add;
};

struct NBodySystem AllocateNBodySystem(int BodyCount, struct Integrator* I);

void NBodySystemAddParticle(struct NBodySystem* M, struct Body B);

void NBodySystemPrint(struct NBodySystem* M);

void DeallocateNBodySystem(struct NBodySystem* M);
