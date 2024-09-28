#include <iostream>
#include <cmath>
using namespace std;
double max(double x, double y) {
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	double x, y, z;
	while (true) {
		cout << "x = ";
		cin >> x;
		cout << "y = ";
		cin >> y;
		cout << "z = ";
		cin >> z;
		if (max(x + y + z, x / (y * z)) == 0 or (y * z) == 0) {
			cout << "Деление на ноль, введите данные ещё раз:" << "\n";
			cin.clear();
			cin.ignore();
			continue;
		}
		else {
			break;
		}
	}
	cout << max(x + y + z, x * y * z) / max(x + y + z, x / (y * z)); ;
}