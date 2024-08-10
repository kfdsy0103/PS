// dp[i] : 0 ~ i 까지 i를 포함한 최대곱
// dp[i] = max(dp[i-1] * dp[i], dp[i]);
#include <bits/stdc++.h>
using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
int n;
double dp[10001], ret;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    scanf_s("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf_s("%lf", &dp[i]);
    }

    ret = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] * dp[i], dp[i]);
        ret = max(ret, dp[i]);
    }
   
    printf("%.3lf", ret);

    return 0;
}