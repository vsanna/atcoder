#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	long long result = 0;
	result = pow((k-1), (n-1)) * k;

	cout << result << endl;

	// k * (k-1) * (k-1) * (k-1);
}