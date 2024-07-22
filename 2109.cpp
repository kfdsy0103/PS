// 그리디 알고리즘
// 1. pair 쌍으로 입력받고 날짜 기준 오름차순 정렬
// 2. 최소힙으로 현재 날짜보다 pq 사이즈가 크다면 최소값을 pop하여 후보군에서 삭제
#include <bits/stdc++.h>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, c, p, ret;
vector<pair<int, int>> vec;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c >> p;
		vec.push_back({ p, c });
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		pq.push(vec[i].second);
		if (pq.size() > vec[i].first) pq.pop();
	}
	while (!pq.empty()) {
		ret += pq.top();
		pq.pop();
	}

	cout << ret;

	return 0;
}
