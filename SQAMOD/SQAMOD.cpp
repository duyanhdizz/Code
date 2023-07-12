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

char a[20], n;
ll F[20][3];

const ll MOD = 1e9 + 7;

ll thu(int i, bool gh, int tong) {
	bool ghm;
	if (i < 0) {
		if(tong == 0) return 1;
		else return 0;
	}
	if(gh == false && F[i][tong] >= 0) return F[i][tong];
	ll kq = 0;
	char maxc = (gh ? a[i] : 9);
	for (char c = 0; c <= maxc; c++) {
		ghm = gh && (c == maxc);
		kq += thu(i - 1, ghm, (tong + c * c) % 3);
	}
	kq %= MOD;
	if (gh == false) F[i][tong] = kq;
	return kq;
}

int dis = 0;

ll G(string x) {
	int t=0;
	n=x.length();
	for (int i=0; i<n; i++) a[n-1-i]=x[i]-48;
	for (int i=0; i<n; i++) t+=a[i]*a[i];
	if (t%3==0) dis=1;
	return thu(n-1,true,0);
}

void SaKaTa() {
	memset(F, -1, sizeof(F));
	string A;
	cin >> A;
	cout << G(A) - dis << '\n';
}

int32_t main() {
#define TASKNAME "SQAMOD"
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
