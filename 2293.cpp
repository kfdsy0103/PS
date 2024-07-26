#include <bits/stdc++.h>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
const int INF = 99999999;
int n, k;
int coin[101];
int dp[100001];

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		int c = coin[i];
		for (int j = c; j <= k; j++) {
			dp[j] += dp[j - c];
		}
	}

	cout << dp[k];
	
	return 0;
}