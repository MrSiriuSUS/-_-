#include <iostream>
#include <conio.h>
#include <random>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main() {
	srand((int)time(0));
	setlocale(LC_ALL, "Russian");
	while (true) {
		int n, m = 0, r = 1, k = 0;
		cout << "������� 1, ����� �������� ��������� ����� ��������� �������, ����� ���� ����� � ����������" << "\n";
		switch (_getch()) {
		case '1':
			n = rand() % 21;
			break;
		default:
			cout << "������� ���������� ��������� � �������: ";
			while (true) {
				cin >> n;
				if (n > 20 or n <= 1) {
					cout << "��� ���� ���������� ��������, ������� ��� ���: ";
					cin.clear();
					cin.ignore();
					continue;
				}
				else {
					break;
				}
			}
		}
		cout << "����������� ���������� �������: " << n << "\n";
		int *mas = new int[n];
		cout << "������� 1, ����� ������ ��������� ����� � ������, ����� ���� � ����������" << "\n";
		switch (_getch()) {
		case '1':
			for (int i = 0; i <= n - 1; i++) {
				mas[i] = rand() % 11;
				cout << mas[i] << "\n";
			}
			break;
		default:
			for (int i = 0; i <= n - 1; i++) {
				cout << "������� " << i + 1 << " ������� �������: ";
				cin >> mas[i];
			}
		}
		for (int i = 0; i <= n - 1; i++) {
			if (mas[i] == 0) {
				m++;
				if (m > 1) {
					break;
				}
			}
			if (mas[i] % 2 == 0 and m == 1 and mas[i] != 0) {
				r *= mas[i];
				k++;
			}
		}
		if (m == 2 and k >= 1) {
			cout << "������������ ������ ��������� ����� ������ � ������ �������� ����������: " << r;
			break;
		}
		else {
			cout << "������ � ������ ������� �������� �� �������!" << "\n";
			continue;
		}
		delete[] mas;
	}
}