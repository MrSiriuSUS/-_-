#include <iostream>
#include <conio.h>
using namespace std;

struct Spis1 {
	int info;
	Spis1* prev, *next;
};

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

Spis1* Create(int in) {
	Spis1* t = new Spis1;
	t->info = in;
	t->next = t->prev = NULL;
	return t;
}

Spis1* Add_Begin(Spis1* b, int in){
	Spis1* t = new Spis1;
	t->info = in;
	t->prev = NULL;
	t->next = b;
	b->prev = t;
	b = t;
	return b;
}

Spis1* Add_End(Spis1* e, int in) {
	Spis1* t = new Spis1;
	t->info = in;
	t->next = NULL;
	t->prev = e;
	e->next = t;
	e = t;
	return e;
}

//void View_Begin(Spis1* t) {
//	cout << "================������� � ������================\n";
//	while (t != NULL) {
//		cout << t->info << "\n";
//		t = t->next;
//	}
//}
//
//void View_End(Spis1* t) {
//	cout << "================������� � �����================\n";
//	while (t != NULL) {
//		cout << t->info << "\n";
//		t = t->prev;
//	}
//}
void View(Spis1* t) {
	cout << "================������� � ������================\n";
	while (t->next != NULL) {
		cout << t->info << "\n";
		t = t->next;
	}
	cout << t->info;
	cout << "\n================������� � �����================\n";
	while (t != NULL) {
		cout << t->info << "\n";
		t = t->prev;
	}
}

void Del_All(Spis1*& p) {
	Spis1* t;
	while (p != NULL) {
		t = p;
		p = p->next;
		delete t;
	}
}

Spis1* Search(Spis1* b) {
	Spis1* key = NULL;
	int i_key = 0;
	cout << "������� ����: ";
	i_key = Input();
	Spis1* t = b;
	while (t != NULL) {
		if (t->info == i_key) {
			key = t;
			break;
		}
		t = t->next;
	}
	return key;
}

Spis1* Del_Begin(Spis1* b) {
	Spis1* t = b;
	b = b->next;
	if (b != NULL) {
		b->prev = NULL;
	}
	else {
		cout << "������� �����!";
	}
	delete t;
	return b;
}

Spis1* Del_End(Spis1* e) {
	Spis1* t = e;
	e = e->prev;
	if (e != NULL) {
		e->next = NULL;
	}
	else {
		cout << "������� �����!";
	}
	delete t;
	return e;
}

Spis1* Del(Spis1* b, Spis1* e) {
	Spis1* key = Search(b);
	if (key != NULL) {
		if (key == b) {
			b = Del_Begin(b);
		}
		else if (key == e) {
			e = Del_End(e);
		}
		else {
			(key->prev)->next = key->next;
			(key->next)->prev = key->prev;
		}
		delete key;
		cout << "������� �����!\n";
	}
	else {
		cout << "������� �� ������!\n";
	}
	return b;
}

Spis1* Min(Spis1* b) {
	int min = b->info;
	Spis1* mini = b;
	while (b != NULL) {
		if (min > b->info) {
			min = b->info;
			mini = b;
		}
		b = b->next;
	}
	return mini;
}

Spis1* More_Min_Begin(Spis1* b, Spis1* e) {
	Spis1* min = Min(b);
	while (e != min) {
		e = Del_End(e);
	}
	return e;
}

Spis1* More_Min_End(Spis1* b) {
	Spis1* min = Min(b);
	while (b != min) {
		b = Del_Begin(b);
	}
	return b;
}

void Switch(Spis1*& b, Spis1*& e)
{
	if (b == NULL || b == e) {
		cout << "������� �����!\n";
		return;
	}
	Spis1* t = b;
	e->next = b->next;
	b->next = NULL;
	(e->prev)->next = b;
	b = e;
	e = t;
}

void main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	Spis1* begin = NULL;
	Spis1* end = NULL;
	int in = 0, n = 0;
	while (true) {
		cout << "\n1 - ������� �������\n2 - �������� ������� � �������\n3 - �������� �������\n4 - ��������� ������\n5 - ������� ��������������� �������\n6 - �������� �� �����\n7 - ������\n0 - �������\n";
		switch (_getch()) {
		case '0':
			return;
		case '1':
			cout << "����������� ��������� �������: ";
			n = Input();
			cout << "������ ������� �������: ";
			in = Input();
			begin = end = Create(in);
			cout << "\n1 - �������� � ������ �������\n����� � ����� �������\n";
			switch (_getch()) {
			case '1':
				cout << "\n1 - ��� ����� ��������� �����\n����� ���� � ����������\n";
				switch (_getch()) {
				case '1':
					for (int i = 0; i <= n - 2; i++) {
						in = rand() % 21 - 10;
						begin = Add_Begin(begin, in);
					}
					break;
				default:
					for (int i = 0; i <= n - 2; i++) {
						cout << "������� �������: ";
						in = Input();
						begin = Add_Begin(begin, in);
					}
				}
				break;
			default:
				cout << "\n1 - ��� ����� ��������� �����\n����� ���� � ����������\n";
				switch (_getch()) {
				case '1':
					for (int i = 0; i <= n - 2; i++) {
						in = rand() % 21 - 10;
						end = Add_End(end, in);
					}
					break;
				default:
					for (int i = 0; i <= n - 2; i++) {
						cout << "������� �������: ";
						in = Input();
						end = Add_End(end, in);
					}
				}
			}
			break;
		case '2':
			cout << "\n1 - �������� � ������ �������\n����� � ����� �������\n";
			switch (_getch()) {
			case '1':
				cout << "\n1 - ��� ����� ��������� �����\n����� ���� � ����������\n";
				switch (_getch()) {
				case '1':
						in = rand() % 21 - 10;
						begin = Add_Begin(begin, in);
					break;
				default:
					cout << "������� �������: ";
					in = Input();
					begin = Add_Begin(begin, in);
				}
				break;
			default:
				cout << "\n1 - ��� ����� ��������� �����\n����� ���� � ����������\n";
				switch (_getch()) {
				case '1':
						in = rand() % 21 - 10;
						end = Add_End(end, in);
					break;
				default:
					cout << "������� �������: ";
					in = Input();
					end = Add_End(end, in);
				}
			}
			break;
		case '3':
			if (begin != NULL and end != NULL) {
				View(begin);
				}
			else {
				cout << "\n�������� �������!\n";
			}
			break;
		case '4':
			Del_All(begin);
			cout << "================������� ��������================\n";
			break;
		case '5':
			cout << "\n1 - �������� ��� �������� ����� ������ ������� � ����������� ��������� �������\n����� �������� ��� �������� ����� ������� ������� � ����������� �������� �������\n";
			switch (_getch()) {
			case '1':
				begin = More_Min_End(begin);
				break;
			default:
				end = More_Min_Begin(begin, end);
			}
			break;
		case '6':
			begin = Del(begin, end);
			break;
		case '7':
			Switch(begin, end);
			View(begin);
		}
	}
}