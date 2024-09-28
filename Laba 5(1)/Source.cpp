#include <iostream>
using namespace std;
int main(){
	setlocale(LC_ALL, "Russian");
	int n, m, sum = 0;
	cout << "Введите количество столбцов: " << "\n";
	cin >> n;
	cout << "Введите количество строк: " << "\n";
	cin >> m;
	int** x = new int* [n];
	for (int i = 0; i <= n - 1; i++) {
		x[i] = new int[m];
	}
	for (int j = 0; j <= m - 1; j++) {
		for (int i = 0; i <= n - 1; i++) {
			cout << "Введите элемент " << i + 1 << " столбца " << j + 1 << " строки: " << "\n";
			cin >> x[i][j];
		}
	}
	for (int j = 0; j <= m - 1; j++) {
		cout << "[ ";
		for (int i = 0; i <= n - 1; i++) {
			cout << x[i][j] << " ";
		}
		cout << " ]" << "\n";
	}
	for (int i = 0; i <= n - 1; i++) {
		for (int j = 0; j <= m - 1; j++) {
			if (x[i][j] < 0) {
				for (int j = 0; j <= m - 1; j++) {
					sum += x[i][j];
				}
				cout << "Сумма элементов " << i+1 << " столбца: " << sum << "\n";
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		delete[] x[i];
	}
	delete[] x;
}