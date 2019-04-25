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
	int a, b, k;
	cin >> a >> b >> k;

	int cnt = 0;
	for (int i = min(a, b); i >= 1; i--)
	{
		if (a % i == 0 && b % i == 0)
			cnt++;

		if (cnt == k)
		{
			cout << i << endl;
			break;
		}
	}
}