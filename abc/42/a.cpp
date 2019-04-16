#include <iostream>

using namespace std;

bool isFSF(int a, int b, int c) {
	int f = 2;
	int s = 1;
	if(a == 5) f--;
	if(a == 7) s--;
	if(b == 5) f--;
	if(b == 7) s--;
	if(c == 5) f--;
	if(c == 7) s--;
	return f == 0 && s == 0;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
    if(isFSF(a, b, c)) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}