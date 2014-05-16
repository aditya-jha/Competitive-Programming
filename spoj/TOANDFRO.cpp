#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    
    cin>>t;
    
    while(t) {
        char s[1001];
        cin>>s;
        
        int len = strlen(s);
        int row = len/t;
        int k=1,i=k*t,j=i+t-1;
        
        while(k<row) {
            while(i<j) {
                swap(s[i],s[j]);
                i++;
                j--;
            }
            k += 2;
            i = k*t; 
            j=i+t-1;   
        }       
        
        i=0,j=0;
        for(;i<t;i++) {
            j=i;
            while(j<len) {
                cout<<s[j];
                j += t;
            }    
        }     
        cout<<endl;
        cin>>t;
    }    
        
    return 0;
}    
