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

int main()
{
	int n;
	cin >> n;
	unordered_set<ll> divs;

	for (int i = 1; i <= n; i++)
	{
		auto divsOfI = divisors(i);
		divs.insert(divsOfI.begin(), divsOfI.end());
		cout << "i:" << i << " size: " << divs.size() << endl;
	}
	cout << (divs.size() & 1000000007) << endl;
}