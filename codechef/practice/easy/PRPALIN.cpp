#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

bool isPrime(int n) {
   
    if(n%2==0 or n%3==0) return false;
    
    int lim = (int)sqrt(float(n));
    
    for(int i=5;i<=lim;i+=2) {
        if(n%i==0) return false;
    }    
    
    return true;
}    


bool isPalindrome(int n) {
    vector<int> v;
    while(n>0) {
        v.push_back(n%10);
        n = n/10;
    }    
    
    for(int i=0,j=v.size()-1; i<j; i++,j--) {
        if(v[i] != v[j]) return false;
    }
    
    return true;    
}    

int main() {
    int n;
    cin>>n;
    
    if(n==1) {
        cout<<2<<endl;
        return 0;
    }    
    if(n==2 or n==3) {
        cout<<n<<endl;
        return 0;
    }    
    
    if(n%2==0) n++;
    
    for(int i=n;;i+=2) {
        if(isPrime(i)) {
            if(isPalindrome(i)) {
                cout<<i<<"\n";
                break;
            }    
        }    
    }    
    
    return 0;
}    
