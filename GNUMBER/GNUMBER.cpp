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

int t;

vector<int> prime;
vector<int> lpf;
void sieve(int n) {
	prime.assign(1, 2);
	lpf.assign(n + 1, 2);

	for (int x = 3; x <= n; x += 2) {
		if (lpf[x] == 2) prime.push_back(lpf[x] = x);
		for (int i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; ++i)
			lpf[prime[i] * x] = prime[i];
	}
}

bool check(int x) {
	return (lpf[x] == x);
}

int po[11];
bool b[11];
int x[11];
map<int, bool> m;

int len;

void printArray(int a[], int n) {
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res = res * 10 + a[i];
		if(check(res) & !m[res]) len++, m[res] = true;
	}
}

void dequy(int k, int n) {
	for (int i = 1; i <= n; i++) {
		if (b[i]) {
			x[k] = po[i];
			if (k == n) {
				printArray(x, n);
			} else {
				b[i] = false;
				dequy(k + 1, n);
				b[i] = true;
			}
		}
	}
}

void solve() {
	m.clear();
	string s;
	cin >> s;
	int pos = 0;
	each(x, s) po[++pos] = (x - '0');
	FOR(i, 1, pos) {
		b[i] = true;
	}
	len = 0;
	dequy(1, pos);
	cout << len << '\n';
}

int32_t main() {
#define TASKNAME "GNUMBER"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	sieve(1e7);
	cin >> t;
	while(t--)
		solve();
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