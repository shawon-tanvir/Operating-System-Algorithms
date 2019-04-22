
#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,p;
    cout<<"Enter the number of the resources :"<<endl;
    cin>>r;
    int instance[r];
    cout<<"Enter the max instances of each resources:"<<endl;
    for(int i=0;i<r;i++){
        cout<<"For the resource "<<(i+1)<<" :"<<endl;
        cin>>instance[i];
    }
    cout<<"Enter the number of process:"<<endl;
    cin>>p;
    int allocated [p][r];
    for(int i=0;i<p;i++){
        cout<<"Allocation for process "<<i+1<<" :"<<endl;
        for(int j=0;j<r;j++){
            cin>>allocated[i][j];
        }
    }
    int maxneed[p][r];
    for(int i=0;i<p;i++){
        cout<<"Enter the max need of resources of the process  "<<i+1<<" :"<<endl;
        for(int j=0;j<r;j++){
            cin>>maxneed[i][j];
        }
    }
    int sumAllocate[r];
    for(int j=0;j<r;j++){
            sumAllocate[j]=0;
        for(int i=0;i<p;i++){
            sumAllocate[j]+=allocated[i][j];
        }
    }
    int available[r];
    for(int i=0;i<r;i++){
        available[i]=instance[i] - sumAllocate[i];
    }
    int remainingNeed[p][r];
    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++){
            remainingNeed[i][j] = maxneed[i][j] - allocated[i][j];
        }
    }
    int count,result = 0;


    do{
        for(int i=0;i<p;i++){
                count = 0;
            for(int j=0;j<r;j++){
                if(available[j]>=remainingNeed[i][j] && remainingNeed[i][j] != -1){
                    count++;
                }
            }
            if(count == r){
                    result++;
                    cout<<"Process "<<i<<"-->";
                    for(int j=0;j<r;j++){
                        available[j]+=allocated[i][j];
                        remainingNeed[i][j] = -1;
                    }
            }

        }
    } while(result < p);


    return 0;

}
