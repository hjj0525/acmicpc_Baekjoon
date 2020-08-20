#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int n;
	char bracket[50];
	int chk = 0;
	cin >> n;
	while (n--) {
		stack<char> s;
		cin >> bracket;
		for (int i = 0; i < 50; i++) {
			if (bracket[i] == '(') {
				s.push(bracket[i]);
			}
			else if (bracket[i] == ')') {
				if (s.empty()) {
					chk = 1;
					break;
				}
				s.pop();
			}
			else
				break;
			chk = 0;
		}
		if (!s.empty())
			chk = 1;

		if (chk == 1)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
		
		chk = 0;
	
	}
	return 0;
}