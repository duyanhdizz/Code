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
const int N = 9 + 1e6;
const int INF = 1e9;
// BAOBAYBONG
// 12345678910
void SaKaTa() {
	int l, r;
	cin >> l >> r;
	l--;
	r--;
	string s = "BAOBAYBONG";
	int ans = 0;
	if(r - l + 1 > 10) {
		while(l % 10 != 0) {
			if(s[l % 10] == 'B') ans++;
			l++;
		}
		while(r % 10 != 9) {
			if(s[r % 10] == 'B') ans++;
			r--;
		}
	} else {
		FOR(i, l % 10, r % 10) {
			if(s[i] == 'B') {
				ans++;
			}
		}
	}
	cout << ans + ((r - l + 1) / 10) * 3;
}

int32_t main() {
#define TASKNAME "bulu"
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
