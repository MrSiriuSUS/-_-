#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

int Out_Rez(double x, double y, int i) {
	cout << i << ": " << "x = " << x << "Y(x) = " << y << "\n";
	i++;
	return i;
}

int main() {
	setlocale(LC_ALL, "Russian");
	double a, b, h, y, x, const PI = acos(-1);
	int i = 1;
	cout << "Нажмите 1, чтобы ввести данные из методички, иначе ввод с клавиатуры" << "\n";
	switch (_getch()) {
	case '1':
		a = -0.3 * PI;
		cout << "a = -0.3*PI = " << a << "\n";
		b = 1.3 * PI;
		cout << "b = 1.3*PI = " << b << "\n";
		h = PI / 10.;
		cout << "h = PI / 10 = " << h << "\n";
		break;
	default:
		cout << "a = ";
		cin >> a;
		cout << "b = ";
		cin >> b;
		cout << "h = ";
		cin >> h;
	}
	for (x = a; x <= b; x += h) {
		y = exp(x) * sin(x);
		i = Out_Rez(x, y, i);
	}
}