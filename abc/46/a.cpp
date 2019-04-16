#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int cnt = 1;
	if(a != b) cnt++;
	if(c != a && c != b) cnt++;
	cout << cnt << endl;
}