#include <bits/stdc++.h>
using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
int n, a, b, lis;
int dp[101];
vector<pair<int, int>> v;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    cin >> n;
    fill(dp, dp + 101, 1);

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({ a, b });
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i].second < v[j].second) continue;
            dp[i] = max(dp[i], dp[j] + 1);
            lis = max(lis, dp[i]);
        }
    }

    cout << n - lis;
    
    return 0;
}