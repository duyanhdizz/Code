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
const int INF = 1e18;

int n, k, a[N];

namespace sub1 {
	void main() {
		sort(a + 1, a + 1 + n);
		cout << a[n] + a[n - 1] - a[1];
	}
};

int ans = -INF;

map<int, int> m;

void dequy(int i, int sum, int du, int check, int member) {
	if(check > 3) check -= 3;
	if(member == k * 3) {
		ans = max(ans, sum);
		return;
	}
	if(i == n + 1) {
		if(member < k * 3) {
			i = 1;
		}
	}
	if(du > 0) {
		dequy(i + 1, sum, du - 1, check, member);
	}
	if(check == 1 || check == 3) dequy(i + 1, sum + a[i], du, check + 1, member + 1);
	else dequy(i + 1, sum - a[i], du, check + 1, member + 1);
}

void IU() {
	cin >> n >> k;
	FOR(i, 1, n) cin >> a[i];
	if(k == 1) sub1::main();
	else {
		FOR(i, 1, n) dequy(i, 0, n - 3 * k, true, 0);
		cout << ans;
	}
}

int32_t main() {
#define TASKNAME "olp4ck1c"
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
