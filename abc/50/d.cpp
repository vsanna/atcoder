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

ll calc(ll n, ll mod)
{
	if (n % 2 == 1)
	{
		ll end = (n + 1) / 2;
		cout << end << endl;
		cout << ((end % mod) * ((end + 1) % mod) % mod) << endl;
		return (end % mod) * ((end + 1) % mod) % mod;
	}
	else
	{
		return (calc(n - 1, mod) + (n / 2 + 1) % mod) % mod;
	}
}

int main()
{
	ll mod = 1000000007;

	ll n;
	cin >> n;

	cout << calc(n, mod) << endl;
}