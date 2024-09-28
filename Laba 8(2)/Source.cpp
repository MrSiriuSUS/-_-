#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

double S(double x, double n) {
	double r = 1, s = 1;
	for (double k = 1; k <= n; k++) {
		r *=  2 * x / k;
		s += r;
	}
	return s;
}

double Y(double x) {
	return exp(2 * x);
}

double Modul(double s, double y) {
	double m = abs(y - s);
	return m;
}

void Out_Rez(double F, double a, double b, double h, double x) {
		cout << "x = " << x << "\t" << F << "\n";
}

double Vvod(double a) {
	while (true) {
		cin >> a;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Введено не число, повторите ввод:\n";
			continue;
		}
		else {
			break;
		}
	}
	return a;
}

int main() {
	double s = 1, y = 1, n{}, a{}, b{}, h{};
	setlocale(LC_ALL, "Russian");
	cout << "Нажмите 1, чтобы ввести данные из методички, иначе ввод с клавиатуры\n";
	switch (_getch()) {
	case '1':
		a = 0.1;
		b = 1.;
		h = 0.1;
		break;
	default:
		a = Vvod(a);
		b = Vvod(b);
		h = Vvod(h);
	}

	n = Vvod(n);
	cout << "1 - S(x)\n2 - Y(x)\n3 - |Y(x) - S(x)|\nлюбое другое нажатие выведет значения всех функций:\n";
	switch (_getch()) {
	case '1':
		for (double x = a; x <= b; x += h) {
			Out_Rez(S(x, n), a, b, h, x);
		}
		break;
	case '2':
		for (double x = a; x <= b; x += h) {
			Out_Rez(Y(x), a, b, h, x);
		}
		break;
	case '3':
		for (double x = a; x <= b; x += h) {
			Out_Rez(Modul(S(x, n), Y(x)), a, b, h, x);
		}
	}
}