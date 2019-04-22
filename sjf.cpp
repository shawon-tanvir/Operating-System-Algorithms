#include<bits/stdc++.h>

using namespace std;

struct Process{
	int wt;
	int at;
	int ct;
	int no;
	int tt;
}arr[10];

bool cmp(Process a, Process b)
{
	return a.at < b.at;
}
bool cmp2(Process a, Process b)
{
	if(a.ct == b.ct){
		return a.at < b.at;
	}
	else{
		return a.ct < b.ct;
	}
}
int main()
{
	int n = 3, currentTime = 0;
	vector<int> vec;
	
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		arr[i].ct = x;
		arr[i].no = i + 1;
	}
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		arr[i].at = x;
	}
	
	sort(arr, arr + n, cmp);
	
	currentTime += arr[0].ct;
	
	arr[0].wt = 0;
	arr[0].tt = arr[0].ct;
	
	sort(arr + 1, arr + n, cmp2);
	
	for(int i = 1; i < n;){
		if(arr[i].at <= currentTime){
			arr[i].wt = currentTime - arr[i].at;
			arr[i].tt = arr[i].wt + arr[i].ct;
			currentTime += arr[i].ct;
			i++;
		}
		else{
			currentTime++;
		}
	}
	
	for(int i = 0; i < n; i++){
		cout << "P" << arr[i].no << ", wating time = " << arr[i].wt << " , turnaroundtime = " << arr[i].tt << endl;
	}
	
	return 0;
}
