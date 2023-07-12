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

int n, b[N];
map<int, int> d;

int tkim(int lo, int hi, int z) {
	int r = lo;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (b[mid] >= z) hi = mid - 1;
		else lo = mid + 1;
	}
	if (b[hi] < z) return hi;
	else return r - 1;
}

int32_t main() {
#define TASKNAME "TRIANGLES"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	int res = 0, m = 0;
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		d[x]++;
		if (d[x] == 3) res++;
		else if (d[x] == 1) m++, b[m] = x;
	}
	sort(b + 1, b + m + 1);
	for (int i = 1; i <= m; i++) {
		if (d[b[i]] >= 2) res = res - 1 + tkim(i + 1, m, b[i] * 2);
		for (int j = i + 1; j <= m; j++) res += tkim(j + 1, m, b[i] + b[j]) - j;
	}
	cout << res;
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
