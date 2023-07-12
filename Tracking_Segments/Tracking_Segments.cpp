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

void SaKaTa() {
	int n, m;
	cin >> n >> m;
	vector<pii> segments(m);
	FOR(i, 0, m - 1) {
		cin >> segments[i].first >> segments[i].second;
	}
	int q;
	cin >> q;
	vector<int> changes(q);
	FOR(i, 0, q - 1) {
		cin >> changes[i];
	}
	vector<int> ones(n + 1);
	int beautifulSegment = -1;
	FOR(i, 0, q - 1) {
		ones[changes[i]] = 1;
		FOR(j, 0, m - 1) {
			int countZeros = 0, countOnes = 0;
			for (int k = segments[j].first; k <= segments[j].second; k++) {
				if (ones[k] == 0) {
					countZeros++;
				} else {
					countOnes++;
				}
			}
			if (countOnes > countZeros) {
				beautifulSegment = i + 1;
				break;
			}
		}
		if (beautifulSegment != -1) {
			break;
		}
	}
	cout << beautifulSegment << '\n';
}

int32_t main() {
#define TASKNAME "Tracking_Segments"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
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
