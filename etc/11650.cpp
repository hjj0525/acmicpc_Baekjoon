#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// pair �ڷ����� �̿����� 

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int main() {
	int n;
	vector<pair<int, int>> v;
	cin >> n;

	for (int i = 0, x=0, y=0; i < n; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end(), cmp); // �������� cmp �Լ��� ����

	// vector�� iterator�� �̿��ؼ� ������ ���� �ݺ������� ������ �� ����
	for (vector<pair<int, int>>::iterator it = v.begin(); it != v.end(); it++) {
		cout << it->first << " " << it->second << "\n";
	}

	return 0;
}