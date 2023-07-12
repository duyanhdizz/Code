/************************************
************************************/

#include <bits/stdc++.h>
#define tachVOI23 ""
#define st first
#define nd second
#define bit(n , i) ((n >> i) & 1)

using namespace std ;

const int N = 5e5 + 65 ;
const int mod = 1e9 + 7 ;
const long long inf = 1e18 ;

int t, n, l[N] ;

int main() {
	cin.tie(0) -> sync_with_stdio(0) ;

	if (fopen(tachVOI23".inp","r")) {
		freopen(tachVOI23".inp", "r", stdin) ;
		freopen(tachVOI23".out", "w", stdout) ;
	}

	cin >> t ;
	while(t--) {
		cin >> n ;
		int ans = 0;
		for (int i = 1 ; i <= n ; i++) {
			cin >> l[i] ;
			ans += l[i] ;
		}
		sort(l + 1, l + 1 + n) ;
		for (int i = 1 ; i <= n ; i++) {
			l[i] += l[i - 1] ;
		}
		int i = n;
		l[0] = 0;
		while ((l[i] - l[i - 1]) >= l[i - 1] && i >= 1) {
			ans -= l[i] - l[i - 1] ;
			i--;
		}
		cout << ans << '\n' ;
	}
}

/** /\_/\
 * (= ._.)
 * / >AC \>AC
**/
