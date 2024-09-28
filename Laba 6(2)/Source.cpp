#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
int main() {
	bool num = false, p = false, minus = false;
	char* s = new char[255];
	setlocale(LC_ALL, "ru");
	cout << "¬ведите строку: ";
	cin.getline(s, 255);

	cout << "„исло: ";

	for (int i = 0; i <= strlen(s); i++) {	//≈щЄ можно while (s[i] != '\0')
		for (int j = 0; j <= 255; j++) {
			if ((char)j == s[i]) {
				if (num == false and s[i] == '-' and minus == false) {
					cout << s[i];
					minus = true;
					break;
				}
				if (p == false and s[i] == '.' and num == true) {
					cout << s[i];
					p = true;
					break;
				}
				if (j >= 48 and j <= 57) {
					cout << s[i];
					num = true;
					break;
				}
				if (num == true and (j < 48 or j > 57)) {
					return 0;
				}
			}
		}
	}
	delete[] s;
}