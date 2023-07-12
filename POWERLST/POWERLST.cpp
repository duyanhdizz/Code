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
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int32_t main() {
#define TASKNAME "POWERLST"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int n;
	cin >> n;
	vector<pii> res;
	FOR(i, 2, sqrt(n)) {
		if(n % i == 0) {
			int d = 1;
			FOR(j, 1, 50) {
				d *= i;
				if(d == n) {
					res.pb({j, i});
					break;
				} else if(d > n) break;
			}
			if(i * i != n) {
				d = 1;
				FOR(j, 1, 50) {
					d *= (n / i);
					if(d == n) {
						res.pb({j, n / i});
						break;
					} else if(d > n) break;
				}
			}
		}
	}
	if(res.size() == 0) return cout << 0, 0;
	sort(all(res));
	cout << res.size() << '\n';
	each(x, res) cout << x.se << ' ' << x.fi << '\n';
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
