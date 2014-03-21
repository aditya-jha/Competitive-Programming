#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int n,t;
    cin>>n;
    
    vector<int> v;
    
    for(int i=0;i<n;i++){
        cin>>t;
        v.push_back(t);
    }    
    
    sort(v.begin(), v.end());
    
    long long sol;
    if(n==1) sol = (long long)v[0]*(long long)v[0];
    else sol = (long long)v[0]*(long long)v[n-1];
    
    cout<<sol<<endl;
    
    return 0;
    
}    
