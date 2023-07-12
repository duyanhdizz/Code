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
const int N = 9 + 5e4;
const int INF = 1e9;

int n, a[N];

int32_t main() {
#define TASKNAME "pvoi14_4"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
	}
	int i = 1, len = 1;
	while(i <= n) {
		int j = i + 1;
		while(j <= n && a[j + 1] >= a[j]) j++;
		int ki = j;
		while(ki <= n && a[ki] <= a[ki + 1]) ki++;
		int kj = ki;
		while(kj <= n && a[kj + 1] >= a[kj]) kj++;
		int kl = kj;
		while(kl <= n && a[kl] <= a[kl + 1]) kl++;
		len = max(len, kl - i + 1);
		i = j;
	}
	cout << len;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
15
1 20 15 30 25 20 15 40 30 20 10 5 4 6 8
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
12
------------------------------    |
==================================+
*/
