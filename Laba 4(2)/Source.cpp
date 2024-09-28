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
		cout << "Нажмите 1, чтобы получить случайное число элементов массива, иначе ввод числа с клавиатуры" << "\n";
		switch (_getch()) {
		case '1':
			n = rand() % 21;
			break;
		default:
			cout << "Введите количество элементов в массиве: ";
			while (true) {
				cin >> n;
				if (n > 20 or n <= 1) {
					cout << "Вне зоны допустимых значений, введите ещё раз: ";
					cin.clear();
					cin.ignore();
					continue;
				}
				else {
					break;
				}
			}
		}
		cout << "Колличество эллементов массива: " << n << "\n";
		int *mas = new int[n];
		cout << "Нажмите 1, чтобы ввести случайные числа в массив, иначе ввод с клавиатуры" << "\n";
		switch (_getch()) {
		case '1':
			for (int i = 0; i <= n - 1; i++) {
				mas[i] = rand() % 11;
				cout << mas[i] << "\n";
			}
			break;
		default:
			for (int i = 0; i <= n - 1; i++) {
				cout << "Введите " << i + 1 << " элемент массива: ";
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
			cout << "Произведение чётных элементов между первым и вторым нулевыми элементами: " << r;
			break;
		}
		else {
			cout << "Первый и второй нулевые элементы не найдены!" << "\n";
			continue;
		}
		delete[] mas;
	}
}