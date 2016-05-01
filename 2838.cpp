#if 1
//树状数组，逆序数;
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=100005;
struct Node{
    int flag;
    long long weight;
};

Node tree[maxn];
int n;

int lowbit(int x)
{
    return x&(-x);
}

void mupdate(int pos,int x)
{
    while(pos<=n)
    {
        tree[pos].flag+=1;
        tree[pos].weight+=x;
        pos=pos+lowbit(pos);
    }
}

long long mqueryw(int x)
{
    long long sum=0;
    while(x>0)
    {
        sum+=tree[x].weight;
        x=x-lowbit(x);
    }
    return sum;
}

int mqueryf(int x)
{
    int sum=0;
    while(x>0)
    {
        sum+=tree[x].flag;
        x=x-lowbit(x);
    }
    return sum;
}

int main()
{
    freopen("input.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        memset(tree,0,sizeof(tree));
        long long t=0;
        for(int i=1;i<=n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            mupdate(tmp,tmp);
            long long cnt=i-mqueryf(tmp);
            //note:cnt must be long long type ,if not , t+=cnt*tmp+k2;将会溢出
            if(cnt!=0)
            {
                long long k2=mqueryw(n)-mqueryw(tmp);
                t+=cnt*tmp+k2;
            }

        }
        printf("%I64d\n",t);
    }
    return 0;
}

#endif // 1
