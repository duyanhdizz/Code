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

vector<int> a = {2, 2 * 3, 2 * 3 * 5, 2 * 3 * 5 * 7, 2 * 3 * 5 * 7 * 11, 2 * 3 * 5 * 7 * 11 * 13, 2 * 3 * 5 * 7 * 11 * 13, 2 * 3 * 5 * 7 * 11 * 13 * 17, 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19, 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19 * 23};
vector<string> b = {"2", "2*3", "2*3*5", "2*3*5*7", "2*3*5*7*11", "2*3*5*7*11*13", "2*3*5*7*11*13", "2*3*5*7*11*13*17", "2*3*5*7*11*13*17*19", "2*3*5*7*11*13*17*19*23"};
int ans[15];

int32_t main() {
#define TASKNAME "BPRIME"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int n;
	while(cin >> n) {
		memset(ans, 0, sizeof ans);
		if(n == 0) return 0;
		cout << n << " = ";
		if(n == 1) {
			cout << 1 << '\n';
			continue;
		}
		int check = 0;
		FORD(i, a.size() - 1, 0) {
			if(n == 0) break;
			ans[i] = n / a[i];
			if(ans[i] > 0 && check == 0) {
				check = i;
			}
			n %= a[i];
		}
		if(n > 0) {
			cout << n << " + ";
		}
		FOR(i, 0, a.size() - 1) {
			if(ans[i] != 0) {
				if(check != i) cout << ans[i] << '*' << b[i] << " + ";
				else cout << ans[i] << '*' << b[i];
			}
		}
		cout << '\n';
	}
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