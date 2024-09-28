#include <iostream>
#include <vector>
using namespace std;
int sum(int j, int **a, int x) {
	int s = 0;
	for (int i = 0; i <= x - 1; i++) {
		s += a[i][j];
	}
	return s;
}
int main() {
	setlocale(LC_ALL, "Russian");
	int x, y;
	cout << "Введите количество столбцов: " << "\n";
	cin >> x;
	cout << "Введите количество строк: " << "\n";
	cin >> y;
	int** a = new int* [x];
	for (int i = 0; i <= x - 1; i++) {
		a[i] = new int[y];
	}
	for (int j = 0; j <= y - 1; j++) {
		for (int i = 0; i <= x - 1; i++) {
			cout << "Введите элемент " << i + 1 << " столбца " << j + 1 << " строки: " << "\n";
			cin >> a[i][j];
		}
	}
	for (int j = 0; j <= y - 1; j++) {
		cout << "[ ";
		for (int i = 0; i <= x - 1; i++) {
			cout << a[i][j] << " ";
		}
		cout << " ]" << "\n";
	}
	for (int i = 0; i <= x - 1; i++) {
		for (int j = 0; j <= y - 2; j++) {
			if (sum(j + 1, a, x) > sum(j, a, x)) {
				for (int i = 0; i <= x - 1; i++) {
					int h = a[i][j + 1];
					a[i][j + 1] = a[i][j];
					a[i][j] = h;
				}
			}
		}
	}
	cout << "\nОтсортированная матрица:\n";
	for (int j = 0; j <= y - 1; j++) {
		cout << "[ ";
		for (int i = 0; i <= x - 1; i++) {
			cout << a[i][j] << " ";
		}
		cout << " ]" << "\n";
	}
	for (int i = 0; i < x; i++) {
		delete[] a[i];
	}
	delete[] a;
}