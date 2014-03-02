#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

#define llu unsigned long long

using namespace std;

vector<vector<int> > v(100001,vector<int>());

void multiply(int prev, int mul) {
    int carry = 0, temp;
    for(int i=0;i<v[prev].size();i++) {
        temp = v[prev][i]*mul + carry;
        v[mul].push_back(temp%10);
        carry = temp/10;
    }    
    
    while(carry != 0) {
        v[mul].push_back(carry%10);
        carry = carry/10;
    }    
}    

void preprocess() {
    v[0].push_back(1);
    
    for(int i=1;i<100001;i++) {
        cout<<i<<endl;
        multiply(i-1,i);
    }    
}    

llu divide(int n, llu b) {
    return v[n][0];
}    

int main() {
    ios_base::sync_with_stdio(0);
    cout<<"start\n";
    preprocess();
    cout<<"end\n";
    int t,n;
    llu b,con;
    
    cin>>t;
    
    while(t--) {
        cin>>n>>b;
        
        con = divide(n,b);
        if(con%2 == 0) cout<<"Even\n";
        else cout<<"Odd\n";
    }    
    
    return 0;
}    
