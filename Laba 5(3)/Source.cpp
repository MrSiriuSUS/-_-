#include <iostream>
using namespace std;

int sqr(int x, int **a) {
	int sum, sumx{};
	for (int i = 0; i <= x - 1; i++) {
		sum = 0;
		for (int j = 0; j <= x - 1; j++) {
			sum += a[i][j];
		}
		sumx = sum;
		const int sumx = sum;
		if (sumx != sum) {
			cout << "Не магический квадрат!";
			return 0;
		}
	}
	for (int j = 0; j <= x - 1; j++) {
		sum = 0;
		for (int i = 0; i <= x - 1; i++) {
			sum += a[i][j];
		}
		if (sumx != sum) {
			cout << "Не магический квадрат!";
			return 0;
		}
	}
	cout << "Магический квадрат, сумма элементов по вертикали и по горизонтали которого равна: ";
	return sumx;
}

int main() {
	int x;
	setlocale(LC_ALL, "Russian");
	while (true) {
		cout << "Введите порядок магического квадрата: ";
		cin >> x;
		if (cin.fail()) {
			cout << "Введено не число!" << "\n";
			cin.clear();
			cin.ignore();
			continue;
		}
		else
		{
			break;
		}
	}
	int** a = new int* [x];
	for (int i = 0; i <= x - 1; i++) {
		a[i] = new int[x];
	}
	for (int i = 0; i <= x - 1; i++) {
		for (int j = 0; j <= x - 1; j++) {
			while (true) {
				cout << "Введите элемент " << j + 1 << " столбца " << i + 1 << " строки: ";
				cin >> a[i][j];
				if (cin.fail()) {
					cout << "Введено не число! Введите повторно." << "\n";
					cin.clear();
					cin.ignore();
					continue;
				}
				else {
					break;
				}
			}
		}
	}
	for (int i = 0; i <= x - 1; i++) {
		cout << "[ ";
		for (int j = 0; j <= x - 1; j++) {
			cout << a[i][j] << " ";
		}
		cout << " ]" << "\n";
	}
	sqr(x, a);
	cout << "\n";

	for (int i = 0; i <= x - 1; i++) {
		for (int j = 0; j <= x - 2; j++) {
			for (int j = 0; j <= x - 2; j++) {
				if (a[i][j + 1] < a[i][j]) {
					int h = a[i][j];
					a[i][j] = a[i][j + 1];
					a[i][j + 1] = h;
				}
			}
		}
	}

	for (int i = 0; i <= x - 1; i++) {
		cout << "[ ";
		for (int j = 0; j <= x - 1; j++) {
			cout << a[i][j] << " ";
		}
		cout << " ]" << "\n";
	}
	for (int i = 0; i <= x - 1; i++){
		delete a[i];
	}
	delete[] a;
}