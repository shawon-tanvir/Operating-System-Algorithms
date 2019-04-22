#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ara[n];
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    int head,temp,sum=0;
    cin>>head;
    temp=head;
    for(int i=0;i<n;i++){
        sum=sum+ abs(ara[i]-temp);
        temp=ara[i];
    }
    cout<<sum<<endl;

}
