#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
const int N = 1 + 1e6;
const int INF = 1e9;

string s;

int32_t main() {
#define TASKNAME ""
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> s;
    string a, b;
    for(int i = 0; i < s.size(); i++) {
        if('a' <= s[i] && s[i] <= 'z') a.pb(s[i]);
        else b.pb(s[i]);
    }
    sort(all(a),greater<int>());
    sort(all(b),greater<int>());
    cout << b << a;
    return 0;
}
