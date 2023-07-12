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

int f[N];
map<int, int> m;
vector<int> v;

int32_t main() {
#define TASKNAME "PERRESTO"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int n;
	cin >> n;
	REP(i, 1, n) cin >> f[i];
	FOR(j, 1, n) {
		m.clear();
		v.clear();
		m[j]++;
		v.pb(j);
		bool work = true;
		int i = 1;
		while(i < n) {
			int a = f[i] - v[v.size() - 1];
			if(m[a] == 1 || a > n) work = false;
			if(work == false) i = n + 1;
			m[a]++;
			v.pb(a);
			i++;
		}
		if(work == true) break;
	}
	each(x, v) cout << x << ' ';
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
