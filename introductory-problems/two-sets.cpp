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

const int inf = 1e9 + 123;
const int N = 2e5 + 123;
const int mod = 1e9 + 7;
const double PI = 3.1415926536;

const long double eps = 1e-7;

int n;

signed main() {
    speed;
    cin >> n;
    if(n % 4 == 2 || n % 4 == 1) {
        cout << "NO";
        return 0;
    } cout << "YES" << endl;
    if(n % 4 == 0){
        vector <int> a,b;
        for(int i = 1; i <= n / 2; ++i){
            if(i % 2 == 1){
                a.pb(i);
                a.pb(n - i + 1);
            } else {
                b.pb(i);
                b.pb(n - i + 1);
            }
        }

        cout << a.size() << endl;
        for(int x: a){
            cout << x << ' ';
        } cout << endl << b.size() << endl;
        for(int x: b){
            cout << x << ' ';
        }
    } else {
        vector <int> a,b;
        a.pb(1);
        a.pb(2);
        b.pb(3);
        for(int i = 4, j = n; i < j; i ++, j --){
            if(i % 2 == 1){
                a.pb(i);
                a.pb(j);
            } else {
                b.pb(i);
                b.pb(j);
            }
        }

        cout << a.size() << endl;
        for(int x: a){
            cout << x << ' ';
        } cout << endl << b.size() << endl;
        for(int x: b){
            cout << x << ' ';
        }
    }
}
