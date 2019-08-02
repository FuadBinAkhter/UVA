#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
int arr[100000];
int n;
int bin_search(int key)
{
    int res=-1,mid=0;
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        mid=(low+high)>>1;
        int val=arr[mid];
        if(val==key){
            res=mid;
            high=mid-1;
        }
        else if(val<key)
            low=mid+1;
        else
            high=mid-1;
    }
    if(res!=-1)
        return low;
    else
        return res;
}
int main()
{
    fastio;
    int k=1,i,j,ans=0,q,n2,flag=0;
    while(cin>>n>>q){
    int a[q+5];
    int b[q+5];
    flag=1;
    if(n==0&&q==0)
        return 0;
    for(i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    for(j=1;j<=q;j++)
    {
        cin>>n2;
        a[j]=n2;
        ans=bin_search(n2);
        b[j]=ans;
    }
    for(j=1;j<=q;j++){
        if(flag>0)
            printf("CASE# %d:\n",k++);
        if(b[j]!=-1)
            printf("%d found at %d\n",a[j],b[j]+1);
        else
            printf("%d not found\n",a[j]);
        flag--;
    }
    }
    return 0;
}
