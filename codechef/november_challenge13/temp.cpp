#include<iostream>

using namespace std;

bool check(unsigned long long n) {
    int see;
    while(n) {
        see = n%10;
        n = n/10;
    }    
    if(see==1) return true;
    else return false;
}    

int main() {
    unsigned long long i=1;
    for(int j=0;j<64;j++) {
        i*=2;
        if(check(i)) cout<<j+1<<" "<<i<<endl;
    }     
    getchar();
    return 0;
}    
