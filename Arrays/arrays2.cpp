#include <bits/stdc++.h>
using namespace std;

//gives the index of the first repeating element
void firstappearence(int a[], int n){
	int ans=0,i=0,mi = INT_MAX;
	const int N = 1e5 + 2;
	int b[N];

	memset(b, -1 , sizeof(b));
	for(i=0;i<n;i++){
		if(b[a[i]] != -1)
			mi = min(mi, b[a[i]]);
		else
			b[a[i]] = i;
	}
	if(mi == INT_MAX) ans = -1;
	else ans = mi +1;
	cout<<ans;
}

//gives the sum of cont. subarray equal to S
void sumOfSubarrays(int a[], int n, int S){
	
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

	// firstappearence(a,t);

	sumOfSubarrays(a,t,x);

	return 0;
}
