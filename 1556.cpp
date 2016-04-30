#if 0
//AC
//树状数组、区间更新;
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=100005;
int tree[maxn];
int n;
int lowbit(int x)
{
    return x&(-x);
}

void mupdate(int pos,int x)
{
    while(pos<=n)
    {
        tree[pos]=tree[pos]+x;
        pos=pos+lowbit(pos);
    }
}

int mquery(int x)
{
    int sum=0;
    while(x>0)
    {
        sum+=tree[x];
        x=x-lowbit(x);
    }
    return sum;
}

int main()
{
    freopen("input.txt","r",stdin);
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        memset(tree,0,sizeof(int)*(n+1));
        for(int i=0;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            mupdate(a,1);
            mupdate(b+1,-1);
        }

        for(int i=1;i<=n;i++)
        {
            if(i!=1)
                printf(" ");
            printf("%d",mquery(i));

        }
        printf("\n");
    }
    return 0;
}
#endif // 1
