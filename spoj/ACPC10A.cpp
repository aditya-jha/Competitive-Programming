#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int a,b,c;
    cin>>a>>b>>c;
    
    while(1) {
        if(a==0 && b==0 && c==0) break;
        
        if((2*b)==(a+c)) {
            cout<<"AP  "<<c+(b-a)<<'\n';
        }
        else {
            cout<<"GP  "<<c*(c/b)<<'\n';
        }
        
        cin>>a>>b>>c;
    }    
    
    return 0;
}
