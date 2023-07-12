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

set<int> s;

int32_t main() {
#define TASKNAME "cppset"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int k;
	while(cin >> k) {
		if (k == 0) break;
		if (k <= 2) {
			int v;
			cin >> v;
			if (k == 1) s.insert(v);
			else s.erase(v);
		} else {
			int sz = s.size();
			if (sz == 0) cout << "empty";
			else {
				if (k == 3) cout << *s.begin();
				else if (k == 4) cout << *s.rbegin();
				else {
					set<int>::iterator pos;
					int v;
					cin >> v;
					if (k <= 6) {
						if (k == 5) pos = s.upper_bound(v);
						else pos = s.lower_bound(v);
						if (pos == s.end()) cout << "no";
						else cout << *pos;
					} else {
						if (k == 7) pos = s.lower_bound(v);
						else pos = s.upper_bound(v);
						if (pos == s.begin()) cout << "no";
						else cout << *--pos;
					}
				}
			}
			cout << '\n';
		}
	}
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
