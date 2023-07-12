#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
const int N = 1 + 1e5;
const int INF = 1e9;

string s, t;
int ss[N], tt[N], q;

int32_t main() {
#define TASKNAME "fct031_strop"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> s >> t;
    ss[-1] = 0;
    for(int i = 0; i < s.size(); i++)
        ss[i] = ss[i - 1] + s[i] - 'A' + 1;
    tt[-1] = 0;
    for(int i = 0; i < t.size(); i++)
        tt[i] = tt[i - 1] + t[i] - 'A' + 1;
    cin >> q;
    while(q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(((ss[b - 1] - ss[a - 2]) % 3) == ((tt[d - 1] - tt[c - 2]) % 3)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
