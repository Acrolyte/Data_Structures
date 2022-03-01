#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &a){
	int i,j,n=a.size();
	for(i=1;i<n;i++){
		for(j=i;j>0;j--){
			if(a[j]<a[j-1])
				swap(a[j],a[j-1]);
			else break;
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
	insertion_sort(a);
	for(auto it: a) cout<<it<<' ';

	return 0;
}