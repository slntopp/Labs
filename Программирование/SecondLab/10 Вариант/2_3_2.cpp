#include <iostream>
#include <math.h>

using namespace std;

int main(){
	double x = 0, xn = 2, dx = 0.1, e = 0.000001, cosx = 1, sinx = x, p = 1, fact = 1, pow = 1;

	for(int j = 0; j <= ((xn/dx)+1); ++j){
		int k = 2;
		while(fabs(p) > e){
				for(int i = 1; i <= 2*k; i++) fact *= i;
				for(int i = 1; i <= 2*k; i++) pow *= x;
				p *= (-pow/fact);
				cosx += p;
				fact = pow = 1;
				k++;
			}
		p = k = 1;
		while(fabs(p) > e){
				for(int i = 1; i <= (2*k + 1); i++) fact *= i;	
				for(int i = 1; i <= (2*k + 1); i++) pow *= x;
				p *= (-pow/fact);
				sinx += p;
				fact = pow = 1;
				k++;	
			}
		cout << "x - " << x << " y - " << (sinx + cosx) << " math.h - " << (cos(x)+sin(x)) << endl;
		x += dx;
		cosx = p = 1;
		sinx = x;
	}

	return 0;
}