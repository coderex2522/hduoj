#if 0
//AC
//树状数组求解
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=50005;
int c[maxn];

int lowbit(int x)
{
    return x&(-x);
}

void madd(int n,int pos,int x)
{
    int tpos=pos;
    while(tpos<=n)
    {
        c[tpos]=c[tpos]+x;
        tpos=tpos+lowbit(tpos);
    }
}

void msub(int n,int pos,int x)
{
    int tpos=pos;
    while(tpos<=n)
    {
        c[tpos]=c[tpos]-x;
        tpos=tpos+lowbit(tpos);
    }
}

int mquery(int x,int y)
{
    int tx,ty,sumx,sumy;
    sumx=sumy=0;
    tx=x;
    ty=y;

    while(tx>0)
    {
        sumx+=c[tx];
        tx=tx-lowbit(tx);
    }
    while(ty>0)
    {
        sumy+=c[ty];
        ty=ty-lowbit(ty);
    }
    return sumy-sumx;
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
        memset(c,0,sizeof(int)*(n+1));
        for(int j=1;j<=n;j++)
        {
            int temp;
            scanf("%d",&temp);
            madd(n,j,temp);
        }
        char cmd[10];
        while(scanf("%s",cmd)!=EOF&&strcmp(cmd,"End")!=0)
        {
           int a,b;
           scanf("%d%d",&a,&b);
           if(strcmp(cmd,"Add")==0)
                madd(n,a,b);
           if(strcmp(cmd,"Sub")==0)
                msub(n,a,b);
           if(strcmp(cmd,"Query")==0)
                printf("%d\n",mquery(a-1,b));
        }
    }

    return 0;
}
#endif // 1
