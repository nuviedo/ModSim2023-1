#include"main.h"
#include"body.h"

struct Body AllocateBody(int Dimensions) {
	struct Body B = {Dimensions, 0,0,0};
	B.p = (double*)malloc(sizeof(double) * Dimensions);
	B.v = (double*)malloc(sizeof(double) * Dimensions);
	B.a = (double*)malloc(sizeof(double) * Dimensions);
	return B;
}

void DeallocateBody(struct Body* B) {
	free(B->p);
	free(B->v);
	free(B->a);
}
