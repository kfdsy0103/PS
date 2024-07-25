// 완탐 -> 2^60 : 시간초과 -> dp.
// long long
#include <bits/stdc++.h>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
const int INF = 99999999;
int n, m;
long long dp[51][51];

long long go(int a, int b) {
	if (a == 0 && b == 0) return 1;
	long long &ret = dp[a][b];
	if (ret) return ret;
	if (a > 0) ret += go(a - 1, b + 1);
	if (b > 0) ret += go(a, b - 1);
	return ret;
}

int main() {
	
	while (true) {
		cin >> n;
		if (n == 0) break;
		cout << go(n, 0) << "\n";
	}
	
	return 0;
}
