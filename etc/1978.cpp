#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#pragma warning(disable: 4996);
using namespace std;

int main() {
	int N;
	int prime=0;
	cin >> N;
	while (N--) {
		int cnt=0;
		float num;
		cin >> num;
		for (int i = 1; i <= num; i++) {
			// �ܼ��� int�� �����ϰ� mod ������ ���ؼ��� �ذ� �� �� �ִ�.
			if (num / (float)i - (int)num / i == 0) 
				cnt++;
		}
		if (cnt == 2)
			prime++;
	}
	cout << prime << '\n';
	return 0;
}