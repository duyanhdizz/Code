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

bool check(string x) {
	if (x.size() == 0) return false;
	if (x[0] == '0' && x.size() > 1) return false;
	for(int i = 0; i < x.size(); i++)
		if (x[i] < '0' || x[i] > '9')
			return false;
	return true;
}

void YeuHuong() {
	string s, a, b;
	cin >> s;
	s += ',';
	int res = -1, n = s.size();
	while (res < n - 1) {
		res++;
		string x = "";
		while (s[res] != ',' && s[res] != ';' && res < n) {
			x += s[res];
			res++;
		}
		if (check(x)) {
			a += x;
			a += ',';
		} else {
			b += x;
			b += ',';
		}
	}
	int ma = a.size(), mb = b.size();
	if (ma == 0) cout << "-" << '\n';
	else cout << (char) 34 << a.substr(0, ma - 1) << (char) 34 << '\n';
	if (mb == 0) cout << "-" << '\n';
	else cout << (char) 34 << b.substr(0, mb - 1) << (char) 34;
}

int32_t main() {
#define TASKNAME "Extract Numbers"
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
