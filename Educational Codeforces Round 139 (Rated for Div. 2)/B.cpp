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

int t;
map<string, int> m, m_m;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	vector<pair<string, int>> v;
	for(int i = 0; i + 1 < s.size(); i++) {
		string res = s.substr(i, 2);
		v.pb({res, i});
	}
	sort(all(v));
	FOR(i, 0, v.size() - 2) {
		FOR(j, i + 1, v.size() - 1) {
			if(v[i].fi == v[j].fi) {
				if(v[i].se + 2 <= v[j].se) {
					cout << "YES" << '\n';
					return;
				}
			} else break;
		}
	}
	cout << "NO" << '\n';
}

int32_t main() {
#define TASKNAME "B"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> t;
	while(t--)
		solve();
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
