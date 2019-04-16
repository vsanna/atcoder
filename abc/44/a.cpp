#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n, k, x, y;
	cin >> n >> k >> x >> y;
	cout << (min(k, n) * x + max((n-k), 0) * y) << endl;
}