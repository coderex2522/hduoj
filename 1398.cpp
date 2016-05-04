#if 0
#include <iostream>
#include <cstdio>

using namespace std;
const int maxn=305;
int coins[18];
int coef[maxn];
int coef1[maxn];

void init()
{
    for(int i=1;i<18;i++)
        coins[i]=i*i;
}

int main()
{
    init();
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(int i=0;i<=n;i++)
        {
            coef[i]=1;
            coef1[i]=0;
        }

        for(int i=2;i<=17;i++)
        {
            for(int j=0;j<=n;j++)
                for(int k=0;k+j<=n;k+=coins[i])
                    coef1[k+j]+=coef[j];

            for(int j=0;j<=n;j++)
            {
                coef[j]=coef1[j];
                coef1[j]=0;
            }
        }
        printf("%d\n",coef[n]);
    }
    return 0;
}
#endif // 1
