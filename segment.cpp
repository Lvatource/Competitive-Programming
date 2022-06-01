#include <bits/stdc++.h>
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e9, MOD = 1e9+7;


struct Seg{
    int val = -INF;
    int l,r,mid; // responisble for [l,r)
    Seg *lp, *rp;
    Seg(int l, int r): l(l), r(r), mid((l+r)/2){
        if (l+1<r){
            lp = new Seg(l, mid);
            rp = new Seg(mid, r);
        }
    }
    void pull(){
        val = max(lp->val, rp->val);
    }
    void update(int i, int x){
        if (l+1==r){
            val = x;
            return ;
        }
        if (i<mid) lp->update(i, x);
        else rp->update(i, x);
        pull();
    }
    int query(int a, int b){ // max of [a,b)
        if (a>=r || b<=l) return -INF; // [a,b) and [l,r) are disjoint
        if (a<=l && r<=b) return val; // [l,r) is inside [a,b)
        return max(lp->query(a,b),rp->query(a,b));
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    int n, q; cin>>n>>q;
    Seg seg(0, n); 
    string op;
    int a,b;
    loop(i,0,q){
        cin>>op>>a>>b;
        if (op == "set"){
            seg.update(a,b);
        }
        else if (op == "get"){
            cout << seg.query(a,b) << endl;
        }
    }
    return 0;
}
/*
color a
cls
g++ segment.cpp -o a & a
5 9
set 0 9
set 1 3
set 2 6
set 3 -10
set 4 -30
get 0 3
get 2 5
set 2 -50
get 2 5
*/