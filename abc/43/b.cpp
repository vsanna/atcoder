#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string input;
	cin >> input;

	string ans;
	for(char& c: input) {
		if(c == '0' || c == '1') {
			string c_str{c}; // char to string
			ans += c_str;
		} else {
			if(ans.size() > 0) ans.pop_back(); // いけた
		}
	}

	cout << ans << endl;
}