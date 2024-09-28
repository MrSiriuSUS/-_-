#include <iostream>
using namespace std;

int Input() {
	int x;
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
	cout << "������� �����: ";
	n = Input();
	cout << "������� ������ ������� ���������: ";
	p = Input();
	cout << p << "-����� ������� � ��������� -> ";
	rec(n, p);
	cout << "\n";
	cout << p << "-����� ������� ��� �������� -> ";
	obich(n, p);
}