#include<iostream>

using namespace std;

long long sum=0;

long long foo(int n) {
    long long pro = 1, i=1, lim = 2*n;
    while(i<lim) {
        pro *= i;
        i += 2;
    }    
    pro *= lim;
    return pro;
}    

int main() {
    for(int i=1;i<16;i++) {
        sum += 2*foo(i);
    }    
    cout<<sum+1<<endl;
    
    getchar();
    return 0;
}    
