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
	int n;
	string s;
	cin >> n >> s;

	int x = 0;
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'I')
		{
			x++;
		}
		else
		{
			x--;
		}

		if (max < x)
			max = x;
	}

	cout << max << endl;
}