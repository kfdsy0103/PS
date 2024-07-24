// a -> d 라고 했을 때,
// 만약 순서가 상관 있다면 {a, b, c, d}, {a, c, b, d} ...
// 순열로써 생각해야 하므로 16!의 시간복잡도가 나온다.
// 그러나 b를 먼저 방문하나, c를 먼저 방문하나 순서는 상관 없이
// {a, b, c}의 부분 최적해 + d로 가는 비용만 구하면 되므로,
// dp + 비트마스킹(특정 지점의 방문처리를 위함)을 활용한다.
// 또한 시작 지점은 어떤 곳이 되든 상관이 없다.
#include <bits/stdc++.h>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
const int INF = 99999999;
int n;
int mp[17][17];
int dp[17][1 << 16];

int travel(int here, int visited) {
	if (visited == (1 << n) - 1) {
		if (mp[here][0]) return mp[here][0];
		else return INF;
	}
	int& ret = dp[here][visited];
	if (~ret) return ret;
	ret = INF;
	for (int i = 0; i < n; i++) {
		if (visited & (1 << i)) continue; // 이미 방문된 지역
		if (mp[here][i] == 0) continue; // 갈 수 없는 지역
		ret = min(ret, travel(i, visited | (1 << i)) + mp[here][i]);
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
		}
	}
	
	cout << travel(0, 1);

	return 0;
}