#if 1
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const long int maxn=200010;
//becanse biiboard max is n,so don't be 1000000005;
int h,w,n;

struct Node{
    int left,right;
    int maxw;
};
Node node[3*maxn];

int mupdate(int root,int x)
{
    if(node[root].left==node[root].right)
    {
        if(node[root].maxw>=x)
        {
            node[root].maxw-=x;
            return node[root].left;
        }
        else
            return -1;

    }
    int res;
    if(node[root<<1].maxw>=x)
        res=mupdate(root<<1,x);
    else
        res=mupdate(root<<1|1,x);
    node[root].maxw=max(node[root<<1].maxw,node[root<<1|1].maxw);
    return res;
}

void build(int root,int l,int r)
{
    node[root].left=l;
    node[root].right=r;
    if(l==r)
    {
        node[root].maxw=w;
        return ;
    }
    int mid=(l+r)/2;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
    node[root].maxw=w;
}

int main()
{
    freopen("input.txt","r",stdin);

    while(scanf("%d%d%d",&h,&w,&n)!=EOF)
    {
        build(1,1,min(h,n));
        for(int i=0;i<n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            printf("%d\n",mupdate(1,tmp));
        }
    }
    return 0;
}
#endif // 1
