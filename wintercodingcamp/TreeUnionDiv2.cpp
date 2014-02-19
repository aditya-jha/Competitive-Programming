#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;



class TreeUnionDiv2 {  
public:  
	
int distA[10][10], distB[10][10];  
vector<int> perm;
    int maximumCycles(vector <string> tree1, vector <string> tree2, int K) {  
    	int n = tree1.size(), sol=0;  
  
	for(int i=0;i<n;i++) {  
		perm.push_back(i);
		
		for(int j=0;j<n;j++) {  
            		if ('X' == tree1[i][j]) distA[i][j] = 1;   
            		else distA[i][j] = 50;  

            		if ('X' == tree2[i][j]) distB[i][j] = 1;  
            		else distB[i][j] = 50;  
            	}  
        }  
  	
    	for(int k=0; k<n; k++) {  
        	for(int i=0; i<n; i++) {  
            		for (int j = 0; j<n; j++) {    
                		if(distA[i][j] > (distA[i][k]+distA[k][j])) distA[i][j] = distA[i][k] + distA[k][j];  
                		
                		if (distB[i][j] > (distB[i][k]+distB[k][j])) distB[i][j] = distB[i][k] + distB[k][j];  
                	}  
            	}  
        }  
  
    	do {  
        	int temp = 0;  
        	for (int i = 0; i<n; i++) {  
            		for (int j=i+1; j<n; j++) {  
                		if(distA[i][j] + distB[perm[i]][perm[j]]+2 == K) temp++;  
            		}  
        	}  
        	
        	sol = max(sol,temp);  
    	} while (next_permutation(perm.begin(), perm.end()));  
  
    	return sol;  
    }  
};  
  


//Powered by [KawigiEdit] 2.0!
