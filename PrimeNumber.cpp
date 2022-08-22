#include "cstdio"
#include "iostream"
#include "cmath"
using namespace::std;
int main(){
    printf("This is program 'PrimeNumber'.\n");
    int m,n;
    cin>>n>>m;
    double pct = 0,sum = m-n+1;
    bool a[m+2];
    memset(a, 0, sizeof(a));
    int x=0;
    int p=2;
    do{
        for(int i=n;i<=m;i++){
            if(i%p==0&&i!=p){
                a[i]=1;
            }
        }
        while (a[p+1]!=0) {
            p++;
        }
        p++;
    }while(p<sqrt(m));
    for(int i=n;i<=m;i++){
        if(a[i]==0&&i!=1&&i>=n){
        x++;
        cout<<i<<" ";
        if((i+1)%18==0){
            cout<<endl;
        }
        }
    }
    pct=x/sum*100;
    printf("\n%d %g%%\n",x,pct);
    return 0;
}
