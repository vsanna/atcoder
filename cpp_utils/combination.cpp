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

unordered_map<ll, ll> fracDP;	// n -> n!
unordered_map<ll, ll> invFracDP; // n -> n^-1
unordered_map<ll, ll> invDP;	 // n -> (n!)^-1

void initFracDP(ll n, ll p)
{
	fracDP[0] = fracDP[1] = 1;
	invFracDP[0] = 1;
	invFracDP[1] = 1;
	invDP[0] = 1;
	invDP[1] = 1;
	// 2から始める
	for (ll i = 2; i <= n; i++)
	{
		fracDP[i] = fracDP[i - 1] * i % p;
		invDP[i] = (p - (p / i)) * invDP[p % i] % p; // inv[i] = P - (P / i) * inv[P % i] % P;
		invFracDP[i] = invFracDP[i - 1] * invDP[i] % p;
	}
}

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
	// return (fractorial(n) * inverse(fractorial(r), p) % p) * inverse(fractorial(n - r), p) % p;
	return (fractorial(n) * invFracDP[r] % p) * invFracDP[n - r] % p;
}

int main()
{
	ll mod = 1000000007;

	initFracDP(1000000, mod);
	cout << combination(100000, 500, mod) << endl;
}