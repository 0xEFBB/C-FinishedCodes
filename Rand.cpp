#include "cstdio"
#include "random"
using namespace::std;
int main(){
    printf("This is program 'Rand'.\n");
    freopen("in.txt", "w", stdout);
    srand((unsigned)time(NULL));
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=rand()%m+1;
    }
    printf("%d\n",n);
    for(int i=0;i<n-1;i++){
        printf("%d ",a[i]);
        if((i+1)%18==0){
            printf("\n");
        }
    }
    printf("%d\n",a[n-1]);
    return 0;
}