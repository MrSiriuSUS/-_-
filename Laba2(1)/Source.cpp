#include <iostream>
#include <cmath>
using namespace std;
int main(){
	double x, y, z;
	cout << "z =";
	cin >> z;
	cout << z;
	cout << "\n";
	if (z >= 0) {
		cout << "z>=0";
		cout << "\n";
		x = 2 * z + 1;
		cout << "x = 2 * z + 1";
	}
	else {
		cout << "z<0";
		cout << "\n";
		x = log(pow(z, 2) - z);
		cout << "x=ln((z^2)-z)";
	}
	cout << "\n";
	cout << "x=" << x;
	cout << "\n";
	y = pow(sin(x), 2) + pow(cos(pow(x, 3)), 5) + log(pow(x, 0.4));
	cout << "y=" << y;
	return 0;
}