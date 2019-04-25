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

// 1からnumまでのxor累積
ll factorialXOR(ll num)
{
	if (num <= 0)
		return 0;

	if (num <= 3)
	{
		ll ans = 1;
		for (int i = 2; i <= num; i++)
		{
			ans = ans ^ i;
		}
		return ans;
	}

	ll maxBy4 = 0;
	if (num % 4 == 0)
		maxBy4 = num - 1;
	if (num % 4 == 1)
		maxBy4 = num - 2;
	if (num % 4 == 2)
		maxBy4 = num - 3;
	if (num % 4 == 3)
		maxBy4 = num;

	ll ans = 0;
	while (maxBy4 < num)
	{
		maxBy4++;
		ans = ans ^ maxBy4;
	}

	return ans;
}

ll f(ll a, ll b)
{
	return factorialXOR(a - 1) ^ factorialXOR(b);
}

int main()
{
	ll a, b;
	cin >> a >> b;
	cout << f(a, b) << endl;
}