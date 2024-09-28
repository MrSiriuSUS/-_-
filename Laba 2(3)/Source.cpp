#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	double m, max1, max2, x, y, z;
	while (true) {
		while (true) {
			cout << "x = ";
			while (true) {
				cin >> x;
				if (cin.fail()) {
					cout << "Введено не число!";
					cin.clear();
					cin.ignore();
					continue;
				}
				else {
					break;
				}
			}
			cout << "y = ";
			while (true) {
				cin >> y;
				if (cin.fail()) {
					cout << "Введено не число!";
					cin.clear();
					cin.ignore();
					continue;
				}
				else {
					break;
				}
			}
			cout << "z = ";
			while (true) {
				cin >> z;
				if (cin.fail()) {
					cout << "Введено не число!";
					cin.clear();
					cin.ignore();
					continue;
				}
				else {
					break;
				}
			}
			max1 = ((x + y + z) > (x * y * z) ? (x + y + z) : (x * y * z));
			cout << "max1 = " << max1 << "\n";
			max2 = ((x + y + z) > (x / (y * z)) ? (x + y + z) : (x / (y * z)));
			if (max2 == (x / (y * z)) and y * z == 0) {
				cout << "Недопустимое значение для max2, давай по новой:" << "\n";
				cin.clear();
				cin.ignore();
				continue;
			}
			else {
				break;
			}

		}
		cout << "max2 = " << max2 << "\n";
		if (max2 == 0) {
			cout << "Деление на ноль! Введите другие значения:" << "\n";
			cin.clear();
			cin.ignore();
			continue;
		}
		else {
			break;
		}
	}
	m = max1 / max2;
	cout << "m = " << m;
}
