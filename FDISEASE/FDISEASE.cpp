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
const int N = 9 + 1e3;
const int INF = 1e9;

int a[N], b[N];

int32_t main() {
#define TASKNAME "FDISEASE"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int n;
	cin >> n;
	int k = 0, h = 0;
	FOR(i, 1, n) {
		int x, y;
		cin >> x >> y;
		if(y == 1) b[++h] = x;
		else a[++k] = x;
	}
	sort(b + 1, b + h + 1);
	sort(a + 1, a + k + 1);
	int mi = INF;
	FOR(i, 1, k) {
		FOR(j, 1, h) {
			mi = min(mi, abs(a[i] - b[j]));
		}
	}
	int m = 1;
	FOR(i, 2, h) {
		if(b[i] - b[i - 1] >= mi) {
			m++;
		}
	}
	cout << m;
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
