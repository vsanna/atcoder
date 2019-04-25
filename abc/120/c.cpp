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
	string s;
	cin >> s;
	int red = 0;
	int blue = 0;
	for (int i = 1; i <= s.length(); i++)
	{
		s[i - 1] == '0' ? red++ : blue++;
	}

	cout << (min(red, blue) * 2) << endl;
}