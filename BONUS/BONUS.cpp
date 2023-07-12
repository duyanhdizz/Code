#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast,O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

int n, a[N], minl[N], maxl[N], minr[N], maxr[N];
stack<int> stmi, stma, stmir, stmar;

int32_t main() {
#define TASKNAME "BONUS"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n) {
		while(stmi.size() && a[i] <= a[stmi.top()]) stmi.pop();
		minl[i] = (stmi.size() > 0 ? stmi.top() : 0);
		while(stma.size() && a[i] >= a[stma.top()]) stma.pop();
		maxl[i] = (stma.size() > 0 ? stma.top() : 0);
		stmi.push(i);
		stma.push(i);
	}
	FORD(i, n, 1) {
		while(stmir.size() && a[i] < a[stmir.top()]) stmir.pop();
		minr[i] = (stmir.size() > 0 ? stmir.top() : n + 1);
		while(stmar.size() && a[i] > a[stmar.top()]) stmar.pop();
		maxr[i] = (stmar.size() > 0 ? stmar.top() : n + 1);
		stmir.push(i);
		stmar.push(i);
	}
	ll ans = 0;
	FOR(i, 1, n) {
		ll smax = 1ll * (i - maxl[i]) * (maxr[i] - i) * a[i];
		ll smin = 1ll * (i - minl[i]) * (minr[i] - i) * a[i];
		ans += (smax - smin);
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
