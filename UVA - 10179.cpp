#include<bits/stdc++.h>
using namespace std;
bool Check(int N,int pos){return (bool)(N & (1<<pos));}
int Set(int N,int pos){	return N=N | (1<<pos);}
int cnt=1;
int N=1000000,prime[1000000];
int status[(1000000/32)+10000];
void sieve()
{
     int i, j;
     int  sqrtN;
     sqrtN = int( sqrt(N));
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
void phy(int n)
{
    int sqrtn=sqrt(n);
    int i;
    int res=n;
    for(i=0;i<cnt && prime[i]<=sqrtn;i++)
    {
    
     
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
              
                n=n/prime[i];
            }
            sqrtn=sqrt(n);
            res/=prime[i];
            res*=prime[i]-1;
        }
    }
    if(n!=1)
    {
        res/=n;
        res*=(n-1);
     
    }
    printf("%d\n",res);
}
int main()
{
    sieve();
    int num;
    while(scanf("%d",&num) && num!=0){
            phy(num);
    }
    return 0;
}