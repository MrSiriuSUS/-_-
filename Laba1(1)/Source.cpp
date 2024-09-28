#include <cmath>
#include <iostream>
using namespace std;
int main() {
	double a, b, z1, z2;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	z1 = pow((cos(a) - cos(b)), 2) - pow((sin(a) - sin(b)), 2);
	cout << "z1 = " << z1;
	cout << "\n";
	z2 = -4 * pow(sin((a - b) / 2.), 2) * cos(a + b);
	cout << "z2 = " << z2;
}