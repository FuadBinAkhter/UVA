#include<bits/stdc++.h>
using namespace std;
bool Check(int N,int pos){return (bool)(N & (1<<pos));}
int Set(int N, int pos){return N=N | (1<<pos);}
int nk=0,k=0,cnt=1;
int N=1000000,prime[1000000];
int status[1000000/32];
void sieve()
{
     int i, j;
     int  sqrtN;
     sqrtN = int( sqrt( N+100 ) );
     for( i = 3; i <= sqrtN; i += 2 )
     {
		 if( Check(status[i<<5],i&31)==0)
		 {
	 		 for( j = i*i; j <= N; j += (i<<1) )
			 {
				status[j>>5]=Set(status[j>>5],j & 31);
	 		 }
		 }
	 }
	 prime[0]=2;
	 for(i=3;i<=N;i+=2)
		if(Check(status[i>>5],i&31)==0)
         {
             prime[cnt++]=i;
         }
}
int decomp(long long int n)
{
    int c=0,i,s=1;
    for(i=0;prime[i]<=sqrt(n);i++)
        {
            c=0;
            while(n%prime[i]==0)
            {
                c++;
                n=n/prime[i];
            }
            s*=(c+1);
        }
        if(n!=1)
            s*=2;
        return s;

}
int main()
{
    sieve();
    long long int n,n2,m,i,c=0,mx=0,tmp=0,tmp2=0;
    int n1;
    scanf("%d",&n1);
    for(int j=0;j<n1;j++)
    {
       scanf("%lld %lld",&n,&m);
       n2=n;
       for(n;n<=m;n++)
       {
           tmp=decomp(n);
          if(mx<tmp){
            mx=tmp;
            tmp2=n;
          }
       }
          printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",n2,m,tmp2,mx);
          mx=0;
    }
    return 0;
}
