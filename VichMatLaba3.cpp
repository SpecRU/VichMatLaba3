
//gauss function

#include <iostream>

double myexp(double x) {
	double res = 1 + x, fact = 1, xx = x, acc = 333;

	for (int i = 2; i < acc + 2; ++i) {
		res += (xx*=x) / (fact *= i);
	}

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