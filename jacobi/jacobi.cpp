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
const int NMAX = 33000;
const int INF = 1e9;

int t;
vector<int> v, prime;
vector<bool> check(NMAX, true);

void sang() {
	check[1] = false;
	FOR(i, 2, NMAX - 1)
	if(check[i] == true) {
		prime.pb(i);
		for(int j = 2 * i; j < NMAX; j += i) check[j] = false;
	}
}

void solve() {
	int a, n;
	cin >> a >> n;
	each(x, prime) if(x <= n - 1 && (x * x) % n == a) {
		v.pb(x);
		if(n - x != x) v.pb(n - x);
	}
	sort(all(v));
	if(v.size() == 0) {
		cout << "Khong co" << '\n';
		return;
	}
	each(i, v) cout << i << ' ' ;
	cout << '\n';
	v.clear();
}

int32_t main() {
#define TASKNAME "jacobi"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	sang();
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
