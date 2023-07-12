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
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 2e5;
const int INF = 1e9;

int n, a[N], b[N];

int tknp(int x) {
	if (b[1] > x ) return b[1];
	if (b[n] < x ) return b[n];
	int l = 1, h = n;
	while(l <= h) {
		int mid = (l + h) / 2;
		if (b[mid] == x) return b[mid];
		else if (b[mid] < x) l = mid + 1;
		else h = mid - 1;
	}
	if (abs(b[l] - x) < abs(b[h] - x)) return b[l];
	return b[h];
}

void SaKaTa() {
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n) cin >> b[i];
	sort(b + 1, b + 1 + n);
	int ans = INF;
	FOR(i, 1, n) {
		int search = tknp(-a[i]);
		int s = abs(a[i] + search);
		if(s == 0) {
			cout << 0;
			return;
		}
		ans = min(ans, s);
	}
	cout << ans;
}

int32_t main() {
#define TASKNAME "nksgame"
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
