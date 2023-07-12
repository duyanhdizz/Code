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

int n, t;

int32_t main() {
#define TASKNAME "bedao_m14_operation"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> t;
	int res = -INF, res2 = INF;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		res = max(res, x);
		res2 = min(res2, x);
	}
	while(t--) {
		int x;
		cin >> x;
		if(res >= x && x >= res2) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
	return 0;
}
/*
INPUT
OUTPUT
*/
