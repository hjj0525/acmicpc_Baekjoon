#include <algorithm>
#include <iostream>
#define DIV 1000000000
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	long dp[201][201] = { 0, };
	// 전체적으로 계차수열로 이루어져 있음
	// 기본 초기화
	int chk = max(n, k);
	for (int i = 0; i <= chk; i++) {
		dp[i][1] = 1;
		dp[0][i] = 1;
	}
	dp[0][0] = 0;
	for (int i = 1; i <= chk; i++) {
		for (int j = 2; j <= chk; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % DIV;
		}
	}

	cout << dp[n][k] << endl;

	


	return 0;
}
