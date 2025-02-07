#include <iostream>
#include <cmath>

class Root {
public:
	virtual void calculate() = 0;
};

class Linear : public Root {
private:
	double a, b;

public:
	Linear(double A, double B) : a(A), b(B) {}

	void calculate() override {
		if (a == 0) {
			if (b == 0) {
				std::cout << "Linear: infinitely many solutions" << std::endl;
			}
			else {
				std::cout << "Linear: no solutions" << std::endl;
			}
		}
		else {
			double x = -b / a;
			std::cout << "Linear solution: " << x << std::endl;
		}
	}
};

class Binary : public Root {
private:
	double a, b, c;

public:
	Binary(double A, double B, double C) : a(A), b(B), c(C) {}

	void calculate() override {
		if (a == 0) {
			std::cout << "Binary: this is not a quadratic equation" << std::endl;
		}

		double D = (b * b) - 4 * a * c;
		if (D > 0) {
			double x1 = (-b + sqrt(D)) / (2 * a);
			double x2 = (-b - sqrt(D)) / (2 * a);
			std::cout << "Binary: x1 = " << x1 << " x2 = " << x2 << std::endl;
		}
		else if (D == 0) {
			double x = (-b) / (2 * a);
			std::cout << "Binary: x1 = " << x << std::endl;
		}
		else {
			std::cout << "Binary: no roots" << std::endl;
		}
	}
};

int main() {
	Linear obj1(5, -7);
	obj1.calculate();

	Binary obj2(1, -3, 2);
	obj2.calculate();

	return 0;
}