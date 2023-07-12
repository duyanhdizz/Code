#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int n;
string a, b;

int32_t main() {
#define TASKNAME "fc014_lamp"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> a >> b;
	int res = 0;
	string aa = a, bb = b, aaa = a, bbb = b;
	for(int i = 0; i < n; i++) {
		if(a[i] == '0') res++;
		if(b[i] == '0') res++;
	}
	res += 2;
	int res2 = 0;
	for(int i = 0; i < n; i++) {
		if(aaa[i] == '0' && bbb[i] == '0') {
			res2++;
			aaa[i] = '1';
			bbb[i] = '1';
		}
	}
	for(int i = 0; i < n; i++) {
		if(aaa[i] == '0') res2++;
		if(bbb[i] == '0') res2++;
	}
	res2 += 2;
	int res3 = 0;
	int i = 0;
	while(i < aa.size()) {
		while(i < aa.size() && aa[i] == '0') i++;
		res3++;
		while(i < aa.size() && aa[i] == '1') i++;
	}
	res3 += 2;
	//cout << res3;
	cout << min({res, res2, res3});
	return 0;
}
/*
INPUT
5
11011
11011
OUTPUT
3
*/