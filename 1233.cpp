#if 0
#include <iostream>
#include <cstdio>

using namespace std;
const int max_point=105;
const int max_edge=105*105;
int graph[max_point][max_point];
struct Edge{
    int point;
    int lowcost;
    bool flag;
};
Edge edge[max_edge];

int prim(int n)
{
    int j=1;
    for(int i=1;i<=n;i++)
    {
            edge[i].point=j;
            edge[i].lowcost=graph[j][i];
            edge[i].flag=false;
    }
    edge[j].lowcost=0;
    edge[j].flag=true;
    int msum=0;//表示最小生成树的权值和;
    for(int i=2;i<=n;i++)
    {
        int k;
        int minx=INT_MAX;
        bool flag=false;
        for(j=2;j<=n;j++)
        {
            if(!edge[j].flag&&edge[j].lowcost<minx)
            {
                k=j;
                minx=edge[j].lowcost;
                flag=true;
            }
        }
        if(!flag)
            return -1;//表示不存在解;
        edge[k].flag=true;
        msum+=edge[k].lowcost;
        for(j=1;j<=n;j++)
        {
            if(!edge[j].flag&&edge[j].lowcost>graph[k][j])
            {
                edge[j].point=k;
                edge[j].lowcost=graph[k][j];
            }
        }
    }
    return msum;

}

int main()
{
    freopen("input.txt","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                graph[i][j]=INT_MAX;
        int m=n*(n-1)/2;
        for(int i=0;i<m;i++)
        {
            int a,b,val;
            scanf("%d%d%d",&a,&b,&val);
            graph[a][b]=graph[b][a]=val;
        }
        printf("%d\n",prim(n));
    }
    return 0;
}

#endif // 1
