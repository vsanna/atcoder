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
	int n, a, b;
	cin >> n >> a >> b;

	ll cost = 0;
	ll current;
	cin >> current;

	for (int i = 1; i < n; i++)
	{
		ll next;
		cin >> next;
		cost += min((ll)b, (next - current) * a);
		current = next;
	}

	cout << cost << endl;
}