#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int n,m;
    cin>>n>>m;
    
    string s[n];    
    int color = 0;
    
    for(int i=0;i<n;i++) {
        cin>>s[i];
        
        if(i%2==0) color = 1;
        else color = 0;
        
        for(int j=0;j<m;j++) {
            if(s[i][j] == '-') {
                cout<<s[i][j];
                if(color == 0) color = 1;
                else color = 0;
            }    
            else {
                if(color == 0) {
                    cout<<"W";
                    color = 1;
                }    
                else {
                    cout<<"B";
                    color = 0;
                }    
            }    
            
        }  
        cout<<endl;
    }
    return 0;    
}    
