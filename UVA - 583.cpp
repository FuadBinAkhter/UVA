#include<bits/stdc++.h>
using namespace std;
bool Check(long int N,long int pos){return (bool)(N & (1<<pos));}
long int Set(long int N,long int pos){	return N=N | (1<<pos);}
long int cnt=0,nk=0,k=1;
long int N=1000000005,prime[100000000];
long int status[(4000000005/32)];

void decomp(long int n)
{
    long int sqrtn=sqrt(n);
    long int i,c=2,c1=0;
    while(n%2==0)
    {
        n=n/2;
        prime[c1++]=2;
    }
    for(i=3;i<=sqrtn;i+=2)
    {
        long int cnt2=0;
             while(n%i==0)
            {
                prime[c1++]=i;
                n=n/i;
            }
            sqrtn=sqrt(n);
    }
    if(n!=1)
    {
           prime[c1++]=n;
    }
    printf(" %ld",prime[0]);
    for(i=1;i<c1;i++)
        printf(" x %ld",prime[i]);
    c1=0;
}
int main()
{

    long int num;
    while(scanf("%ld",&num) && num!=0){
    printf("%ld =",num);
    if(num<0){
        printf(" -1 x");
        num=num*(-1);
    }
   decomp(num);
   printf("\n");
    }
    return 0;
}
