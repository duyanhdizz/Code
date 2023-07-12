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

ll a[N];
map<ll, int> m;

void IU() {
	int n, k;
	cin >> n >> k;
	FOR(i, 1, n) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	ll ans = 0;
	if(k == 1) {
		FORD(i, n, 0) {
			if(m.find(a[i] + 1) != m.end()) ans += m[a[i] + 1];
			m[a[i]]++;
		}
		cout << ans;
		return;
	}
	if(k == -1) {
		FORD(i, n, 0) {
			if(m.find(a[i] - 1) != m.end()) ans += m[a[i] - 1];
			if(m.find(a[i] + 1) != m.end()) ans += m[a[i] + 1];
			m[a[i]]++;
		}
		cout << ans;
		return;
	}
	FORD(i, n, 0) {
		ll d = 1;
		while(d <= 1e14) {
			if(m.find(a[i] + d) != m.end()) ans += m[a[i] + d];
			d *= k;
		}
		m[a[i]]++;
	}
	cout << ans;
}

int32_t main() {
#define TASKNAME "Gym-364577H"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int testcase = 1;
//    cin >> testcase;
	while(testcase--)
		IU();
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
