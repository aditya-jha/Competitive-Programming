#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<cstdlib>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int t,m,n;
    bool ans;
    
    cin>>t;
    
    while(t--) {
        cin>>m>>n;
        
        int **input = new int*[m];
        int *table = new int[n+1];
        
        ans = true;
        
        for(int i=0;i<m;i++) {
            input[i] = new int[2];
            cin>>input[0][0]>>input[i][1];
        }    
        
        memset(table, -1, sizeof(table));
        
        for(int i=0;i<m;i++) {
            if(table[input[i][0]] == -1) {
                table[input[i][0]] = i;
            }    
            else if(table[input[i][1]] == -1) { 
                table[input[i][1]] = i;
            }    
            else {
                
            }    
        }    
        
        if(ans) {
            cout<<"successful hashing\n";
        }    
        else {
            cout<<"rehash necessary\n";
        }    
        
        delete[] input, table;
    }    
    
    return 0;
}    
