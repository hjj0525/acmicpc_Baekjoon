#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#pragma warning(disable: 4996);
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	string s1 = to_string(a) + to_string(b);
	string s2 = to_string(c) + to_string(d);

	// stoi: string to int
	// stol: string to long
	// stoll: string to long long
	long long n1 = stoll(s1);
	long long n2 = stoll(s2);
	cout << n1 + n2 << endl;
	return 0;
}