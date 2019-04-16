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

int main()
{
	int n;
	cin >> n;

	vector<int> ts(n);
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> ts[i];
		sum += ts[i];
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int p, x;
		cin >> p >> x;
		cout << (sum - ts[p - 1] + x) << endl;
	}
}