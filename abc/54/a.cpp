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

string judge(int a, int b)
{
	if (a == b)
		return "Draw";

	if (a == 1)
		return "Alice";

	if (b == 1)
		return "Bob";

	return (a > b) ? "Alice" : "Bob";
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << judge(a, b) << endl;
}