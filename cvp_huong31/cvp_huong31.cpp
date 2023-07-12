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
const int N = 9 + 1e2;
const int INF = 1e9;

int s, k, f[N], g[N];

void print(int n) {
	FOR(i, 1, n) {
		FOR(j, 1, g[i]) {
			cout << f[i];
			if (i == n && j == g[n]) break;
			cout << '+';
		}
	}
	cout << '\n';
}
void sinh(int sum, int n) {
	if(sum < 0) return;
	else if (sum == 0) print(n - 1);
	else if (f[n] > s) return;
	else {
		FORD(j, min(k, sum / f[n]), 0) {
			g[n] = j;
			sinh(sum - j * f[n], n + 1);
		}
	}
}

int32_t main() {
#define TASKNAME "cvp_huong31"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> s >> k;
	int n = 3;
	f[1] = 1;
	f[2] = 2;
	while(f[n - 1] + f[n - 2] <= s) {
		f[n] = f[n - 1] + f[n - 2];
		n++;
	}
	f[n] = 1e9;
	sinh(s, 1);
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
