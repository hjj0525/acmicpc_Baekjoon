#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N, n1, n2;
	cin >> N;

	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		cin >> n1 >> n2;
		v.push_back(make_pair(n1, n2));
	}

	sort(v.begin(), v.end(), cmp);

	int cnt = 1;
	int min = v[0].second;

	for (int i = 1; i < N; i++) {
		if (v[i].first >= min) {
			min = v[i].second; // 미리 정렬 해놓아서 사용할 수 있음
			cnt++;
		}
	}
	
	cout << cnt << '\n';

	return 0;
}