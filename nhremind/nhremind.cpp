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

int n;
string a, b[N];

int32_t main() {
#define TASKNAME "nhremind"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	FOR(i, 1, n) cin >> b[i];
	cin >> a;
	int j = 2;
	vector<string> ans;
	while(j < a.size()) {
		FOR(i, 0, a.size() - j) {
			string res = a.substr(i, j);
			//cout << res << '\n';
			bool check = true;
			FOR(k, 1, n) {
				FOR(kk, 0, b[k].size() - j) {
					string r = b[k].substr(kk, j);
					if(r == res) {
						check = false;
						break;
					}
				}
				if(check == false) break;
			}
			//cout << check << '\n';
			if(check == true) ans.pb(res);
		}
		if(ans.size() != 0) break;
		j++;
	}
	sort(all(ans));
	cout << ans[0];
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