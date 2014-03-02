#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int knapsack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
 
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
}

int main() {
    ios_base::sync_with_stdio(0);
    
    int t,n,W;
    
    cin>>t;
    
    while(t--) {
    	//total = 0;
    	
        cin>>n>>W;
        
        int *w = new int[n];
        int *v = new int[n];
        
        for(int i=0;i<n;i++) cin>>w[i];
        for(int i=0;i<n;i++) cin>>v[i];
         
        
        cout<<knapsack(W,w,v,n)<<endl;
        
        delete[] w,n;
    }    
    return 0;
}    
