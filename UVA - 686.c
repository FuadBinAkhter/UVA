#include<stdio.h>
int n=1000001;
int p[1000001];
void sieve()
{
    int i,j;
    for(i=2;i<=n;i++)
        p[i]=i;
    i=2;
    while((i*i)<=n)
    {
        if(p[i]!=0)
        {
            for(j=2;j<=n;j++)
            {
                if((p[i]*j)>n)
                    break;
                else
                    p[p[i]*j]=0;
            }
        }
        i++;
    }
}
int main()
{
    sieve();
    int i,m,j=0,d=0,t=0;
    while(scanf("%d",&m)!=EOF && m!=0)
    {
        int c=0;
        for(i=2;i<=(m/2);i++)
        {
            d=m-i;
            if(p[i]!=0 && p[d]!=0)
            {
                c++;
            }

        }
        printf("%d\n",c);
        }
return 0;
}
