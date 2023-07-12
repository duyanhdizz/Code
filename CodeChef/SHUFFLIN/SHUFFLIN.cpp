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
	int n;
	cin >> n;
	int res = 0, res2 = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(x % 2 == 0) res++;
		else res2++;
	}
	cout << min((n + 1) / 2, res) + min(n - (n + 1) / 2, res2) << '\n';
}

int32_t main() {
#define TASKNAME "SHUFFLIN"
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
3
3
1 2 3
3
2 4 5
2
2 4
OUTPUT
2
3
1
*/
