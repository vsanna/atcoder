#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

#include <algorithm>

using namespace std;

using us = unordered_set<int>;

int main() {
	int n, k;
	cin >> n >> k;
	us availables = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for(int i = 0; i < k; i++) {
		int num; cin >> num;
		availables.erase(num);
	}

	while(true) {
		string num = to_string(n);
		bool found = false;
		for(int i = 0; i < num.size(); i++) {
			if(availables.find(num[i] - '0') == availables.end()) {
				break;
			}
			if(i == num.size() - 1) {
				found = true;
			}
		}
		if(found) {
			break;
		} else {
			n++;
		}
	}
	cout << n << endl;
}