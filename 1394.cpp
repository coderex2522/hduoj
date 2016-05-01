#if 0
//TL
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=5005;
int tree[maxn];
int num[maxn];
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
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
            num[i]+=1;
        }

        int minx=0x7ffffff;
        for(int i=0;i<n;i++)
        {
            memset(tree,0,sizeof(int)*(n+1));
            int cnt=0;
            for(int j=1,k=i;j<=n;j++,k=(k+1)%n)
            {
                mupdate(num[k],1);
                cnt+=j-mquery(num[k]);
            }
            if(cnt<minx)
                minx=cnt;
        }
        printf("%d\n",minx);
    }
    return 0;
}
#endif // 1
