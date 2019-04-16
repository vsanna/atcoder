#include <iostream>
#include <vector>
#include <string>

#include <algorithm>

using namespace std;

int main() {
	int n, l;
	cin >> n >> l;
	vector<string> words;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		words.push_back(s);
	}

	sort(words.begin(), words.end());

	string ans;
	
	for(auto itr = words.begin(); itr != words.end(); itr++) {
		ans += *itr;
	}

	cout << ans;
}