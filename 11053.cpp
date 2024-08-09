#include <bits/stdc++.h>
using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
int n, lis;
int dp[1001];
int a[1001];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    cin >> n;
    fill(dp, dp + 101, 1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] <= a[j]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
        lis = max(lis, dp[i]);
    }

    cout << lis;
    
    return 0;
}