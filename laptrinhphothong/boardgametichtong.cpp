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
#define ll unsigned long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const ll INF = 1e21;

ll a[4];
string s;

int32_t main() {
#define TASKNAME "boardgametichtong"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	cin >> s;
	sort(a, a + 4);
	ll cong = 0;
	each(x, s) cong = cong + (x == '+' ? 1 : 0);
	ll sum = 0;
	if(cong == 3) {
		FOR(i, 0, 3) sum += a[i];
	} else if(cong == 2) {
		ll s = 0;
		FOR(i, 1, 3) s += a[i];
		sum = s * a[0];
	} else if(cong == 1) {
		sum = INF;
		if(s[0] == '+') {
			sum = a[0] * a[1] * (a[2] + a[3]);
		} else if(s[1] == '+') {
			sum = min({(a[1] * a[3] + a[2]) * a[0], (a[0] * a[3] + a[2]) * a[1], (a[0] * a[2] + a[3]) * a[1], (a[0] * a[2] + a[1]) * a[3], (a[1] * a[2] + a[3]) * a[0], (a[1] * a[0] + a[3]) * a[2]});
		} else if(s[2] == '+') {
			sum = (a[0] * a[2]) * a[1] + a[3];
		}
	} else if(cong == 0) {
		sum = 1;
		FOR(i, 0, 3) sum *= a[i];
	}
	cout << sum;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
1 1 5 7
+**
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
12
------------------------------    |
==================================+
*/