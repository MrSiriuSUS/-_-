#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;
double sum(double x, double y, double k, double r, double s) {
	//while (true) {
	if (abs(y - s) >= 0.0001) {
		r *= (2 * x) / k;
		s += r;
		k++;
		//continue;
		return sum(x, y, k, r, s);
	}
	else {
		//break;
		//}
		return s;
	}
}
double Y(double x, double y) {
	y = exp(2 * x);
	return y;
}
int main() {
	double s, r, y = 1, a, b, h, x, k;
	int i = 1;
	setlocale(LC_ALL, "Russian");
	cout << "Нажмите 1, чтобы ввести данные из методички, иначе ввод с клавиатуры" << "\n";
	switch (_getch()) {
	case '1':
		a = 0.1;
		b = 1;
		h = 0.1;
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
		k = 1;
		s = 1;
		r = 1;
		cout << i << ": " << "x = " << x << ": " << "\t" << "S(x) = " << sum(x, Y(x, y), k, r, s) << "\t" << " Y(x) = " << Y(x, y) << "\t" << " |Y(x) - S(x)| = " << abs(Y(x, y) - sum(x, Y(x, y), k, r, s)) << "\n";
		i++;
	}
	cout << "Конец вычислений.";
}