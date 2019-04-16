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

// 最大公約数
template <typename T>
T gcd(T a, T b)
{
	if (a < b)
	{
		T tmp = b;
		b = a;
		a = tmp;
	}
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

// 最小公倍数
template <typename T>
T lcm(T a, T b)
{
	return a * b / gcd(a, b);
}

// 素数判定
template <typename T>
bool isPrime(T num)
{
	if (num < 2)
		return false;

	for (int i = 2; i < sqrt(num); i++)
	{
		if (num % i == 0)
			return false;
	}

	return true;
}

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
				cout << "before: " << table[j] << endl;
				if (table[j] && (j % i == 0))
				{
					table[j] = false;
				}
				cout << "after: " << table[j] << endl;
			}
		}
	}

	std::vector<T> result;
	for (int i = 2; i <= max; i++)
	{
		cout << "table: " << i << " => " << table[i] << endl;
		if (table[i])
			result.push_back(i);
	}

	return result;
}

// 約数の個数列挙: O(sqrt(N))
template <typename T>
T countDivisor(T num, T mod = 1000000007)
{
	if (num < 1)
		return num;

	int ans = 0; // 1と自分

	for (int i = 1; i <= sqrt(num); i++)
	{
		if (num % i == 0)
			ans += (i == sqrt(num) ? 1 : 2);
	}

	return ans;
}

// 約数列挙: O(sqrt(N))
template <typename T>
vector<T> divisors(T num)
{
	if (num == 0)
		return vector<int>{};
	if (num == 1)
		return vector<int>{1};

	vector<T> ans;

	for (int i = 1; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{

			if (i == sqrt(num))
			{
				ans.push_back(sqrt(num));
			}
			else
			{
				ans.push_back(i);
				ans.push_back(num / i);
			}
		}
	}
	sort(ans.begin(), ans.end());

	return ans;
}

template <typename T>
std::unordered_map<int, int> primeFactorize(std::vector<ll> &primes, T num)
{
	std::unordered_map<int, int> mp;

	if (num == 0)
	{
		throw std::invalid_argument("num must be gt 0");
	}

	for (int i = 0; i < primes.size(); i++)
	{
		ll p = primes[i];
		T tmp = num;

		while (num % p == 0)
		{
			mp[p]++;
			tmp = tmp / p;
		}
	}

	return mp;
}

int main()
{
	cout << gcd(15, 13) << endl;
	cout << lcm(15, 12) << endl;
	for (int i = 0; i <= 20; i++)
	{
		cout << "i: " << i << " ans: " << countDivisor(i) << endl;
		for (int j = 0; j < divisors(i).size(); j++)
			cout << divisors(i)[j] << ", ";
		cout << endl;
	}

	auto primes = createPrimeList(100);
	cout << "size: " << primes.size() << endl;
	for (int i = 0; i < primes.size(); i++)
	{
		cout << "prime: " << primes[i] << endl;
	}
}