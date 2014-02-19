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
 
#define vec vector<vector<int> >
const int maxn = 1001;
int n,m,k,x,y,Q;

bool grid[maxn][maxn];
vector<vec> v(maxn,vector<vector<int> >());
vector<int> a;

int getMaxArea(vector<int> &hist) {
	for(int i=0;i<hist.size();i++) cout<<hist[i]<<" ";
	cout<<endl;
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

void preprocess(int start) {
	for(int i=0;i<=start;i++) {
		v[start].push_back(vector<int>());
	}	
	
	for(int i=0;i<m;i++) v[start][start].push_back(grid[start][i]);	
	
	for(int i=start+1;i<n;i++) {
		v[start].push_back(vector<int>());
		
		for(int j=0;j<m;j++) {
			if(grid[i][j] == 1) v[start][i].push_back(v[start][i-1][j] + 1);
			else v[start][i].push_back(0);
		}
	}
}


int main() {
		
	n = scan_d(); m = scan_d(); k = scan_d();
	
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) grid[i][j] = 1;
	
	while(k--) {
		x = scan_d(); y = scan_d(); 
		grid[x-1][y-1] = 0; 
	}
	
	for(int i=0;i<n;i++) {
		preprocess(i);		
	}
	
	Q = scan_d();	
	
	while(Q--) {
		x = scan_d(); y = scan_d();
		print_d(getMaxArea(v[x-1][y-1]));
	}
	
	return 0;
}


