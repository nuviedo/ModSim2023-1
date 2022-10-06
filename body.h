#pragma once

struct Body {
	int dim;
	double* p;
	double* v;
	double* a;
};

struct Body AllocateBody(int Dimensions);

void DeallocateBody(struct Body* B);
