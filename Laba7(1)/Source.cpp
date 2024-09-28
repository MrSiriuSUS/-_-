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

int vvod(FILE* spisok, int n) {
	cout << "\nФамилия: ";
	cin >> st[n].name;
	fputs("\nФИО: ", spisok);
	fprintf(spisok, "%s", st[n].name);
	cout << "Номер группы: ";
	cin >> st[n].gruppa;
	fputs("\nНомер группы: ", spisok);
	fprintf(spisok, "%ld", st[n].gruppa);
	cout << "Средний балл по физике: ";
	cin >> st[n].fiz;
	fputs("\nСредний балл по физике: ", spisok);
	fprintf(spisok, "%f", st[n].fiz);
	cout << "Средний балл по математике: ";
	cin >> st[n].mat;
	fputs("\nСредний балл по математике: ", spisok);
	fprintf(spisok, "%f", st[n].mat);
	cout << "Средний балл по информатике: ";
	cin >> st[n].inf;
	fputs("\nСредний балл по информатике: ", spisok);
	fprintf(spisok, "%f", st[n].inf);
	st[n].ball = (st[n].fiz + st[n].mat + st[n].inf) / 3.;
	cout << "Средний балл: " << st[n].ball << "\n";
	fputs("\nСредний балл: ", spisok);
	fprintf(spisok, "%f", st[n].ball);
	fputs("\n", spisok);
	n++;
	return n;
}

void vivod(FILE* spisokr) {
	char buffer[256];
	while (fgets(buffer, 100, spisokr) != 0) {
		cout << buffer;
	}
}

int add(FILE* spisoka, int n) {
	cout << "\nФамилия: ";
	cin >> st[n].name;
	fputs("\nФИО: ", spisoka);
	fprintf(spisoka, "%s", st[n].name);
	cout << "Номер группы: ";
	cin >> st[n].gruppa;
	fputs("\nНомер группы: ", spisoka);
	fprintf(spisoka, "%ld", st[n].gruppa);
	cout << "Средний балл по физике: ";
	cin >> st[n].fiz;
	fputs("\nСредний балл по физике: ", spisoka);
	fprintf(spisoka, "%f", st[n].fiz);
	cout << "Средний балл по математике: ";
	cin >> st[n].mat;
	fputs("\nСредний балл по математике: ", spisoka);
	fprintf(spisoka, "%f", st[n].mat);
	cout << "Средний балл по информатике: ";
	cin >> st[n].inf;
	fputs("\nСредний балл по информатике: ", spisoka);
	fprintf(spisoka, "%f", st[n].inf);
	st[n].ball = (st[n].fiz + st[n].mat + st[n].inf) / 3.;
	cout << "Средний балл: " << st[n].ball << "\n";
	fputs("\nСредний балл: ", spisoka);
	fprintf(spisoka, "%f", st[n].ball);
	fputs("\n", spisoka);
	n++;
	return n;
}

void Ind(FILE* ind, int n) {
	double sball = 0;
	for (int i = 0; i <= n - 1; i++) {
		sball += st[i].ball;
	}
	sball = sball / n;
	for (int i = 0; i <= n - 1; i++) {
		if (st[i].ball >= sball) {
			fputs("\nФамилия: ", ind);
			fprintf(ind, "%s", st[i].name);
			fputs("\nНомер группы: ", ind);
			fprintf(ind, "%ld", st[i].gruppa);
			fputs("\nСредний балл по физике: ", ind);
			fprintf(ind, "%f", st[i].fiz);
			fputs("\nСредний балл по математике: ", ind);
			fprintf(ind, "%f", st[i].mat);
			fputs("\nСредний балл по информатике: ", ind);
			fprintf(ind, "%f", st[i].inf);
			fputs("\nСредний балл: ", ind);
			fprintf(ind, "%f", st[i].ball);
			fputs("\n", ind);
		}
	}
	cout << "Индивидуальное задание выполнено успешно.\nСредний балл учащихся: " << sball << "\n";
}

void main() {
	setlocale(LC_ALL, "ru");
	int n = 0, size = sizeof(student);


	while (true) {
		cout << "\n1 - Создать файл" << "\n" << "2 - Просмотр файла" << "\n" << "3 - Добавление" << "\n" << "4 - Индивидуальное задание" << "\n" << "0 - Выход" << "\n";
		switch (_getch()) {
		case '0':
			return;
		case '1':
		{FILE* spisok = fopen("spisok.txt", "w");
		if (spisok != 0) {
			bool povt = 0;
			while (true) {
				if (povt == 0) {
					cout << "Нажмите +, чтобы добавить ученика. -, чтобы остановиться.\n";
					switch (_getch()) {
					case '+':
						n = vvod(spisok, n);
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
		{FILE* spisokr = fopen("spisok.txt", "r");
		if (spisokr != 0) {
			vivod(spisokr);

			fclose(spisokr);
		}
		else {
			cout << "ERROR!";
		}
		break; }
		case '3':
		{FILE* spisoka = fopen("spisok.txt", "a");
		if (spisoka != 0) {

			n = add(spisoka, n);

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
			Ind(ind, n);
			fclose(ind);
		}
		else {
			cout << "ERROE!";
		}
		break; }
		}
	}
}