#include <bits/stdc++.h>
using namespace std;
int main(){

    int i,j,n,a[50],frame[10],no,k;
    cin>>n;
    for(i=0;i<n;i++)
       cin>>a[i];
    cin>>no;
    for(i=0;i<no;i++)
        frame[i]=-1;
    int count1=0,track=0,available,p=0;
    for(int i=0;i<n;i++){

        available=0;
        for(int j=0;j<no;j++){
            if(frame[j]==a[i]){
                available=1;
            }
        }
        if(available==0){
            int temp=100,keep=100;
            if(p<=no-1){
                frame[p++]=a[i];
                count1++;
            }
            else{
                int j;
                keep=-4;
                for(int k=0;k<no;k++){
                    for(j=i+1;j<n;j++){
                        if(a[j]==frame[k]){
                            temp=j;
                            break;
                        }
                    }
                    if(j==n){
                        temp=n;
                    }
                    if(temp>keep){
                        keep=temp;
                        track=k;
                    }
                }
            frame[track]=a[i];
            count1++;
            }
            cout<<a[i]<<" -> ";
            for(int j=0;j<no;j++){
            cout<<frame[j]<<" ";
            }
            cout<<endl;
        }

    }
    cout<<"Page Fault = "<<count1<<endl;

}
/*
22
7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1
3
*/
