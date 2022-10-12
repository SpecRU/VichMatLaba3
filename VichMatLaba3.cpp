
//gauss function

#include <iostream>

double myexp(double x, bool flag) {
	double x1 = fmod(x, floor(x)), res = 1 + x1, fact = 1, xx = x1, acc = 10 * pow(0.1, 10), add;
	int i = 2;

	do {
		add = (xx*=x) / (fact *= i);
		res += add;
		++i;
	} while (abs(add) > acc);

	if (flag) return res * myexp(floor(x), 0);
	else return res;
}

double gaussacc = 10 * pow(0.1, 100), x = 0.01, gauss, tmp, tmp1;
double sqrt2pi = 1 / sqrt(2 * std::atan(1) * 4);

int main()
{
	while (1) {
		tmp1 = x * x / 2 * -1;
		tmp = myexp(tmp1, 1);
		gauss = sqrt2pi * tmp;

		if (gaussacc >= gauss) {
			break;
		}

		std::cout << gauss << " x=" << x << " exp(" << tmp1 << ")=" << tmp << std::endl;

		x += 0.01;
	}
}