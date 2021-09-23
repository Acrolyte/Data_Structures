#include <bits/stdc++.h>
using namespace std;

int linear_search(int a[], int x){
	int ans=-1;
	for(int i=0;i<10;i++)
		if(a[i]==x){
			ans = i;
			break;
		}
	return ans;
}
int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	cout<<linear_search(a,11);
	return 0;
}