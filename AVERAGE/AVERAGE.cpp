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
const int N = 9 + 1e2;
const int INF = 1e9;

int a[N];

void SaKaTa() {
	int n;
	cin >> n;
	FOR(i, 0, n - 1) cin >> a[i];
	int ans = 0;
	FOR(i, 0, n - 1) {
		double sum = 0;
		FOR(j, i, n - 1) {
			sum += a[j];
			double avg = sum / (j - i + 1);
			bool check = false;
			FOR(k, i, j) {
				if (a[k] == avg) {
					check = true;
					break;
				}
			}
			if(check) {
				ans++;
			}
		}
	}
	cout << ans;
}

int32_t main() {
#define TASKNAME "AVERAGE"
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
