#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
#pragma warning(disable: 4996);
using namespace std;

// 유클리드 호제법을 이용한 최대공약수 구하기
int GCD(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return GCD(b, a%b);
	}
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n1, n2;
		cin >> n1 >> n2;
		int gcd = GCD(n1,n2);
		int lcm = n1 * n2 / gcd;
		cout << lcm << endl;
	}
	return 0;
}