#include <math.h>

double Algorithm(double t, double x) {
	double result;
	result = pow(t + pow(x, 3), 0.2);
	return result;
}