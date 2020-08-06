#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	long n;
	long dp[100001] = { 0, };

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j*j <= i; j++) {
			if (dp[i] > dp[i - j * j] + 1 || dp[i] == 0)
				dp[i] = dp[i - j * j] + 1;
		}
	}


	cout << dp[n] << endl;

	return 0;
}
