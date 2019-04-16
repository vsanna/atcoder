#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;

void Print(vector<ll> nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
}
int main()
{
	int n, t;
	cin >> n >> t;
	vector<ll> prices(n);
	for (int i = 0; i < n; i++)
	{
		cin >> prices[i];
	}

	ll min = -1;
	ll max_profit_cnt = 0;
	ll max_profit = 0;

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			min = prices[i];
			continue;
		}

		if (min > prices[i])
		{
			min = prices[i];
		}

		ll profit = prices[i] - min;
		if (profit == max_profit)
		{
			max_profit_cnt++;
		}
		else if (profit > max_profit)
		{
			max_profit_cnt = 1;
			max_profit = profit;
		}
	}

	cout << max_profit_cnt << endl;
}