#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(v) (int)v.size()

/*#pragma optimize ("g",on)
#pragma GCC optimize ("inline")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("03")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx2,mmx,fma,avx,tune=native")
#pragma comment(linker, "/stack:200000000")*/

using namespace std;

const int inf = 1e9 + 123;
const int N = 2e5 + 123;
const int mod = 1e9 + 7;
const double PI = 3.1415926536;

const double eps = 1e-20;

int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};

int n,q,a[1005][1005],p[1005][1005];

signed main() {
    speed;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            char x;
            cin >> x;
            if(x == '*'){
                a[i][j] = 1;
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + a[i][j];
        }
    }

    /*for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cout << p[i][j] << ' ';
        } cout << endl;
    }*/

    while(q --){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << p[x2][y2] - p[x2][y1 - 1] - p[x1 - 1][y2] + p[x1 - 1][y1 - 1] << endl;
    }
}
