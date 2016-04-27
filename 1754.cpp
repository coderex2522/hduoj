#if 0
//AC
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn=200005;
struct Node{
    int left;
    int right;
    int score;
};
Node node[3*maxn];
int score[maxn];

void mbuild(int root,int l,int r)
{
    node[root].left=l;
    node[root].right=r;
    if(l==r)
    {
        node[root].score=score[l];
        return ;
    }
    int mid=(l+r)/2;
    mbuild(root<<1,l,mid);
    mbuild(root<<1|1,mid+1,r);
    node[root].score=max(node[root<<1].score,node[root<<1|1].score);
}

int mquery(int root,int l,int r)
{
    if(l<=node[root].left&&r>=node[root].right)
    {
        return node[root].score;
    }
    int mid=(node[root].left+node[root].right)/2;
    int maxx=-1;
    if(l<=mid)
        maxx=mquery(root<<1,l,r);
    if(r>mid)
        maxx=max(maxx,mquery(root<<1|1,l,r));
    return maxx;
}

void mupdate(int root,int pos,int val)
{
    if(node[root].left==pos&&node[root].left==node[root].right)
    {
        node[root].score=val;
        return ;
    }
    int mid=(node[root].left+node[root].right)/2;
    if(pos<=mid)
        mupdate(root<<1,pos,val);
    if(pos>mid)
        mupdate(root<<1|1,pos,val);
    node[root].score=max(node[root<<1].score,node[root<<1|1].score);
    return ;
}

int main()
{
    freopen("input.txt","r",stdin);
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%d",&score[i]);
        mbuild(1,1,n);
        char str[10];
        for(int i=0;i<m;i++)
        {
            scanf("%s",str);
            int a,b;
            scanf("%d%d",&a,&b);
            if(str[0]=='Q')
            {
                printf("%d\n",mquery(1,a,b));
            }
            if(str[0]=='U')
            {
               mupdate(1,a,b);
            }
        }
    }
    return 0;
}
#endif
