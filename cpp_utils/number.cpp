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

// 素数リストを作る: O(N)
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

// 素因数分解. 1を含まないので約数列挙と微妙にロジック異なる
template <typename T>
std::unordered_map<int, int> primeFactorize(std::vector<T> &primes, T num)
{
	std::unordered_map<int, int> mp;

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

	return mp;
}

// 1からnumまでのxor累積
ll factorialXOR(ll num)
{
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

	ll ans = maxBy4;
	while (maxBy4 < num)
	{
		maxBy4++;
		ans = ans ^ maxBy4;
	}

	return ans;
}

int main()
{
	// cout << gcd(15, 13) << endl;
	// cout << lcm(15, 12) << endl;

	// for (int i = 0; i <= 20; i++)
	// {
	// 	cout << "i: " << i << " ans: " << countDivisor(i) << endl;
	// 	for (int j = 0; j < divisors(i).size(); j++)
	// 		cout << divisors(i)[j] << ", ";
	// 	cout << endl;
	// }

	vector<int> primes = createPrimeList(10000);
	auto primeFactors = primeFactorize(primes, 120);

	cout << primeFactors.size() << endl;

	for (auto kv : primeFactors)
	{
		cout << kv.first << " => " << kv.second << endl;
	}
}