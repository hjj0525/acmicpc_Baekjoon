#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// pair 자료형을 이용하자 

bool cmp(pair<int, string> a, pair<int, string> b) {
	if (a.first < b.first)
		return true;
	else if (a.first == b.first)
		return false;
	return false;
}

int main() {
	int n;
	vector<pair<int, string>> v;
	cin >> n;
	int age;
	string name;
	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		v.push_back(make_pair(age, name));
	}

	// stable sort는 순서를 보장한다.
	stable_sort(v.begin(), v.end(), cmp); // 기준으로 cmp 함수를 실행

	// vector는 iterator를 이용해서 다음과 같이 반복문으로 구현할 수 있음
	for (vector<pair<int, string>>::iterator it = v.begin(); it != v.end(); it++) {
		cout << it->first << " " << it->second << "\n";
	}

	return 0;
}