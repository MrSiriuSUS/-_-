#include <iostream>
#include <conio.h>
using namespace std;

struct Stack {
	int info;
	Stack* next;
};

int Input() {
	int x;
	while (true) {
		cin >> x;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "\nВведено не корректное значение!\nВведите ещё раз: ";
		}
		else break;
	}
	return x;
}

Stack* InStack(Stack* p, int in) {
	Stack* t = new Stack;
	t->info = in;
	t->next = p;
	return t;
}

void View_Rev(Stack* t) {
	if (t == NULL) {
		return;
	}
	View_Rev(t->next);
	cout << t->info << "\n";
}

void View(Stack* t) {
	cout << "\n1 - Вывод с вершины стека\nИначе вывод с конца стека\n";
	switch (_getch()) {
	case '1':
		View_Rev(t);
		break;
	default:
		while (t != NULL) {
			cout << t->info << "\n";
			t = t->next;
		}
	}
}


void Del_All(Stack*& p) {
	Stack* t;
	while (p != NULL) {
		t = p;
		p = p->next;
		delete t;
	}
}

Stack* OutStack(Stack* p) {
	Stack* t = p;
	p = p->next;
	delete t;
	return p;
}

Stack* Min(Stack* t) {
	int min = t->info;
	Stack* mini = t->next;
	while (t != NULL) {
		if (min > t->info) {
			min = t->info;
			mini = t->next;
		}
		t = t->next;
	}
	return mini;
}

Stack* More_Min(Stack* b) {
	Stack* min = Min(b);
	while (b->next != min) {
		b = OutStack(b);
	}
	return b;
}

void main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int in = 0, n = 0;
	Stack* begin = NULL;
	while (true) {
		cout << "\n1 - Создать стек\n2 - Добавить элемент в стек\n3 - Просмотр стека\n4 - Отчистить память\n5 - Решение индивидуального задания\n0 - Закрыть\n";
		switch (_getch()) {
		case '1':
			if (begin != NULL) {
				cout << "Отчистите память!\n";
				break;
			}
			cout << "\nКоличество элементов в стеке: ";
			n = Input();
			cout << "1 - Для ввода случайных чисел\nИначе ввод с клавиатуры\n";
			switch (_getch()) {
			case '1':
				for (int i = 0; i < n; i++) {
					in = rand() % 21 - 10;
					begin = InStack(begin, in);
				}
				break;
			default:
				for (int i = 0; i < n; i++) {
					cout << "Число: ";
					in = Input();
					begin = InStack(begin, in);
				}
			}
			break;
		case '2': 
			{
			int a = 0;
			cout << "Введите элемент стека: ";
			a = Input();
			begin = InStack(begin, a);
			break;
		}
		case '3':
			View(begin);
			break;
		case '4':
			if (!begin) {
				cout << "Стек пуст!\n";
				break;
			}
			Del_All(begin);
			break;
		case '5':
			cout << "\n---------------------------\nОтсортированный стек:\n";
			begin = More_Min(begin);
			View(begin);
			break;
		case '0':
			Del_All(begin);
			return;
		default:
			cout << "Ошибка ввода, введите ещё раз:\n";
		}
	}
}