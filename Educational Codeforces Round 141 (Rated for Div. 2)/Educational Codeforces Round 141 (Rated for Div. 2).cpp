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

void IU() {
	int n;
	cin >> n;
	int le = 1;
	int chan = 2;
	bool work = true;
	int work_le = 0, work_chan = 0;
	int n_n = n;
	while(n--) {
		if(work == true) {
			vector<int> a;
			FOR(i, 1, n_n) {
				a.pb(le);
				le += 2;
			}
			work_le++;
			if(work_le % 2 == 1) reverse(all(a));
			each(x, a) cout << x << ' ';
			work = false;
		} else {
			vector<int> a;
			FOR(i, 1, n_n) {
				a.pb(chan);
				chan += 2;
			}
			work_chan++;
			if(work_chan % 2 == 0) reverse(all(a));
			each(x, a) cout << x << ' ';
			work = true;
		}
		cout << '\n';
	}
//	cout << '\n';
}

int32_t main() {
#define TASKNAME "Educational Codeforces Round 141 (Rated for Div. 2)"
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
