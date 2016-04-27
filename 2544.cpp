#if 0
//AC
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=105;
int graph[maxn][maxn],dist[maxn];
bool mark[maxn];

int dijkstra(int n)
{
    memset(mark,0,sizeof(mark));
    for(int i=1;i<=n;i++)
        dist[i]=INT_MAX;
    int j=1;
    mark[j]=true;
    for(int i=1;i<=n;i++)
    {
        if(graph[j][i]>0)
        {
            dist[i]=graph[j][i];
        }
    }
    for(int i=2;i<=n;i++)
    {
        int minx=INT_MAX,k;
        for(j=1;j<=n;j++)
        {
            if(!mark[j]&&minx>dist[j])
            {
                minx=dist[j];
                k=j;
            }
        }
        mark[k]=true;
        for(j=1;j<=n;j++)
        {
            if(!mark[j]&&graph[k][j]>0)
            {
                int temp=graph[k][j]+dist[k];
                if(dist[j]>temp)
                {
                    dist[j]=temp;
                }
            }
        }
    }
    return dist[n];
}

int main()
{
    freopen("input.txt","r",stdin);
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&n!=0)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                graph[i][j]=-1;
        for(int i=0;i<m;i++)
        {
            int a,b,val;
            scanf("%d%d%d",&a,&b,&val);
            if(graph[a][b]==-1||graph[a][b]>val)
            {
                graph[a][b]=graph[b][a]=val;
            }
        }
        printf("%d\n",dijkstra(n));
    }

    return 0;
}
#endif // 1
