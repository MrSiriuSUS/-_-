#include <iostream>
#include <stdlib.h>
#include <conio.h>
#pragma warning(disable : 4996)
using namespace std;

void vvod(FILE* shifr, char* mes) {
	cout << "\n������� ���������, ������� ������ �����������:\n";
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
		cout << "\n1 - ���� ������\n2 - ����� ������\n3 - ���������� ������\n4 - ����������� ������\n0 - �����\n";
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
			// � - 192, � - 197, � - 200, � - 206, � - 221, � - 219, � - 221, � - 222, � - 223
			// � - 224, � - 229, � - 232, � - 238, � - 243, � - 251, � - 253, � - 254, � - 255
			FILE * shifr = fopen("shifr.txt", "w");
			if (shifr != 0) {
				char buffer[256];
				cout << "������� ������, ������� ������ �����������:\n";
				cin.getline(mes, 256);
				for (int i = 0; i <= strlen(mes); i++) {
					if (mes[i] == '�' or mes[i] == '�' or mes[i] == '�' or mes[i] == '�' or mes[i] == '�' or mes[i] == '�' or mes[i] == '�' or mes[i] == '�' or mes[i] == '�' or mes[i] == '�' or mes[i] == '�' or mes[i] == '�' or mes[i] == '�' or mes[i] == '�' or mes[i] == '�' or mes[i] == '�' or mes[i] == '�' or mes[i] == '�') {
						strncpy(buffer, mes, i);
						buffer[i + 1] = '�';
						buffer[i + 2] = '�';
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