#include"main.h"
#include"integrator.h"
#include"body.h"
#include"nbodysystem.h"

struct NBodySystem AllocateNBodySystem(int BodyCount, struct Integrator* I) {
	struct NBodySystem S = {BodyCount,0,0};
	S.bodies = (struct Body*)malloc(BodyCount * sizeof(struct Body));
	return S;
}

void NBodySystemAddParticle(struct NBodySystem* M, struct Body B) {
	if (M->_next_body_to_add == M->body_count) {
		printf("Attempt to add particle to a model that is already full.");
		return;
	}
	M->bodies[M->_next_body_to_add] = B;
	M->_next_body_to_add += 1;
}

void NBodySystemPrint(struct NBodySystem* M) {
	printf("---NBODY_MODEL_START---\n");
	for (int i = 0; i < M->_next_body_to_add; i++) {
		struct Body* B = &(M->bodies[i]);
		printf("(Body<%p> ", (void*)B);
		printf("[");
		for (int j = 0; j < B->dim; j++) {
			printf("%.04f",B->p[j]);
			if (j != B->dim-1) {
				printf(", ");
			}
		}
		printf("]");
		printf("[");
		for (int j = 0; j < B->dim; j++) {
			printf("%.04f", B->v[j]);
			if (j != B->dim - 1) {
				printf(", ");
			}
		}
		printf("]");
		printf("[");
		for (int j = 0; j < B->dim; j++) {
			printf("%.04f", B->a[j]);
			if (j != B->dim - 1) {
				printf(", ");
			}
		}
		printf("])\n");
	}
	printf("---NBODY_MODEL_END---\n");
}

void DeallocateNBodySystem(struct NBodySystem* M) {
	for (int i = 0; i < M->_next_body_to_add; i++) {
		DeallocateBody(&(M->bodies[i]));
	}
	free(M->bodies);
}