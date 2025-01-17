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

int n,a[N],dp[N];

int main() {
    speed;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        dp[i] = inf;
    }

    dp[0] = -inf;
    dp[n + 1] = inf;
    for(int i = 1; i <= n; ++i){
        int l = 0, r = n, ans = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            if(dp[mid] < a[i]){
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        dp[ans + 1] = a[i];
    }

    for(int i = 1; i <= n + 1; ++i){
        if(dp[i] == inf){
            cout << i - 1;
            return 0;
        }
    }
}