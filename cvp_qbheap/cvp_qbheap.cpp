#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e5;
const int INF = 1e9;

string s;
vector<int> a;
priority_queue<int> qu;

int32_t main() {
#define TASKNAME "cvp_qbheap"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	while(cin >> s) {
		if(s[0] == '-') {
			if(!qu.empty()) {
				int pos = qu.top();
				while(!qu.empty() && qu.top() == pos) qu.pop();
			}
		} else s.erase(0, 1), qu.push(stoi(s));
	}
	cout << qu.size();
	while(!qu.empty()) {
		cout << qu.top();
		qu.pop();
	}
	return 0;
}
