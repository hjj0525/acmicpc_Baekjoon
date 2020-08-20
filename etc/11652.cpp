#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	long long input;
	vector <long long> v;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());

	int mostCnt = 1;
	long long mostIdx = v[0]; // 단 하나만 입력했을 때 예외를 처리해주기 위함
	int cnt = 1;

	for (int i = 1; i < N; i++) {
		if (v[i] == v[i - 1])
			cnt++;
		else
			cnt = 1;

		if (mostCnt < cnt) {
			mostCnt = cnt;
			mostIdx = v[i];
		}
	}

	cout << mostIdx << endl;

	return 0;
}