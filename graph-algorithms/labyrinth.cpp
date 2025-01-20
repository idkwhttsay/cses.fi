#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair <int, int>


using namespace std;

const ll inf = 1e9;
const ll N = 1e6 + 3;
const ll mod = 1e9 + 7;

int n, m;
char A[1010][1010];
bool vis[1010][1010];
int previousStep[1010][1010];

// 0 = up, 1 = right, 2 = down, 3 = left
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string stepDir = "URDL";

int main() {
    cin >> n >> m;
    queue <pii> q;
    pii begin, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
            if (A[i][j] == 'A') {
                begin = mp(i, j);
            } else if (A[i][j] == 'B') {
                end = mp(i, j);
            }
        }
    }

    q.push(begin);
    vis[begin.f][begin.s] = true;

    while (!q.empty()) {
        pii u = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            pii v = mp(u.f + dx[i], u.s + dy[i]);
            if (v.f < 0 || v.f >= n || v.s < 0 || v.s >= m) continue;
            if (A[v.f][v.s] == '#') continue;
            if (vis[v.f][v.s]) continue;
            vis[v.f][v.s] = true;
            previousStep[v.f][v.s] = i;
            q.push(v);
        }
    }

    if (vis[end.f][end.s]) {
        cout << "YES" << endl;
        vector<int> steps;
        while (end != begin) {
            int p = previousStep[end.f][end.s];
            steps.push_back(p);
            end = mp(end.f - dx[p], end.s - dy[p]);
        }
        reverse(steps.begin(), steps.end());

        cout << steps.size() << endl;
        for (char c : steps) {
            cout << stepDir[c];
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}