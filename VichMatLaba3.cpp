
//gauss function

#include <iostream>

double myexp(double x) {
	double res = 1 + x, fact = 1, xx = x, acc = 10 * pow(0.1, 100), add;
	int i = 2;

	do {
		add = (xx*=x) / (fact *= i);
		res += add;
		++i;
	} while (abs(add) > acc);

	return res;
}

double gaussacc = 10 * pow(0.1, 1000), x = -6.23, gauss, tmp, tmp1;
double sqrt2pi = 1 / sqrt(2 * std::atan(1) * 4);

int main()
{
	while (1) {
		tmp1 = x * x / 2 * -1;
		tmp = myexp(tmp1);
		gauss = sqrt2pi * tmp;

		if (gaussacc >= gauss) {
			break;
		}

		std::cout << gauss << " x=" << x << " exp(" << tmp1 << ")=" << tmp << std::endl;

		x += 0.01;
	}
}