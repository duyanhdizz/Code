#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
long long ans[100005];
int n,k,a,b;
pair<int,pair<int,int>> c[100005],r[100005],x1[100005],x2[100005];
int main(){
     freopen("queens.inp","r",stdin);
     freopen("queens.out","w",stdout);
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);
     cin>>k>>n;
     for (int i=1;i<=n;i++)
     {
         cin >> a >> b;
         c[i] = {b,{a,i}};
         r[i] = {a,{b,i}};
         x1[i] = {a-b+k,{a,i}};
         x2[i] = {a-(k-b+1)+k,{a,i}};
     }
    sort(c+1,c+n+1);
    sort(r+1,r+n+1);
    sort(x1+1,x1+n+1);
    sort(x2+1,x2+n+1);
    for (int i=1;i<=n;i++)
    {
        if ( c[i].fi == c[i-1].fi )
            ans[c[i].se.se] += ( c[i].se.fi - c[i-1].se.fi-1 );
        else
            ans[c[i].se.se] += (c[i].se.fi-1);
        if ( c[i].fi == c[i+1].fi )
            ans[c[i].se.se] += ( c[i+1].se.fi - c[i].se.fi-1 );
        else
            ans[c[i].se.se]+=(k-c[i].se.fi);
    }
    for (int i=1;i<=n;i++)
    {
        if (r[i].fi==r[i-1].fi)
            ans[r[i].se.se]+=(r[i].se.fi-r[i-1].se.fi-1);
        else
            ans[r[i].se.se]+=(r[i].se.fi-1);
        if (r[i].fi==r[i+1].fi)
            ans[r[i].se.se]+=(r[i+1].se.fi-r[i].se.fi-1);
        else
            ans[r[i].se.se]+=(k-r[i].se.fi);
    }

    for (int i=1;i<=n;i++)
    {
        if (x1[i].fi==x1[i-1].fi)
            ans[x1[i].se.se]+=(x1[i].se.fi-x1[i-1].se.fi-1);
        else
            ans[x1[i].se.se]+=(x1[i].se.fi-(max(0,x1[i].fi-k))-1);
        if (x1[i].fi==x1[i+1].fi)
            ans[x1[i].se.se]+=(x1[i+1].se.fi-x1[i].se.fi-1);
        else
            ans[x1[i].se.se]+=(min(k+1,x1[i].fi+1)-x1[i].se.fi-1);
    }
     for (int i=1;i<=n;i++)
    {
        if (x2[i].fi==x2[i-1].fi)
            ans[x2[i].se.se]+=(x2[i].se.fi-x2[i-1].se.fi-1);
        else
            ans[x2[i].se.se]+=(x2[i].se.fi-(max(0,x2[i].fi-k))-1);
        if (x2[i].fi==x2[i+1].fi)
            ans[x2[i].se.se]+=(x2[i+1].se.fi-x2[i].se.fi-1);
        else
            ans[x2[i].se.se]+=(min(k+1,x2[i].fi+1)-x2[i].se.fi-1);
    }
    for (int i=1;i<=n;i++)
        cout<<ans[i]<<"\n";
return 0;
}
/*
*/