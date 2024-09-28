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
            cout << "\n������� �� ���������� ��������!\n������� ��� ���: ";
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
    cout << "1 - ������ ������ �� ���������\n����� ���� ������ � ������\n";
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
        cout << "h (���) = ";
        h = Input();
        cout << "epsilon (��������) = ";
        epsilon = Input();
    }
    cout << "\n1 - ����� �������\n2 - ����� ������� ��������\n";
    switch (_getch()) {
    case '1': {
        for (double j = a; j <= b; j += h) {
            if (F(j) * F(j + h) < 0) {
                int iterations = 0;
                double res = Metod_Sec(j, epsilon, iterations);
                cout << "������: x = " << res << "\n" << "�������� �������: y = " << F(res) << "\n";
                cout << "����� ��������: " << iterations << "\n";
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
                cout << "������: x = " << res << "\n" << "�������� �������: y = " << F(res) << "\n";
                cout << "����� ��������: " << iterations << "\n";
                found = true;
            }
        }
        break;
    }
    }
    if (found == false) cout << "����� �� ������� �� �������� �������!";
    return 0;
}
