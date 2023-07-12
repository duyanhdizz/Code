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

ll n, a[N];

int32_t main() {
#define TASKNAME ""
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	ll res = 0;
	for(int i = 1; i * (i + 1) / 2 <= n; i++) {
		int work = 0;
		map<ll, ll> cnt;
		FOR(j, 1, n) {
			if(a[j] <= i) {
				cnt[a[j]]++;
				work += (cnt[a[j]] == a[j]);
			}
			if (j > i * (i + 1) / 2 && a[j - i * (i + 1) / 2] <= i) {
				work -= cnt[a[j - i * (i + 1) / 2]] == a[j - i * (i + 1) / 2];
				cnt[a[j - i * (i + 1) / 2]]--;
			}
			res += (work == i);
		}
	}
	cout << (7 & 3) + (7 | 3) + (7 ^ 3);
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
6
2 2 1 2 2 1
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/
