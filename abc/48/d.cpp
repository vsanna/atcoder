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

bool canTake(string &s, int const pos)
{
	return s[pos - 1] != s[pos + 1];
}

void take(string &s, int pos)
{
	string tmp = s.substr(0, pos) + s.substr(pos + 1);
	s = tmp;
}

int main()
{
	string s;
	cin >> s;

	string current = "First";
	while (true)
	{
		cout << s << endl;
		if (s.length() == 2)
		{
			// 取れなかった = 今の手番が負け = 相手が勝利
			cout << ((current == "First") ? "Second" : "First") << endl;
			return 0;
		}

		bool taken = false;
		for (int i = 1; i < s.length() - 1; i++)
		{
			if (canTake(s, i))
			{
				take(s, i);
				i--;
				current = (current == "First") ? "Second" : "First";
				taken = true;
				break;
			}
		}
		if (!taken)
		{
			// 取れなかった = 今の手番が負け = 相手が勝利
			cout << ((current == "First") ? "Second" : "First") << endl;
			return 0;
		}
	}
}