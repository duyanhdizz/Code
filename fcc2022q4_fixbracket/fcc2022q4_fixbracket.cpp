#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for (int i = (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (int) (b); --i)
#define REP(i, a, b) for (int i = (a); i < (int) (b); ++i)
#define each(a, x) for (auto &a : x)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int t;
bool a[N], cnt[N];

void solve() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	REP(i, 0, n) a[i] = (s[i] == ')' || s[i] == '(') ? true : false;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		int mid = 0;
		for (int i = l; i <= r; i++) {
			if (mid == 0 || cnt[mid] != a[i]) cnt[++mid] = a[i];
			else mid--;
		}
		cout << mid / 2 << '\n';
	}
}

int32_t main() {
#define TASKNAME "fcc2022q4_fixbracket"
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
