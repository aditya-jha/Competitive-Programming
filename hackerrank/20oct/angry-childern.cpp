#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int main() {
    long int n,k,temp;
    vector<long int> v;
    scanf("%ld %ld",&n,&k);
    
    for(long int i=0;i<n;i++) {
        scanf("%ld",&temp);
        v.push_back(temp);
    }    
    
    sort(v.begin(),v.end());
    
    long int diff=0;
    long long int min=1000000001;
    for(long int i=0;i+k<=n;i++) {
        diff = v[i+k-1] - v[i];
        if(diff<min) {
            min = diff;
        }    
    }    
    printf("%lld\n",min);
    
    return 0;
}    
