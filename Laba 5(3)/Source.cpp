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
			cout << "�� ���������� �������!";
			return 0;
		}
	}
	for (int j = 0; j <= x - 1; j++) {
		sum = 0;
		for (int i = 0; i <= x - 1; i++) {
			sum += a[i][j];
		}
		if (sumx != sum) {
			cout << "�� ���������� �������!";
			return 0;
		}
	}
	cout << "���������� �������, ����� ��������� �� ��������� � �� ����������� �������� �����: ";
	return sumx;
}

int main() {
	int x;
	setlocale(LC_ALL, "Russian");
	while (true) {
		cout << "������� ������� ����������� ��������: ";
		cin >> x;
		if (cin.fail()) {
			cout << "������� �� �����!" << "\n";
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
				cout << "������� ������� " << j + 1 << " ������� " << i + 1 << " ������: ";
				cin >> a[i][j];
				if (cin.fail()) {
					cout << "������� �� �����! ������� ��������." << "\n";
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