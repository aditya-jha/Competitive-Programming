#include<iostream>
#include<cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    long long int sol, n, nn;
    cin>>t;
    while(t--) {
        cin>>n;
        
        nn = n;

        int m = 0;
        while(nn) {
            nn /= 2;
            m++;
        }
        //cout<<m<<endl;
        sol = (n*(n+1))/2 - 2*((1<<m) - 1);
        cout<<sol<<endl;
    }
    return 0;
}
