#include iostream
#include cstdio
#include algorithm
using namespace std;
constexpr auto MOD = 1000000000;;


int main() {
	int n;
	long sum=0;
	cin  n;
	long dp[101][11] = { 0, };
	for (int i = 1; i = 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i = n; i++) {
		for (int j = 0; j = 9; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1] % MOD;
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1] % MOD;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;

		}
	}
	for (int i = 0; i = 9; i++)
		sum += dp[n][i];

	cout  (sum % MOD)  endl;
	return 0;
}
 sliding window 기법으로도 풀 수 있음 dp[2][11]로 생각 가능 - 점화식에서는 두 배열만 계산하면 되기 때문