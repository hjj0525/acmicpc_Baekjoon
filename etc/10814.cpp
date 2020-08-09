#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// pair �ڷ����� �̿����� 

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

	// stable sort�� ������ �����Ѵ�.
	stable_sort(v.begin(), v.end(), cmp); // �������� cmp �Լ��� ����

	// vector�� iterator�� �̿��ؼ� ������ ���� �ݺ������� ������ �� ����
	for (vector<pair<int, string>>::iterator it = v.begin(); it != v.end(); it++) {
		cout << it->first << " " << it->second << "\n";
	}

	return 0;
}