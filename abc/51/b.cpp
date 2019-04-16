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

using namespace std;

using ll = long long;

int main()
{
	int k, s;
	cin >> k >> s;

	ll ans;

	for (int x = 0; x <= min(k, s); x++)
	{
		for (int y = 0; y <= min(k, s - x); y++)
		{
			int z = s - (x + y);
			if (z >= 0 && z <= k)
				ans++;
		}
	}

	cout << ans << endl;
}