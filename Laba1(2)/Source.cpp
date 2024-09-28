#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	double a, z1, z2;
	cout << "a=";
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
		if (a + 2 > 0) {
			z1 = (sqrt(2 * a + 2 * sqrt(pow(a, 2) - 4))) / (sqrt(pow(a, 2) - 4) + a + 2);
			z2 = 1/(sqrt(a+2));
			cout << "z1=" << z1;
			cout << "\n";
			cout << "z2=" << z2;
	}
		else {
			cout << "Недопустимое значение!";
		}
}