#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,int> > v, no;

int main() {
    ios_base::sync_with_stdio(0);
    
    int t,n,k,s,temp;
    cin>>t;
    
    while(t--) {
        v.clear();
        no.clear();
        
        cin>>n>>k>>s;
        
        long long totalSum = 0;
        for(int i=1;i<=n;i++) {
            cin>>temp;
            if(temp<=s) v.push_back(make_pair(temp,i));
            else no.push_back(make_pair(temp,i));
        }    
        
        sort(v.begin(), v.end());
        
        for(int i=0;i<v.size();i++) cout<<v[i].second<<" ";
        cout<<endl;
        
        for(int i=0;i<no.size();i++) cout<<no[i].second<<" ";
        cout<<endl;   
    }    
    
    return 0;
}    

   
