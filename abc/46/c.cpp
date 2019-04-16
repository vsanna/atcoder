#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;
using ll = long long;

// 最大公約数
ll gcd(ll a, ll b)
{
	if (a < b)
	{
		ll tmp = b;
		b = a;
		a = tmp;
	}
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

// 最小公倍数
ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> votes;

	ll total_t = 0;
	ll total_a = 0;

	for (int i = 0; i < n; i++)
	{
		int t, a;
		cin >> t >> a;

		printf("\n%d %d %lld %lld\n", t, a, total_t, total_a);

		if (i == 0)
		{
			total_t = t;
			total_a = a;
		}
		else
		{
			ll lcm_of_t = lcm(total_t, t);
			ll tmp_t = lcm_of_t;

			while (true)
			{
				if (tmp_t % a == 0 && (tmp_t / t) * a >= total_a)
					break;
				tmp_t += lcm_of_t;
			}
			total_t = tmp_t;
			total_a = (tmp_t / t) * a;
		}
	}

	cout << (total_t + total_a) << endl;
}
