#include <iostream>
#include <stdlib.h>
#include <conio.h>
#pragma warning(disable : 4996)
using namespace std;

struct student {
	char name[100];
	long int gruppa;
	double fiz, mat, inf, ball;
}st[100];

int vvod(FILE *spisok, int n, student *st) {
	cout << "\n�������: ";
	cin >> st[n].name;
	fputs("\n", spisok);
	fprintf(spisok, "%d", n + 1);
	fputs(" ���: ", spisok);
	fprintf(spisok, "%s", st[n].name);
	cout << "����� ������: ";
	cin >> st[n].gruppa;
	fputs("\n����� ������: ", spisok);
	fprintf(spisok, "%ld", st[n].gruppa);
	cout << "������� ���� �� ������: ";
	cin >> st[n].fiz;
	fputs("\n������� ���� �� ������: ", spisok);
	fprintf(spisok, "%f", st[n].fiz);
	cout << "������� ���� �� ����������: ";
	cin >> st[n].mat;
	fputs("\n������� ���� �� ����������: ", spisok);
	fprintf(spisok, "%f", st[n].mat);
	cout << "������� ���� �� �����������: ";
	cin >> st[n].inf;
	fputs("\n������� ���� �� �����������: ", spisok);
	fprintf(spisok, "%f", st[n].inf);
	st[n].ball = (st[n].fiz + st[n].mat + st[n].inf) / 3.;
	cout << "������� ����: " << st[n].ball << "\n";
	fputs("\n������� ����: ", spisok);
	fprintf(spisok, "%f", st[n].ball);
	fputs("\n", spisok);
	n++;
	return n;
}

void vivod(FILE *spisokr) {
	char buffer[256];
	while (fgets(buffer, 256, spisokr) != 0) {
		cout << buffer;
	}
}

int add(FILE *spisok, int n, student *st) {
	cout << "\n�������: ";
	cin >> st[n].name;
	fputs("\n", spisok);
	fprintf(spisok, "%d", n + 1);
	fputs(" ���: ", spisok);
	fprintf(spisok, "%s", st[n].name);
	cout << "����� ������: ";
	cin >> st[n].gruppa;
	fputs("\n����� ������: ", spisok);
	fprintf(spisok, "%ld", st[n].gruppa);
	cout << "������� ���� �� ������: ";
	cin >> st[n].fiz;
	fputs("\n������� ���� �� ������: ", spisok);
	fprintf(spisok, "%f", st[n].fiz);
	cout << "������� ���� �� ����������: ";
	cin >> st[n].mat;
	fputs("\n������� ���� �� ����������: ", spisok);
	fprintf(spisok, "%f", st[n].mat);
	cout << "������� ���� �� �����������: ";
	cin >> st[n].inf;
	fputs("\n������� ���� �� �����������: ", spisok);
	fprintf(spisok, "%f", st[n].inf);
	st[n].ball = (st[n].fiz + st[n].mat + st[n].inf) / 3.;
	cout << "������� ����: " << st[n].ball << "\n";
	fputs("\n������� ����: ", spisok);
	fprintf(spisok, "%f", st[n].ball);
	fputs("\n", spisok);
	n++;
	return n;
}

void Ind(FILE* ind, int n, student *st) {
	double sball = 0;
	for (int i = 0; i <= n - 1; i++) {
		sball += st[i].ball;
	}
	sball = sball / n;
	for (int i = 0; i <= n - 1; i++) {
		if (st[i].ball >= sball) {
			fputs("\n", ind);
			fprintf(ind, "%d", i + 1);
			fputs(" �������: ", ind);
			fprintf(ind, "%s", st[i].name);
			fputs("\n����� ������: ", ind);
			fprintf(ind, "%ld", st[i].gruppa);
			fputs("\n������� ���� �� ������: ", ind);
			fprintf(ind, "%f", st[i].fiz);
			fputs("\n������� ���� �� ����������: ", ind);
			fprintf(ind, "%f", st[i].mat);
			fputs("\n������� ���� �� �����������: ", ind);
			fprintf(ind, "%f", st[i].inf);
			fputs("\n������� ����: ", ind);
			fprintf(ind, "%f", st[i].ball);
			fputs("\n", ind);
		}
	}
	cout << "�������������� ������� ��������� �������.\n������� ���� ��������: " << sball << "\n";
}

void main() {
	setlocale(LC_ALL, "ru");
	int n = 0, m = 0, i;

	//cout << "������������ ���������� ���������:\n";
	//cin >> i;
	//student* st = new student[i];

	while (true) {
		cout << "\n1 - ������� ����" << "\n" << "2 - �������� �����" << "\n" << "3 - ����������" << "\n" << "4 - �������������� �������" << "\n" << "5 - ��������������\n" << "6 - ����������\n" << "0 - �����" << "\n";
		switch (_getch()) {
		case '0':
			return;
		case '1':
		{FILE* spisok = fopen("spisok.txt", "w");
		if (spisok != 0) {
			bool povt = 0;
			n = 0;
			while (true) {
				if (povt == 0) {
					cout << "������� +, ����� �������� �������. -, ����� ������������.\n";
					switch (_getch()) {
					case '+':
						n = vvod(spisok, n, st);
						break;
					case '-':
						povt = 1;
						break;
					}
				}
				else break;
			}
			fclose(spisok);
		}
		else {
			cout << "ERROR!";
			return;
		}
		break;

		}
		case '2':
		{FILE* spisokr = fopen("spisok.txt", "a+");
		if (spisokr != 0) {
			vivod(spisokr);

			fclose(spisokr);
		}
		else {
			cout << "ERROR!";
		}
		break; }
		case '3':
		{FILE* spisoka = fopen("spisok.txt", "a+");
		if (spisoka != 0) {

			n = add(spisoka, n, st);

			fclose(spisoka);
		}
		else {

			cout << "ERROR!";

		}
		break;
		}
		case '4':
		{FILE* ind = fopen("ind.txt", "w");
		if (ind != 0) {
			Ind(ind, n, st);
			fclose(ind);
		}
		else {
			cout << "ERROE!";
		}
		break; }
		case '5':
		{FILE* spisok = fopen("spisok.txt", "a+");
		if (spisok != 0) {
			int stud;
			vivod(spisok);
			fclose(spisok);
			cout << "�������� ����� ��������, �������� ������ ��������:\n";
			cin >> stud;
			cout << "+ - ���������\n- - ��������";
			switch (_getch()) {
			case '+':
			{FILE* spisok = fopen("spisok.txt", "w");
			for (int i = 0; i <= n - 1; i++) {
				if (i != stud - 1) {
					fputs("\n", spisok);
					fprintf(spisok, "%d", i + 1);
					fputs(" ���: ", spisok);
					fprintf(spisok, "%s", st[i].name);
					fputs("\n����� ������: ", spisok);
					fprintf(spisok, "%ld", st[i].gruppa);
					fputs("\n������� ���� �� ������: ", spisok);
					fprintf(spisok, "%f", st[i].fiz);
					fputs("\n������� ���� �� ����������: ", spisok);
					fprintf(spisok, "%f", st[i].mat);
					fputs("\n������� ���� �� �����������: ", spisok);
					fprintf(spisok, "%f", st[i].inf);
					st[i].ball = (st[i].fiz + st[i].mat + st[i].inf) / 3.;
					fputs("\n������� ����: ", spisok);
					fprintf(spisok, "%f", st[i].ball);
					fputs("\n", spisok);
				}
				else {
					vvod(spisok, stud - 1, st);
				}
			}
			n++;
			fclose(spisok);
			break; }
			case '-':
			{FILE* spisokf = fopen("spisok.txt", "w");
			for (int i = 0; i <= n - 1; i++) {
				if (i != stud - 1) {
					fputs("\n", spisokf);
					fprintf(spisokf, "%d", i + 1);
					fputs(" ���: ", spisokf);
					fprintf(spisokf, "%s", st[i].name);
					fputs("\n����� ������: ", spisokf);
					fprintf(spisokf, "%ld", st[i].gruppa);
					fputs("\n������� ���� �� ������: ", spisokf);
					fprintf(spisokf, "%f", st[i].fiz);
					fputs("\n������� ���� �� ����������: ", spisokf);
					fprintf(spisokf, "%f", st[i].mat);
					fputs("\n������� ���� �� �����������: ", spisokf);
					fprintf(spisokf, "%f", st[i].inf);
					st[i].ball = (st[i].fiz + st[i].mat + st[i].inf) / 3.;
					fputs("\n������� ����: ", spisokf);
					fprintf(spisokf, "%f", st[i].ball);
					fputs("\n", spisokf);
				}
				else {}
			}
			n--;
			fclose(spisokf);
			break; }
			}

			fclose(spisok);
		}
		else {
			cout << "ERROR!";
		}
		break;
		}
		case '6':
		{FILE* spisok = fopen("spisok.txt", "w");
		if (spisok != 0) {
			while (true) {
				cout << "\n1 - ���������� �� �������� \n2 - ���������� �� ����������� �������� ����� \n3 - ���������� �� �������� �������� �����";
				switch (_getch()) {
				case '1':
					for (int j = 0; j <= 255; j++) {
						for (int i = 0; i <= n - 1; i++) {
							if (*st[i].name == (char)j) {
								st[99] = st[m];
								st[m] = st[i];
								st[i] = st[99];
								m++;
							}
						}
					}

					vivod(spisok);

					for (int i = 0; i <= n - 1; i++) {
						fputs("\n", spisok);
						fprintf(spisok, "%d", i + 1);
						fputs(" ���: ", spisok);
						fprintf(spisok, "%s", st[i].name);
						fputs("\n����� ������: ", spisok);
						fprintf(spisok, "%ld", st[i].gruppa);
						fputs("\n������� ���� �� ������: ", spisok);
						fprintf(spisok, "%f", st[i].fiz);
						fputs("\n������� ���� �� ����������: ", spisok);
						fprintf(spisok, "%f", st[i].mat);
						fputs("\n������� ���� �� �����������: ", spisok);
						fprintf(spisok, "%f", st[i].inf);
						st[i].ball = (st[i].fiz + st[i].mat + st[i].inf) / 3.;
						fputs("\n������� ����: ", spisok);
						fprintf(spisok, "%f", st[i].ball);
						fputs("\n", spisok);
					}

				case '2':
					for (int j = 0; j <= n - 1; j++) {
						for (int i = 0; i <= n - 2; i++) {
							if (st[i].ball > st[i + 1].ball) {
								st[99] = st[i + 1];
								st[i + 1] = st[i];
								st[i] = st[99];
							}
						}
					}
					for (int i = 0; i <= n - 1; i++) {
						fputs("\n", spisok);
						fprintf(spisok, "%d", i + 1);
						fputs(" ���: ", spisok);
						fprintf(spisok, "%s", st[i].name);
						fputs("\n����� ������: ", spisok);
						fprintf(spisok, "%ld", st[i].gruppa);
						fputs("\n������� ���� �� ������: ", spisok);
						fprintf(spisok, "%f", st[i].fiz);
						fputs("\n������� ���� �� ����������: ", spisok);
						fprintf(spisok, "%f", st[i].mat);
						fputs("\n������� ���� �� �����������: ", spisok);
						fprintf(spisok, "%f", st[i].inf);
						st[i].ball = (st[i].fiz + st[i].mat + st[i].inf) / 3.;
						fputs("\n������� ����: ", spisok);
						fprintf(spisok, "%f", st[i].ball);
						fputs("\n", spisok);
					}
				case '3':
					for (int j = 0; j <= n - 1; j++) {
						for (int i = 0; i <= n - 2; i++) {
							if (st[i].ball < st[i + 1].ball) {
								st[99] = st[i + 1];
								st[i + 1] = st[i];
								st[i] = st[99];
							}
						}
					}
					for (int i = 0; i <= n - 1; i++) {
						fputs("\n", spisok);
						fprintf(spisok, "%d", i + 1);
						fputs(" ���: ", spisok);
						fprintf(spisok, "%s", st[i].name);
						fputs("\n����� ������: ", spisok);
						fprintf(spisok, "%ld", st[i].gruppa);
						fputs("\n������� ���� �� ������: ", spisok);
						fprintf(spisok, "%f", st[i].fiz);
						fputs("\n������� ���� �� ����������: ", spisok);
						fprintf(spisok, "%f", st[i].mat);
						fputs("\n������� ���� �� �����������: ", spisok);
						fprintf(spisok, "%f", st[i].inf);
						st[i].ball = (st[i].fiz + st[i].mat + st[i].inf) / 3.;
						fputs("\n������� ����: ", spisok);
						fprintf(spisok, "%f", st[i].ball);
						fputs("\n", spisok);
					}

				}
		fclose(spisok);
		break;
			}
		}
		else {
			cout << "ERROR!";
		}
		}
		}
	}
	for (int j = 0; j < i; j++) {
		delete[] st[j].name;
	}
	delete[] st;
}