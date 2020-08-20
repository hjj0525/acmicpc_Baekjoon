#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Student {
public:
	string name;
	int korean;
	int english;
	int math;
};

bool cmp(Student a, Student b) {
	if (a.korean > b.korean) // 앞에 것이 증가하는 순으로 (내림차순)
		return true;
	else if (a.korean == b.korean && a.english == b.english && a.math == b.math)
		return a.name < b.name;
	else if (a.korean == b.korean && a.english == b.english)
		return a.math > b.math;
	else if (a.korean == b.korean)
		return a.english < b.english;
	return false;
}

int main() {
	int n;
	vector<Student> v;
	cin >> n;
	Student tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp.name >> tmp.korean >> tmp.english >> tmp.math;
		v.push_back(tmp);
	}

	// stable sort는 순서를 보장한다.
	stable_sort(v.begin(), v.end(), cmp); // 기준으로 cmp 함수를 실행

	for (int i = 0; i < n; i++) {
		cout << v[i].name << "\n";
	}
	return 0;
}