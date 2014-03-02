#include<iostream>
#define llu unsigned long long
using namespace std;

int divide(int dp[], llu b, int index) {
    int digits = 0;
    llu temp = b, div = 0;
    
    while(temp != 0) {
        digits++;
        temp = temp/10;
    }    
    
    for(int i=0;i<digits-1 and i<index; i++) {
        div = 10*div + dp[i];
    }    
    
    llu quo = 0,rem;
    for(int i= digits-1;i<index;i++) {
        div = 10*div + dp[i];
        rem = div%b;
        quo = quo*10 + div/b;
    }    
    
    return quo;
}    

int multiply(int dp[], int mul, int index) {
    int carry = 0, temp;
    for(int i=0;i<index;i++) {
        temp = dp[i]*mul + carry;
        dp[i] = temp%10;
        carry = temp/10;
    }    
    
    while(carry != 0) {
        dp[index++] = carry%10;
        carry = carry/10;
    }    
    
    return index;
} 

int solve(int n, llu b) {
    llu count=0;
    if(n==0) {
        count = 1/b;
        if(count == 0) return 1;
        else return 0;
    }    
    int *dp = new int[500000];
    
    int index = 0, temp = n;
    
    while(temp != 0) {
        dp[index++] = temp%10;
        temp = temp/10;
    } 
    
    //for(int i=0;i<index;i++) cout<<dp[i];
    //cout<<endl;
    
    for(int i=n-1;i>1;i--) {
        index = multiply(dp,i,index);
        //for(int i=0;i<index;i++) cout<<dp[i];
        //cout<<endl;
    }    
    
    count = divide(dp,b,index);
    //cout<<count<<endl;
    
    delete[] dp;
    
    if(count%2 == 0) return 1;
    else return 0;
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    int t,n;
    llu b;
    cin>>t;
    
    while(t--) {
        cin>>n>>b;
        
        if(solve(n,b) == 1) cout<<"Even\n";
        else cout<<"Odd\n";
    }        
    return 0;
}    
