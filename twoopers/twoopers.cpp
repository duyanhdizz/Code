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
#define int long long
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e7;
const int INF = 1e9;
const long long MOD = 1e9 + 7;

string s, t;
long long pow26[N], hashS[2 * N], hashT[N], res, tang[N], giam[N];

long long getHashS(int i, int j) {
	if (i > j) return 0;
	if (i == 0) return hashS[j];
	return (hashS[j] - hashS[i - 1] * pow26[j - i + 1] + MOD * MOD) % MOD;
}

long long getHashT(int i, int j) {
	if (i > j) return 0;
	if (i == 0) return hashT[j];
	return (hashT[j] - hashT[i - 1] * pow26[j - i + 1] + MOD * MOD) % MOD;
}

int32_t main() {
#define TASKNAME ""
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> s >> t;
	int n = s.size();
	s = ' ' + t + ' ' + s + s + ' ' + t;
	int l = 1;
	int len = 4 * n + 2;
	for (int i = 2; i <= len; i++) {
		tang[i] = max(0ll, min(tang[i - l + 1], l + tang[l] - i));
		while (i + tang[i] <= 4 * n + 2 && s[tang[i] + 1] == s[i + tang[i]]) tang[i]++;
		if (i + tang[i] > l + tang[l]) l = i;
	}
	l = 4 * n + 2;
	for (int i = len - 1; i > 0; i--) {
		giam[i] = max(0ll, min(giam[4 * n + 2 - l + i], i - l + giam[l]));
		while (i - giam[i] > 0 && s[4 * n + 2 - giam[i]] == s[i - giam[i]]) giam[i]++;
		if (i - giam[i] < l - giam[l]) l = i;
	}
	long long res = 0;
	for (int i = (len + 2) / 4 + 1; i <= len / 2; i++) {
		if (tang[i] == n) res += n;
		if (giam[i + n - 1] + tang[i] == n - 1) res++;
	}
	cout << res;
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
