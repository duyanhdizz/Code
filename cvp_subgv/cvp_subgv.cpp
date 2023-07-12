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

ll f[1009][1009], df[1009][1009], as[1009][1009], i, j, n, m, p, rs = 0, vt1 = 0, vt2 = 0, l, r, x, y, vt3 = 0, vt4 = 0;

int32_t main() {
#define TASKNAME "cvp_subgv"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin>>m>>n;
	for(i=1; i<=m; i++) {
		for(j=1; j<=n; j++) {
			cin>>f[i][j];
			if(j>1) {
				if(f[i][j]==f[i][j-1])
					df[i][j]=df[i][j-1]+1;
				else df[i][j]=1;
			} else df[i][j]=1;
			//rs=max(rs,df[i][j]);
			if(df[i][j]>=rs) {
				vt1=i;
				vt3=i;
				vt2=j-df[i][j]+1;
				vt4=j;
				rs=df[i][j];
			}
			as[i][j]=1;
			//cout<<df[i][j]<<" ";
		}
		//cout<<"\n";
	}
	for(i=2; i<=m; i++) {
		for(j=1; j<=n; j++) {
			if(f[i][j]==f[i-1][j]) {
				df[i][j]=min(df[i-1][j],df[i][j]);
				as[i][j]=as[i-1][j]+1;
				r=as[i][j]*df[i][j];
				//if(r==6) cout<<rs<<" ";
				if(r>rs) {
					x=i-as[i][j]+1;
					y=j-df[i][j]+1;
					vt1=x;
					vt2=y;
					vt3=i;
					vt4=j;
					rs=r;
				} else if(r==rs) {
					x=i-as[i][j]+1;
					y=j-df[i][j]+1;
					//if(i==4 && j==4) cout<<x<<" "<<y<<"\n"<<vt1<<" "<<vt2<<"\n";
					if(x>vt1) {
						vt1=x;
						vt2=y;
						vt3=i;
						vt4=j;
					} else {
						if(x==vt1) {
							if(y>vt2) {
								vt1=x;
								vt2=y;
								vt3=i;
								vt4=j;
							}
						}
					}
					rs=r;
				}
			}
		}
	}
	cout << vt1 << " " << vt2 << " " << vt3 << " " << vt4;
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
