#include<iostream>
#include<string>

using namespace std;

#define min(a,b) (a<b?a:b)

int main() {
    ios_base::sync_with_stdio(0);
    
    int t, count;
    string a, b;
    
    cin>>t;
    
    int aa[130], bb[130];
    int lena, lenb;
    
    while(t--) {
        count =0;
        cin>>a>>b;
        
        for(int i=0;i<130;i++) {
            aa[i]=0;
            bb[i]=0;
        }    
        
        lena = a.length();
        lenb = b.length();
        
        for(int i=0;i<lena;i++) aa[a[i]]++;
        for(int i=0;i<lenb;i++) bb[b[i]]++;
        
        for(int i=0;i<130;i++) count += min(aa[i],bb[i]);
        
        cout<<count<<'\n';
    }    
    
    return 0;
}    
