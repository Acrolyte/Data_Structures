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

int main(){
	int n;
	char ch;
	cin>>n>>ch;
	invertedHalfPyramid(n,ch);
	return 0;
}