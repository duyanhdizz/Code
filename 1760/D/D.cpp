#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 2e5;
const int INF = 1e9 + 19;

int t, a[N];

void solve() {
	int n;
	cin >> n;
	int res = 0;
	for(int i = 0; i < n; i++) cin >> a[i];
	int bdau = INF;
	for(int i = 0; i < n; i++) {
		if(i != 0 && a[i] != a[i - 1]) bdau = a[i - 1];
		if(i == n - 1) {
			if(a[i] < bdau && a[i] < INF) res++;
			//continue;
		}
		else if(a[i] < bdau && a[i] < a[i + 1]) res++;
		if(res > 1) {
			cout << "NO" << '\n';
			return;
		}
	}
	//cout << res << '\n';
	if(res != 0) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int32_t main() {
#define TASKNAME "D"
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

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/
