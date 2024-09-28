#include <iostream>
#include <conio.h>
#include <cctype>
using namespace std;

struct Stack {
	char c;
	Stack* next;
};

double Input();
int Prior(char);
Stack* InS(Stack*, char);
Stack* OutS(Stack*, char&);
double Result(char*);
bool Check_Brackets(char*);

void main() {
	setlocale(LC_ALL, "ru");
	Stack* Op = NULL;
	char a, In[81], Out[81];
	int k, l = 0;
	while (true) {
		cout << "\nНажмите любую кнопку, чтобы ввести формулу\n0 - закрыть программу\n";
		switch (_getch()) {
		case '0':
			return;
		default:
			cout << "Введите формулу:\n";
			cin >> In;
			if (!Check_Brackets(In)) {
				break;
			}
			for (k = 0; In[k] != '\0'; ++k) {	
				switch (In[k]) {
				case '(':
					Op = InS(Op, In[k]);
					break;
				case ')':
					while ((Op->c) != '(') {
						Op = OutS(Op, a);
						if (!Op) a = '\0';
						Out[l++] = a;
					}
					Op = OutS(Op, a);
					break;
				case '+': case '-': case '*': case '/': case'%':
					while (Op != NULL && Prior(Op->c) >= Prior(In[k])) {
						Op = OutS(Op, a);
						Out[l++] = a;
					}
					Op = InS(Op, In[k]);
					break;
				default:
					Out[l++] = In[k];
				}
			}
			while (Op != NULL) {
				Op = OutS(Op, a);
				Out[l++] = a;
			}
			Out[l] = '\0';
			cout << "\nПольская запись выражения -> " << Out << "\n";
			cout << "Результат = " << Result(Out) << "\n";
		}
	}
}

double Input() {
	double x;
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

int Prior(char a) {
	switch(a){
	case '*': case '/': case'%': return 3;
	case '-': case '+': return 2;
	case '(': return 1;
	}
	return 0;
}

Stack* InS(Stack* p, char s) {
	Stack* t = new Stack;
	t->c = s;
	t->next = p;
	return t;
}
Stack* OutS(Stack* p, char &s){
	Stack* t = p;
	s = p->c;
	p = p->next;
	delete t;
	return p;
}

double Result(char* str) {
	int i;
	Stack* begin = NULL;
	char ss, ss1, ss2, ssR = 'z' + 1;
	double op1, op2, res = 0, mas[50];
	bool used[26] = { false };
	for (i = 0; str[i] != '\0'; ++i) {
		if (isalpha(str[i])) {
			used[int(str[i] - 'a')] = true;
		}
	}
	cout << "Введите значения:\n";
	for (char var = 'a'; var <= 'z'; ++var) {
		if (used[int(var - 'a')]) {
			cout << var << " = ";
			mas[int(var - 'a')] = Input();
		}
	}
	for (i = 0; str[i] != '\0'; ++i) {
		ss = str[i];
		if (!(ss == '+' || ss == '-' || ss == '*' || ss == '/' || ss == '%'))
			begin = InS(begin, ss);
		else {
			begin = OutS(begin, ss2);
			begin = OutS(begin, ss1);
			op2 = mas[int(ss2 - 'a')];
			op1 = mas[int(ss1 - 'a')];
			if (ss == '/' && op2 == 0) {
				while (op2 == 0) {
					cout << "\nНекорректный ввод, деление на 0. Введите другой делитель: ";
					op2 = Input();
				}
			}
			switch (ss) {
			case '+': res = op1 + op2;
				break;
			case '-': res = op1 - op2;
				break;
			case '*': res = op1 * op2;
				break;
			case '/': res = op1 / op2;
				break;
			case '%': res = op1 * (op2 - op1);
			}
			mas[int(ssR - 'a')] = res;
			begin = InS(begin, ssR);
			ssR++;
		}
	}
	return res;
}

bool Check_Brackets(char* str) {
	Stack* brackets = NULL;

	for (int i = 0; str[i] != '\0'; ++i) {
		char currentChar = str[i];
		if (currentChar == '(') {
			brackets = InS(brackets, currentChar);
		}
		else if (currentChar == ')') {
			if (brackets == NULL || brackets->c != '(') {
				cout << "Ошибка: Несбалансированные скобки\n";
				return false;
			}
			else {
				brackets = OutS(brackets, currentChar);
			}
		}
	}

	if (brackets != NULL) {
		cout << "Ошибка: Несбалансированные скобки\n";
		return false;
	}
	return true;
}