#include<bits/stdc++.h>
using namespace std;

int main(){
    int total;
    cin>>total;
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
    int count1=0;
    for(int i=head;i<total;i++){
        for(int j=0;j<n;j++){
            if(ara[j]==i && mark[j]==0){
                int def=ara[j]-temp;
                sum+=def;
                temp=ara[j];
                mark[j]=1;
                count1++;
                cout<<ara[j]<<" "<<def<<endl;
                break;
            }
            if(i==total-1){
                sum+=i-temp;
                i=0;
                temp=0;
                sum+=total;
            }

        }
        if(count1==n){
                break;
            }

    }
    cout<<sum<<endl;

}


