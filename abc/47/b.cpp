#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int w, h, n;
	cin >> w >> h >> n;

	int min_h = 0;
	int max_h = h;

	int min_w = 0;
	int max_w = w;

	for (int i = 0; i < n; i++)
	{
		int x, y, a;
		cin >> x >> y >> a;
		switch (a)
		{
		case 1:
			min_w = x;
			break;
		case 2:
			max_w = x;
			break;
		case 3:
			min_h = y;
			break;
		case 4:
			max_h = y;
			break;
		}
	}

	cout << max(((max_w - min_w) * (max_h - min_h)), 0) << endl;
}