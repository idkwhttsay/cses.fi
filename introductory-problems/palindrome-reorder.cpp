#include <bits/stdc++.h>
#define ll long long
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
 
const ll inf = 1e18 + 123;
const int N = 2e5 + 123;
const int mod = 1e9 + 7;
const double PI = 3.1415926536;
 
const long double eps = 1e-7;
 
string s;
int cnt[26],n,o,c=-1;
 
signed main() {
    speed;
    cin >> s;
    n = s.size();
    for(int i = 0; i < n; ++i){
        cnt[int(s[i] - 'A')] ++;
    }
 
    for(int i = 0; i < 26; ++i){
        if(cnt[i] % 2 == 1){
            o ++;
            c = i;
        }
    }
 
    if(n % 2 == 0 && o > 0){
        cout << "NO SOLUTION";
        return 0;
    } else if(n % 2 == 1 && o > 1){
        cout << "NO SOLUTION";
        return 0;
    }
 
 
    for(int i = 0; i < 26; ++i){
        for(int j = 0; j < cnt[i] / 2; ++j){
            cout << char(i + 'A');
        }
    }
 
    if(c != -1){
        cout << char(c + 'A');
    }
 
    for(int i = 25; i >= 0; --i){
        for(int j = 0; j < cnt[i] / 2; ++j){
            cout << char(i + 'A');
        }
    }
}