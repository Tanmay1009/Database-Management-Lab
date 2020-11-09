/*
 * Author: Anmol Choudhary
 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define rep0(a,b) for(int a=0;a<b;a++)
#define rep1(a,b) for(int a=1;a<=b;a++)
#define repp(a,b,c) for(int a=b;a<c;a++)
#define in insert
#define len length()
#define si size()
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define pr(a) cout<<a
#define pr2(a,b) cout<<a<<" "<<b<<"\n"
#define nextl cout<<"\n"
#define deb(x) cout<<#x<<"="<<x<<"\n"
#define deb2(x,y) cout<<"["<<#x<<"="<<x<<"] , ["<<#y<<"="<<y<<"]"<<"\n"
#define int ll
const ll mod = 1000000007;
const ll maxn = 100005;
const ll mm = 1e+18;
vector<int>gr[maxn];
int h[maxn];
int arr[maxn];
map<int,set<int>>s[maxn];
int wh[maxn];
int tree[4*maxn];
int mx=-1;
void dfs(int he,int pa,int d){
    mx=max(mx,d);
    wh[he]=d;
    s[d][arr[he]].in(he);
    for(auto x:gr[he]){
        if(x!=pa) dfs(x,he,d+1);
    }
}
void build(int no,int l,int r){
    if(l==r){
        tree[no]=h[l];
        return;
    }
    int mid=(l+r)>>1;
    build(2*no,l,mid);
    build(2*no+1,mid+1,r);
    tree[no]=max(tree[2*no],tree[2*no+1]);
}
void update(int no,int l,int r,int wh,int z){
    if(l==r){
        assert(wh==l);
        tree[no]=z;
        h[wh]=z;
        return;
    }
    int mid=(l+r)>>1;
    if(wh<=mid) update(2*no,l,mid,wh,z);
    else update(2*no+1,mid+1,r,wh,z);
    tree[no]=max(tree[2*no],tree[2*no+1]);
}
int qry(int no,int l,int r,int st,int en){
    if(l>en||r<st) return 0;
    if(l>=st&&r<=en) return tree[no];
    int mid=(l+r)>>1;
    return max(qry(2*no,l,mid,st,en),qry(2*no+1,mid+1,r,st,en));
}
void solve()
{
    int n;
    cin>>n;
    rep1(i,n) cin>>arr[i];
    rep0(i,n-1){
        int x,y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    dfs(1,-1,1);
    rep1(i,mx){
        auto it=s[i].end();
        assert(s[i].si>0);
        --it;
        h[i]=it->f;
    }
    // rep1(i,mx) cout<<h[i]<<" ";
    // cout<<"\n";
    build(1,1,mx);
    int q;
    cin>>q;
    while(q--){
        int c;
        cin>>c;
        if(c==1){
            int x,y;
            cin>>x>>y;
            int z=wh[x];
            assert(s[z].si>0);
            auto it=s[z].end();
            --it;
            int cu=it->f;
            assert(cu==h[z]);
            int x1=s[z][arr[x]].si;
            if(x1>1) s[z][arr[x]].erase(x);
            else s[z].erase(arr[x]);
            s[z][y].in(x);
            update(1,1,mx,z,(s[z].rbegin())->f);
            arr[x]=y;
        }
        else{
            int x;
            cin>>x;
            int z=mod;
            int l=1;
            int r=mx;
            while(l<=r){
                int mid=(l+r)>>1;
                //deb(mid);
                if(qry(1,1,mx,1,mid)>x){z=min(z,mid); r=mid-1;}
                else l=mid+1;
            }
            if(z==mod){
                cout<<-1<<"\n";
            }
            else{
                auto it=s[z].ub(x);
                assert(it!=s[z].end());
                cout<<*(it->s.begin())<<"\n";
            }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
        //nextl;
    }
    return 0;
}
