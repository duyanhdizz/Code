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

int32_t main() {
#define TASKNAME "coci1920_r3_preokret"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int n;
	cin >> n;
	int MAN = 0, MU = 0;
	int tang = 0;
	int hoa = 1;
	int last = 0;
	int ans = 0;
	int ls;
	while(n--) {
		int x;
		cin >> x;
		if(x == 1) MAN++;
		else MU++;
		if(MAN == MU) hoa++;
		if(last == 0) {
			last = x;
		} else {
			if(last == x) {
				if(MU != 0) {
					tang++;
				}
			} else {
				if(x == 1) {
					if(MU > MAN - 1 && MU - tang < MAN - 1) {
						ans = max(ans, tang);
					}
					tang = 1;
					last = x;
				} else {
					if(MAN > MU - 1 && MAN - tang < MU - 1) {
						ans = max(ans, tang);
					}
					tang = 1;
					last = x;
				}
			}
		}
		if(n == 0) ls = x;
	}
	if(ls == 2) {
		if(MU > MAN && MU - tang < MAN) {
			ans = max(ans, tang);
		}
	} else {
		if(MAN > MU && MAN - tang < MU) {
			ans = max(ans, tang);
		}
	}
	cout << MAN << ' ' << MU << '\n' << hoa << '\n' << ans;
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
