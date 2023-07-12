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
const int N = 9 + 3e2;
const int INF = 1e9;

int n, k;
int a[N];
long long f[N][N][N >> 1];
long long Calc(int l, int r, int k) {
	if (k == 0) return 0;
	if (l > r) return -1e15;
	long long &res = f[l][r][k];
	if (res != -1) return res;
	res = max(Calc(l + 1, r, k), Calc(l, r - 1, k));
	if (l <= r - 1) {
		res = max(res, Calc(l, r - 2, k - 1) + abs(a[r] - a[r - 1]));
		res = max(res, Calc(l + 2, r, k - 1) + abs(a[l] - a[l + 1]));
		res = max(res, Calc(l + 1, r - 1, k - 1) + abs(a[l] - a[r]));
	}
	return res;
}

void SaKaTa() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	memset(f, 255, sizeof(f));
	cout << Calc(1, n, k);
}

int32_t main() {
#define TASKNAME "voi20bonus"
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
