#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

long long a[3];

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    cin>>t;
    
    for(int i=1;i<=t;i++) {
        cin>>a[0]>>a[1]>>a[2];
        
        sort(a,a+3);
        
        if(a[0]+a[1]>a[2] and a[0]+a[2]>a[1] and a[2]+a[1]>a[0]) {
            if(a[0] == a[1] and a[1] == a[2]) {
                cout<<"Case "<<i<<": Equilateral\n";
            }    
            else if(a[0] == a[1] or a[1] == a[2]) {
                cout<<"Case "<<i<<": Isosceles\n";
            }    
            else {
                cout<<"Case "<<i<<": Scalene\n";
            }    
        }
        else {
            cout<<"Case "<<i<<": Invalid\n";
        }        
    }  
    return 0;  
}    
