#include <algorithm>
#include <iostream>
#include <string>
#define DIV 1000000

using namespace std;

int main() {
	string pw;
	int dp[5000][2] = { 0, };
	
	// 0행은 끝이 한자리로 끝나는 알파벳
	// 1행은 끝이 두자리로 끝나는 알파벳 (10~26)

	cin >> pw;
	if (pw[0] > '0') {
		dp[0][0] = 1;
		if(pw[1] > '0')
			dp[1][0] = 1;
		if (pw[0] == '1' || (pw[0] == '2' && pw[1] <= '6')) {
			dp[0][1] = 0;
			dp[1][1] = 1;
		}
	}


	for (int i = 2; i < pw.length(); i++) {
		if(pw[i] > '0')
			dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % DIV;
		if (pw[i-1] =='1' || (pw[i - 1] == '2' && pw[i] <= '6'))
			dp[i][1] = (dp[i - 2][0] + dp[i - 2][1]) % DIV;
		else
			dp[i][1] = 0;
	}
	cout << (dp[pw.length()-1][0] + dp[pw.length()-1][1]) % DIV << endl;
	return 0;
}
