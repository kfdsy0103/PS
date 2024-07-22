// 최댓값을 찾는 법
// 1. 최소를 작게 (이 방법을 사용함)
// 2. 최대를 크게
// 따라서 최소힙을 사용하여 풀이
#include <bits/stdc++.h>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, a, b, ret;
vector<pair<int, int>> vec;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
	cin >> n;
	
	while (n--) {
		cin >> a >> b;
		vec.push_back({ a, b });
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		pq.push(vec[i].second);
		if (pq.size() > vec[i].first) {
			pq.pop();
		}
	}

	while (!pq.empty()) {
		ret += pq.top();
		pq.pop();
	}

	cout << ret << "\n";

	return 0;
}