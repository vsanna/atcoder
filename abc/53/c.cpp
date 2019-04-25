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

template <typename T>
inline bool chmax(T &a, T b)
{
	if (a < b)
	{
		a = b;
		return 1;
	}
	return 0;
}

// 65 65  65 65
int main()
{
	ll x;
	cin >> x;
	ll cnt = x / 11;
	if (x % 11 == 0)
	{
		cout << cnt * 2 << endl;
	}
	else if (x % 11 > 6)
	{
		cout << (cnt * 2 + 2) << endl;
	}
	else
	{
		cout << (cnt * 2 + 1) << endl;
	}
}