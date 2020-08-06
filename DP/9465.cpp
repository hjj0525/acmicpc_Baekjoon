#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int score[2][100001] = { 0, };
		int dp[2][100001] = { 0, };

		for (int i = 0; i < 2; i++) 
			for (int j = 0; j < n; j++) 
				cin >> score[i][j];
		
		dp[0][0] = score[0][0];
		dp[1][0] = score[1][0];
		dp[0][1] = score[0][1] + dp[1][0];
		dp[1][1] = score[1][1] + dp[0][0];

		for (int i = 2; i < n; i++) {
			dp[0][i] = score[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = score[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}
	
		cout << max(dp[0][n-1], dp[1][n-1]) << endl;
	}


	return 0;
}