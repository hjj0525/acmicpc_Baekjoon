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
			// 단순히 int로 선언하고 mod 연산을 통해서도 해결 할 수 있다.
			if (num / (float)i - (int)num / i == 0) 
				cnt++;
		}
		if (cnt == 2)
			prime++;
	}
	cout << prime << '\n';
	return 0;
}