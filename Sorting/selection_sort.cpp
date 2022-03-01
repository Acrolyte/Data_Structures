#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &a){
	int i,j,n=a.size(),mi;
	
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j])
				swap(a[i],a[j]);
		}
	}
}

int main(){
	int n,i;
	cin>>n;

	vector<int> a;
	while(n--){
		cin>>i;
		a.push_back(i);
	}
	selection_sort(a);
	for(auto it: a) cout<<it<<' ';

	return 0;
}