#include <math.h>

double Algorithm(double s, double x) {
	double result;
	result = (atan(pow(x, 0.2))) / (x*x + s * sin(x));
	return result;
}