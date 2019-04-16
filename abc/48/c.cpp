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
using ull = unsigned long long;

int main()
{
	ll n, x;
	cin >> n >> x;

	ll cnt = 0;

	vector<ll> box;
	for (ll i = 0; i < n; i++)
	{
		ll tmp;
		cin >> tmp;
		box.push_back(tmp);
		// cin >> box[i]; だとREになった。なぜか不明
	}

	for (int i = 0; i < n - 1; i++)
	{
		if (box[i] > x)
		{
			cnt += box[i] - x;
			box[i] = x;
		}

		while (i < n && box[i] + box[i + 1] > x)
		{
			ll gap = box[i] + box[i + 1] - x;
			cnt += gap;
			if (gap > box[i + 1])
			{
				gap -= box[i + 1];
				box[i + 1] = 0;
				box[i] -= gap;
			}
			else
			{
				box[i + 1] -= gap;
			}
		}
	}

	cout << cnt << endl;
}