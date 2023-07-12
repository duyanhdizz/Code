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
const int N = 2106 + 2e5;
const int INF = 2106 + 1e9;

int n, k, a[N], b[N];

namespace sub124 {
	void main() {
		FOR(i, 1, n) {
			b[i] += b[i - 1] + a[i];
		}
		int ans = 0;
		FOR(i, 1, n) {
			int _ = 0, __ = -INF;
			int kc = k, ___ = 0;
			int sl = 0;
			FORD(j, i - 1, 1) {
				if(kc == 0) break;
				_ += a[i] - a[j];
				___++;
				if(_ > __) {
					__ = _;
					sl = ___;
				}
				kc--;
			}
			int p = i - sl - 1;
			_ = 0;
			__ = -INF;
			kc = k;
			int ____ = 0;
			int sl2 = 0;
			FOR(j, i + 1, n) {
				if(kc == 0) break;
				_ += a[i] - a[j];
				____++;
				if(_ > __) {
					__ = _;
					sl2 = max(sl2, ____);
				}
				kc--;
			}
			int pp = i + sl2 + 1;
			int sum = a[i] * (sl + sl2 + 1);
			if(p != 0) sum += b[p] - b[0];
			if(pp != 0) sum += b[n] - b[pp - 1];
			ans = max(ans, sum);
		}
		cout << ans;
	}
};

namespace sub3 {
	void main() {
		int _ = 0;
		FOR(i, 1, n) _ += a[i];
		cout << _;
	}
};

void SaKaTa() {
	cin >> n >> k;
	FOR(i, 1, n) cin >> a[i];
	if(k == 0) sub3::main();
	else sub124::main();
}

int32_t main() {
#define TASKNAME "respool"
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
		SaKaTa();
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
