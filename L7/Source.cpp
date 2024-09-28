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
			cout << "\nВведено не корректное значение!\nВведите ещё раз: ";
		}
		else break;
	}
	return x;
}

double F(double x) {
	return pow(sin(x), 2) - x / 5.;
}

double Line_Interpolation(double xt, double* x, double* y, int k) {
	return y[k - 1] + (xt - x[k - 1]) * ((y[k] - y[k - 1]) / (x[k] - x[k - 1]));
}

double Squer_Interpolation(double xt, double* x, double* y, int k) {
	double N1 = y[k - 1] + (xt - x[k - 1]) * ((y[k] - y[k - 1]) / (x[k] - x[k - 1]));
	return N1 + (xt - x[k - 1]) * (xt - x[k]) * ((((y[k - 1] - y[k]) / (x[k - 1] - x[k])) - ((y[k] - y[k + 1]) / (x[k] - x[k + 1]))) / (x[k - 1] - x[k + 1]));

}

void main() {
	setlocale(LC_ALL, "ru");
	while (true) {
		double a = 0, b = 0, m = 0, h = 0, * m_x = new double[50], * m_y = new double[50], * y_t = new double[50], x = 0;
		cout << "\n1 - Квадратичная интерполяция\n2 - Линейная интерполяция\n0 - Выход\n";
		switch (_getch()) {
		case '0':
			return;
		case '1':
			cout << "\n1 - Ввести данные из методички\nИначе ввод данных вручную\n";
			switch (_getch()) {
			case '1':
				a = 0.;
				b = 4.;
				m = 11.;
				cout << "\na (Начало) = " << a << "\tb (Конец) = " << b << "\tm (Количество точек) = " << m << "\n";
				break;
			default:
				cout << "a (Начало) = ";
				a = Input();
				cout << "b (Конец) = ";
				b = Input();
				cout << "m (Количество точек) = ";
				m = Input();
			}
			h = (b - a) / (m - 1);
			x = a;
			for (int i = 0; i < m + 1; i++) {
				m_x[i] = x;
				m_y[i] = F(x);
				x += h;
			}
			x = a;
			for (int i = 0; i < m; i++) {
				int k = i + 1;
				y_t[i] = Squer_Interpolation(x, m_x, m_y, k);
				cout << "\t\tx = " << x << "\t\tf(x) = " << m_y[i] << "\t\tf*(x) = " << y_t[i] << "\n";
				x += h;
			}
			break;
		case '2':
			cout << "\n1 - Ввести данные из методички\nИначе ввод данных вручную\n";
			switch (_getch()) {
			case '1':
				a = 0.;
				b = 4.;
				m = 11.;
				cout << "\na (Начало) = " << a << "\tb (Конец) = " << b << "\tm (Количество точек) = " << m << "\n";
				break;
			default:
				cout << "a (Начало) = ";
				a = Input();
				cout << "b (Конец) = ";
				b = Input();
				cout << "m (Количество точек) = ";
				m = Input();
			}
			h = (b - a) / (m - 1);
			x = a;
			for (int i = 0; i < m + 1; i++) {
				m_x[i] = x;
				m_y[i] = F(x);
				x += h;
			}
			x = a;
			for (int i = 0; i < m; i++) {
				int k = i + 1;
				y_t[i] = Line_Interpolation(x, m_x, m_y, k);
				cout << "\t\tx = " << x << "\t\tf(x) = " << m_y[i] << "\t\tf*(x) = " << y_t[i] << "\n";
				x += h;
			}
		}
		delete[] m_x;
		delete[] m_y;
		delete[] y_t;
	}
}