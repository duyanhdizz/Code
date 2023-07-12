#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define sz(a) int((a).size())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(), _e = (c).end(); i != _e; ++i)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,n) for(int i = 0, _n = (n); i < _n; ++i)
#define repd(i,n) for(int i = (n)-1; i >= 0; --i )
#define fo(i,a,b) for(int i = (a), _b = (b); i <= _b; ++i)
#define fod(i,a,b) for(int i = (a), _b = (b); i >= _b; --i)

#define INF 1000000000
#define N

char s[100000];

int main() {
#define TASKNAME "cvp_qbheap"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
    priority_queue<int> qu;
    while(gets(s) != NULL) {
        if( s[0] == '-' ) {
            if(!qu.empty()) {
                int mx = qu.top();
                while(!qu.empty() && qu.top() == mx) qu.pop();
            }
        } else if(qu.size() < 15000) {
            qu.push(atoi(s+1));
        }
    }
    vi res;
    int prev = INT_MAX;
    for(;!qu.empty(); qu.pop()) {
        if(qu.top() != prev)
        res.pb(prev = qu.top());
    }
    printf("%d\n", res.size());
    tr(res,it) printf("%d\n", *it);
    return 0;
}
