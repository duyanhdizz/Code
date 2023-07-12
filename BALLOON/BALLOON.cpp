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

map<int, int> cheo1;
int n, k, hang[109], cot[109], cheo2[209], dem[109][109], t;

int32_t main() {
#define TASKNAME "BALLOON"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> k;
	for(int i = 1; i <= k; i++) {
		int x, y;
		cin >> x >> y;
		dem[x][y]++;
		hang[x]++;
		cot[y]++;
		cheo1[x - y]++;
		cheo2[x + y]++;
	}
	int res = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if((hang[i] + cot[j] + cheo1[i - j] + cheo2[i + j] - 3 * dem[i][j]) == k)
				res++;
	cout << res;
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
