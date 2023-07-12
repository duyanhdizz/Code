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

map<string, bool> m;

int32_t main() {
#define TASKNAME "BROTAT"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int n;
	cin >> n;
	vector<string> s(n);
	cin >> s[0];
	vector<string> v;
	v.pb(s[0]);
	while(m[s[0]] == false) {
		m[s[0]] = true;
		s[0] = s[0].substr(1, s[0].size() - 1) + s[0].substr(0, 1);
		v.pb(s[0]);
	}
	FOR(i, 1, n - 1) {
		cin >> s[i];
		if(m[s[i]] == false) return cout << -1, 0;
	}
	int ans = 17062106;
	each(x, v) {
		int solan = 0;
		each(c, s) {
			FORD(i, c.size(), 1) {
				if(x.substr(0, i) == c.substr(c.size() - i, i)) {
					solan += c.size() - i;
					//cerr << i << ' ';
					break;
				}
			}
		}
		//cout << solan << ' ' << x << '\n';
		ans = min(ans, solan);
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
