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

int n, a[N], b[N];
int len = 0;

void check(int l, int r, int u, int v, int val) {
	if(v < l || u > r) return;
	if(l == r) {
		if(a[l] == val) len++;
		return;
	}
	int mid = (l + r) / 2;
	check(l, mid, u, v, val);
	check(mid + 1, r, u, v, val);
}

int32_t main() {
#define TASKNAME "AVERVALS"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	FOR(i, 1, n) cin >> a[i], b[i] = b[i - 1] + a[i];
	int res = 0;
	REP(i, 1, n)
	FOR(j, i + 1, n)
	if((b[j] - b[i - 1]) % (j - i + 1) == 0) {
		len = 0;
		check(1, n, i, j, (b[j] - b[i - 1]) / (j - i + 1));
		if(len > 0) res++;
	}
	cout << res + n;
	cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
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
