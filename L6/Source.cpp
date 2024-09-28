#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;

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

double F(double x) {
    return pow(sin(x), 2) - x / 5. - 1.;
}

double Metod_Sec(double x0, double epsilon, int &iterations) {
    double x1 = x0 + epsilon;
    double x;
    do {
        x = x1 - F(x1) * epsilon / (F(x1) - F(x1 - epsilon));
        x0 = x1;
        x1 = x;
        iterations++;
    } while (fabs(x1 - x0) > epsilon);
    return x1;
}

double Simple_Iteration(double x0, double epsilon, int &iterations) {
    double x1;
    while (iterations < 10000) {
        x1 = x0 + 0.1 * fabs(F(x0));
        if (fabs(x1 - x0) < epsilon) {
            break;
        }
        x0 = x1;
        iterations++;
    }
    return x1;
}

int main() {
    setlocale(LC_ALL, "ru");
    double a = 0, b = 0, h = 0, epsilon = 0;
    bool found = false;
    cout << "1 - Ввести данные из методички\nИначе ввод данных в ручную\n";
    switch (_getch()) {
    case '1':
        a = -4;
        b = 0;
        h = 0.01;
        epsilon = 1e-8;
        break;
    default:
        cout << "a = ";
        a = Input();
        cout << "b = ";
        b = Input();
        cout << "h (шаг) = ";
        h = Input();
        cout << "epsilon (точность) = ";
        epsilon = Input();
    }
    cout << "\n1 - Метод секущих\n2 - Метод простой итерации\n";
    switch (_getch()) {
    case '1': {
        for (double j = a; j <= b; j += h) {
            if (F(j) * F(j + h) < 0) {
                int iterations = 0;
                double res = Metod_Sec(j, epsilon, iterations);
                cout << "Корень: x = " << res << "\n" << "Значение функции: y = " << F(res) << "\n";
                cout << "Число итераций: " << iterations << "\n";
                found = true;
            }
        }
        break;
    }
    case '2': {
        for (double j = a; j <= b; j += h) {
            if (F(j) * F(j + h) < 0) {
                int iterations = 0;
                double res = Simple_Iteration(j, epsilon, iterations);
                cout << "Корень: x = " << res << "\n" << "Значение функции: y = " << F(res) << "\n";
                cout << "Число итераций: " << iterations << "\n";
                found = true;
            }
        }
        break;
    }
    }
    if (found == false) cout << "Корни не найдены на заданном отрезке!";
    return 0;
}
