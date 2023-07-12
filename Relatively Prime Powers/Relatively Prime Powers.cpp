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
const ll INF = 2e18;

vector<ll> a[60];

void prime() {
	REP(i, 3, 60) {
		int x = 2;
		while (true) {
			ll tmp = 1;
			REP(j, 0, i) {
				if (tmp > INF / x) {
					tmp = -1;
					break;
				}
				tmp *= x;
			}
			if (tmp == -1)
				break;
			a[i].push_back(tmp);
			x++;
		}
	}
}

void YeuHuong() {
	ll n;
	cin >> n;
	vector<ll> cnt(60);
	cnt[1] = n - 1;
	cnt[2] = floor(sqrt(n)) - 1;
	if(1ll * cnt[2] * cnt[2] > n) cnt[2]--;
	if(1ll * (cnt[2] + 1) * (cnt[2] + 1) <= n) cnt[2]++;
	cnt[2]--;
	for (int i = 3; i < 60; i++) cnt[i] = upper_bound(a[i].begin(), a[i].end(), n) - a[i].begin();
	for (int i = 59; i >= 1; i--)
		for (int j = 2 * i; j < 60; j += i)
			cnt[i] -= cnt[j];
	cout << cnt[1] << '\n';
}

int32_t main() {
#define TASKNAME "Relatively Prime Powers"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	prime();
	int testcase;
	cin >> testcase;
	while(testcase--)
		YeuHuong();
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
