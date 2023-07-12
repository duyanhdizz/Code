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
const int N = 9 + 1e2;
const int INF = 1e9;

int n, a[N];
map<bool, int> m;

int32_t main() {
#define TASKNAME "ZZZ"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	FOR(i, 1, 1e6) m[i] = false;
	FOR(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = 1;
	//FOR(i, 1, n) cout << a[i] << '\n';
	FOR(i, 1, n) {
		int r = a[i];
		vector<int> v;
		FOR(kk, 1, n) m[a[kk]] = true;
		//cout << a[kk] << '\n';
		//cout << m[4];
		//FOR(kk, 1, n) cout << a[kk] << ' ' << m[a[kk]] << '\n';
		int loat = 1;
		//cout << a[i] << '\n';
		v.pb(a[i]);
		//cout << v[0];
		//cout << m[5] << '\n';
		while(true) {
			vector<int> p;
			FOR(k, 0, v.size() - 1) {
				FOR(j, 1, loat) {
					//cout << v[k] + j;
					if(m[v[k] + j] == true) {
						m[v[k] + j] = false;
						p.pb(v[k] + j);
						cout << v[k] + j << '\n';
					}
				}
			}
			if(p.size() == 0) break;
			//cout << p.size() << '\n';
			each(x, p) v.pb(x);
			loat++;
		}
		ans = max(ans, loat);
		m[r] = false;
	}
	cout << ans;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
6
8
5
6
13
3
4
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/
