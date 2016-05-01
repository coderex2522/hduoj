#if 1
//AC
//tree array
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
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        memset(tree,0,sizeof(int)*(n+1));
        int sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
            num[i]+=1;//because default tree array from 1 to n;
            mupdate(num[i],1);
            sum+=i+1-mquery(num[i]);
        }
        int minx=sum;
        for(int i=0;i<n;i++)
        {
            sum+=n+1-2*num[i];
            if(sum<minx)
                minx=sum;
        }
        printf("%d\n",minx);
    }
    return 0;
}
#endif // 1
