#include <bits/stdc++.h>

#define int long long
#define F first
#define S second
#define pii pair<int, int>

using namespace std;

const int N = 1e5+123;
const int INF = 1e18;
const int mod = 1e9+7;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

void moveDisk(int diskNumber, vector<vector<int> >& moves, int sourceStack, int destinationStack, int auxiliaryStack) {
    if (diskNumber == 1) {
        moves.push_back({ sourceStack, destinationStack });
        return;
    }

    moveDisk(diskNumber - 1, moves, sourceStack, auxiliaryStack, destinationStack);

    moves.push_back({ sourceStack, destinationStack });

    moveDisk(diskNumber - 1, moves, auxiliaryStack, destinationStack, sourceStack);
}


void towerOfHanoi(int numberOfDisks) {
    vector<vector<int> > moves; 
    int sourceStack = 1, destinationStack = 3, auxiliaryStack = 2;
    moveDisk(numberOfDisks, moves, sourceStack, destinationStack, auxiliaryStack);

    cout << moves.size() << "\n";

    for (auto move : moves) {
        cout << move[0] << " " << move[1] << "\n";
    }
}

void solve() {
    int numberOfDisks;
    cin >> numberOfDisks;
    towerOfHanoi(numberOfDisks);
}

signed main() {
    int tt = 1;
    // cin >> tt;
    while(tt --) {
        solve();
        cout << '\n';
    }
}