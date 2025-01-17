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
 
const long double eps = 1e-7;
 
int a[10][10],ans,used[10][10];
 
bool go(int x, int y){
    bool ok = 1;
    for(int i = 0; i < 8; ++i){
        if(used[x][i] || used[i][y]){
            ok = 0;
        }
    }
 
    for(int i = 0; x - i >= 0 && y - i >= 0; ++i){
        if(used[x - i][y - i]){
            ok = 0;
        }
    }
 
    for(int i = 0; x - i >= 0 && y + i < 8; ++i){
        if(used[x - i][y + i]){
            ok = 0;
        }
    }
 
    return ok;
}
 
bool check(){
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            if(used[i][j] && a[i][j]){
                return false;
            }
        }
    }
 
    return true;
}
 
void rec(int i){
    if(i == 8){
        if(check()){
            ans ++;
        } return;
    }
 
 
    for(int j = 0; j < 8; ++j){
        if(go(i, j)){
            used[i][j] = 1;
            rec(i + 1);
            used[i][j] = 0;
        }
    }
}
 
signed main() {
    speed;
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            char c;
            cin >> c;
            a[i][j] = (c == '*');
        }
    }
 
    rec(0);
    cout << ans;
}