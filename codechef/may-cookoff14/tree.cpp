#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int> > v(100011,vector<int>());
vector<pair<int,int> > val(

int main() {
    ios_base::sync_with_stdio(0);
    
    int n,m,x,y,a,b;
    
    cin>>n;
    
    for(int i=1;i<=n;i++) {
        cin>>val[i];
    }    
    
    for(int i=0;i<(n-1);i++) {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }    
    
        
    
    return 0;
}    
