#include <iostream>
using namespace std;
int main() {
	int n, j = 1, i;
	double sum = 0;
	setlocale(LC_ALL, "Russian");
	cout << "������� ����� ��������� �������: ";
	while (true) {
		cin >> n;
		if (n > 20) {
			cout << "��� ����������� ��������! " << "������� ����� ��������� �������: ";
			cin.clear();
			cin.ignore();
		}
		else {
			if (cin.fail()) {
				cout << "������� �� �����! " << "������� ����� ��������� �������: ";
				cin.clear();
				cin.ignore();
			}
			else {
				break;
			}
		}
	}
	double *arr = new double[n];
	for (i = 0; i <= n-1; i++) {
		cout << "������� " << j << " ������� �������: ";
		j++;
		cin >> arr[i];
		sum += arr[i];
			if (arr[i] < 0) {
				sum = 0;
			}
	}
	cout << "����� ����� = " << sum;
}