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

int a[N], b[N];

void YeuHuong() {
	int n, m;
	cin >> n >> m;
	FOR(i, 1, n) cin >> a[i], b[i] = 0;
	FOR(i, 1, n) b[i] += b[i - 1] + a[i];
	int DA = 0;
	int ans = 0;
	bool work = false;
	FOR(i, 1, n) {
		if(i < m) {
			if(b[i] - DA < b[m]) {
				work = true;
			}
		}
		if(i != m) {
			if(b[i] - DA < b[m] && a[i] < 0) {
				DA += 2 * a[i];
				ans++;
			}
		}
	}
	cout << ans + work << '\n';
}

int32_t main() {
#define TASKNAME "C"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int testcase;
	cin >> testcase;
	while(testcase--)
		YeuHuong();
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
