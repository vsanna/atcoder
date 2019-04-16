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
#include <sstream>

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

int ctoi(char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}
	return 0;
}

// itoc
char itoc(int n)
{
	if (n > 9 || n < 0)
		throw std::invalid_argument("received invalid range value");

	return char('0') + n;
}

// stoi
// built-inである

// itos
string itos(int num)
{
	std::stringstream ss;
	ss << num;
	return ss.str();
}

// ctos

int main()
{
	string sample = "hoge,geho,gaho,asf";
	vector<string> splitted = split(sample, ",");
	for (auto str : splitted)
	{
		cout << str << endl;
	}

	cout << join(splitted, "-") << endl;

	cout << "3:" << itoc(3) << " type: " << typeid(itoc(3)).name() << endl;
	cout << "8:" << ctoi('8') << " type: " << typeid(ctoi('8')).name() << endl;
	cout << "511:" << stoi("511") << " type: " << typeid(stoi("511")).name() << endl;
	cout << "123123:" << itos(123123) << " type: " << typeid(itos(123123)).name() << endl;
}