#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <utility>

using namespace std;

bool isUnbalanced(string s, int start, int end){
	string target = s.substr(start, (end - start + 1));
	if(target.length() == 2) {
		return target[0] == target[1];
	}

	unordered_map<char, int> freq; // defaultで0
	for(int i = 0; i < target.length(); i++) {
		char c = target[i];
		freq[c]++;
		if(freq[c] > floor(target.length() / 2.0)) {
			return true;
		}
	}

	return false;
}

int main() {
	string input;
	cin >> input;

	for(int i = 0; i < input.length(); i++) {
		for(int j = input.length() - 1; j >= 0; j--) {
			if(i == j) break;
			if(isUnbalanced(input, i, j)) {
				cout << i+1 << " " << j+1 << endl;
				return 0;
			}
		}
	}

	cout << "-1 -1" << endl;
}