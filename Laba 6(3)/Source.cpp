#include <iostream>
using namespace std;
int main() {
	int n = 0;
	setlocale(LC_ALL, "ru");
	char* s = new char[255];
	cout << "������� ������: ";
	cin.getline(s, 255);
	for (int i = 0; s[i] != '\0'; i++) {

		n++;

	}
	cout << "����� ������ �����: " << n << "\n";
	cout << "�� ���������: " << "\n";
	for (int i = 0; i <= n; i++) {
		cout << s[i] << "\n";
	}
	cout << "�� ���������: " << "\n";
	for (int i = 0; i <= n; i++) {
		cout << s[i] << "\n";
		for (int j = 0; j <= i; j++) {
			cout << "\t";
		}
	}
	cout << "\n� �������� �������: ";
	char p = 0;
	int j = n;
	for (int i = 0; i <= n / 2; i++) {
		p = s[j];
		s[j] = s[i];
		s[i] = p;
		j--;
	}
	for (int i = 0; i <= n; i++) {
		cout << s[i];
	}
}