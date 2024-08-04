#include <bits/stdc++.h>
using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };

struct info {
    int a;
    int b;
    int c;
    int d;
};
int n, k;
int a, b, c, d;
int dp[101][100001];
vector<info> v;

int go(int here, int time) {
    if (here == n) return 0;

    int& ret = dp[here][time];
    if (~ret) return ret;

    if (time - v[here].a >= 0) ret = max(ret, go(here + 1, time - v[here].a) + v[here].b);
    if (time - v[here].c >= 0) ret = max(ret, go(here + 1, time - v[here].c) + v[here].d);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        v.push_back({ a, b, c, d });
    }

    cout << go(0, k);

    return 0;
}