#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int  count=1;
    cin>>n;
    queue<int>q;
    
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        q.push(x);
    }
    cout<<q.size();
    while(q.size()!=1)
    {
        // position;
        int count=1;
        for(auto i=q.front();i!=q.back();i++)
       {
          if(count%2!=0)
          {
          q.pop();
          }
           count++;
        
        
        }

    }
    while(!q.empty()){
        cout<<q.front();
        q.pop();
    }
    
    return 0;
}