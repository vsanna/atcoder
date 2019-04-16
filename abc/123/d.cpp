#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using ll = long long;

using namespace std;

int main()
{
	int x, y, z, k;
	cin >> x >> y >> z >> k;

	vector<ll> as(x), bs(y), cs(z);

	for (int i = 0; i < x; i++)
		cin >> as[i];
	for (int i = 0; i < y; i++)
		cin >> bs[i];
	for (int i = 0; i < z; i++)
		cin >> cs[i];

	sort(as.begin(), as.end());
	reverse(as.begin(), as.end());
	sort(bs.begin(), bs.end());
	reverse(bs.begin(), bs.end());
	sort(cs.begin(), cs.end());
	reverse(cs.begin(), cs.end());

	vector<ll> ab, abc;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			ab.push_back(as[i] + bs[j]);
		}
	}

	sort(ab.begin(), ab.end());
	reverse(ab.begin(), ab.end());

	for (int i = 0; i < min(k, (int)ab.size()); i++)
	{
		for (int j = 0; j < cs.size(); j++)
		{
			abc.push_back(ab[i] + cs[j]);
		}
	}

	sort(abc.begin(), abc.end());
	reverse(abc.begin(), abc.end());

	for (int i = 0; i < k; i++)
	{
		cout << abc[i] << endl;
	}
}