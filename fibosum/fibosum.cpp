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

const int mod = 1e9 + 7;
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
					product.a[i][k] = (product.a[i][k]
					                   + (long long) a[i][j] * other.a[j][k]) % mod;
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

int32_t main() {
#define TASKNAME "fibosum"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	long long n;
	cin >> n;
	Matrix single;
	single.a[0][0] = 0;
	single.a[0][1] = 1;
	single.a[1][0] = 1;
	single.a[1][1] = 1;
	cout << expo_power(single, n + 3).a[1][0] - 1;
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
