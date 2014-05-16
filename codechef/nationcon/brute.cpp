#include<iostream>

using namespace std;

int main() {
    
    for(int i=0;i<400;i++) {
        long long n = rand()%(long long)1000000001;
        int k = rand()%10001;
        long long m = rand()%(long long)10000000001;
        cout<<n<<" "<<k<<" "<<m<<endl;
        /*
        for(int i=0;i<m;i++) {
            if(n%k==0) n=n/k;
            else n=n*k;
        }    
        
        cout<<n<<endl;
        */
    }       
    
    return 0;
}    
