#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (i = 0; i < n; ++i)
#define rept(i,n) for (i = n; i > 0; --i)
#define ll long long

//to print rectangle pattern
void rectanglepattern(int r, int c, char ch){
	int i,j;
	rep(i,r){
		rep(j,c){
			cout<<ch<<' ';
		}
		cout<<'\n';
	}
}

//to print hollow rectangle pattern
void hollowrectangle(int r, int c, char ch){
	int i,j;
	rep(i,c) cout<<ch<<' ';
	cout<<'\n';
	rep(i,r-2){
		cout<<ch<<' ';
		rep(j,c-2){
			cout<<"  ";
		}
		cout<<ch<<" \n";
	}	
	rep(i,c) cout<<ch<<' ';
}

//to print inverted half pyramid
void invertedHalfPyramid(int n,char ch){
	int i,j;
	rept(i,n){
		rep(j,i){
			cout<<ch<<' ';
		}
		cout<<'\n';
	}
}

//to print half pyramid
void halfPyramid(int n, char ch){
	int i,j;
	for(int i=1;i<=n;i++){
		rept(j,n-i){
			cout<<"  ";
		}
		rep(j,i){
			cout<<ch<<' ';
		}
		cout<<'\n';
	}
}

//half pyramid using numbers
void halfNumberPyramid(int n){
	int i,j;
	for(int i=1;i<=n;i++){
		rep(j,i){
			cout<<i<<' ';
		}
		cout<<'\n';
	}
}

//Floyd's Triangle
// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15
void FloydsTriangle(int n){
	int i,j,c=1;
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			cout<<c<<' ';
			c++;
		}
		cout<<'\n';
	}
}

//to print butterfly pattern
void butterflyPattern(int n,char ch){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			cout<<ch<<' ';
		}
		for(j=(n-i)*2;j>0;j--){
			cout<<"  ";
		}		
		for(j=1;j<=i;j++){
			cout<<ch<<' ';
		}
		cout<<endl;
	}
	for(i=n;i>0;i--){		
		for(j=1;j<=i;j++){
			cout<<ch<<' ';
		}
		for(j=(n-i)*2;j>0;j--){
			cout<<"  ";
		}		
		for(j=1;j<=i;j++){
			cout<<ch<<' ';
		}
		cout<<endl;
	}

}

int main(){
	int n;
	char ch;
	cin>>n>>ch;
	butterflyPattern(n,ch);
	return 0;
}