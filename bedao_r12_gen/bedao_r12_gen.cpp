/************************************
************************************/

#include <bits/stdc++.h>
#define tachVOI23 "VOI23"
#define st first
#define nd second
#define bit(n , i) ((n >> i) & 1)

using namespace std ;

const int N = 1e5 + 65 ;
const int mod = 1e9 + 7 ;
const long long inf = 1e18 ;

int n ;

int main() {
	cin.tie(0) -> sync_with_stdio(0) ;

	if (fopen(tachVOI23".inp","r")) {
		freopen(tachVOI23".inp", "r", stdin) ;
		freopen(tachVOI23".out", "w", stdout) ;
	}

	cin >> n ;
	long long ma = 0, len = 0, m = 0;
	for (int i = 1 ; i <= n ; i++) {
		string s ;
		cin >> s ;
		len = s.size() ;
		long long x = 0 ;
		for (int j = 0 ; j < len ; j++) {
			x = x * 10 + (s[j] - '0') ;
		}
		ma = max(ma, x) ;
		m = max(m, len);
	}
	int mm = m;
	mm--;
	long long k = 1;
	while(mm--) k *= 10;
	cout << max(k, ma) << '\n';
	while(m--) cout << 9;
}

/** /\_/\
 * (= ._.)
 * / >AC \>AC
**/
