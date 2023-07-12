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

int n;

pii trans(int x, int y) {
	return {x - y, x + y};
}

int32_t main() {
#define TASKNAME "pvoi14_1"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	int xleft = -INF, xright = INF, yup = INF, ydown = -INF;
	FOR(i, 1, n) {
		int X1, Y1, X2, Y2, X3, Y3, X4, Y4;
		cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3 >> X4 >> Y4;
		pii rect1 = trans(X1, Y1);
		pii rect2 = trans(X2, Y2);
		pii rect3 = trans(X3, Y3);
		pii rect4 = trans(X4, Y4);

		xleft = max(xleft, min({rect1.fi, rect2.fi, rect3.fi, rect4.fi}));
		xright = min(xright, max({rect1.fi, rect2.fi, rect3.fi, rect4.fi}));
		yup = min(yup, max({rect1.se, rect2.se, rect3.se, rect4.se}));
		ydown = max(ydown, min({rect1.se, rect2.se, rect3.se, rect4.se}));
	}
	ll ans = 1ll * (yup - ydown - 1) * (xright - xleft - 1);
	if((xleft + yup) & 1 && (xright + ydown) & 1) cout << ans / 2;
	else cout << (ans + 1) / 2;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
3
3 0 0 3 4 7 7 4
5 0 7 2 2 7 0 5
5 7 7 5 3 1 1 3
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
4
------------------------------    |
==================================+
*/
