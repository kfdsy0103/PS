// �Ҹ��� �迭 ������ �ϴ� �ϳ��� ���ڸ� �����
// ��Ʈ �����ڸ� ���� Ž��, ���� ���� �۾��� ��
// ��� ������ ���� �� ����ϸ� �����ϴ�.
// int ���� �Ѱ谡 �����Ƿ� n�� 30 ���ϸ� ����غ��� �ϴ�.
#include <bits/stdc++.h>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, mp, mf, ms, mv, cost;
int p, f, s, v, c;
int ret = 99999999;
map<int, vector<vector<int>>> m;

struct ss {
	int p, f, s, v, c;
}a[16];

int main() {
	cin >> n;
	cin >> mp >> mf >> ms >> mv;

	for (int i = 0; i < n; i++) {
		cin >> a[i].p >> a[i].f >> a[i].s >> a[i].v >> a[i].c;
	}

	for (int i = 1; i < (1 << n); i++) { // 1, 2, ..., n��° ��Ʈ�� �Ѽ� �ĺ����� �ֱ�
		p = f = s = v = c = 0;
		vector<int> li;
		for (int j = 0; j < n; j++) { // �� ��° ��Ʈ�� �ĺ������� üũ
			if (i & (1 << j)) {
				p += a[j].p;
				f += a[j].f;
				s += a[j].s;
				v += a[j].v;
				c += a[j].c;
				li.push_back(j + 1);
			}
		}
		if (p >= mp && f >= mf && s >= ms && v >= mv) {
			if (c <= ret) {
				ret = c;
				m[ret].push_back(li);
			}
		}
	}

	if (ret == 99999999) {
		cout << "-1\n";
	}
	else {
		sort(m[ret].begin(), m[ret].end());
		cout << ret << "\n";
		for (int a : m[ret][0]) {
			cout << a << " ";
		}
	}

	return 0;
}