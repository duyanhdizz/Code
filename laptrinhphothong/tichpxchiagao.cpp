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

int a[9];

int32_t main() {
#define TASKNAME "tichpxchiagao"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int sum = 0;
	FOR(i, 0, 8) cin >> a[i], sum += a[i];
	int ans = INF;
	FOR(i, 0, 8) {
		int d[9];
		d[i]++;
		FOR(j, 0, 8) {
			if(d[j] == 0) {
				d[j]++;
				FOR(z, 0, 8) {
					if(d[z] == 0) {
						d[z]++;
						int one = a[i] + a[j] + a[z];
						FOR(k, 0, 8) {
							if(d[k] == 0) {
								d[k]++;
								FOR(kk, 0, 8) {
									if(d[kk] == 0) {
										d[kk]++;
										FOR(kkk, 0, 8) {
											if(d[kkk] == 0) {
												d[kkk]++;
												int two = a[k] + a[kk] + a[kkk];
												//if(i != j && j != z && z != k && k != kk && kk != kkk)
												ans = min(ans, max({one, two, sum - one - two}) - min({one, two, sum - one - two}));
												//if(max({one, two, sum - one - two}) == min({one, two, sum - one - two})) cout << one << ' ' << i << ' ' << j << ' ' << k << '\n';
												d[kkk] = 0;
											}
										}
										d[kk] = 0;
									}
								}
								d[k] = 0;
							}
						}
						d[z] = 0;
					}
				}
				d[j] = 0;
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
