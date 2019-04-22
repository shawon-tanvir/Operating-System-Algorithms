#include<bits/stdc++.h>

using namespace std;

struct Process{
	int at;
	int wt;
	int tt;
	int ct;
	int previousCompleteTime;
	int serialNo;
};

bool cmp(Process a, Process b)
{
	return a.at < b.at;
}
int main()
{
	int n = 4, x, spendTime = 0, qTime = 2;
	
	Process *arr = new Process[sizeof(Process) * n];
	
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		arr[i].ct = x;
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		arr[i].at = x;
	}
	
	sort(arr, arr + n, cmp);
	
	arr[0].serialNo = 0;
	arr[0].previousCompleteTime = 0;
	arr[0].wt = 0;
	arr[0].tt = arr[0].ct;
	
	for(int i = 1; i < n; i++){
		arr[i].serialNo = i;
		arr[i].previousCompleteTime = arr[i].at;
		arr[i].wt = 0;
		arr[i].tt = arr[i].ct;
	}
	
	queue<int> q;
	q.push(arr[0].serialNo);
	
	int i = 1;
	while(!q.empty()){
		int sn = q.front();
		q.pop();
		
		arr[sn].wt += spendTime - arr[sn].previousCompleteTime;
				
		if(arr[sn].ct >= qTime){
			spendTime += qTime;
			arr[sn].ct -= qTime;
		}
		else{
			spendTime += arr[sn].ct;
			arr[sn].ct = 0;
		}
		
		for(; i < n;){
		//	if()
			if(arr[i].at <= spendTime){
				q.push(i);
				i++;
			}
			else break;
		}
		
		if(arr[sn].ct > 0) q.push(sn);
		
		arr[sn].previousCompleteTime = spendTime;
	}
	
	for(int i = 0; i < n; i++){
		arr[i].tt += arr[i].wt + arr[i].ct;
	}
	
	double sum = 0;
	for(int i = 0; i < n; i++){
		cout << arr[i].wt << endl;
		sum += arr[i].wt;	
	}

	cout << " = " << sum / n << endl;;
	
	sum = 0;
	for(int i = 0; i < n; i++){
		cout << arr[i].tt << endl;
		sum += arr[i].tt;	
	}
	
	cout << " = " << sum / n << endl;
	
	return 0;
}

/*
5 7 9 9
4 0 6 10
*/
