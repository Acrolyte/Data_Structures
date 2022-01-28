#include <bits/stdc++.h>
using namespace std;

#define ll long long int

//linear search
int linear_search(int a[],int t,int x){
	int i=0;
	for(i=0;i<t;i++){
		if(x==a[i])
			return i;
	}
	return -1;
}

//binary search
int binary_search(int a[],int t, int x){
	int low = 0 , high = t;

	while(low<=high){
		int mid = (low+high)/2;

		cout<<low<<' '<<mid<<' '<<high<<endl;
		if(a[mid] == x) return mid;

		else if(x<a[mid]) high = mid-1;
		
		else  low = mid+1;
	}

	return -1;
}

int main(){
	int n,i=0,x,t;
	cin>>n;
	int a[n]={};
	t=n;
	while(n--){
		cin>>a[i];
		i++;
	}
	cin>>x;
	
	//linear search
	// cout<<linear_search(a,t,x);

	//binary search
	// sort(a,a+t);
	// cout<<binary_search(a,t,x);

	return 0;
}