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

using namespace std;

using ll = long long;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int xdiff = c - a;
	int ydiff = d - b;

	for (int i = 0; i < ydiff; i++)
	{
		cout << 'U';
	}
	for (int i = 0; i < xdiff; i++)
	{
		cout << 'R';
	}

	for (int i = 0; i < ydiff; i++)
	{
		cout << 'D';
	}
	for (int i = 0; i < xdiff; i++)
	{
		cout << 'L';
	}

	cout << 'L';
	for (int i = 0; i < ydiff + 1; i++)
	{
		cout << 'U';
	}
	for (int i = 0; i < xdiff + 1; i++)
	{
		cout << 'R';
	}
	cout << 'D';

	cout << 'R';
	for (int i = 0; i < ydiff + 1; i++)
	{
		cout << 'D';
	}
	for (int i = 0; i < xdiff + 1; i++)
	{
		cout << 'L';
	}
	cout << 'U';

	cout << endl;
}