#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	double x, y, z, f, a, c;
	cout << "z=";
	while (true) {
		cin >> z;
		if (cin.fail()) {
			cout << ("Введено не число!");
			cin.clear();
			cin.ignore();
			continue;
		}
		else {
			break;
		}
	}
	if (z >= 0) {
		x = 2 * z + 1;
		cout << "x = 2z + 1;";
	}
	else {
		x = log(pow(z, 2) - z);
		cout << "x = ln(z^2 - z)";
	}
	while (true) {
		if (pow(x, 0.4) <= 0) {
			cout << "Недопустимое значение!";
			cin.clear();
			cin.ignore();
			continue;
		}
		else{
			break;
		}
	}
	cout << "\n" << "1:2x 2:x^2 3:x/3 (любое другое нажатие будет расцениваться как 1):" << "\n";
	switch (_getch()) {
	case '2':
		f = pow(x, 2);
		cout << "f = x^2";
		break;
	case '3':
		f = x / 3.;
		cout << "f = x/3";
		break;
	default:
		f = 2 * x;
		cout << "f = 2x";
	}
	cout << "\n" << "a=";
	while (true) {
		cin >> a;
		if (cin.fail()) {
			cout << ("Введено не число!");
			cin.clear();
			cin.ignore();
			continue;
		}
		else {
			break;
		}
	}
	cout << "c=";
	while (true) {
		cin >> c;
		if (cin.fail()) {
			cout << ("Введено не число!");
			cin.clear();
			cin.ignore();
			continue;
		}
		else {
			break;
		}
	}
	y = pow(sin(f),2)+a*pow(cos(pow(x,3)),5)+c*log(pow(x,0.4));
	cout << "y=" << y;
}