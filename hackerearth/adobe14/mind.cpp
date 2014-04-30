#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int grid[1001][1001];
int n,m,x;

int bs(int index, int low, int high) {
    if(low > high) return -1;
    
    int mid = low + (high-low)/2;
    if(grid[index][mid] == x) return mid;
    
    if(grid[index][mid] > x) {
        return bs(index, low, mid-1);
    }    
    else return bs(index, mid+1, high);
}        

void search() {
    for(int i=0;i<n;i++) {
        if(grid[i][0] <= x and grid[i][m-1] <= x) {
            int temp = bs(i, 0, m-1);
            if(temp != -1) {
                cout<<i<<" "<<temp<<endl;
                break;
            }     
        }    
    }  
    cout<<"-1 -1\n";  
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    cin>>n>>m;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cin>>grid[i][j];
    }       
    
    int q;
    cin>>q;
    
    while(q--) {
        cin>>x;
        search();
    }    
    
    return 0;
}    
