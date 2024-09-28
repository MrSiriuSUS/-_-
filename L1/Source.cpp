#include <iostream>
using namespace std;

int Input() {
	int x;
	while (true) {
		cin >> x;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "\n¬ведено не корректное значение!\n¬ведите ещЄ раз: ";
		}
		else break;
	}
	return x;
}


void obich(long n, int p) {
	int rez[100]; 
	int i = 0;
	if (n < 0) {
		n *= -1;
		cout << "-";
	}
	while (n > 0) {
		rez[i] = n % p;
		n /= p;
		i++;
	}
	for (int j = i - 1; j >= 0; j--) {
		cout << rez[j];
	}
}

void rec(long n, int p) {
	if (n < 0) {
		n *= -1;
		cout << "-";
	}
	if (n == 0) return;
	else {
		rec(n / p, p);
		cout << n % p;
	}
	return;
}

void main() {
	long n = 0;
	int p = 0;
	setlocale(LC_ALL, "ru");
	cout << "¬ведите число: ";
	n = Input();
	cout << "¬ведите разр€д системы счислени€: ";
	p = Input();
	cout << p << "-ична€ система с рекурсией -> ";
	rec(n, p);
	cout << "\n";
	cout << p << "-ична€ система без рекурсии -> ";
	obich(n, p);
}