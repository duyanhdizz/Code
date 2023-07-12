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

int n, pp;
bool b[21];
int x[21], a[N];
int ans = 0;
map<int, bool> m;

void printArray(int p[], int n) {
	int res = 0;
	if(p[1] == 0) return;
	for (int i = 1; i <= n; i++) res = res * 10 + p[i];
	if(res % 2 == 0) ans++;
	//cout << res << '\n';
}

void dequy(int k, int n) {
	for (int i = 1; i <= n; i++) {
		if (b[i]) {
			x[k] = a[i];
			if (k == pp) {
				printArray(x, pp);
			} else {
				b[i] = false;
				dequy(k + 1, n);
				b[i] = true;
			}
		}
	}
}

int32_t main() {
#define TASKNAME "bedao_m16_number"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	cin >> pp;
	for (int i = 1; i <= n; i++) {
		b[i] = true;
	}
	dequy(1, n);
	cout << ans / pp;
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
