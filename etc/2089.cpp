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
// �� ǥ���� �� �ִ�. �º��� ��ǻ���� ����̰�, �캯�� Ǯ�� ����̴�.
// �̸� ���ؼ�, �������� ��ȣ�� �ٲ��ְ�, ���� 1��ŭ ���־� ���� �ϳ� Ű���ش�.
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