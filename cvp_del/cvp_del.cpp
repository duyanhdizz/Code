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

int n, pre[N], a[N];

int32_t main() {
#define TASKNAME "cvp_del"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	pre[0] = 0;
	FOR(i, 1, n) {
		cin >> a[i];
		pre[i] += pre[i - 1] + a[i];
	}
	sort(a + 1, a + n + 1);
	FOR(i, 1, n) cout << a[i] << ' ';
	cout << '\n';
	int m = n, len = 1, work = true;
	ll trungvi = (n + 1) / 2;
	while(m--) {
		ll sum = 0;
		//sum += (trungvi - 1) * a[trungvi] - (pre[trungvi - 1] - pre[0]) + (pre[n] - pre[trungvi]) - (n - trungvi) * a[trungvi];
		cout << (trungvi - 1) * a[trungvi] << ' ';
		if(work == true) {
			trungvi += len;
			work = false;
		} else {
			len++;
			trungvi -= len;
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