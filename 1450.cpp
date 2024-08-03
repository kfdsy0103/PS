// meet in the middle : 완탐인데 범위가 클 경우 절반으로 나누고 이진탐색
#include <bits/stdc++.h>
using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
long long n, c, ret;
int a[31];
vector<int> v1, v2;

void dfs(int here, int to, vector<int>& v, int sum) {
    if (sum > c) return;
    if (here > to) {
        v.push_back(sum);
        return;
    }

    dfs(here + 1, to, v, sum + a[here]);
    dfs(here + 1, to, v, sum);
    return;
}

int main() {
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dfs(0, n / 2, v1, 0);
    dfs(n / 2 + 1, n - 1, v2, 0);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (int b : v1) {
        if (c - b >= 0)ret += ((int)(upper_bound(v2.begin(), v2.end(), c - b) - v2.begin()));
    }
  
    cout << ret;
    return 0;
}