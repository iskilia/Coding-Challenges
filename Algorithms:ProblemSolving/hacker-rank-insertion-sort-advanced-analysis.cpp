#include<iostream>
#include<cstdio>
using namespace std;
long long ans = 0;

void mergeInsert(int arr[],int l,int r,int mid)
{
    int ni=mid-l+1;
    int nj=r-mid;
    int L[ni],R[nj];
    for(int i=0;i<ni;i++){
        L[i]=arr[i+l];
    }
    for(int j=0;j<nj;j++){
        R[j]=arr[j+mid+1];
    }
    int i=0,j=0,k=l;
    while(i<ni && j<nj){
        if(L[i]<=R[j]){
            arr[k++]=L[i++];
        } else {
            arr[k++]=R[j++];
            ans += (ni-i);
        }
    }
    for(;i<ni;){
        arr[k++]=L[i++];
    }
    for(;j<nj;){
        arr[k++]=R[j++];
    }
}

void mergeSort(int a[],int i,int j)
{
    int mid=(i+j)/2;
    if(i < j){
        mergeSort(a,i,mid);
        mergeSort(a,mid+1,j);
        mergeInsert(a,i,j,mid);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        ans=0;
        scanf("%d",&n);
        int * a = new int[n];
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        mergeSort(a,0,n-1);
        cout<<ans<<endl;
    }
    return 0;
}