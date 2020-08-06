#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	int MOD = 10007;
	int sum = 0;
	int dp[1001][10] = { 0, };
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= T; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
			}
			dp[i][j] %= MOD; // 주의하기!
		}
	}

	for (int i = 0; i <= 9; i++)
		sum += dp[T][i];

	cout << sum % MOD << endl;
	return 0;
}