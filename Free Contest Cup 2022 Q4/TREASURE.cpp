#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast","unroll-loops")
#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (int) (b); --i)
#define REP(i, a, b) for (int i = (a); i < (int) (b); ++i)
#define each(a, x) for (auto &a : x)
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 2e5;
const int INF = 1e9;

int n, m, a[N], b[N];

int32_t main() {
#define TASKNAME "C"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> m;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, m) cin >> b[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	int ans = 1;
	FOR(i, 1, n - 1) {
		int res = 1;
		int z = i, j = 1;
		while(j < m) {
			if((a[z] / __gcd(a[z], b[j])) == (a[z + 1] / __gcd(a[z + 1], b[j + 1])) && (b[j] / __gcd(a[z], b[j])) == (b[j + 1] / __gcd(a[z + 1], b[j + 1]))) {
				while(j < m && z < n && (a[z] / __gcd(a[z], b[j])) == (a[z + 1] / __gcd(a[z + 1], b[j + 1])) && (b[j] / __gcd(a[z], b[j])) == (b[j + 1] / __gcd(a[z + 1], b[j + 1]))) {
					z++;
					j++;
					res++;
				}
				if(res > 1) ans = max(ans, res + 1);
			} else {
				if(res > 1) ans = max(ans, res + 1);
				j++;
				res = 1;
			}
		}
		if(res > 1) ans = max(ans, res + 1);
	}
	cout << ans;
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
