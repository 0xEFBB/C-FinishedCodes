#include "cstdio"
#include "iostream"
using namespace::std;
void Merge(int a[],int start,int middle,int end,int tmp[]){
    int t=0,hf1=start,hf2=middle+1;
    while (hf1<=middle&&hf2<=end) {
        if (a[hf1]<a[hf2]) {
            tmp[t++]=a[hf1++];
        }
        else{
            tmp[t++]=a[hf2++];
        }
        
        }
    while (hf1<=middle) {
        tmp[t++]=a[hf1++];
    }
    while (hf2<=end) {
        tmp[t++]=a[hf2++];
    }
    for (int i=0; i<=end-start; i++) {
        a[start+i]=tmp[i];
    }

}
void Split(int a[],int start,int end,int tmp[]){
    if (start<end) {
        int middle=start+(end-start)/2;
        Split(a, start, middle, tmp);
        Split(a, middle+1, end, tmp);
        Merge(a, start, middle, end, tmp);
    }
}
int main(){
    printf("This is program 'Merge sorting'.\n");
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n;
    cin>>n;
    int a[n];
    int tmp[n];
    memset(tmp, 0, sizeof(tmp));
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    Split(a, 0, n-1, tmp);
    for (int i=0; i<n; i++) {
        cout<<a[i]<<" ";
        if((i+1)%18==0){
            cout<<endl;
        }
    }		
    return 0;
}
