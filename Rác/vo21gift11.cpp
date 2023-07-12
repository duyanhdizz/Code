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

const int mod = 998244353;

int n;
int a[2020];
int v[2][12];
vector<int> g[2];
int cnk[4020][4020];
int fact[4020];
ll cntOfDivide(int n, int g) {
	return cnk[n + g - 1][n];
}
int dppos[2010][11];
int dpneg[2020][11];

int32_t main() {
#define TASKNAME "vo21gift11"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cnk[0][0] = 1;
	for (int i = 1; i <= 4000; ++i) {
		cnk[i][0] = 1;
		for (int j = 1; j <= 4000; ++j) {
			cnk[i][j] = cnk[i - 1][j - 1] + cnk[i - 1][j];
			if (cnk[i][j] >= mod) {
				cnk[i][j] -= mod;
			}
		}
	}
	fact[0] = 1;
	for (int i = 1; i <= 4000; ++i) {
		fact[i] = fact[i - 1] * (ll)i % mod;
	}
	int tc;
	cin >> tc;
	while (tc--) {
		int neg = 0;
		int pos = 0;
		cin >> n;
		int sum = 0;
		int sumPos = 0;
		int sumNeg = 0;
		memset(v, 0, sizeof(v));
		g[0].clear();
		g[1].clear();
		memset(dppos, 0, sizeof(dppos));
		memset(dpneg, 0, sizeof(dpneg));
		FOR(i, 1, n) {
			cin >> a[i];
			int x = a[i];
			int cnt = 0;
			while (x > 0) {
				x /= 10;
				++cnt;
			}
			v[cnt % 2][a[i] % 11]++;
			if (cnt % 2 == 1) {
				++neg;
				sumNeg += a[i] % 11;
			} else {
				++pos;
				sumPos += a[i] % 11;
			}
			sum += a[i] % 11;
			g[cnt % 2].push_back(a[i] % 11);
		}
		sumPos %= 11;
		sumNeg %= 11;
		dppos[0][0] = 1;
		for (int i = 0; i < g[0].size(); ++i) {
			int val = g[0][i];
			for (int j = i; j >= 0; --j) {
				for (int k = 0; k < 11; ++k) {
					int to = k + val;
					if (to >= 11) to -= 11;
					dppos[j + 1][to] += dppos[j][k];
					if (dppos[j + 1][to] >= mod) {
						dppos[j + 1][to] -= mod;
					}
				}
			}
		}
		dpneg[0][0] = 1;
		for (int i = 0; i < g[1].size(); ++i) {
			int val = g[1][i];
			for (int j = i; j >= 0; --j) {
				for (int k = 0; k < 11; ++k) {
					int to = k + val;
					if (to >= 11) to -= 11;
					dpneg[j + 1][to] += dpneg[j][k];
					if (dpneg[j + 1][to] >= mod) {
						dpneg[j + 1][to] -= mod;
					}
				}
			}
		}
		if (neg == 0) {
			cout << (sum % 11 == 0 ? fact[n] : 0) << endl;
			continue;
		}
		ll ans = 0;
		int rangesMinus = (neg + 1) / 2;
		int rangesPlus = 1 + neg / 2;
		for (int i = 0; i <= pos; ++i) {
			for (int s1 = 0; s1 < 11; ++s1) {
				int s2 = (sumPos + 11 - s1) % 11;
				for (int s3 = 0; s3 < 11; ++s3) {
					int s4 = (sumNeg + 11 - s3) % 11;
					if ((s1 - s2 + s3 - s4) % 11 != 0) {
						continue;
					}
					ll res = 1;
					res = res * dpneg[rangesMinus][s3] % mod;
					res = res * fact[rangesMinus] % mod;
					res = res * fact[neg - rangesMinus] % mod;

					res = res * dppos[i][s1] % mod;
					res = res * fact[pos - i] % mod;
					res = res * fact[i] % mod;
					res = res * cnk[i + rangesPlus - 1][i] % mod;
					res = res * cnk[pos - i + rangesMinus - 1][pos - i] % mod;
					ans += res;
				}
			}
		}
		cout << ans % mod << '\n';
	}
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
