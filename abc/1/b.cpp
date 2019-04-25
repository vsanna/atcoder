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

int main()
{
	int m;
	cin >> m;
	if (m < 100)
	{
		cout << "00" << endl;
	}
	else if (m <= 5000)
	{
		ll vv = (m * 10 / 1000);
		if (vv >= 10)
		{
			cout << vv << endl;
		}
		else
		{
			cout << "0" << vv << endl;
		}
	}
	else if (m <= 30000)
	{
		ll vv = (m / 1000) + 50;
		cout << vv << endl;
	}
	else if (m <= 70000)
	{
		ll vv = (((m / 1000) - 30) / 5) + 80;
		cout << vv << endl;
	}
	else
	{
		cout << 89 << endl;
	}
}