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

int main()
{
	ll mod = 1000000007;
	int n;
	cin >> n;

	unordered_map<int, ll> frac;
	frac[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		frac[i] = frac[i - 1] * i % mod;
	}

	vector<int> mp(n, 0);

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		mp[a]++;
	}

	//err check
	for (int i = 0; i < n; i++)
	{
		bool err = false;
		if (n % 2 == 0)
		{
			if (i % 2 == 0 && mp[i] > 0)
			{
				err = true;
			}
		}
		else
		{
			if (mp[0] != 1)
			{
				err = true;
			}

			if (i % 2 == 1 && mp[i] > 0)
			{
				err = true;
			}
		}

		if (err)
		{
			cout << 0 << endl;
			return 0;
		}
	}

	ll ans = 1;
	for (int i = 0; i < n; i++)
	{
		ans = ans * frac[mp[i]] % mod;
	}

	cout << ans << endl;
}