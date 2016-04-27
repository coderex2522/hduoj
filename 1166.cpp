#if 0
//RUNING ERROR
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=50005;
struct Node{
    int left;
    int right;
    int cnt;
};
Node node[4*maxn];
int num[maxn];

void mupdate(int r,int pos,int val)
{
    if(r>=4*maxn)
        return ;
    if(node[r].left==pos&&node[r].right==node[r].left)
    {
        node[r].cnt=val;
        return ;
    }
    int mid=(node[r].left+node[r].right)/2;
    if(pos<=mid)
        mupdate(r<<1,pos,val);
    else
        mupdate(r<<1|1,pos,val);
    node[r].cnt=node[r<<1].cnt+node[r<<1|1].cnt;
    return ;
}

int mquery(int root,int i,int j)
{
     if(root>=4*maxn)
        return 0;
    if(node[root].left>=i&&node[root].right<=j)
        return node[root].cnt;
    int ret=0,mid;
    mid=(node[root].left+node[root].right)/2;
    if(i<=mid)
        ret+=mquery(root<<1,i,j);
    if(j>mid)
        ret+=mquery(root<<1|1,i,j);
    return ret;
}

void mbuild(int root,int l,int r)
{
     if(root>=4*maxn||l>=maxn)
        return ;
    node[root].left=l;
    node[root].right=r;
    if(l==r)
    {
        node[root].cnt=num[l];
        return ;
    }
    int mid=(l+r)/2;
    mbuild(root<<1,l,mid);
    mbuild(root<<1|1,mid+1,r);
    node[root].cnt=node[root<<1].cnt+node[root<<1|1].cnt;
}

int main()
{
    freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Case %d:\n",i);
        int n;
        scanf("%d",&n);
        for(int j=1;j<=n;j++)
            scanf("%d",&num[j]);
        mbuild(1,1,n);
        char cmd[10];
        while(scanf("%s",cmd)!=EOF&&strcmp(cmd,"END")!=0)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(cmd[0]=='A')
            {
                num[a]=num[a]+b;
                mupdate(1,a,num[a]);
            }
            if(cmd[0]=='S')
            {
                num[a]=num[a]-b;
                mupdate(1,a,num[a]);
            }
            if(cmd[0]=='Q')
            {
                if(a>b)
                {
                    int temp=a;
                    a=b;
                    b=temp;
                }
                printf("%d\n",mquery(1,a,b));
            }
        }
    }
    return 0;
}
#endif // 1
