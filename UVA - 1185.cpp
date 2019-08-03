#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
int main()
{
   int t,n,j;
   scanf("%d",&t);
   for(int i=1;i<=t;i++)
   {
       double s=0;
       scanf("%d",&n);
       for(j=1;j<=n;j++)
            s+=log10(j);
       printf("%d\n",(int)(floor(s))+1);
   }
   return 0;
}
