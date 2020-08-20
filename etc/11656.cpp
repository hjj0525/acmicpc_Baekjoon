#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#pragma warning(disable: 4996);
using namespace std;

// suffix
int main() {
	string word;
	vector<string> suffix;
	cin >> word;
	for (int i = 0; i < word.size(); i++) {
		suffix.push_back(word.substr(i));
	}
	sort(suffix.begin(), suffix.end());

	for (string x : suffix)
		cout << x << endl;
	return 0;
}