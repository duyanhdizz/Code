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

map<int, int> m;
int a[10][10];

void IU() {
	FOR(i, 1, 3) FOR(j, 1, 3) cin >> a[i][j], m[a[i][j]]++;
	if(m.size() == 1) {
		cout << "NO";
		return;
	}
	set<int> s;
	s.insert(a[1][1] + a[1][2] + a[1][3]);
	s.insert(a[2][1] + a[2][2] + a[2][3]);
	s.insert(a[3][1] + a[3][2] + a[3][3]);
	s.insert(a[1][1] + a[2][1] + a[3][1]);
	s.insert(a[1][2] + a[2][2] + a[3][2]);
	s.insert(a[1][3] + a[2][3] + a[3][3]);
	cout << (s.size() == 1 ? "YES" : "NO");
}

int32_t main() {
#define TASKNAME "olp4ck1a"
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
