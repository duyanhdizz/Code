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
const int N = 9 + 1e5;
const int INF = 1e9;

int n;
int a[N], b[N], m[N];

int32_t main() {
#define TASKNAME "bedao_m16_shooting"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	int mi_n = INF, ma_x = -INF;
	FOR(i, 1, n) cin >> a[i] >> b[i], mi_n = min(mi_n, a[i]), ma_x = max(ma_x, b[i]);
	int ans = 0;
	FOR(i, mi_n, ma_x) {
		FOR(p, i + 1, ma_x) {
			memset(m, false, sizeof m);
			FOR(j, 1, n) {
				if(a[j] <= i && i <= b[j]) {
					m[j] = true;
				}
			}
			int len = 0;
			FOR(jj, 1, n) {
				if(a[jj] <= p && p <= b[jj]) {
					m[jj] = true;
				}
			}
			//cout << i << ' ' << p << '\n';
			FOR(jj, 1, n) {
				if(m[jj] == true) {
					len++;
					//cout << jj << ' ';
				}
			}
			ans = max(ans, len);
			//cout << '\n';
			//cout << len << ' ' << i << ' ' << p << '\n';
		}
	}
	cout << ans;
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
