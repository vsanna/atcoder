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

template <typename T>
inline bool chmax(T &a, T b)
{
	if (a < b)
	{
		a = b;
		return 1;
	}
	return 0;
}

int main()
{
	int n;
	cin >> n;
	vector<ll> hs(n+1, 0);

	vector<int> dp(n + 1, 0);

	for (int i = 1; i <= n; i++)
		cin >> hs[i];

	dp[0] = 0;
	dp[1] = hs[1];
	dp[2] = hs[2];

	for (int i = 3; i <= n; i++)
	{
		dp[i] = min(
			dp[i-1] + abs(hs[i]-hs[i-1])
		);
	}

	cout << dp[n] << endl;
}