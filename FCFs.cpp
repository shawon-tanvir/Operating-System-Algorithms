#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n],pro[n],brst[n],wt[n],turn[n];
    for(int i=0;i<n;i++){
        wt[i]=0;
    }
    for(int i=0;i<n;i++){
        cin>>pro[i];
        cin>>arr[i];
        cin>>brst[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swap(pro[j],pro[j+1]);
                swap(brst[j],brst[j+1]);

            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<pro[i]<<" "<<arr[i]<<" "<<brst[i]<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            wt[i]+=brst[j];
        }
        wt[i]=wt[i]-arr[i];
    }
     for(int i=0;i<n;i++){
        cout<<wt[i]<<endl;
    }
    for(int i=0;i<n;i++){
        turn[i]=brst[i]+wt[i];
    }
    for(int i=0;i<n;i++){
        cout<<turn[i]<<endl;
    }
    double avgwt=0,avgturn=0;
    for(int i=0;i<n;i++){
        avgwt+=wt[i];
        avgturn+=turn[i];
    }
    cout<<"Average Waiting time= "<<avgwt/n<<endl;
    cout<<"Average Turn around time= "<<avgturn/n<<endl;
}

