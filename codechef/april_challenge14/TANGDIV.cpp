#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

map<int,int> mymap;

int main(){
    ios_base::sync_with_stdio(0);
    
    int t;
    cin>>t;
    
    while(t--){
        int n,k,p;
        cin>>n>>k>>p;
        
        int flag = 0,l,r;
        
        while(k--) {
            cin>>l>>r;
            mymap[r] = 1; 
        }

        while(p--) {
            cin>>l>>r;
            if(mymap.find(r) == mymap.end()){
                flag = 1;
            }
        }
        
        if(flag == 1){
            cout<<"No\n";
        } else {
            cout<<"Yes\n";
        }     
        
        mymap.clear();  
    }
    
    return 0;
}
