#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    vector<int> a,b;
    int n,t,temp;
    cin>>t;
    
    while(t--) {
        a.clear();
        b.clear();
        
        cin>>n;
        
        for(int i=0;i<n;i++) {
            cin>>temp;
            a.push_back(temp);
        }
        for(int i=0;i<n;i++) {
            cin>>temp;
            b.push_back(temp);
        }    
        
        sort(a.begin(),a.end());
        sort(b.begin(), b.end());    
        
        int j=0;
        for(int i=0;i<n;i++) {
            if(a[j]<=b[i]) {
                j++;
            }    
        }    
        cout<<j<<'\n';
    }    
    return 0;
}    
