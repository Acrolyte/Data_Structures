#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &a){
	int i,j,n=a.size();
	for(i=0;i<n;i++)
		for(j=0;j<n-1;j++)
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);	
}

int main(){
	int n,i;
	cin>>n;

	vector<int> a;
	while(n--){
		cin>>i;
		a.push_back(i);
	}
	bubble_sort(a);
	for(auto it: a) cout<<it<<' ';

	return 0;
}