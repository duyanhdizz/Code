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

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int32_t main() {
#define TASKNAME "COMMAND"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	string s;
	while (cin >> s) {
		if (s == "[END]") break;
		assert(s == "[CASE]");
		cin >> s;
		int len = 1, x = 0, y = 0;
		while (cin >> s) {
			if (s == ">>") break;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == 'L') {
					len++;
					if (len >= 4) len -= 4;
				} else if (s[i] == 'R') {
					len--;
					if (len < 0) len += 4;
				} else {
					x += dx[len];
					y += dy[len];
				}
			}
		}
		cout << ((x == 0 && y == 0) || (len != 1) ? "bounded" : "unbounded") << '\n';
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
