// 1
//#include <iostream>
//#include <cmath>
//
//class Root {
//public:
//	virtual void calculate() = 0;
//};
//
//class Linear : public Root {
//private:
//	double a, b;
//
//public:
//	Linear(double A, double B) : a(A), b(B) {}
//
//	void calculate() override {
//		if (a == 0) {
//			if (b == 0) {
//				std::cout << "Linear: infinitely many solutions" << std::endl;
//			}
//			else {
//				std::cout << "Linear: no solutions" << std::endl;
//			}
//		}
//		else {
//			double x = -b / a;
//			std::cout << "Linear solution: " << x << std::endl;
//		}
//	}
//};
//
//class Binary : public Root {
//private:
//	double a, b, c;
//
//public:
//	Binary(double A, double B, double C) : a(A), b(B), c(C) {}
//
//	void calculate() override {
//		if (a == 0) {
//			std::cout << "Binary: this is not a quadratic equation" << std::endl;
//		}
//
//		double D = (b * b) - 4 * a * c;
//		if (D > 0) {
//			double x1 = (-b + sqrt(D)) / (2 * a);
//			double x2 = (-b - sqrt(D)) / (2 * a);
//			std::cout << "Binary: x1 = " << x1 << " x2 = " << x2 << std::endl;
//		}
//		else if (D == 0) {
//			double x = (-b) / (2 * a);
//			std::cout << "Binary: x1 = " << x << std::endl;
//		}
//		else {
//			std::cout << "Binary: no roots" << std::endl;
//		}
//	}
//};
//
//int main() {
//	Linear obj1(5, -7);
//	obj1.calculate();
//
//	Binary obj2(1, -3, 2);
//	obj2.calculate();
//
//	return 0;
//}

// 2
#include <iostream>
#include <fstream>

class Shape {
public:
	virtual void Show() const = 0;
	virtual void Save(std::ofstream& out) const = 0;
	virtual void Load(std::ifstream& in) = 0;
	virtual ~Shape() {}
};

class Square : public Shape {
private:
	int x, y, side;

public:
	Square(int x = 0, int y = 0, int s = 1) : x(x), y(y), side(s) {}

	void Show() const override {
		std::cout << "Square: (" << x << ", " << y << ") Side: " << side << std::endl;
	}
	void Save(std::ofstream& out) const override {
		out << "Square " << x << " " << y << " " << side << std::endl;
	}
	void Load(std::ifstream& in) override {
		in >> x >> y >> side;
	}
};

class Rectangle : public Shape {
private:
	int x, y, width, height;
public:
	Rectangle(int x = 0, int y = 0, int w = 1, int h = 1) : x(x), y(y), width(w), height(h) {}
	void Show() const override {
		std::cout << "Rectangle: (" << x << ", " << y << ") W: " << width << " H: " << height << std::endl;
	}
	void Save(std::ofstream& out) const override {
		out << "Rectangle " << x << " " << y << " " << width << " " << height << std::endl;
	}
	void Load(std::ifstream& in) override {
		in >> x >> y >> width >> height;
	}
};

class Circle : public Shape {
private:
	int cx, cy, radius;
public:
	Circle(int cx = 0, int cy = 0, int r = 1) : cx(cx), cy(cy), radius(r) {}
	void Show() const override {
		std::cout << "Circle: Center(" << cx << ", " << cy << ") Radius: " << radius << std::endl;
	}
	void Save(std::ofstream& out) const override {
		out << "Circle " << cx << " " << cy << " " << radius << std::endl;
	}
	void Load(std::ifstream& in) override {
		in >> cx >> cy >> radius;
	}
};

class Ellipse : public Shape {
private:
	int x, y, width, height;
public:
	Ellipse(int x = 0, int y = 0, int w = 1, int h = 1) : x(x), y(y), width(w), height(h) {}
	void Show() const override {
		std::cout << "Ellipse: (" << x << ", " << y << ") W: " << width << " H: " << height << std::endl;
	}
	void Save(std::ofstream& out) const override {
		out << "Ellipse " << x << " " << y << " " << width << " " << height << std::endl;
	}
	void Load(std::ifstream& in) override {
		in >> x >> y >> width >> height;
	}
};

void SaveShapes(Shape* shapes[], int count, const std::string& filename) {
	std::ofstream out(filename);
	for (int i = 0; i < count; ++i) shapes[i]->Save(out);
	out.close();
}

void LoadShapes(Shape* shapes[], int& count, const std::string& filename) {
	std::ifstream in(filename);
	count = 0;
	std::string type;
	while (in >> type && count < 10) {
		if (type == "Square") shapes[count] = new Square();
		else if (type == "Rectangle") shapes[count] = new Rectangle();
		else if (type == "Circle") shapes[count] = new Circle();
		else if (type == "Ellipse") shapes[count] = new Ellipse();
		if (shapes[count]) { shapes[count]->Load(in); count++; }
	}
	in.close();
}

int main() {
	Shape* shapes[10];
	int count = 4;
	shapes[0] = new Square(1, 2, 5);
	shapes[1] = new Rectangle(3, 4, 6, 7);
	shapes[2] = new Circle(5, 5, 10);
	shapes[3] = new Ellipse(2, 3, 8, 4);

	SaveShapes(shapes, count, "shapes.txt");

	for (size_t i = 0; i < count; ++i) { shapes[i]->Show(); delete shapes[i]; }
    
	LoadShapes(shapes, count, "shapes.txt");

	for (size_t i = 0; i < count; i++) { delete shapes[i]; }

	return 0;
}