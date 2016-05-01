#if 1
//树状数组，求逆序数;
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=1005;
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

    while(scanf("%d",&n)!=EOF)
    {
        memset(tree,0,sizeof(int)*(n+1));
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            mupdate(tmp,1);
            cnt+=i-mquery(tmp);
        }
        printf("%d\n",cnt);
    }
    return 0;
}
#endif // 1
