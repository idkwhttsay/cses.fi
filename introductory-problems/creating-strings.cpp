#include<bits/stdc++.h>
#define ll long long
 
using namespace std;
 
set <string> st;
 
int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    st.insert(s);
    while(next_permutation(s.begin(), s.end())){
        st.insert(s);
    }
 
    cout << st.size() << endl;
    for(auto x: st){
        cout << x << endl;
    }
}