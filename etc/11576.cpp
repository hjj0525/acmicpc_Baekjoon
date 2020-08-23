#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#pragma warning(disable: 4996);
#define ll long long
using namespace std;

void cal(int B, int num) {
	if (num == 0)
		return;

	cal(B, num / B);
	cout << num % B << " ";
}

int main() {
	int A, B;
	cin >> A >> B;
	int m;
	cin >> m;
	vector<int> num;
	for (int i = 0; i < m;i++) {
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}
	int dec = 0;
	for (int i = 0; i < m; i++)
		dec += pow(A, i) * num[m - i - 1];

	cal(B, dec);
	return 0;
}