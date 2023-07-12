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
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 2106 + 1e6;
const int INF = 2106 + 1e9;

long long n, l, _;

struct Matrix {
	int a[2][2] = {{0, 0}, {0, 0}};
	Matrix operator *(const Matrix& other) const {
		Matrix product;
		for(int i : {
		            0, 1
		        }) {
			for(int j : {
			            0, 1
			        }) {
				for(int k : {
				            0, 1
				        }) {
					product.a[i][k] = (product.a[i][k] + (long long) a[i][j] * other.a[j][k]) % _;
				}
			}
		}
		return product;
	}
};

Matrix expo_power(Matrix a, long long n) {
	Matrix res;
	res.a[0][0] = res.a[1][1] = 1;
	while(n) {
		if(n % 2) {
			res = res * a;
		}
		n /= 2;
		a = a * a;
	}
	return res;
}

int v[N], f[N];
Matrix single;

void SaKaTa() {
	cin >> n >> l >> _;
//	expo_power(single, i).a[1][0]
	int pos = 0;
	FOR(i, l, l + n - 1) v[++pos] = expo_power(single, i).a[1][0];
	FOR(i, 1, pos) f[i] += f[i - 1] + v[i], f[i] %= _;
	f[0] = 0;
	gp_hash_table<int, int> DA;
	FOR(i, 0, pos) {
		if(DA[f[i]] == 0) {
			if(f[i] != 0) DA[f[i]] = i;
			else {
				if(i != 0) {
					cout << i - DA[f[i]] << ' ';
					FOR(j, DA[f[i]] + 1, i) cout << j + l - 1 << ' ';
					cout << '\n';
					FOR(o, 1, pos) f[o] = 0;
					return;
				}
			}
		} else {
			cout << i - DA[f[i]] << ' ';
			FOR(j, DA[f[i]] + 1, i) cout << j + l - 1 << ' ';
			cout << '\n';
			FOR(o, 1, pos) f[o] = 0;
			return;
		}
	}
	cout << 0 << '\n';
}

int32_t main() {
#define TASKNAME "voi17fibseq"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	single.a[0][0] = 0;
	single.a[0][1] = 1;
	single.a[1][0] = 1;
	single.a[1][1] = 1;
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
