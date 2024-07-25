#include <bits/stdc++.h>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
const int INF = 99999999;
int n, m;
char mp[51][51];
int visited[51][51];
int dp[51][51];

bool check(int y, int x) {
	return (0 <= y && y < n && 0 <= x && x < m);
}

int go(int y, int x) {
	if (!check(y, x) || mp[y][x] == 'H') {
		return 0;
	}
	if (visited[y][x]) {
		cout << "-1\n";
		exit(0);
	}
	int& ret = dp[y][x];
	if (ret) return ret;

	int value = mp[y][x] - '0';
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i] * value;
		int nx = x + dx[i] * value;
		ret = max(ret, go(ny, nx) + 1);
	}
	visited[y][x] = 0;
	return ret;
}

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			mp[i][j] = str[j];
		}
	}

	cout << go(0, 0);

	return 0;
}