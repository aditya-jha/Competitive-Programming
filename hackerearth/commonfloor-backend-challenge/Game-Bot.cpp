#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> dpa,dpb;

void solve(string a, string b) {
   dpa.clear(); dpb.clear();
    string ta = "", tb = "";
    for(int i=0;i<a.length();i++) {
        if(a[i] != '#') {
            ta+=a[i];
            dpa.push_back(i);
        }    
    }    
    
    for(int i=0;i<b.length();i++) {
    	if(b[i] != '#') {
            tb += b[i];
            dpb.push_back(i);
        }   
    }
    
    for(int i=0;i<ta.length();i++) {
        if(ta[i] != tb[i]) {
            cout<<"No\n";
            return;
        }    
    }    
    
    
    for(int i=0;i<dpa.size();i++) {
        if(ta[i] == 'A' and dpa[i]<dpb[i]) {
            cout<<"No\n";
            return;
        }    
        if(ta[i] == 'B' and dpa[i]>dpb[i]) {
            cout<<"No\n";
            return;
        }    
    }    
    
    cout<<"Yes\n";
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    cin>>t;
    
    string a,b;
    
    while(t--) {
        cin>>a>>b;
        
        solve(a,b);
    }   
    
     return 0; 
}    
