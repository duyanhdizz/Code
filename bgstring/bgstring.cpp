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

string s;

bool check(string res) {
	bool ktra = true;
	string ss = s;
	//cout << res << '\n';
	while(ktra == true) {
		if(ss == "") return true;
		bool r = false;
		for(int i = 0; i + res.size() - 1 < ss.size(); i++) {
			string v = ss.substr(i, res.size());
			//cout << v << '\n';
			if(v == res) {
				//cout << v << '\n';
				ss.erase(i, res.size());
				r = true;
			}
		}
		if(r == false) ktra = false;
	}
	return ktra;
}

bool cmp(string l, string r) {
	if(l.size() == r.size()) return l < r;
	return l.size() < r.size();
}

int32_t main() {
#define TASKNAME "bgstring"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> s;
	vector<string> ss;
	for(int v = 0; v < s.size(); v++) {
		for(int i = 1; i + v - 1 < s.size(); i++) {
			string res = s.substr(v, i);
			//cout << res << '\n';
			if(check(res) == true) {
				ss.pb(res);
			}
		}
	}
	sort(all(ss), cmp);
	cout << ss[0];
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
hhehellolloelhellolo
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
hello
------------------------------    |
==================================+
*/
