#include "body.h"
const double e = 0.000001;

double Integr(double a, double b, double s, double t){
	
	double h = (b - a) * e, result;
	result += (Algorithm(t, a) + Algorithm(t, a)) / 2;
	for(int i = 1; i < 1/e; ++i){
		result += Algorithm(t, i*h);
	}
	return (result * h);
}