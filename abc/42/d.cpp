#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;

unordered_map<ll, ll> fracDP;

void initFracDP(ll n, ll p)
{
	fracDP[0] = 1;
	for (ll i = 1; i <= n; i++)
	{
		fracDP[i] = fracDP[i - 1] * i % p;
	}
}
// initFracDP(n, p);

ll fractorial(ll n)
{
	return fracDP[n];
}

ll pow(ll a, ll b, ll p)
{
	ll ans = 0;
	if (b == 0)
	{
		ans = 1 % p;
	}
	else if (b == 1)
	{
		ans = a % p;
	}
	else
	{
		if (b % 2 == 0)
		{
			ll tmp = pow(a, b / 2, p) % p;
			ans = (tmp * tmp) % p;
		}
		else
		{
			ans = a * pow(a, b - 1, p) % p;
		}
	}
	return ans;
}

ll inverse(ll n, ll p)
{
	return pow(n, (p - 2), p);
}

ll combination(ll n, ll r, ll p)
{
	return (fractorial(n) * inverse(fractorial(r), p) % p) * inverse(fractorial(n - r), p) % p;
}

ll mod = 1000000007;
int main()
{
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	ll ans = 0;

	initFracDP(h + w, mod);

	for (int i = b + 1; i <= w; i++)
	{
		ll before = combination(((h - a - 1) + (i - 1)), (h - a - 1), mod);
		ll after = combination(((a - 1) + (w - i)), (a - 1), mod);
		// cout << "before: " << before << endl;
		// cout << "after: " << after << endl;
		ans += (before * after) % mod;
		ans = ans % mod;
	}

	cout << ans << endl;
}