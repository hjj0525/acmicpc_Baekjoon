#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#pragma warning(disable: 4996);
#define ll long long
using namespace std;

// -3 = 1 * (-2) - 1 = 2 * (-2) + 1
// 로 표현할 수 있다. 좌변이 컴퓨터의 계산이고, 우변이 풀이 방식이다.
// 이를 위해서, 나머지는 부호만 바꿔주고, 수는 1만큼 빼주어 몫을 하나 키워준다.
void cal(ll num) {
	if (num == 0)
		return;
	if (num < 0) {
		cal((num - 1) / -2);
		cout << -num % 2;
	}
	else if (num > 0) {
		cal(num / -2);
		cout << num % -2;
	}
}

int main() {
	ll n;
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	cal(n);

	return 0;
}