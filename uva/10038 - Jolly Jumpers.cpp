#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

bool jolly(int a[], int n) {
    for(int i=1;i<n;i++) {
        if(a[i] == 0) return false;
    }
    return true;    
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    int n,b,a;
    
    while(cin>>n) {
        if(n==1) {
            cin>>a;
            cout<<"Jolly\n";
        }
        else {
            int *hash = new int[n];
            for(int i=0;i<n;i++) hash[i] = 0;
            
            cin>>a;
            
            for(int i=1;i<n;i++) {
                cin>>b;
                a = abs(b-a);
                if(a<n) hash[a] = 1;
                a = b;
            }
            
            if(jolly(hash,n) == true) cout<<"Jolly\n";
            else cout<<"Not jolly\n";
            
            delete[] hash;
        }    
    }    
    return 0;
}    
