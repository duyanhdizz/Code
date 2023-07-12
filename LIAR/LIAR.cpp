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
const int N = 9 + 1e3;
const int INF = 1e9;

pair<int, char> v[N];

void SaKaTa() {
	int n;
	cin >> n;
	FOR(i, 1, n) {
		char c;
		int x;
		cin >> c >> x;
		v[i].fi = x;
		v[i].se = c;
	}
	sort(v + 1, v + n + 1);
	int ans = n;
	FOR(i, 1, n) { // cho i dung thi xet 1 -> i - 1 va i + 1 -> n
		int cnt = 0; // so loi noi doi
		FOR(j, 1, i - 1) {
			if(v[j].se == 'L' && v[i].fi != v[j].fi) cnt++; // < p[i]
		}
		FOR(j, i + 1, n) {
			if(v[j].se == 'G' && v[i].fi != v[j].fi) cnt++; // > p[i]
		}
		ans = min(ans, cnt);
	}
	cout << ans;
}

int32_t main() {
#define TASKNAME "LIAR"
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
