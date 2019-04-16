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

int main()
{
	string s;
	cin >> s;

	string k1 = "dream";
	string k2 = "dreamer";
	string k3 = "erase";
	string k4 = "eraser";

	while (true)
	{
		if (s.length() >= k1.length() && s.substr(s.length() - k1.length()) == k1)
		{
			s = s.substr(0, s.length() - k1.length());
			continue;
		}
		if (s.length() >= k2.length() && s.substr(s.length() - k2.length()) == k2)
		{
			s = s.substr(0, s.length() - k2.length());
			continue;
		}
		if (s.length() >= k3.length() && s.substr(s.length() - k3.length()) == k3)
		{
			s = s.substr(0, s.length() - k3.length());
			continue;
		}
		if (s.length() >= k4.length() && s.substr(s.length() - k4.length()) == k4)
		{
			s = s.substr(0, s.length() - k4.length());
			continue;
		}
		break;
	}

	if (s.length() == 0)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}