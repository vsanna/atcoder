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
	string s;
	cin >> s;
	int from = -1;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'A' && from == -1)
		{
			from = i;
			break;
		}
	}

	int to = -1;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] == 'Z' && to == -1)
		{
			to = i;
			break;
		}
	}

	cout << (to - from + 1) << endl;
}