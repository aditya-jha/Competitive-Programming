#include<iostream>
#include<cstdio>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int n;
    cin>>n;
    
    while(n!= -1) {
        int *a = new int[n];
        int sum=0,all,count=0;
        
        for(int i=0;i<n;i++) {
            cin>>a[i];
            sum+=a[i];
        }    
        
        if(sum%n!=0) {
            cout<<"-1\n";
        }    
        else {
            all = sum/n;
            for(int i=0;i<n;i++) {
                if(a[i]<all) count += (all-a[i]);
            } 
            cout<<count<<"\n";   
        }
        
        delete[] a;
        cin>>n;    
    }    
    return 0;    
}    
