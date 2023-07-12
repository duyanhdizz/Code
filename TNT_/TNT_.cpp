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

char a[9], n;
ll F[9][73];
bool nguyento[73];
void sangnguyento(int n) {
	int i, j;
	memset(nguyento, true, sizeof(nguyento));
	nguyento[0] = nguyento[1] = false;
	for (i=2; i<=n; i++) {
		if (nguyento[i]) {
			for (j=i*i; j<=n; j+=i) nguyento[j] = false;
		}
	}
}
ll thu(int i, bool gh, int tong) {
	bool ghm;
	if (i < 0) {
		if(nguyento[tong]) return 1;
		else return 0;
	}
	if(gh == false && F[i][tong] >= 0) return F[i][tong];
	ll kq = 0;
	char maxc = (gh ? a[i] : 9);
	for (char c = 0; c <= maxc; c++) {
		ghm = gh && (c == maxc);
		kq += thu(i - 1, ghm, tong + c);
	}
	if (gh == false) F[i][tong] = kq;
	return kq;
}

ll G(ll x) {
	a[0] = 0;
	n = 0;
	while (x) {
		a[n] = x % 10;
		x /= 10;
		n++;
	}
	return thu(n - 1, true, 0);
}

void SaKaTa() {
	memset(F, -1, sizeof(F));
	sangnguyento(72);
	ll A, B;
	cin >> A >> B;
	cout << G(B) - G(A-1) << '\n';
}

int32_t main() {
#define TASKNAME "TNT_"
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
