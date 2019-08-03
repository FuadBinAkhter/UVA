#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
int main()
{
    ll n,m;
    ll a[7]={2,3,5,7,13,17,31};
    scanf("%llu",&n);
    for(int i=0;i<n;i++)
    {
        int c=0;
        scanf("%llu,",&m);
        for(int j=0;j<7;j++)
        {
            if(m==a[j] && c!=1)
            {
                printf("Yes\n");
                c=1;
            }
        }
        if(c==0)
            printf("No\n");


    }
    return 0;
}
