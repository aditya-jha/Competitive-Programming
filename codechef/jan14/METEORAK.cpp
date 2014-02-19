#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<cstring>
#include<stack>

using namespace std;
 
#define MOD 1000000007
#define llu long long unsigned
#define lld long long
#define ld long
 
int scan_d() {
	int ip=getchar_unlocked(),ret=0;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked());
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())
		ret=ret*10+ip-'0';

	return ret;
}

void print_d(int n) {
	int i=10;
	char output_buffer[11];output_buffer[10]='\n';
	
	do {
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	} while(n);
	
	do {
		putchar_unlocked(output_buffer[i]);
	} while(++i<11);
}
 
const int maxn = 1010;
int n,m,k,x,y,Q;

int grid[maxn][maxn];
int sol[maxn][maxn];

int getMaxArea(int hist[]) {

	stack<int> s;
 
    	int max_area = 0; // Initalize max area
    	int tp;  // To store top of stack
    	int area_with_top; // To store area with top bar as the smallest bar
 
    	// Run through all bars of given histogram
    	int i = 0;
    	while (i < m) {
	        // If this bar is higher than the bar on top stack, push it to stack
        	if (s.empty() || hist[s.top()] <= hist[i]) s.push(i++);
 
        	// If this bar is lower than top of stack, then calculate area of rectangle
        	// with stack top as the smallest (or minimum height) bar. 'i' is
        	// 'right index' for the top and element before top in stack is 'left index'
        	else
        	{
            		tp = s.top();  // store the top index
            		s.pop();  // pop the top
 
            		// Calculate the area with hist[tp] stack as smallest bar
            		area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
            		// update max area, if needed
            		if (max_area < area_with_top) max_area = area_with_top;
        	}
    	}
 
    	// Now pop the remaining bars from stack and calculate area with every
    	// popped bar as the smallest bar
    	while (s.empty() == false) {
        	tp = s.top();
        	s.pop();
        	area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
	        if (max_area < area_with_top)
            		max_area = area_with_top;
    	}
 
    	return max_area;
}

int small(int index) {
	int area[m],maxarea;
	
	if(grid[index][0]==1) area[0]=1;
	else area[0] = 0;
	
	maxarea = area[0];
	for(int i=1;i<m;i++) {
		if(grid[index][i] == 1) {
			area[i] = area[i-1]+1;
			if(area[i]>maxarea) maxarea = area[i];
		}
		else area[i] = 0;
	}
	
	return maxarea;
}

void preprocess(int start) {
	int mat[maxn][maxn], area[m],maxm;
	
	area[0] = grid[start][0];
	maxm = area[0];
	mat[start][0] = maxm;
	
	for(int i=1;i<m;i++) {
		mat[start][i] = grid[start][i];
		if(grid[start][i]) {
			area[i] = area[i-1]+1;
			if(area[i]>maxm) maxm = area[i];
		}
		else area[i]=0;
	}
	sol[start][start] = maxm;
		
	for(int i=1;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(grid[i][j]==1) {
				for(int k=0;k<i;k++) mat[k][j] += 1;
				mat[i][j] = 1;
			} 
			else {
				for(int k=0;k<i;k++) mat[k][j] = 0;
				mat[i][j] = 1;
			}
		}
//		sol[i][i] = max(getMaxArea(mat[i]),sol[start][i-1]);
		for(int j=0;j<=i;j++) sol[j][i] = max(getMaxArea(mat[j]),sol[j][i-1]);
	}

/*	
	for(int i=start+1;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(grid[i][j] == 1) mat[i][j] = mat[i-1][j] + 1;
			else mat[i][j] = 0;
		}
		sol[start][i] = max(getMaxArea(mat[i]),sol[start][i-1]);
	}
*/
}


int main() {
		
	n = scan_d(); m = scan_d(); k = scan_d();
	
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) grid[i][j] = 1;
	
	while(k--) {
		x = scan_d(); y = scan_d(); 
		grid[x-1][y-1] = 0; 
	}
	
	Q = scan_d();
	
	//for(int i=0;i<n;i++) {
		preprocess(0);		
//	}
	
	while(Q--) {
		x = scan_d(); y = scan_d();
		print_d(sol[x-1][y-1]);
	}
	
	return 0;
}


