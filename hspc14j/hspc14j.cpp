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
const int N = 9 + 1e3;
const int INF = 1e9;

int n, k;
bool prime[N];

void solve(int n, int k) {
	int len = 0;
	memset(prime, true, sizeof prime);
	FOR(i, 2, n) {
		if(prime[i]) {
			for(int j = i; j <= n; j += i) {
				if(prime[j]) {
					prime[j] = false;
					k--;
					if(k == 0) {
						cout << j;
						return;
					}
				}
				//cout << j << '\n';
			}
		}
	}
}

int32_t main() {
#define TASKNAME "hspc14j"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	while(cin >> n >> k) solve(n, k), cout << '\n';
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
