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

	fill(dp, dp + 100001, INF);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	cout << (dp[k] == INF ? -1 : dp[k]);

	return 0;
}