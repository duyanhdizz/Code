#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int t;

void solve() {
	string a, b, c;
	cin >> a >> b >> c;
	if(c + b == a) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int32_t main() {
#define TASKNAME "icpc22_national_f"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> t;
    while(t--)
    solve();
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
2
tranloc
loc
tran
alberteinstein
albert
einstein
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
YES
NO
------------------------------    |
==================================+
*/
