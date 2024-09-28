#include <iostream>
#include <cstring>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	char* S = new char[255];
	cout << "¬ведите строку: ";
	cin >> S;
	int k = 0;
	for (int i = 0; i <= strlen(S); i++) {
		if (S[i] == '!') {
			if (k % 2 == 0) {
				S[i] = '$';
			}
			k++;
		}
	}
	cout << S;
}