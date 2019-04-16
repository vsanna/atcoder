#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;

int on(int bits, int pos) {
	int mask = 1 << pos;
	return bits | mask;
}

ll calc(string s, int bits) {
	vector<int> nums;
	int len = 1;

	while(bits > 0) {
		if((bits & 1) > 0) {
			nums.push_back(stoll(s.substr(0, len)));
			s = s.substr(len);
			len = 1;
		} else {
			len++;
		}
		bits = bits >> 1;
	}
	nums.push_back(stoll(s));


	ll sum = 0;
	for(auto itr = nums.begin(); itr != nums.end(); itr++) {
		cout << *itr;
		cout << "/";
		sum += *itr;
	}
	cout << endl;
	return sum;
}

int cnt = 0;

void dfs(string s, int bits, int pos, ll& result) {
	if(pos > s.length() - 2) {
		cnt++;
		ll tmp = calc(s, bits);
		result += tmp;
		return;
	}

	dfs(s, bits, pos + 1, result);
	bits = on(bits, pos);
	dfs(s, bits, pos + 1, result);
}

int main() {
	string s;
	cin >> s;

	ll result = 0;

	dfs(s, 0, 0, result);

	cout << result << endl;
	cout << cnt;
}