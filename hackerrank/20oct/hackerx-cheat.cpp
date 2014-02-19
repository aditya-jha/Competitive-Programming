#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long int n;
	scanf("%ld",&n);
	
	pair<int, int> p[n+5];
	long int t[n+5], f[n+5], dp[n+5];
	
	for (long int i = 1; i <= n; i++) {
		scanf("%ld %ld",&t[i],&f[i]);
		p[i].first = t[i] - f[i];
		p[i].second = t[i] + f[i];
	}
        
        sort(p + 1, p + n + 1);
	/*
        long int ans = 0;
        dp[1] = 1;
        
        for (long int i = 2; i <= n; i++) {
              dp[i] = 1;
              for (int j = 1; j < i; j++) {
                      if (p[i].second < p[j].second) {
                              dp[i] = max(dp[i], dp[j] + 1);
                      }
              }
                       
              ans = max(ans, dp[i]);
        }
              
        printf("%ld\n",ans);
        */
        vector<long int> v;
        
        for (long int i = 1; i <= n; i++) {
        	long int val = p[i].second;
        	long int low = 0, high = v.size() - 1;
        	
        	while (low <= high) {
        		long int mid = (low + high)/2;
                        if (v[mid] > val) low = mid + 1;
                        else high = mid - 1;
                }
                
                if (v.size() <= low) v.push_back(val);
                else v[low] = val;
        }
         
        printf("%d\n",v.size());
            
        return 0;
}
