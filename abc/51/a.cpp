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
vector<string> split(string src, string del = "")
{
	vector<string> result;

	if (del == "")
	{
		for (char s : src)
		{
			result.push_back(string{s});
		}
		return result;
	}

	int start = 0;
	int last = src.find_first_of(del);

	while (start < src.length())
	{
		string sub(src, start, last - start);

		result.push_back(sub);

		start = last + 1;
		last = src.find_first_of(del, start);
		if (last == string::npos)
		{
			last = src.size();
		}
	}

	return result;
}

string join(vector<string> els, string con = "")
{
	string result = "";

	for (auto itr = els.begin(); itr != els.end(); itr++)
	{
		result += *itr;
		if (itr + 1 != els.end())
		{
			result += con;
		}
	}

	return result;
}

int main()
{
	string input;
	cin >> input;

	cout << (join(split(input, ","), " ")) << endl;
}