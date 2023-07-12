/************************************
************************************/

#include <bits/stdc++.h>
#define tachVOI23 "VOI23"
#define st first
#define nd second
#define bit(n , i) ((n >> i) & 1)

using namespace std ;

const int N = 1e6 + 65 ;
const int mod = 1e9 + 7 ;
const long long inf = 1e18 ;

map<int , int> cnt ;
string s ;

int cv(char c) {
	return c - '0' + 8 ;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0) ;

    if (fopen(tachVOI23".inp","r")) {
        freopen(tachVOI23".inp", "r", stdin) ;
        freopen(tachVOI23".out", "w", stdout) ;
    }

    cin >> s ;
    for (char c : s) cnt[cv(c)] ++ ;
	for (int i = 0 ; i < cnt[52] ; i++) {
		cnt[cv(':')] -- ;
		cnt[cv('-')] -- ;
		cnt[cv('/')] -- ;
		cout << ":-\\" << '\n' ;
	}
	for (int i = 0 ; i < cnt[cv('P')] ; i++) {
		cnt[cv(':')] -- ;
		cnt[cv('-')] -- ;
		cnt[cv('P')] -- ;
		cout << ":-P" << '\n' ;
	}
	for (int i = 0 ; i < cnt[cv('D')] ; i++) {
		cnt[cv(':')] -- ;
		cnt[cv('D')] -- ;
		cout << ":D" << '\n' ;
	}
	for (int i = 0 ; i < cnt[cv('C')] ; i++) {
		cnt[cv(':')] -- ;
		cnt[cv('C')] -- ;
		cout << ":C" << '\n' ;
	}
	for (int i = 0 ; i < cnt[cv('8')] ; i++) {
		cnt[cv('8')] -- ;
		cnt[cv('-')] -- ;
		cnt[cv('0')] -- ;
		cout << "8-0" << '\n' ;
	}
	for (int i = 0 ; i < cnt[cv('E')] ; i++) {
		cnt[cv(':')] -- ;
		cnt[cv('-')] -- ;
		cnt[cv('E')] -- ;
		cout << ":-E" << '\n' ;
	}
	for (int i = 0 ; i < cnt[cv('X')] ; i++) {
		cnt[cv(':')] -- ;
		cnt[cv('-')] -- ;
		cnt[cv('X')] -- ;
		cout << ":-X" << '\n' ;
	}
	for (int i = 0 ; i < cnt[cv('0')] ; i++) {
		cnt[cv(':')] -- ;
		cnt[cv('-')] -- ;
		cnt[cv('0')] -- ;
		cout << ":-0" << '\n' ;
	}
	for (int i = 0 ; i < cnt[cv('[')] ; i++) {
		cnt[cv('[')] -= 2 ;
		cnt[cv(':')] -= 2 ;
		cnt[cv('|')] -= 3 ;
		cout << "[:|||:]" << '\n' ;
	}
	for (int i = 0 ; i < cnt[cv('~')] ; i++) {
		cnt[cv(':')] -- ;
		cnt[cv('~')] -- ;
		cnt[cv('(')] -- ;
		cout << ":~(" << '\n' ;
	}
	for (int i = 0 ; i < cnt[cv('|')] ; i++) {
		cnt[cv(':')] -- ;
		cnt[cv('-')] -- ;
		cnt[cv('|')] -- ;
		cout << ":-|" << '\n' ;
	}
	for (int i = 0 ; i < cnt[cv('-')] ; i++) {
		for (int j = 0 ; j < cnt[1] ; j++) {
			cnt[cv(';')] -- ;
			cnt[cv('-')] -- ;
			cnt[1] -- ;
			cout << ";-)" << '\n' ;
		}
		for (int j = 0 ; j < cnt[0] ; j++) {
			cnt[cv(';')] -- ;
			cnt[cv('-')] -- ;
			cnt[0] -- ;
			cout << ";-(" << '\n' ;
		}
	}
	for (int i = 0 ; i < cnt[0] ; i++) {
		cout << ":(" << '\n' ;
	}
	for (int i = 0 ; i < cnt[1] ; i++) {
		cout << ":)" << '\n' ;
	}
}

/** /\_/\
 * (= ._.)
 * / >AC \>AC
**/
