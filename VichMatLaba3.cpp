
//gauss function

#include <iostream>

double myexp(double x) {
	double res = 1 + x, fact = 1, xx = x, acc = 0.00001, add;
	int i = 2;

	do {
		add = (xx*=x) / (fact *= i);
		res += add;
		++i;
	} while (abs(add) > acc);

	return res;
}

double gaussacc = 0.0001, x = 0, gauss;
double sqrt2pi = 1 / sqrt(2 * std::atan(1) * 4);

int main()
{
	while (1) {
		gauss = sqrt2pi * myexp(x*x / 2 * -1);

		if (gauss <= gaussacc) {
			break;
		}

		std::cout << gauss << " x=" << x << std::endl;

		x += 0.01;
	}
}