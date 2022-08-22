#include "cstdio"
#include "iostream"
#include "string"
using namespace::std;
int ary[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
int main(){
    printf("This is program 'CitizenIDNumber'.\n");
    string id,map="10X98765432";
    label:
    int ans = 0;
    cout<<"The Citizen ID Number Without Checksum Code:\n";
    cin>>id;
    if(id.length()!=17){
        cout<<"Error Input!\n";
        goto label;
    }
    else{
        for(int i=0;i<17;i++){
            if('0'<=id[i]&&id[i]<='9'){
                ans+=(id[i]-'0')*ary[i];
            }
            else{
                cout<<"Error Input!\n";
                goto label;
            }
        }
        cout<<"The Citizen ID Number:\n"<<id<<map[ans%11]<<endl;
    }
    return 0;
}
