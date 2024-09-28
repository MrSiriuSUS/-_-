#include <iostream>
#include <conio.h>
using namespace std;
char mas(int s) {
	int m = 0;
	char* x = new char[s];
	for (int n = 0; n <= s - 1; n++) {
		cout << "Введите " << n + 1 << " элемент массива: " << "\n";
		x[n] = _getch();
		cout << x[n] << "\n";
	}
	
	for (int i = 0; i <= 255; i++) {
		for (int n = 0; n <= s - 1; n++) {
			if (x[n] == (char)i) {
				x[n] = x[m];
				x[m] = (char)i;
				m++;
			}
		}
	}
	char *un = new char[s];
	cout << "Неповторяющиеся элементы массива в алфавитном порядке: ";
	for (int n = 0; n <= s - 1; n++) {
		char c = x[n];
		bool unic = true;
		for (int j = 0; j <= s - 1; j++) {
			if (x[n] == x[j] and n != j) {
				unic = false;
			}
		}
		if (unic == true)
			cout << c;
	}
	delete[] x;
	delete[] un;
	return 0;
}

int main() {
	int s;
	setlocale(LC_ALL, "ru");
	while (true) {
		cout << "Введите количество элементов массива: ";
		cin >> s;
		if (cin.fail() or s <= 0) {
			cin.clear();
			cin.ignore();
			cout << "ERROR!\n";
			continue;
		}
		else {
			cout << mas(s);
			break;
		}
	}
}