#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(v) (int)v.size()
#define f first
#define s second
#define ld long double
#define ent "\n"
 
/*#pragma optimize ("g",on)
#pragma GCC optimize ("inline")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("03")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx2,mmx,fma,avx,tune=native")
#pragma comment(linker, "/stack:200000000")*/
 
using namespace std;
 
const int inf = 1e18 + 123;
const int N = 2e5 + 123;
const int mod = 1e9 + 7;
const double PI = 3.1415926536;
 
const double eps = 1e-20;
 
int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};
 
struct node{
    int sum, pref;
};
 
int n,q,a[N];
node t[4*N];
 
node comb(node a, node b){
    node res;
    res.sum = a.sum + b.sum;
    res.pref = max(a.sum + b.pref, a.pref);
    res.pref = max(res.pref, res.sum);
    return res;
}
 
void build(int v, int tl, int tr){
    if(tl == tr){
        t[v].pref = max(0LL, a[tl]);
        t[v].sum = a[tl];
        return;
    }
 
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = comb(t[v * 2], t[v * 2 + 1]);
}
 
node get(int v, int tl, int tr, int l, int r){
    if(l > tr || r < tl){
        node res;
        res.pref = res.sum = 0;
        return res;
    }
 
    if(l <= tl && r >= tr){
        return t[v];
    }
 
    int tm = (tl + tr) / 2;
    return comb(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm + 1, tr, l, r));
}
 
void update(int v, int tl, int tr, int pos, int val){
    if(tl == tr){
        t[v].pref = max(0LL, val);
        t[v].sum = val;
        return;
    }
 
    int tm = (tl + tr) / 2;
    if(pos <= tm){
        update(v * 2, tl, tm, pos, val);
    } else {
        update(v * 2 + 1, tm + 1, tr, pos, val);
    }
 
    t[v] = comb(t[v * 2], t[v * 2 + 1]);
}
 
signed main() {
    speed;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
 
    build(1, 1, n);
    while(q --){
        int type;
        cin >> type;
        if(type == 1){
            int pos, val;
            cin >> pos >> val;
            update(1, 1, n, pos, val);
        } else {
            int l, r;
            cin >> l >> r;
            cout << get(1, 1, n, l, r).pref << endl;
        }
    }
}