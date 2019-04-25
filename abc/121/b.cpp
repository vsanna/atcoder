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

int main()
{
	int n, m, c;
	cin >> n >> m >> c;

	vector<int> bs(m + 1);
	for (int i = 1; i <= m; i++)
		cin >> bs[i];

	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		ll sum = 0;
		for (int j = 1; j <= m; j++)
		{
			int a;
			cin >> a;
			sum += (a * bs[j]);
		}
		if (sum + c > 0)
			ans++;
	}

	cout << ans << endl;
}