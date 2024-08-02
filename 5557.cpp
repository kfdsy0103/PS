#include <bits/stdc++.h>
using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
int n;
int a[101];
long long dp[101][21];

long long solve(int here, int sum) {
    if (sum < 0 || sum > 20) return 0;
    if (here == n - 2) {
        if(sum == a[n-1]) return 1;
        return 0;
    }
    long long& ret = dp[here][sum];
    if (~ret) return ret;

    ret = 0;
    ret += solve(here + 1, sum + a[here+1]);
    ret += solve(here + 1, sum - a[here+1]);

    return ret;
}

int main() {
    cin >> n;

    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cout << solve(0, a[0]);

    return 0;
}