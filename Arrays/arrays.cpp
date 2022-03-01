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

//max till i
void maxtillI(int a[],int n){
	int b[n]={};
	int m = INT_MIN;
	b[0] = a[0];
	for(int i=0;i<n;i++){
		b[i] = max(m,a[i]);
		m = max(m,b[i]);
	}
	for(auto i : b) cout<<i<<' ';
}

//sum of all subarrays
void sumSubArrays(int a[],int n){
	int i,j,sum;
	for(i=0;i<n;i++){
		sum =0;
		for(j=i;j<n;j++){
			sum += a[j];
			cout<<sum<<' ';
		}
	}
}

//longest arithmetic subarray
int longestArithmeticSubarray(int a[], int n){
	int i,j=2,sum=0,ans=2;
	int pd = a[1] - a[0];
	int curr = 2;

	while(j<n){
		if(pd == a[j]-a[j-1]) curr++;
		else {
			pd = a[j] - a[j-1];
			curr = 2;
		}
		ans = max(curr, ans);
		j++;
	}

	return ans;
}

int recordBreaking(int a[], int n ){
	int ans=0, m = 0,i=0;
	int b[n] = {};
	for(i=0;i<n-1;i++){
		if(a[i] > m && a[i]>a[i+1]) {
			m = a[i];
			b[i] = 1;
			ans ++;
		}
	}
	if(a[i] > m ) b[i] = 1;
	for(i=0;i<n;i++)
		cout<<b[i]<<" ";
	cout<<endl;
	return ans;
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

	// maxtillI(a,t);

	// sumSubArrays(a,t);

	// cout<<longestArithmeticSubarray(a,t);

	cout<<recordBreaking(a,t);
	return 0;
}