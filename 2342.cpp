#include <bits/stdc++.h>
using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
int n;
int dp[5][5][100001];
vector<int> a;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int move(int from, int to) {
    if (from == 0) return 2;
    if (from == to) return 1;
    if (abs(from - to) == 2) return 4;
    return 3;
}

int go(int here, int y, int x) {
    if (here == a.size()) return 0;
    int& ret = dp[y][x][here];
    if (~ret) return ret;

    ret = min(go(here + 1, a[here], x) + move(y, a[here]), go(here + 1, y, a[here]) + move(x, a[here]));
    return ret;
}

int main() {
    init();
    
    while (true) {
        cin >> n;
        if (n == 0) break;
        a.push_back(n);
    }
    memset(dp, -1, sizeof(dp));

    cout << go(0, 0, 0);

    return 0;
}