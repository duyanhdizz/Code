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
const int N = 9 + 2e5;
const int INF = 1e9;

pii p[N];

void SaKaTa() {
	int n;
	cin >> n;
	FOR(i, 0, n - 1) {
		cin >> p[i].fi;
		p[i].se = 0;
	}
	FOR(i, n, 2 * n - 1) {
		cin >> p[i].fi;
		p[i].se = 1;
	}
	sort(p, p + 2 * n - 1);
	bool check = false;
	int cnt = 0;
	FOR(i, 0, 2 * n - 2) {
		if(check) check = false;
		else if (p[i].se != p[i + 1].se) {
			++cnt;
			check = true;
		}
	}
	cout << cnt;
}

int32_t main() {
#define TASKNAME ""
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
