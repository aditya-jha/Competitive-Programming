#include<iostream>
#include<vector>

using namespace std;

int times[10001];

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    cin>>t;
    
    while(t--) {
        for(int i=0;i<10001;i++) times[i] = 0;
        
        int n,r;
        cin>>n;
        
        while(n--) {
            cin>>r;
            times[r]++;
        }
        //cout<<times[1]<<endl;
        int minim = 0;
        for(int i=0;i<10001;i++) {
            if(times[i]>times[minim]) {
                //cout<<minim<<endl;
                minim = i;
            }    
        }        
        
        cout<<minim<<" "<<times[minim]<<endl;
    }    
    
    return 0;
    
}    
