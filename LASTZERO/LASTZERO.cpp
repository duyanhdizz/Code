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
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int n, b;

int bin_pow(int a, int b) {
	int res = 1;
	while(b > 0) {
		if(b & 1) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

int32_t main() {
#define TASKNAME "LASTZERO"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> b;
	vector<pii> prime_factor;
	for (int i = 2; i * i <= b; i++) {
		int cnt = 0;
		while (b % i == 0) {
			cnt++;
			b /= i;
		}
		if(cnt != 0) prime_factor.pb({i, cnt});
	}
	if(b > 1) prime_factor.pb({b, 1});
	int ans = 0;
	int res = 1e18;
	each(x, prime_factor) {
		vector<int> a;
		a.pb(x.fi);
		int z = 0;
		while(a[a.size() - 1] < n) a.pb(a[a.size() - 1] * x.fi);
		REP(i, 0, a.size()) {
			int k = n / a[i] * a[i];
			z += (k - a[i]) / a[i] + 1;
		}
		if(res > z / x.se) res = z / x.se;
		//cerr << x.fi << ' ' << x.se << '\n';
	}
	cout << res;
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