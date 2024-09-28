#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;
int main() {
	double s, r, y, a, b, h, x, k, n;
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
	cout << "n = ";
	cin >> n;
	for (x = a; x <= b; x += h) {
		k = 1;
		s = 1;
		r = 1;
		for (k = 1; k <= n; k++) {
			r = r * (2 * x) / k;
			s += r;
		}
		y = exp(2 * x);
		cout << i << ": " << "x = " << x << ": " << "S(x) = " << s << " Y(x) = " << y << " |Y(x) - S(x)| = " << abs(y - s) << "\n";
		i++;
	}
}