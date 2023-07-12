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
const int N = 9 + 2e3;
const int INF = 1e9;

int n, m;
bool cnt[N][N];

int32_t main() {
#define TASKNAME "CREAM"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> m;
	FOR(i, 1, m) {
		int a, b;
		cin >> a >> b;
		if(a >= b) swap(a, b);
		cnt[a][b] = true;
	}
	int ans = 0;
	FOR(i, 1, n - 2) {
		FOR(j, i + 1, n - 1) {
			FOR(k, j + 1, n) {
				if(cnt[i][j] == false && cnt[j][k] == false && cnt[i][k] == false) {
					ans++;
				}
			}
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
