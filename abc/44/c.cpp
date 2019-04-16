#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <sstream>

using namespace std;

using ll = long long;

int main()
{
	int n, a;
	cin >> n >> a;

	vector<int> cards(n + 1);
	ll maxsum = 0;
	// 1-indexedにするほうがいい
	for (int i = 1; i <= n; i++)
	{
		cin >> cards[i];
		maxsum += cards[i];
	}

	// dpの範囲外を問う条件に注意
	if (a > maxsum)
	{
		cout << 0 << endl;
		return 0;
	}

	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(maxsum + 1, 0)));
	// i: 使うカードの種類数. i=kのとき、0...k-1までのk枚を使う
	for (int i = 0; i <= n; i++)
	{
		// j: そのうちj枚使う
		for (int j = 0; j <= n; j++)
		{
			// sum: 合計いくつにするか
			for (int sum = 0; sum <= maxsum; sum++)
			{
				if (i == 0)
				{
					if (j == 0)
					{
						dp[i][j][sum] = (sum == 0) ? 1 : 0;
					}
				}
				else
				{
					if (sum < cards[i])
					{
						dp[i][j][sum] = dp[i - 1][j][sum];
					}
					else
					{
						if (j == 0)
						{
							dp[i][j][sum] = (sum == 0) ? 1 : 0;
						}
						else
						{
							dp[i][j][sum] = dp[i - 1][j][sum] + dp[i - 1][j - 1][sum - cards[i]];
						}
					}
				}
			}
		}
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ll tmp = dp[n][i][i * a];
		ans += tmp;
	}

	cout << ans << endl;
}