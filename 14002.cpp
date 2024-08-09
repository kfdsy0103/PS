#include <bits/stdc++.h>
using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
int n, lis = 1, idx;
int dp[1001];
int trace[1001];
int a[1001];
stack<int> st;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    cin >> n;
    fill(dp, dp + 101, 1);
    fill(trace, trace + 1001, -1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] <= a[j]) continue;
            if (dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                trace[i] = j;
            }
        }
        if (lis < dp[i]) {
            idx = i;
            lis = dp[i];
        }
    }

    cout << lis << "\n";
    for (int i = idx; i != -1; i = trace[i]) {
        st.push(a[i]);
    }

    while (!st.empty()) {
        cout << st.top() << " "; 
        st.pop();
    }
    
    return 0;
}