#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
const ll inf = 1e18;
const ll N = 1e5 + 123;
const ll mod = 1e6 + 3;
const double PI = 3.1415926536;
 
int n,m,d[N],p[N];
vector <int> g[N], u;
bool used[N];
queue <int> q;
 
int main() {
    speed;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int x,y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    
    used[1] = true;
    d[1] = 0;
    p[1] = 0;
    q.push(1);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int to: g[v]){
            if(!used[to]){
                q.push(to);
                d[to] = d[v] + 1;
                p[to] = v;
                used[to] = true;
            }
        }
    }
    
    if(d[n] == 0){
        cout << "IMPOSSIBLE";
        return 0;
    } 
    
    vector <int> ans;
    for(int k = n; k > 0; k = p[k]){
        ans.pb(k);
    }
    
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int x: ans){
        cout << x << ' '; 
    }
}