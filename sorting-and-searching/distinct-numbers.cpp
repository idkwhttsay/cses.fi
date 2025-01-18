#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const ll inf = 1e9;
const ll N = 5e5 + 123;
const ll mod = 1e9 + 7;

int main() {
    speed;
    int n;
    cin >> n;
    set <int> s;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        s.insert(x);
    }

    cout << s.size();
}