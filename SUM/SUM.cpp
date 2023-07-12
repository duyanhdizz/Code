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

map<int, int> m;

void IU() {
	m.clear();
	int n;
	cin >> n;
	while(n--) {
		int x;
		cin >> x;
		m[x % 10]++;
	}
	FOR(i, 0, 9) {
		if(m[i] > 0) {
			m[i]--;
			FOR(j, 0, 9) {
				if(m[j] > 0) {
					m[j]--;
					FOR(z, 0, 9) {
						if(m[z] > 0) {
							m[z]--;
							if((i + j + z) % 10 == 3) {
//								cout << i << ' ' << j << ' ' << z << '\n';
								cout << "YES" << '\n';
								return;
							}
							m[z]++;
						}
					}
					m[j]++;
				}
			}
			m[i]++;
		}
	}
	cout << "NO" << '\n';
}

int32_t main() {
#define TASKNAME "SUM"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int testcase = 1;
	cin >> testcase;
	while(testcase--)
		IU();
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
