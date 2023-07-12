#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define FOR(i, a, b) for (int i = (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (int) (b); --i)
#define REP(i, a, b) for (int i = (a); i < (int) (b); ++i)
#define each(a, x) for (auto &a : x)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 2106 + 1e9;

const int mod = 1234567891;

int pre[N][20];

int scs(ll x) {
	int res = 0;
	set<int> s;
	while(x > 0) {
		s.insert(x % 10);
		x /= 10;
		res++;
	}
	return s.size();
}

void SaKaTa() {
	ll l, r;
	int k;
	cin >> l >> r >> k;
	cout << (pre[r][k] - pre[l - 1][k]) % mod << '\n';
}

int32_t main() {
#define TASKNAME "B"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	FOR(i, 1, 1e6) {
		pre[i][scs(i)] += i;
	}
	FOR(i, 1, 20) {
		FOR(j, 1, 1e6) {
			pre[j][i] += pre[j - 1][i];
		}
	}
	int testcase;
	cin >> testcase;
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
