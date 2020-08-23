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
	int t, n;
	cin >> t;
	while (t--) {
		vector<int> num;
		long long res = 0;
		int tmp;
		cin >> n;
		while (n--) {
			cin >> tmp;
			num.push_back(tmp);
		}
		for (int i = 0; i < num.size(); i++) {
			for (int j = i + 1; j < num.size(); j++)
				res += GCD(num[i], num[j]);
		}
		cout << res << endl;
	}
	
	return 0;
}