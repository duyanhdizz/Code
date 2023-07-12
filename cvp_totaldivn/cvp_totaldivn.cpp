/************************************
f[i][j] là số cách chọn đến số thứ i mà chia n dư j
************************************/

#include <bits/stdc++.h>
#define tachVOI23 ""
#define st first
#define nd second
#define bit(n , i) ((n >> i) & 1)

using namespace std ;

const int N = 5e3 + 65 ;
const int mod = 1e9 + 7 ;
const long long inf = 1e18 ;

int m , n , a[N] ;
long long f[N][N] ;

int main() {
    cin.tie(0) -> sync_with_stdio(0) ;

    if (fopen(tachVOI23".inp","r")) {
        freopen(tachVOI23".inp", "r", stdin) ;
        freopen(tachVOI23".out", "w", stdout) ;
    }

	cin >> m >> n ;
	for (int i = 1 ; i <= m ; i++) {
		cin >> a[i] ;
		a[i] %= n ;
	}
	for (int i = 0 ; i < m ; i++) f[i][0] = 1 ;
	for (int i = 1 ; i <= m ; i++) {
		for (int j = 0 ; j < n ; j++) f[i][j] = f[i - 1][j] ;
		for (int j = 0 ; j < n ; j++) f[i][(j + a[i]) % n] += f[i - 1][j] ;
	}
	// for (int i = 1 ; i <= m ; i++) {
		// for (int j = 0 ; j < n ; j++) {
			// cout << f[i][j] << ' ' ;
		// }
		// cout << '\n' ;
	// }
	cout << f[m][0] - 1 ;
}