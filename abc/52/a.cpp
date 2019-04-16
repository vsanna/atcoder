#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	ll A = a * b;
	ll B = c * d;
	cout << (A >= B ? A : B) << endl;
}