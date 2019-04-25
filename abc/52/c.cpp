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

// O(N)
template <typename T>
std::vector<T> createPrimeList(T max)
{
	if (max < 2)
		throw std::invalid_argument("max must be gteq 2");

	std::vector<bool> table(max + 1, true);
	table[0] = false;

	for (int i = 2; i <= max; i++)
	{
		if (table[i])
		{
			for (int j = i + 1; j <= max; j++)
			{
				if (table[j] && (j % i == 0))
				{
					table[j] = false;
				}
			}
		}
	}

	std::vector<T> result;
	for (int i = 2; i <= max; i++)
	{
		if (table[i])
			result.push_back(i);
	}

	return result;
}

using ll = long long;
template <typename T>
void primeFactorize(std::vector<T> &primes, unordered_map<int, int> &mp, T num)
{

	if (num == 0)
	{
		throw std::invalid_argument("num must be gt 0");
	}

	for (int i = 0; i < primes.size(); i++)
	{
		ll p = primes[i];
		if (p > num)
			break;

		T tmp = num;

		while (tmp % p == 0)
		{
			mp[p]++;
			tmp = tmp / p;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	unordered_set<ll> divs;

	vector<int> primes = createPrimeList(10000);
	std::unordered_map<int, int> mp;
	for (int i = 1; i <= n; i++)
	{
		primeFactorize(primes, mp, i);
	}

	ll ans = 1;
	ll mod = 1000000007;
	for (auto kv : mp)
	{
		ans = (ans * (kv.second + 1)) % mod;
	}

	cout << ans << endl;
}
