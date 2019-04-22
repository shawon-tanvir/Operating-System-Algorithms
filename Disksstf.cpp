#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ara[n],mark[n];
    for(int i=0;i<n;i++){
        cin>>ara[i];
        mark[i]=0;
    }
    int head,temp,sum=0;
    cin>>head;
    temp=head;
    int id;

    for(int j=0;j<n;j++){
        int min1=100000;
        for(int i=0;i<n;i++){
            if(abs(ara[i]-temp)<min1 && mark[i]==0){
                min1=abs(ara[i]-temp);
                id=i;

            }

        }
         cout<<temp<<" "<<min1<<" "<<sum<<endl;
        temp=ara[id];
        mark[id]=1;
        sum=sum+min1;

    }
    cout<<sum<<endl;

}

