#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

vector<vector<int> > v;

int main() {
    ios_base::sync_with_stdio(0);
    
    int t,n,k,s,temp;
    cin>>t;
    
    while(t--) {
        v.clear();
        
        for(int i=0;i<10010;i++) {
            v.push_back(vector<int>());
        }    
        
        cin>>n>>k>>s;
        
        for(int i=1;i<=n;i++) {
            cin>>temp;
            v[temp].push_back(i);
        }    
        if(s>10001) s = 10001;
        
        for(int i=s;i>0;i--) {
            for(int j=0;j<v[i].size();j++) {
                cout<<v[i][j]<<" ";
            }    
        }    
        
        for(int i=s+1;i<10010;i++) {
            for(int j=0;j<v[i].size();j++) {
                cout<<v[i][j]<<" ";
            }
        }  
        cout<<"\n";  
    }    
    
    return 0;
} 
