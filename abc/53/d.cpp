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

// 捨てたいカードで挟むようにする
// ダブった中での
// vector<i
int main()
{
	ll n;
	cin >> n;
	vector<ll> as(n);

	vector<ll> freq(100000, 0);
	vector<ll> uniq;

	vector<ll> duplicated;

	for (int i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		if (freq[a] == 0)
		{
			freq[a]++;
			uniq.push_back(a);
		}
		else
		{
			duplicated.push_back(a);
		}
	}

	sort(duplicated.begin(), duplicated.end());
	sort(uniq.begin(), uniq.end());

	// for (int i = 0; i < duplicated.size(); i++)
	// 	cout << "dup: " << duplicated[i] << endl;

	// for (int i = 0; i < uniq.size(); i++)
	// 	cout << "uniq: " << uniq[i] << endl;

	while (duplicated.size())
	{
		// cout << "size: " << duplicated.size() << endl;
		// for (int i = 0; i < duplicated.size(); i++)
		// 	cout << "dup: " << duplicated[i] << endl;

		// for (int i = 0; i < uniq.size(); i++)
		// 	cout << "uniq: " << uniq[i] << endl;
		// dupが3枚以上ある => dupの中心から3枚捨てる
		// dupが2枚 => dupから2枚, uniqの中央から1枚
		//   - 1枚しか捨てられない可能性がある
		// dupが1枚 => dupから1枚, uniqから2枚
		//   - 捨てられない可能性がある
		if (duplicated.size() >= 3)
		{
			ll center_idx = (duplicated.size() - 1) / 2;
			duplicated.erase(duplicated.begin() + (center_idx - 1));
			duplicated.erase(duplicated.begin() + (center_idx));
		}
		else if (duplicated.size() == 2)
		{
			ll top = duplicated.front(); // top < tail
			ll tail = duplicated.back();
			bool removed = false;
			for (int i = 0; i < uniq.size(); i++)
			{
				if (top <= uniq[i] && uniq[i] <= tail)
				{
					// 間にuniq挟んで処理
					duplicated.pop_back();
					duplicated.erase(duplicated.begin());
					cout << uniq.size() << endl;
					return 0;
				}
			}

			if (uniq.back() <= top)
			{
				uniq.pop_back();
				duplicated.pop_back();
			}
			else if (tail <= uniq.front())
			{
				uniq.erase(uniq.begin());
				duplicated.erase(uniq.begin());
			}
		}
		else
		{
			ll last_dup = duplicated.front();
			// duplicatedが1このとき
			// それよりおおきいものが2つある or 小さいものが2つある=>dup1ことuniq2個削る
			// そうでないとき == 1 dup 1　のときのみなので0かえす
			ll lg_cnt = 0;
			ll sm_cnt = 0;

			for (int i = 0; i < uniq.size(); i++)
			{
				if (uniq[i] <= last_dup)
					lg_cnt++;
				if (uniq[i] >= last_dup)
					sm_cnt++;
			}

			if (sm_cnt >= 2 || lg_cnt >= 2)
			{
				cout << uniq.size() - 1 << endl;
				return 0;
			}
			else
			{
				cout << 0 << endl;
				return 0;
			}
		}
	}

	cout << uniq.size() << endl;
}