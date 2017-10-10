#include "act.h"
const double e = 0.000001;

double Integrate(double a, double b, double s, double t){
	
	double h = (b - a) * e, result;
	result += (Algorithm(s, a) + Algorithm(s, a)) * t / 2;
	for(int i = 1; i < 1/e; ++i){
		result += Algorithm(s, i*h) * t;
	}
	return (result * h);
}