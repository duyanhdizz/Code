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

int cham[N], thang[N];

void IU() {
	int n;
	string s;
	cin >> n >> s;
	thang[-1] = 0;
	thang[0] = (s[0] == '#');
	FOR(i, 1, s.size() - 1) thang[i] += thang[i - 1] + (s[i] == '#');
	cham[s.size()] = 0;
	cham[s.size() - 1] = (s[s.size() - 1] == '.');
	FORD(i, s.size() - 2, 0) cham[i] += cham[i + 1] + (s[i] == '.');
	int ans = INF;
	FOR(i, 0, s.size()) {
		ans = min(ans, thang[i - 1] + cham[i]);
	}
	cout << ans;
}

int32_t main() {
#define TASKNAME "PCHAR"
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
