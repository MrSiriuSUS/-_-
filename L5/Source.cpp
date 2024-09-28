#include <iostream>
#include <conio.h>
using namespace std;

struct Tree {
	int info;
	Tree* left, *right;
};

Tree* List(int i) {
	Tree* t = new Tree;
	t->info = i;
	t->left = t->right = NULL;
	return t;
}

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

Tree* Create(Tree* root, int &N) {
	Tree* Prev = NULL, * t;
	int b = 0, find = 0;
	cout << "Количество ключей дерева = ";
	N = Input();
	if (!root) {
		N--;
		cout << "Корень дерева: ";
		b = Input();
		root = List(b);
	}
	for (int i = 1; i <= N; ++i) {
		cout << "Ключи дерева: ";
		b = Input();
		t = root;
		find = 0;
		while (t && !find) {
			Prev = t;
			if (b == t->info) {
				find = 1;
				cout << "Такой ключ дерева уже существует!\n";
				i--;
			}
			else
				if (b < t->info) t = t->left;
				else t = t->right;
		}
		if (!find) {
			t = List(b);
			if (b < Prev->info)
				Prev->left = t;
			else Prev->right = t;
		}
	}
	return root;
}

void Add_List(Tree* root, int key, int &N) {
	Tree* prev = NULL, * t;
	int find = 1;
	t = root;
	while (t && find) {
		prev = t;
		if (key == t->info) {
			find = 0;
			cout << "Такой ключ уже существует!\n";
		}
		else
			if (key < t->info) t = t->left;
			else
				t = t->right;
	}
	if (find) {
		N++;
		t = List(key);
		if (key < prev->info)
			prev->left = t;
		else
			prev->right = t;
	}
}

Tree* Del(Tree* root, int key) {
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = root;
	Prev_Del = NULL;
	while (Del != NULL && Del->info != key) {
		Prev_Del = Del;
		if (key < Del->info) Del = Del->left;
		else Del = Del->right;
	}
	if (Del == NULL) {
		cout << "\nКлюч не найден!\n";
		return root;
	}
	if (Del->right == NULL) R = Del->left;
	else
		if (Del->left == NULL) R = Del->right;
		else {
			if (Del->left == NULL) R = Del->right;
			else {
				Prev_R = Del;
				R = Del->left;
				while (R->right != NULL) {
					Prev_R = R;
					R = R->right;
				}
				if (Prev_R == Del)
					R->right = Del->right;
				else {
					R->right = Del->right;
					Prev_R->right = R->left;
					R->left = Prev_R;
				}
			}
			if (Del == root) root = R;
			else
				if (Del->info < Prev_Del->info)
					Prev_Del->left = R;
				else
					Prev_Del->right = R;
			cout << "Удаление ключа " << Del->info << "\n";
			delete Del;
			return root;
		}
	if (Del == root) root = R;
	else
		if (Del->info < Prev_Del->info)
			Prev_Del->left = R;
		else
			Prev_Del->right = R;
	cout << "Удаление ключа " << Del->info << "\n";
	delete Del;
	return root;
}

void View(Tree* t, int level) {
	if (t) {
		View(t->right, level + 1);
		for (int i = 0; i < level; ++i)
			cout << "   ";
		cout << t->info << "\n";
		View(t->left, level + 1);
	}
}

void Del_All(Tree*& t) {
	if (t != NULL) {
		Del_All(t->left);
		Del_All(t->right);
		delete t;
		t = NULL;
	}
}

void Min_Key(Tree* p) {
	while (p->left != NULL)
		p = p->left;
	cout << "\nМинимальный ключ: " << p->info << "\n";
}

void Max_Key(Tree* p) {
	while (p->right != NULL)
		p = p->right;
	cout << "\n Максимальный ключ: " << p->info << "\n";
}

void Search(Tree* p, int key) {
	if (p != NULL) {
		if (p->info == key) {
			cout << "\nКлюч " << key << " существует в данном дереве\n";
			return;
		}
		if (key < p->info)
			Search(p->left, key);
		else
			Search(p->right, key);
	}
	else {
		cout << "\nКлюч " << key << " не существует в данном дереве\n";
	}
}

void Make_Blns(Tree** p, int n, int k, int* nodes) {
	if (n == k) {
		*p = NULL;
		return;
	}
	else {
		int m = (n + k) / 2;
		*p = new Tree;
		(*p)->info = nodes[m];
		Make_Blns(&(*p)->left, n, m, nodes);
		Make_Blns(&(*p)->right, m + 1, k, nodes);
	}
}

void Fill_Array(Tree* root, int* nodes, int& index) {
	if (root == NULL)
		return;
	Fill_Array(root->left, nodes, index);
	nodes[index++] = root->info;
	Fill_Array(root->right, nodes, index);
}

void Sort_Array(int* nodes, int N) {
	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (nodes[i] > nodes[j]) {
				int temp = nodes[i];
				nodes[i] = nodes[j];
				nodes[j] = temp;
			}
		}
	}
}

void Left_Root_Right(Tree* root) {
	if (root == NULL)
		return;
	Left_Root_Right(root->left);
	cout << root->info << " ";
	Left_Root_Right(root->right);
}

void Root_Left_Right(Tree* root) {
	if (root == NULL)
		return;
	cout << root->info << " ";
	Root_Left_Right(root->left);
	Root_Left_Right(root->right);
}

void Left_Right_Root(Tree* root) {
	if (root == NULL)
		return;
	Left_Right_Root(root->left);
	Left_Right_Root(root->right);
	cout << root->info << " ";
}

void List_Count(Tree* root, int level, int*& count) {
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL) {
		count[level]++;
	}
	List_Count(root->left, level + 1, count);
	List_Count(root->right, level + 1, count);
}

void Zaschita(Tree*& root, int key) {
	if (key != root->info) {
		if (key < root->info) {
			Zaschita(root->left, key);
		}
		if (key > root->info) {
			Zaschita(root->right, key);
		}
	}
	else {
		Del_All(root);
	}
}

void main() {
	setlocale(LC_ALL, "ru");
	Tree* root = NULL;
	int key = 0, N = 0;
	while (true) {
		cout << "\n1 - Создать\n2 - Добавить\n3 - Просмотр\n4 - Удалить ключ\n5 - Освободить память\n6 - Сбалансировать\n7 - Поиск\n8 - Обход дерева\n9 - Индтвидуальное задание\n0 - Выход\na - Защита\n";
		switch (_getch()) {
		case '0':
			Del_All(root);
			return;
		case '1':
			root = Create(root, N);
			break;

		case '2':
			cout << "Введите ключ: ";
			key = Input();
			Add_List(root, key, N);
			break;
		case '3':
			View(root, 0);
			break;
		case '4':
			cout << "Введите ключ для удаления: ";
			key = Input();
			root = Del(root, key);
			break;
		case '5':
			Del_All(root);
			break;
		case '6':
		{
			int* nodes = new int[N];
			for (int i = 0; i < N; i++) {
				Fill_Array(root, nodes, i);
			}
			Sort_Array(nodes, N);
			Make_Blns(&root, 0, N + 1, nodes);
			break; 
		}
		case '7':
			cout << "\n1 - Максимальный ключ\n2 - Минимальный ключ\nИначе свой ключ\n";
			switch (_getch()) {
			case '1':
				Max_Key(root);
				break;
			case '2':
				Min_Key(root);
				break;
			default:
				cout << "\nВведите ключ: ";
				key = Input();
				Search(root, key);
				break;
			}
			break;
		case '8':
			cout << "\n1 - Обход слева направо\n2 - Обход сверху вниз\nИначе обход снизу вверх\n";
			switch (_getch()) {
			case '1':
				Left_Root_Right(root);
				break;
			case '2':
				Root_Left_Right(root);
				break;
			default:
				Left_Right_Root(root);
			}
			break;
		case '9': {
			int* count = new int[N] {};
			List_Count(root, 0, count);
			for (int i = 0; i < N; i++) {
				if (count[i] > 0) {
					cout << "Колличество листьев на " << i + 1 << " уровне: " << count[i] << "\n";
				}
			}
			delete[] count;
			break; 
		}
		case 'a':
			int key = 0;
			key = Input();
			Zaschita(root, key);
		}
	}
}