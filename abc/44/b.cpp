#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

bool isBeauty(string w) {
	unordered_map<char, int> freq;
	for (int i = 0; i < w.length(); i++)
	{
		char c = w[i];
		if (freq[c] == 0)
		{
			freq[c]++;
		}
		else
		{
			freq[c]--;
		}
	}

	for(auto itr = freq.begin(); itr != freq.end(); itr++) {
		if(itr->second != 0) return false;
	}
	return true;
}

int main() {
	string w;
	cin >> w;
	cout << (isBeauty(w) ? "Yes" : "No") << endl;
}