#pragma once

enum IntegrationMethod {
	Trapezium,
};

struct Integrator {
	enum IntegrationMethod method;
	double dt;
};

struct Integrator AllocateIntegrator(enum IntegrationMethod method, double dt);