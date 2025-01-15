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
 
int n,m,ans;
vector <int> g[N], u;
bool used[N];
 
void dfs(int v){
    used[v] = true;
    for(int to: g[v]){
        if(!used[to]){
            dfs(to);
        }
    }
}
 
int main() {
    speed;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int x,y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    
    for(int i = 1; i <= n; ++i){
        if(!used[i]){
            dfs(i);
            u.pb(i);
            ans ++;
        }
    }
    
    cout << ans - 1 << endl;
    for(int i = 1; i < u.size(); ++i){
        cout << u[i] << ' ' << u[i - 1] << endl;
    }
}