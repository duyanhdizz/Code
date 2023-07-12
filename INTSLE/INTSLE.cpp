#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast,O3,unroll-loops")
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

int t;

void solve() {
	int a1, a2, b1, b2, c1, c2;
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	int d = a1 * b2 - a2 * b1;
	int dx = c1 * b2 - c2 * b1;
	int dy = a1 * c2 - c1 * a2;
	if(a1 * a1 + b1 * b1 != 0 || a2 * a2 + b2 * b2 != 0) {
		if(d != 0) {
			if(dx % d == 0 && dy % d == 0) cout <<  dx / d << ' ' << dy / d << '\n';
			else cout << "NO SOLUTION" << '\n';
		} else {
			if(dx != 0 || dy != 0) cout << "NO SOLUTION" << '\n';
			else {
				if(a1 == 0 && b1 != 0) cout << (c1 % b1 == 0 ? "INFINITE" : "NO SOLUTION") << '\n';
				if(a1 != 0 && b1 == 0) cout << (c1 % a1 == 0 ? "INFINITE" : "NO SOLUTION") << '\n';
				if(a1 != 0 && b1 != 0) cout << (c1 % (__gcd(abs(a1), abs(b1))) == 0 ? "INFINITE" : "NO SOLUTION") << '\n';
				if(a1 == 0 && b1 == 0) {
					if(a2 == 0 && b2 != 0) cout << (c2 % b2 == 0 ? "INFINITE" : "NO SOLUTION") << '\n';
					if(a2 != 0 && b2 == 0) cout << (c2 % a2 == 0 ? "INFINITE" : "NO SOLUTION") << '\n';
					if(a2 != 0 && b2 != 0) cout << (c2 % (__gcd(abs(a2), abs(b2))) == 0 ? "INFINITE" : "NO SOLUTION") << '\n';
				}
			}
		}
	} else cout << (c1 == 0 && c2 == 0 ? "INFINITE" : "NO SOLUTION") << '\n';
}

int32_t main() {
#define TASKNAME "INTSLE"
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
4
1 2 3 2 4 7
1 2 3 2 4 6
1 1 36 2 4 100
1 1 1 1 -1 0
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/
