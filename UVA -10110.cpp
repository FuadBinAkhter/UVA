#include<bits/stdc++.h>
using namespace std;
bool Check(long int N,long int pos){return (bool)(N & (1<<pos));}
long int Set(long int N,long int pos){	return N=N | (1<<pos);}
long int cnt=1,nk=0,k=1;
long int N=1000000005,prime[100000000];
long int status[(4000000005/32)];

void decomp(long int n)
{
    long long int sqrtn=sqrt(n);
    long long int cnt2=1,s=1;
    long long int i;
    while(n%2==0)
    {
        n=n/2;
        cnt2++;
    }
    if(cnt2>0)
    {
        s*=cnt2;
        cnt2=1;
    }
    for(i=3;i<=sqrtn;i+=2)
    {
        cnt2=1;
             while(n%i==0)
            {
                cnt2++;
                n=n/i;
            }
            s*=cnt2;
            sqrtn=sqrt(n);
    }
    if(n>1)
    {
        s*=2;
    }
    if(s%2==0){
        cout<<"no";
    }
    else
        cout<<"yes";
    }
int main()
{
    long long int num;
    while(scanf("%lld",&num) && num!=0){
    decomp(num);
    printf("\n");
    }
    return 0;
}
