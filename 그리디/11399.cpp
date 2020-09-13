#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int time;
		cin >> time;
		v.push_back(time);
	}

	sort(v.begin(), v.end());

	int sum = 0;

	for (int i = 0; i < N; i++) {
		sum += v[i] * (N - i);
	}

	cout << sum << '\n';

	return 0;
}
