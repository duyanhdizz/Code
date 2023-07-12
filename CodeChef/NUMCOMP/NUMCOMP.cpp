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
	int a, b, n;
	cin >> a >> b >> n;
	if(n % 2 == 0) {
		a = abs(a);
		b = abs(b);
		if(a > b) cout << 1 << '\n';
		else if(a == b) cout << 0 << '\n';
		else cout << 2 << '\n';
	} else {
		if(a > b) cout << 1 << '\n';
		else if(a == b) cout << 0 << '\n';
		else cout << 2 << '\n';
	}
}

int32_t main() {
#define TASKNAME "NUMCOMP"
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
INPUT
2
3 4 5
-3 2 4
OUTPUT
2
1
*/
