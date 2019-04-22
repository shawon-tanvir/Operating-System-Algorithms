#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m;
    int mem[m];
    for(int i=0;i<m;i++){
        cin>>mem[i];
    }
    cin>>n;
    int req[n];
    int frag=0;
    for(int i=0;i<n;i++){
        cin>>req[i];
    }
    int table[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            table[i][j]=-2;
        }
    }
    int col=0;
    bool check,tempcheck;
    int temp,id;
    for(int i=0;i<n;i++){
        check=false;
        tempcheck=false;
        temp=10000000;
        for(int j=0;j<m;j++){
            if(req[i]<=mem[j] && mem[j]<temp){
                tempcheck=true;
                temp=mem[j];
                id=j;
            }
        }
        if(tempcheck==true){
            mem[id]-=req[i];
            check=true;
        }
        if(check==true){
        for(int row=0,j=0;j<m;j++){
            table[row++][col]=mem[j];
        }
        col++;
        }
        if(check==false){
            for(int i=0;i<m;i++){
                frag+=mem[i];
            }
            break;
        }
    }
    for(int i=0;i<n;i++){
        cout<<req[i]<<"\t";
    }
    cout<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<table[i][j]<<"\t";
        }
        cout<<endl;
    }
    if(frag>0){
        cout<<"External Fragmentation = "<<frag<<endl;
    }
    else
        cout<<"No External Fragmentation"<<endl;

}

/*
5
50
200
70
115
15
10
100
10
35
15
23
6
25
55
88
40

*/

