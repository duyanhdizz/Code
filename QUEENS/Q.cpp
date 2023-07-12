#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> a;
int hang,cot,cheo1,i,j,n,k,x,y,l,r,tg,cheo2;
pair<int,int> b[100009];
map<int,int>demhang,demcot,demcheo1,demcheo2;
long long sum;
int main()
{
    freopen("QUEENS.inp","r",stdin);
    freopen("QUEENS.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>k>>n;
    a.push_back({0,0});
    for(i=1;i<=n;i++)
    {
        cin>>x>>y;
        a.push_back({x,y});
        b[i].first=x;
        b[i].second=y;
    }
    sort(a.begin(),a.end());
    hang=0;
    cot=0;
    cheo1=0;
    cheo2=0;
    for(i=1;i<=n;i++)
    {
        if(demhang[a[i].first]==0)
        {
            hang++;
            demhang[a[i].first]=hang;
        }
        if(demcot[a[i].second]==0)
        {
            cot++;
            demcot[a[i].second]=cot;
        }
        if(demcheo1[a[i].first-a[i].second]==0)
        {
            cheo1++;
            demcheo1[a[i].first-a[i].second]=cheo1;
        }
        if(demcheo2[a[i].first+a[i].second]==0)
        {
            cheo2++;
            demcheo2[a[i].first+a[i].second]=cheo2;
        }
    }
    vector <int> vhang[hang+2],vcot[cot+2],vcheo1[cheo1+2],vcheo2[cheo2+2];
    for(i=1;i<=n;i++)
    {
        vhang[demhang[a[i].first]].push_back(a[i].second);
        vcot[demcot[a[i].second]].push_back(a[i].first);
        vcheo1[demcheo1[a[i].first-a[i].second]].push_back(a[i].first);
        vcheo2[demcheo2[a[i].first+a[i].second]].push_back(a[i].first);
    }
    // thuc hien
    for(i=1;i<=n;i++)
    {
        // hang
        hang=demhang[b[i].first];
        cot=demcot[b[i].second];
        cheo1=demcheo1[b[i].first-b[i].second];
        cheo2=demcheo2[b[i].first+b[i].second];
        sum=0;
        l=0;
        r=vhang[hang].size()-1;
        tg=vhang[hang].size();
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(vhang[hang][mid]==b[i].second)
            {
                l=mid;
                break;
            }
            else
                if(vhang[hang][mid]>b[i].second)
                r=mid-1;
            else
                l=mid+1;
        }
        if(l==0)
            sum=sum+b[i].second-1;
        else
            sum=sum+b[i].second-vhang[hang][l-1]-1;
        if(l==tg-1)
            sum=sum+k-b[i].second;
        else
            sum=sum+vhang[hang][l+1]-b[i].second-1;
            // cot
        l=0;
        r=vcot[cot].size()-1;
        tg=vcot[cot].size();
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(vcot[cot][mid]==b[i].first)
            {
                l=mid;
                break;
            }
            else
                if(vcot[cot][mid]>b[i].first)
                r=mid-1;
            else
                l=mid+1;
        }
        if(l==0)
            sum=sum+b[i].first-1;
        else
            sum=sum+b[i].first-vcot[cot][l-1]-1;
        if(l==tg-1)
            sum=sum+k-b[i].first;
        else
            sum=sum+vcot[cot][l+1]-b[i].first-1;
            //hang cheo
        l=0;
        r=vcheo1[cheo1].size()-1;
        tg=vcheo1[cheo1].size();
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(vcheo1[cheo1][mid]==b[i].first)
            {
                l=mid;
                break;
            }
            else
                if(vcheo1[cheo1][mid]>b[i].first)
                r=mid-1;
            else
                l=mid+1;
        }
        if(l==0)
            sum=sum+min(b[i].first-1,b[i].second-1);
        else
            sum=sum+b[i].first-vcheo1[cheo1][l-1]-1;
        if(l==tg-1)
            sum=sum+min(k-b[i].first,k-b[i].second);
        else
            sum=sum+vcheo1[cheo1][l+1]-b[i].first-1;
           // cheo 2
        l=0;
        r=vcheo2[cheo2].size()-1;
        tg=vcheo2[cheo2].size();
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(vcheo2[cheo2][mid]==b[i].first)
            {
                l=mid;
                break;
            }
            else
                if(vcheo2[cheo2][mid]>b[i].first)
                r=mid-1;
            else
                l=mid+1;
        }
        if(l==0)
            sum=sum+min(b[i].first-1,k-b[i].second);
        else
            sum=sum+b[i].first-vcheo2[cheo2][l-1]-1;
        if(l==tg-1)
            sum=sum+min(k-b[i].first,b[i].second-1);
        else
            sum=sum+vcheo2[cheo2][l+1]-b[i].first-1;
        cout<<sum<<"\n";
    }
    return 0;
}

/*
199999999
299999998
300000000
300002019
300006901
300847963
300043677
301962491
303964991
300005879
*/