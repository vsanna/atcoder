#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <cmath>

using ll = long long;

using namespace std;

ll n, a, b, c, d, e;

int main()
{
	cin >> n >> a >> b >> c >> d >> e;
	vector<ll> nums{a, b, c, d, e};

	ll min = a;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] < min)
		{
			min = nums[i];
		}
	}
	cout << ll(5 + floor((n - 1) / min)) << endl;
}

// 1000000000000000