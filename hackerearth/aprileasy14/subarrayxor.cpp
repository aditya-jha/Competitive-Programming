// Program to show segment tree operations like construction, query and update
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

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

int getMid(int s, int e) {  return s + (e -s)/2;  }

int getSumUtil(int *st, int ss, int se, int qs, int qe, int index)
{

    if (qs <= ss && qe >= se)
        return st[index];
 
    if (se < qs || ss > qe)
        return 0;
 
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*index+1) ^
           getSumUtil(st, mid+1, se, qs, qe, 2*index+2);
}
 
void updateValueUtil(int *st, int ss, int se, int i, int diff, int index)
{

    if (i < ss || i > se)
        return;
        
    st[index] = st[index] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*index + 2);
    }
}
 
// The function to update a value in input array and segment tree.
// It uses updateValueUtil() to update the value in segment tree
void updateValue(int arr[], int *st, int n, int i, int new_val)
{
    int diff = new_val - arr[i];
 
    arr[i] = new_val;
 
    updateValueUtil(st, 0, n-1, i, diff, 0);
}
 
// Return sum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses getSumUtil()
int getSum(int *st, int n, int qs, int qe)
{
 
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}
 
// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    int mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) ^
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}
 
/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
int *constructST(int arr[], int n)
{
    // Allocate memory for segment tree
    int x = (int)(ceil(log2(n))); //Height of segment tree
    int max_size = 2*(int)pow(2.0, x) - 1; //Maximum size of segment tree
    int *st = new int[max_size];
 
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);
 
    // Return the constructed segment tree
    return st;
}
 
int main() {
    
    int t;
    t=scan_d();
    
    while(t--) {
        int n;
        n=scan_d();
        
        int *dp = new int[n];
        for(int i=0;i<n;i++) dp[i]=scan_d();
        
        int *st = constructST(dp, n);
        
        int q, a, b;
        q=scan_d();
        
        while(q--) {
            a=scan_d();
            b=scan_d();
            print_d(getSum(st, n, a, b));
        }    
        
        delete[] dp;
        delete[] st;
    }    
    
    return 0;
}    
