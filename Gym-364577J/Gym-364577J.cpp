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

vector <string> v;
bool can[10000];

bool check(string &s, string &t, int a, int b) {
	REP(i, 0, 4) {
		REP(j, 0, 4) {
			if(s[i] == t[j]) {
				if(i == j) a--;
				else b--;
			}
		}
	}

	if(a == 0 && b == 0) return true;
	return false;
}

void IU() {
	REP(i, 0, 10) {
		REP(j, 0, 10) {
			REP(k, 0, 10) {
				REP(l, 0, 10) {
					if(i != j && i != k && i != l && j != k && j != l && k != l) {
						string s;
						s += (char)('0' + i);
						s += (char)('0' + j);
						s += (char)('0' + k);
						s += (char)('0' + l);
						v.push_back(s);
					}
				}
			}
		}
	}

	int M = 10 * 9 * 8 * 7;
	REP(i, 0, M) can[i] = true;

	string t;
	int N, a, b;

	cin >> N;
	REP(i, 0, N) {
		cin >> t >> a >> b;
		REP(j, 0, M) if(!check(t, v[j], a, b)) can[j] = false;
	}

	int cnt = 0;
	string ans;
	REP(i, 0, M) if(can[i]) {
		ans = v[i];
		cnt++;
	}

	if(cnt == 0) cout << "Incorrect data";
	else if(cnt > 1) cout << "Need more data";
	else cout << ans;
}

int32_t main() {
#define TASKNAME "Gym-364577J"
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
