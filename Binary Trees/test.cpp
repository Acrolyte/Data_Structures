#include <bits/stdc++.h>
using namespace std;
string simplifyPath(string path) {
    int l = path.length();
    for(int i = 0;i<l-1;i++){
        if(path[i] == '/'){
            if(path[i+1]=='/'){
                path = path.substr(0,i) + path.substr(i+1);
            }
            else if(path[i+1] == '.'){
                if(path[i+2] == '/'){
                    path = path.substr(0,i) + path.substr(i+2);
                    continue;
                }
                else if(path[i+3] == '/'){
                    path = path.substr(0,i) + path.substr(i+3);
                    continue;
                }
            }
        }
    }
    if(path[path.length()-1] == '/') path = path.substr(0,path.length()-1);
    return path;
}

int main(){
    string s;
    cin>>s;
    cout<<simplifyPath(s);
    return 0;
}