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

int res, n;
int a[N];
int sign[3];

const int modulo = 1e9 + 7;

int compute() {
	stack<pii> st;
	st.push({sign[1], a[1]});

	FOR(i, 2, n) {
		if (sign[i] == 2) {
			assert(st.empty() == false);
			pii u = st.top();
			st.pop();
			u.se = 1LL * u.se * a[i] % modulo;
			st.push(u);
		} else st.push({sign[i], a[i]});
	}
	int finalSum = 0;
	while (!st.empty()) {
		pii u = st.top();
		st.pop();
		finalSum = (finalSum + (u.fi == 0 ? u.se : -u.se)) % modulo;
	}
	return finalSum;
}
void backtrack(int i) {
	if (i == n) {
		if (compute() == 0) res++;
		return;
	}
	REP(j, 0, 3) { // 0 => +; 1 => -; 2 => *;
		sign[i + 1] = j;
		backtrack(i + 1);
	}
}

void solve() {
	int m;
	cin >> n >> m;
	FOR(i, 1, n) cin >> a[i];
	res = 0;
	backtrack(1);
	cout << res << '\n';
}

int32_t main() {
#define TASKNAME "backtrack_e"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int testcase;
	cin >> testcase;
	while(testcase--)
		solve();
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
