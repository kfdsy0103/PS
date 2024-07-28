#include <bits/stdc++.h>

using namespace std;

struct status {
	int y, x, dir;
};

const int dy[] = { 0, 0, -1, 1};
const int dx[] = { 1, -1, 0, 0};
int n, k, y, x, dir;
int a[13][13];	// 체스판의 상태
vector<int> v[13][13]; // 칸 별로 존재하는 말의 정보
vector<status> mal; // 말의 상태

void move(int m, int y, int x, int dir) {
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if (ny < 0 || ny >= n || nx < 0 || nx >= n || a[ny][nx] == 2) {
		mal[m].dir ^= 1;
		ny = y + dy[mal[m].dir];
		nx = x + dx[mal[m].dir];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n || a[ny][nx] == 2) {
			return;
		}
	}
	vector<int>::iterator pos = find(v[y][x].begin(), v[y][x].end(), m);
	if (a[ny][nx] == 1) {
		reverse(pos, v[y][x].end());
	}
	for (auto i = pos; i != v[y][x].end(); i++) {
		v[ny][nx].push_back(*i);
		mal[*i].y = ny;
		mal[*i].x = nx;
	}
	v[y][x].erase(pos, v[y][x].end());
}

bool check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j].size() >= 4) return true;
		}
	}
	return false;
}

bool play() {
	for (int i = 0; i < mal.size(); i++) {
		int y = mal[i].y;
		int x = mal[i].x;
		int dir = mal[i].dir;
		move(i, y, x, dir);
		if (check()) return true;
	}
	return false;
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		cin >> y >> x >> dir;
		y--; x--; dir--;
		mal.push_back({ y, x, dir });
		v[y][x].push_back(i);
	}

	int turn = 0;
	int flag = 0;
	while (turn <= 1000) {
		turn++;
		if (play()) {
			flag = 1;
			break;
		}
	}

	if (flag) cout << turn;
	else cout << -1;

	return 0;
}