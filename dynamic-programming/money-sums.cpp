#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


using namespace std;

const ll inf = 1e9;
const ll N = 1e6 + 3;
const ll mod = 1e9 + 7;

int n,x[1000],sum,cnt;
bool used[N];

int main() {
    speed;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> x[i];
        sum += x[i];
    }

    used[0] = true;
    for(int i = 1; i <= n; ++i){
        for(int j = sum - x[i]; j >= 0; --j){
            if(used[j]){
                used[j + x[i]] = true;
            }
        }
    }

    for(int i = 1; i <= sum; ++i){
        if(used[i]){
            cnt ++;
        }
    }

    cout << cnt << endl;
    for(int i = 1; i <= sum; ++i){
        if(used[i]){
            cout << i << ' ';
        }
    }
}