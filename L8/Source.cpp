#include <iostream>
#include <conio.h>
using namespace std;

double Input() {
	double x;
	while (true) {
		cin >> x;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "\n������� �� ���������� ��������!\n������� ��� ���: ";
		}
		else break;
	}
	return x;
}

double F(double x) {
	return pow(sin(x), 2) - x / 5.;
}

double Metod_Trapeciy(double a, double b, double n) {
	double s = 0, h = (b - a) / n, x = a;
	for (int i = 0; i <= n - h; i++) {
		s += (F(x) + F(x + h)) / 2.;
		x += h;
	}
	return s * h;
}

double Metod_Srednih(double a, double b, double n) {
	double s = 0, h = (b - a) / n, x = a;
	for (int i = 0; i <= n - h; i++) {
		s += F(x + h / 2.);
		x += h;
	}
	return s * h;
}

void main() {
	setlocale(LC_ALL, "ru");
	while (true) {
		cout << "\n������� ����� �������, ����� ������\n0 - ������� ���������\n";
		switch (_getch()) {
		case '0':
			return;
		default:
			double a = 0, b = 0, epsilon = 0, n = 0, h = 0, In = 0, In2 = 0, pogr = 0;
			cout << "1 - ����� ��������\n2 - ����� �������\n";
			switch (_getch()) {
			case '1':
				cout << "\n1 - ���� ������ �� ���������\n����� ���� ������ � ������\n";
				switch (_getch()) {
				case '1':
					a = 0.;
					b = 4.;
					epsilon = 1e-7;
					n = 2.;
					In2 = Metod_Trapeciy(a, b, n);
					do {
						n *= 2.;
						In = Metod_Trapeciy(a, b, n);
						pogr = fabs(In - In2);
						In2 = In;
					} while (pogr > epsilon);
					break;
				default:
					cout << "a = ";
					a = Input();
					cout << "b = ";
					b = Input();
					cout << "\n1 - ������ ����� ���������\n����� ������ �����������\n";
					switch (_getch()) {
					case '1':
						cout << "n (����� ���������) = ";
						n = Input();
						In = Metod_Trapeciy(a, b, n);
						break;
					default:
						cout << "epsilon (�����������) = ";
						epsilon = Input();
						n = 2.;
						do {
							n *= 2.;
							In = Metod_Trapeciy(a, b, n);
							pogr = fabs(In - In2);
							In2 = In;
						} while (pogr > epsilon);
					}
				}
				break;
			case '2':
				cout << "\n1 - ���� ������ �� ���������\n����� ���� ������ � ������\n";
				switch (_getch()) {
				case '1':
					a = 0.;
					b = 4.;
					epsilon = 1e-7;
					n = 2.;
					In2 = Metod_Srednih(a, b, n);
					do {
						n *= 2.;
						In = Metod_Srednih(a, b, n);
						pogr = fabs(In - In2);
						In2 = In;
					} while (pogr > epsilon);
					break;
				default:
					cout << "a = ";
					a = Input();
					cout << "b = ";
					b = Input();
					cout << "\n1 - ������ ����� ���������\n����� ������ �����������\n";
					switch (_getch()) {
					case '1':
						cout << "n (����� ���������) = ";
						n = Input();
						In = Metod_Srednih(a, b, n);
						break;
					default:
						cout << "epsilon (�����������) = ";
						epsilon = Input();
						n = 2.;
						do {
							n *= 2.;
							In = Metod_Srednih(a, b, n);
							pogr = fabs(In - In2);
							In2 = In;
						} while (pogr > epsilon);
					}
				}
			}
			cout << "�������� ���������: " << In;
		}
	}
}