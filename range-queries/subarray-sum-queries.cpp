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
 
int n,q,a[N],t[4*N],sum[4*N],pref[4*N],suf[4*N];
 
void build(int v, int tl, int tr){
    if(tl == tr){
        t[v] = max(a[tl], 0LL);
        sum[v] = a[tl];
        pref[v] = max(a[tl], 0LL);
        suf[v] = max(a[tl], 0LL);
    } else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        sum[v] = sum[v * 2] + sum[v * 2 + 1];
        pref[v] = max(pref[v * 2], sum[v * 2] + pref[v * 2 + 1]);
        suf[v] = max(suf[v * 2 + 1], sum[v * 2 + 1] + suf[v * 2]);
        t[v] = max(t[v * 2], max(t[v * 2 + 1], suf[v * 2] + pref[v * 2 + 1]));
    }
}
 
void update(int v, int tl, int tr, int pos, int val){
    if(tl == tr){
        t[v] = max(val, 0LL);
        sum[v] = val;
        pref[v] = max(val, 0LL);
        suf[v] = max(val, 0LL);
        return;
    }
 
    int tm = (tl + tr) / 2;
    if(pos <= tm){
        update(v * 2, tl, tm, pos, val);
    } else {
        update(v * 2 + 1, tm + 1, tr, pos, val);
    }
 
    sum[v] = sum[v * 2] + sum[v * 2 + 1];
    pref[v] = max(pref[v * 2], sum[v * 2] + pref[v * 2 + 1]);
    suf[v] = max(suf[v * 2 + 1], sum[v * 2 + 1] + suf[v * 2]);
    t[v] = max(t[v * 2], max(t[v * 2 + 1], suf[v * 2] + pref[v * 2 + 1]));
}
 
signed main() {
    speed;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
 
    build(1, 1, n);
    while(q --){
        int pos, val;
        cin >> pos >> val;
        update(1, 1, n, pos, val);
        cout << t[1] << endl;
    }
}