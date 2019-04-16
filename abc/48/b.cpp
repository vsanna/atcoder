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

using namespace std;
using ll = long long;

ll deviders(ll a, ll b)
{
	return floor(a / (double long)b) + 1;
}

int main()
{
	ll a, b, x;
	cin >> a >> b >> x;
	ll cnt = 0;

	ll head = deviders(b, x);
	ll tail = (a == 0) ? 0 : deviders(a - 1, x);
	cnt = head - tail;
	cout << cnt << endl;
}