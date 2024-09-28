#include <iostream>
using namespace std;

int obich(int n, int* arr) {
	int max = arr[0];
	for (int i = 0; i <= n - 1; i++) {
		if (max < arr[i]) max = arr[i];
	}
	if (max > arr[n]) {
		return max;
	}
	else {
		return arr[n];
	}
}

int rec(int n, int* arr) {
	int max = arr[0];
	for (int i = 0; i <= n - 1; i++) {
		if (max < arr[i]) max = arr[i];
	}
	if (max > arr[n]) {
		return rec((n - 1), arr);
	}
	else if (n == 0) {
		return arr[n];
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	int n, i = 0;
	cout << "������� ���������� ��������� �������: \n";
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i <= n - 1; i++) {
		cout << i + 1 << " ������� �������:\n";
		cin >> arr[i];
	}
	cout << "[ ";
	for (int i = 0; i <= n - 1; i++) {
		cout << arr[i] << " ";
	}
	cout << "]\n";
	cout << "� ������� ������� ������� ��������: " << obich(n - 1, arr);
	cout << "\n� ������� ����������� ������� ��������: " << rec(n - 1, arr);
	if (obich(n - 1, arr) == rec(n - 1, arr)) {
		cout << "\n" << obich(n - 1, arr) << " = " << rec(n - 1, arr) << " �� �����";
	}
	else {
		cout << "����� ��� ������� ������, �� ������ �� ������!";
	}
}