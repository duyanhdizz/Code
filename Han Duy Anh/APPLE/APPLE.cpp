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
const int N = 9 + 1e5;
const int INF = 1e9;

int n;

int32_t main() {
#define TASKNAME "APPLE"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	ll res = 0, res1 = 0, res2 = 0, res3 = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(x % 3 == 0) res1++;
		else if(x % 3 == 1) res2++;
		else res3++;
	}
	res += res1;
	res += (res2 / 3) * 3;
	res2 %= 3;
	res += (res3 / 3) * 3;
	res3 %= 3;
	cout << res + 2 * min(res2, res3);
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
5
6 7 6 2 1
---
10
3 6 4 2 7 3 1 4 2 9
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
4
---
9
------------------------------    |
==================================+
*/
