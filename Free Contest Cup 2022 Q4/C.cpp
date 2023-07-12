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
const int N = 9 + 1e4;
const int INF = 1e9;

int n, m, a[N], b[N];

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

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
	//sort(a + 1, a + n + 1);
	//sort(b + 1, b + m + 1);
	ll ans = 1;
	FOR(i, 1, n - 1) {
		int j = 1;
		while(j < m) {
			ll res = 1;
			while(j < m && (a[i] / gcd(a[i], b[j])) != (a[i + 1] / gcd(a[i + 1], b[j + 1])) && (b[j] / gcd(a[i], b[j])) != (b[j + 1] / gcd(a[i + 1], b[j + 1]))) j++;
			if(j == m - 1) break;
			int z = i;
			while(j < m && z < n && (a[z] / gcd(a[z], b[j])) == (a[z + 1] / gcd(a[z + 1], b[j + 1])) && (b[j] / gcd(a[z], b[j])) == (b[j + 1] / gcd(a[z + 1], b[j + 1]))) {
				j++;
				z++;
				res++;
			}
			if(res > 1) ans = max(ans, res);
			//if(j == m - 1 || z == n - 1) break;
			j++;
			if(j >= m - 1) break;
		}
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
