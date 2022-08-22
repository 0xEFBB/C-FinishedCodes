#include<bits/stdc++.h> 
using namespace std;
const int inf=0x3f3f3f3f;
int cnt,x_Jenny,y_Jenny,mx,pp=0;
struct Board{
     int left,right,high;
};
bool cmp(Board x,Board y){
     return x.high>y.high;
}
int FallOn(int x,int up,Board Brd[]){
     for (int i=0; i<cnt; i++) {
          if (x>=Brd[i].left&&x<=Brd[i].right&&x>Brd[i].high) {
               if (up-Brd[i].high>mx) {
                    return inf;
               }
               pp=up-Brd[i].high;
               return i;
          }
     }
     return -inf;
}
int S_Board(int x,int left,int right,int high,Board Brd[]){
     if (FallOn(left-1, high, Brd)==-inf&&FallOn(right+1, high, Brd)==-inf) {
          if (high>mx) {
               return inf;
          }
          return min(x-(left-1)), right+1-x)+high;
     }
     int m=FallOn(left-1, high, Brd);
     int n=FallOn(right+1, high, Brd);
     if (m==inf) {
          return right+1-x+high-Brd[n].high+S_Board(right+1, Brd[n].left, Brd[n].right, Brd[n].high, Brd);
     }
     else if (n==inf){
          return x-(left-1)+high-Brd[m].high+S_Board(left-1, Brd[m].left, Brd[m].right, Brd[m].high, Brd);
     }
     else {
          return min(x-(left-1)+high-Brd[m].high+S_Board(left-1, Brd[m].high, Brd[m].left, Brd[m].right, Brd), right+1-x+high-Brd[n].high+S_Board(right+1, Brd[n].high, Brd[n].left, Brd[n].right, Brd));
     }
}
int main() {
     int n,bn;
     cin>>n;
     int ans[n+1];
     memset(ans, 0, sizeof(ans));
     for (int i=0; i<n; i++) {
          cin>>cnt>>x_Jenny>>y_Jenny>>mx;
          Board Brd[cnt];
          for (int j=0; j<cnt; j++) {
               cin>>Brd[j].left>>Brd[j].right>>Brd[j].high;
          }
          sort(Brd, Brd+cnt, cmp);
          bn=FallOn(x_Jenny, y_Jenny, Brd);
          ans[i]+=pp;
          ans[i]+=S_Board(x_Jenny, Brd[bn].left, Brd[bn].right, Brd[bn].high, Brd);
     }
     for (int i=0; i<n-1; i++) {
          cout<<ans[i]<<' ';
     }
     cout<<ans[n-1];
     return 0;
     /**/
}
