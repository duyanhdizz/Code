#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
const int N = 9 + 1e6;
const int INF = 1e9;

int t;

void solve() {
	ll n;
	cin >> n;
	if(n == 1) cout << 2 << '\n';
	else cout << (n + 2) / 3 << '\n';
}

int32_t main() {
#define TASKNAME "A"
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
