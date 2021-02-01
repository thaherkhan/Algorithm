#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[100005];

struct info
{
    ll prop,sum;
} tree[100005*3];

void buildTree(ll node,ll b,ll e)
{
    if(b==e)
    {
        tree[node].sum = arr[b];
        return;
    }
    ll left = node*2;
    ll right = node*2+1;
    ll mid = (b+e)/2;

    buildTree(left,b,mid);
    buildTree(right,mid+1,e);

    tree[node].sum = tree[left].sum + tree[right].sum;
}


void update(ll node,ll b,ll e,ll i,ll j,ll x)
{
    if(i>e || j<b)
        return;
    if(b>=i && e<=j)
    {
        tree[node].sum+=((e-b+1)*x);
        tree[node].prop+=x;
        return;
    }
    ll left = node*2;
    ll right = (node*2)+1;
    ll mid = (b+e)/2;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].sum = tree[left].sum+tree[right].sum +( (e-b+1)*tree[node].prop);
}

ll query(ll node,ll b,ll e,ll i,ll j,ll carry = 0)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return tree[node].sum+carry*(e-b+1);
    ll left = node <<1;
    ll right = (node << 1)+1;
    ll mid = (b+e) >> 1;
    ll p1 = query(left,b,mid,i,j,carry+tree[node].prop);
    ll p2 = query(right,mid+1,e,i,j,carry+tree[node].prop);

    return p1+p2;
}

int main()
{
    //freopen("output.txt","w",stdout);

    ll n,i,j,x,y,t,q;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&q);
        for(i=1; i<=n; i++)
            arr[i] = 0;
        for(i=1; i<=3*n+1; i++)
        {
            tree[i].prop = 0;
            tree[i].sum = 0;
        }

        buildTree(1,1,n);
        while(q--)
        {
            scanf("%lld",&j);
            if(j==0)
            {
                scanf("%lld%lld%lld",&j,&x,&y);
                update(1,1,n, j,x,y);
            }
            else
            {
                scanf("%lld%lld",&x,&y);
                ll c=query(1,1,n,x,y);
                printf("%lld\n",c);
            }
        }
    }
    return 0;
}
