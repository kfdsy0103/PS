#include <bits/stdc++.h>
using namespace std;

const int dy[4] = { 1, -1, 0, 0 };
const int dx[4] = { 0, 0, 1, -1 };
int n, m, a, b;
int mp[2001], dp[2001][2001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> mp[i];
    }
    cin >> m;

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (mp[i] == mp[i+1]) dp[i][i + 1] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j + i <= n; j++) {
            if (mp[j] == mp[j + i] && dp[j + 1][j + i - 1]) dp[j][j + i] = 1;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << dp[a][b] << "\n";
    }

    return 0;
}