#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using ll = long long;

using namespace std;

int main()
{
	int a, b, c, d, e, k;
	cin >> a >> b >> c >> d >> e >> k;

	if (e - a <= k)
	{
		cout << "Yay!" << endl;
	}
	else
	{
		cout << ":(" << endl;
	}
}