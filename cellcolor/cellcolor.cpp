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

int f[16][16];

void SaKaTa() {
	int r, c;
	cin >> r >> c;
	if(r == 1 || r == 15) cout << "black";
	if(r == 2 || r == 14) cout << (c == 1 || c == 15 ? "black" : "white");
	if(r == 3 || r == 13) cout << (c == 2 || c == 14 ? "white" : "black");
	if(r == 4 || r == 12) cout << (c == 1 || c == 3 || c == 13 || c == 15 ? "black" : "white");
	if(r == 5 || r == 11) cout << (c == 2 || c == 4 || c == 12 || c == 14 ? "white" : "black");
	if(r == 6 || r == 10) cout << (c == 1 || c == 3 || c == 5 || c == 11 || c == 13 || c == 15 ? "black" : "white");
	if(r == 7 || r == 9) cout << (c == 2 || c == 4 || c == 6 || c == 10 || c == 12 || c == 14 ? "white" : "black");
	if(r == 8) cout << (c % 2 == 0 ? "white" : "black");
}

int32_t main() {
#define TASKNAME "cellcolor"
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
