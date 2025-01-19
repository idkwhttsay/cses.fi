#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair <int, int>
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(v) (int)v.size()
#define f first
#define s second
#define ld double
#define ent "\n"
#define S(x,y,z) ((x)*(x) + (y)*(y) + (z)*(z))

//#pragma optimize ("g",on)
//#pragma GCC optimize ("inline")
//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize ("03")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx2,mmx,fma,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")

using namespace std;

const int inf = 1e18 + 123;
const int N = 1e6 + 123;
const int mod = 1e9 + 7;
const double PI = 3.1415926536;

const long double eps = 1e-7;

int lp[N+10],n;
vector <int> pr;

signed main() {
    speed;
    for(int i = 2; i <= N; ++i){
        if(lp[i] == 0){
            lp[i] = i;
            pr.push_back(i);
        }

        for(int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j){
            lp[i * pr[j]] = pr[j];
        }
    }

    int q;
    cin >> q;
    while(q --){
        int x,ans=1;
        cin >> x;
        unordered_map <int, int> mp;
        while(x > 1){
            mp[lp[x]] ++;
            x /= lp[x];
        }

        for(auto e: mp){
            ans *= (e.s + 1);
        }

        cout << ans << ent;
    }
}