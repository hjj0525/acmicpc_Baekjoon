#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
#pragma warning(disable: 4996);
using namespace std;

// ��Ŭ���� ȣ������ �̿��� �ִ����� ���ϱ�
long long GCD(long a, long b) {
	if (b == 0) {
		return a;
	}
	else {
		return GCD(b, a%b);
	}
}
int main() {
	long long n1, n2;
	cin >> n1 >> n2;
	
	long long gcd = GCD(n1, n2);

	for (int i = 0; i < gcd; i++) {
		cout << '1';
	}
	
	return 0;
}