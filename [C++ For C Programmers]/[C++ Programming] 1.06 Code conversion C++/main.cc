/* IN C

#include <stdio.h>
#include <math.h>

double fcn(double x)
{ return (x * x - 1);}

double fcn2(double x)
{ return (x*x*x*x*x - exp(x)-2);}

double root_find(
		double f(double), // functin with root
		double a, double b, //interval (a, b) with root
		double eps,			//accuracy
		double *root		// root --output
)
{
	if(b - a < eps){
		*root = (b + a)/2.0;
		return (f(*root));
	}
	else if(f(a)*f((b + a)/2) <= 0){
		return (root_find(f, a, (b+a)/2, eps, root));
	}
	else{
		return (root_find(f, (b+a)/2, b, eps, root));
	}
}

int main(void)
{
	double x;

	printf("Root finder\n");
	root_find(fcn, 0.0, 4.0, 0.00001, &x);
	printf("root is at %g with residual %g \n", x, fcn(x));
	root_find(fcn2, 0.0, 14.0, 0.00001, &x);
	printf("root is at %g\n", x);
	return (0);

}
*/

#include <iostream>
#include <cmath>

inline double fcn(double x)
{ return (x * x - 1);}

inline double fcn2(double x)
{ return (x*x*x*x*x - exp(x)-2);}

double root_find(
		double f(double), /* functin with root */
		double a, double b, /*interval (a, b) with root*/
		double eps,			/*accuracy*/
		double *root)		/* root --output*/
{
	if(b - a < eps){
		*root = (b + a)/2.0;
		return (f(*root));
	}
	else if(f(a)*f((b + a)/2) <= 0){
		return (root_find(f, a, (b+a)/2, eps, root));
	}
	else{
		return (root_find(f, (b+a)/2, b, eps, root));
	}
}

int main(void)
{
	using namespace std;
	double x;

	cout << "Root finder" << endl;
	root_find(fcn, 0.0, 4.0, 0.00001, &x);
	cout << "root is at " << x
		 << " with residual " << fcn(x)
		 << endl;
	root_find(fcn2, 0.0, 14.0, 0.00001, &x);
	cout << "root is at " << x;
	return (0);

}
