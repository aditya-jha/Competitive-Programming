#include<iostream>
#include<cstdio>
#include<string>
#include<climits>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int t,n;
    long long int min, val,count;
    char s[10001][6];

    scanf("%d",&t);

    while(t--) {
	scanf("%d",&n);
    	vector<long long int> hold,cc;
    	
    	for(int i=0;i<n;i++) {
    		scanf("%s %lld",s[i],&val);
    		hold.push_back(val);
		cc.push_back(val);
    	}
    
    	sort(hold.begin(),hold.end());
    
    	count=0;
    	min=LLONG_MAX;
    	
    	for(int i=0;i<hold.size();i++) {
    		val=hold[i];
    		
    		for(i++;i<hold.size();i++) {
    			if(val==hold[i]) count++;
    			else {i--; break; }
    		}
    		
    		if(count==0) { min=val; break; }
    		else count=0;
    	}
    	
    	if(min==LLONG_MAX) printf("Nobody wins.\n");
    	else {
    		for(int i=0;i<cc.size();i++) {
    		if(cc[i]==val) {
    			printf("%s\n",s[i]);
   	 		break;
    		}
    	}
    }	
  }
    //system("pause");
    return 0;
} 
