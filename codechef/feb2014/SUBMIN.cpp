#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int a[100001], k, q;

long long submin(int index, int flag) {
    int counter = 0;
    
    if(flag == 0) {
        for(int i=index+1;i<n;i++) {
                if(a[i] < k) break;
                else if(a[i] == k) {                
                    index++;
                    counter++;
                    break;                                                     
                }    
                else index++;
        }    
        if(counter == 0) return 0;
    }    
    
    for(int i=index+1;i<n;i++) {
        if(a[i] >= k) counter++;
        else break;
    }    
    
    return counter;
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    
    cin>>q;
    
    while(q--) {
        cin>>k;
        
        int counter=0;
        for(int i=0;i<n;i++) {
            if(a[i] == k) {
                counter += submin(i,1)+1;
                //cout<<i<<" "<<counter<<endl;
            }    
            else if(a[i] > k) {
                counter += submin(i,0);
                //cout<<i<<" "<<counter<<endl;
            }    
        }     
        
        cout<<counter<<'\n';
    }    
    
    return 0;
}    
