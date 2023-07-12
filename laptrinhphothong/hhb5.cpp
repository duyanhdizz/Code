#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast","unroll-loops")
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

int a[3];

int32_t main() {
#define TASKNAME "hhb5"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	if(a[0] + a[1] <= a[2]) {
		cout << "KHONG PHAI TAM GIAC";
		return 0;
	}
	if(a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) {
		cout << "TAM GIAC VUONG";
		return 0;
	}
	if(a[0] == a[1] || a[1] == a[2]) {
		cout << "TAM GIAC CAN";
		return 0;
	}
	cout << "TAM GIAC THUONG";
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
