#include "cstdio"
#include "iostream"
using namespace::std;
void QS(int a[],int start,int end){
    if (start>=end) {
        return;
    }
    int k=a[start];
    int i=start,j=end;
    for (;i!=j;) {
        for (;j>i&&a[j]>=k;j--) {
            continue;
        }
        swap(a[i], a[j]);
        for (;i<j&&a[i]<=k;i++) {
            continue;
        }
        swap(a[i], a[j]);
    }
    QS(a, start, i-1);
    QS(a, i+1, end);
}
int main(){
    printf("This is program 'QuickSort'.\n");
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    QS(a, 0, n-1);
    for (int i=0; i<n; i++) {
        cout<<a[i]<<' ';
        if((i+1)%18==0){
            cout<<endl;
        }
    }
    cout<<endl;
    return 0;
}
