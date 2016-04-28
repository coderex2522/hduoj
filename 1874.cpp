#if 0
//AC
#include <iostream>
#include <cstdio>

using namespace std;
const int maxx=INT_MAX;
const int maxn=205;
int graph[maxn][maxn];
int dist[maxn][maxn];

void floyd(int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dist[i][j]=graph[i][j];

    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(dist[i][k]!=maxx
                   &&dist[k][j]!=maxx
                   &&dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
}

int main()
{
    //freopen("input.txt","r",stdin);
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    graph[i][j]=0;
                else
                    graph[i][j]=maxx;
            }


        for(int i=0;i<m;i++)
        {
            int a,b,val;
            scanf("%d%d%d",&a,&b,&val);
            int temp=graph[a][b];
            graph[a][b]=graph[b][a]=val>temp?temp:val;
        }

        floyd(n);
        int s,t;
        scanf("%d%d",&s,&t);
        if(dist[s][t]==maxx)
            printf("-1\n");
        else
            printf("%d\n",dist[s][t]);
    }
    return 0;
}
#endif // 1
