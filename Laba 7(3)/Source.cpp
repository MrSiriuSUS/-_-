#include <iostream>
#include <stdlib.h>
#include <conio.h>
#pragma warning(disable : 4996)
using namespace std;

void vvod(FILE* shifr, char* mes) {
	cout << "\nВведите сообщение, которое хотите зашифровать:\n";
	cin.getline(mes, 256);
	fprintf(shifr, "%s", mes);
}

void vivod(char* sh, FILE* shifrr) {
	cout << fgets(sh, 256, shifrr);
}

void main() {
	system("chcp 1251");
	setlocale(LC_ALL, "ru");
	char mes[256], sh[256];
	while (true) {
		cout << "\n1 - Ввод строку\n2 - Вывод строки\n3 - Шифрование текста\n4 - Расшифровка текста\n0 - Выход\n";
		switch (_getch()) {
		case '0':
			return;
		case '1':
		{FILE* shifr = fopen("shifr.txt", "w");
		if (shifr != 0) {
			vvod(shifr, mes);
			fclose(shifr);
		}
		else {
			cout << "ERROR!";
			return;
		}
		break;
		}
		case '2':
		{FILE* shifrr = fopen("shifr.txt", "r");
		if (shifrr != 0) {
			vivod(sh, shifrr);
			fclose(shifrr);
		}
		else {
			cout << "ERROR!";
			return;
		}
		break;
		}  
		case '3':  
			// А - 192, Е - 197, И - 200, О - 206, У - 221, Ы - 219, Э - 221, Ю - 222, Я - 223
			// а - 224, е - 229, и - 232, о - 238, у - 243, ы - 251, э - 253, ю - 254, я - 255
			FILE * shifr = fopen("shifr.txt", "w");
			if (shifr != 0) {
				char buffer[256];
				cout << "Введите строку, которую хотите зашифровать:\n";
				cin.getline(mes, 256);
				for (int i = 0; i <= strlen(mes); i++) {
					if (mes[i] == 'А' or mes[i] == 'Е' or mes[i] == 'И' or mes[i] == 'О' or mes[i] == 'У' or mes[i] == 'Ы' or mes[i] == 'Э' or mes[i] == 'Ю' or mes[i] == 'Я' or mes[i] == 'а' or mes[i] == 'е' or mes[i] == 'и' or mes[i] == 'о' or mes[i] == 'у' or mes[i] == 'ы' or mes[i] == 'э' or mes[i] == 'ю' or mes[i] == 'я') {
						strncpy(buffer, mes, i);
						buffer[i + 1] = 'л';
						buffer[i + 2] = 'а';
					}
				}
				for (int n = 0; n <= sizeof(buffer) - 1; n++) {
					cout << buffer[n];
				}
				cout << strlen(buffer) << "\n" << strlen(mes);
				fclose(shifr);
			}
			else {
				cout << "ERROR!";
				return;
			}
		}
	}
}