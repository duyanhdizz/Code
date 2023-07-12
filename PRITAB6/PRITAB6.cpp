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
const int N = 9 + 1e7;
const int INF = 1e9;

int sss(string s) {
	int suu=0;
	for(int i=0; i<s.size(); i++)
		suu=suu*10+(s[i]-48);
	return suu;
}

int n,a[1509][1509],sum=0,dem=0,m,snt[N+1];

int32_t main() {
#define TASKNAME "PRITAB6"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	for(int i=2; i<=N; i++)
		snt[i]=1;
	snt[1]=0;
	for(int i=2; i<=sqrt(N); i++)
		if(snt[i]==1)
			for(int j=2*i; j<=N; j=j+i)
				snt[j]=0;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>a[i][j];
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(a[i][j]!=0) {
				string sau="";
				sau=(a[i][j]+48);
				for(int t=1; t<=5; t++) {
					sau+=(a[i][j+t]+48);
					if(j+t<=m) {
						long long soqua=sss(sau);
						if(snt[soqua]==1) {
							dem++;
							sum+=soqua;
						}
					}
				}
				sau="";
				sau=(a[i][j]+48);
				for(int t=1; t<=5; t++) {
					sau+=(a[i+t][j]+48);
					if(i+t<=n) {
						long long soqua=sss(sau);
						if(snt[soqua]==1) {
							dem++;
							sum+=soqua;
						}
					}
				}
				sau=(a[i][j]+48);
				for(int t=1; t<=5; t++) {
					sau+=(a[i+t][j+t]+48);
					if(i+t<=n) {
						long long soqua=sss(sau);
						if(snt[soqua]==1) {
							dem++;
							sum+=soqua;
						}
					}
				}
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(snt[a[i][j]]==1) {
				dem++;
				sum+=a[i][j];
			}

		}
	}
	cout<<dem<<' '<<sum;
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
