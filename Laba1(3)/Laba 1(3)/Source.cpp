#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
		double x, y, z, f;
		cout << "������� 1, ����� �������� �� ���������� �� ���������. ����� ���� ����� � ����������.";
		if (_getch() != '1'){
			cout << "x = ";
			while (true) {
				cin >> x;
				if (cin.fail()) {
					cout << ("������� �� �����!");
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
					cout << ("������� �� �����!");
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
					cout << ("������� �� �����!");
					cin.clear();
					cin.ignore();
					continue;
				}
				else {
					break;
				}
			}
			if (atan(x) + atan(z) != 0 && y > 0) {
				f = exp(abs(x - y)) * pow(abs(x - y), (x + y)) / ((atan(x) + atan(z))) + pow(pow(x, 6) + pow(log(y), 2), (1. / 3.));
				cout << "f = " << f;
			}
			else
			{
				cout << "������������ ��������!";
			}
		}
		else {
			x = -2.235e-2;
			y = 2.23;
			z = 15.221;
			f = exp(abs(x - y)) * pow(abs(x - y), (x + y)) / ((atan(x) + atan(z))) + pow(pow(x, 6) + pow(log(y), 2), (1. / 3.));
			cout << "\n" << "x = " << x << "\n" << "y = " << y << "\n" << "z = " << z << "\n" << "f = " << f;
		}
	return 0;
}