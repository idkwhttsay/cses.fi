#include <bits/stdc++.h>

#define int long long
#define F first
#define S second
#define pii pair<int, int>

using namespace std;

const int N = 1e5+123;
const int INF = 1e18;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int n,m,k;
vector <pii> g[N];
priority_queue <int> bs[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void solve() {
    cin >> n >> m >> k;
    for(int i = 0; i < m; ++i) {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    bs[1].push(0);
    pq.push({0, 1});
    while(!pq.empty()) {
        auto v = pq.top();
        pq.pop();

        if(v.F > bs[v.S].top()) continue;
        for(auto [to, w]: g[v.S]) {
            int tmp = v.F + w;
            if(bs[to].size() < k) {
                bs[to].push(tmp);
                pq.push({tmp, to});
            } else if(tmp < bs[to].top()) {
                bs[to].pop();
                bs[to].push(tmp);
                pq.push({tmp, to});
            }
        }
    }

    vector <int> ans;
    while(!bs[n].empty()) {
        ans.push_back(bs[n].top());
        bs[n].pop();
    }

    reverse(ans.begin(), ans.end());
    for(int e: ans) {
        cout << e << ' ';
    }
}

signed main() {
    int tt = 1;
    // cin >> tt;
    while(tt --) {
        solve();
        cout << '\n';
    }
}
