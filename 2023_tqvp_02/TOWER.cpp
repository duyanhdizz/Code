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
const int N = 9 + 1e3;
const int INF = 2106 + 1e9;

int a[N][N], dp[N * 20];

void SaKaTa() {
	int s, n, m;
	cin >> s >> n >> m;
	REP(i, 0, s) {
		REP(j, 0, n) {
			cin >> a[i][j];
		}
	}
	REP(i, 0, n) sort(a[i], a[i] + m);
	FOR(i, 1, n) {
		FORD(j, m, 0) {
			REP(k, 0, s) {
				if(j < 2 * a[i][k] + 1) break;
				dp[j] = max(dp[j], dp[j - 2 * a[i][k] - 1] + (k + 1) * s);
			}
		}
	}
	cout << dp[m];
}

int32_t main() {
#define TASKNAME "TOWER"
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
