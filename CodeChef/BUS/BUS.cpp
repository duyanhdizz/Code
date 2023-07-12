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
	int n, m, q;
	cin >> n >> m >> q;
	map<int, int> d;
	int res = 0;
	bool ktra = true;
	while(q--) {
		char c;
		int a;
		cin >> c >> a;
		if(c == '+') {
			d[a]++;
			res++;
		} else {
			res--;
			d[a]--;
		}
		if(d[a] < 0 || res > m) {
			ktra = false;
		}
	}
	if(ktra == true) cout << "Consistent" << '\n';
	else cout << "Inconsistent" << '\n';
}

int32_t main() {
#define TASKNAME "BUS"
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
OUTPUT
*/
