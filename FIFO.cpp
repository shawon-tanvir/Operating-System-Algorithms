#include <bits/stdc++.h>
using namespace std;
int main(){

    int i,j,n,a[50],frame[10],no,k;
    cin>>n;
    for(i=1;i<=n;i++)
       cin>>a[i];
    cin>>no;
    for(i=0;i<no;i++)
        frame[i]= -1;
    j=0;
    for(i=1;i<=n;i++){
        avail=0;
        for(k=0;k<no;k++)
           if(frame[k]==a[i])
            avail=1;
           if (avail==0){
                 frame[j]=a[i];
                 j=(j+1)%no;
                 count++;
                 for(k=0;k<no;k++)
                    cout<<frame[k]<<"\t";
    }
    cout<<endl;
    }
    cout<<"Page Fault Is : "<<count<<endl;
}
