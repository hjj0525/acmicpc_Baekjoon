#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// pair 자료형을 이용하자 

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second== b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	int n;
	vector<pair<int, int>> v;
	cin >> n;

	for (int i = 0, x=0, y=0; i < n; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end(), cmp); // 기준으로 cmp 함수를 실행

	// vector는 iterator를 이용해서 다음과 같이 반복문으로 구현할 수 있음
	for (vector<pair<int, int>>::iterator it = v.begin(); it != v.end(); it++) {
		cout << it->first << " " << it->second << "\n";
	}

	return 0;
}