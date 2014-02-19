#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

int hash(char s[]) {
    int value = 0, len = strlen(s);
    for(int i=0;i<len;i++) {
        value += ((int)s[i])*(i+1);
    }    
    return (value%101*19)%101;
} 

int main() {
	ios_base::sync_with_stdio(0);
	
	int t,n,h,val,con,look[105],len,k;

	cin>>t;
	
	while(t--) {
		
		cin>>n;
		
		char **table = new char*[n+2];
		char *s = new char[25];
		
		table[0] = new char[25];
		
		memset(look,-1,sizeof(look));
		con=0;
		for(int i=1;i<=n;i++) {
			table[i] = new char[25];
			cin>>s;
			len = strlen(s);
			k=0;
			for(int j=4;j<len;j++) table[i][k++] = s[j];
			table[i][k] = '\0';
			
			h = hash(table[i]);
			
			if(s[0]=='A') {
				for(int j=0;j<20;j++) {
					val = (h + j*j + 23*j)%101;
					if(look[val] == -1 or look[val] == 0) { 
						con++; look[val] = i; break; 
					}    
					else {					
					if(strcmp(table[i],table[look[val]])==0)
						break;
					}
				}
			}
			else {
				for(int j=0;j<20;j++) {
					val = (h + j*j + 23*j)%101;
					if(look[val] == -1) break;
                    			else if(look[val]==0) continue;
                    			else if(strcmp(table[i],table[look[val]]) == 0) { con--; look[val]=0; break; }
				}
			}
		}
		
		cout<<con<<"\n";
        	for(int i=0;i<102;i++) 
        		if(look[i]>0) cout<<i<<":"<<table[look[i]]<<"\n";
        	delete[] s;
        	delete[] table;
	}
	
	return 0;
}
