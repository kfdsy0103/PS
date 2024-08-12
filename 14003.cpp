#include <bits/stdc++.h>
using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
int n, num, len;
int lis[1000001];
pair<int, int> ans[1000001];
const int INF = 1e9 + 1;
stack<int> st;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    init();
    fill(lis, lis + 1000001, INF);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        auto pos = lower_bound(lis, lis + len, num);
        int idx = (int)(pos - lis);
        if (*pos == INF) len++;
        *pos = num;
        ans[i].first = idx;
        ans[i].second = num;
    }
    
    cout << len << "\n";
    
    for (int i = n - 1; i >= 0; i--) {
        if (ans[i].first == len - 1) {
            st.push(ans[i].second); 
            len--;
        }
    }

    while (st.size()) {
        cout << st.top() << " "; 
        st.pop();
    }
    
    return 0;
}