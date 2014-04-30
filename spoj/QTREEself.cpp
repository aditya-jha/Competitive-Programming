#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>

using namespace std;

#define N 100010

vector< int > tree[N], cost[N], indexx[N];
int parent[N], depth[N], subTree[N];
int chain, baseArray[N], ptr;
int chainHead[N], posInBase[N], chainInd[N], chainSize[N];




void HLD(int currNode, int cost, int prev) {
    if(chainHead[currNode] == -1) {
        chainHead[chain] = currNode;
    }    
    
    chainInd[currNode] = chain;
    posInBase[currNode] = ptr; // Position of this node in baseArray which we will use in Segtree
    baseArray[ptr++] = cost;
    
    int specialChild = -1, ncost;
    for(int i=0;i<tree[currNode].size();i++) {
        if(tree[currNode][i] != prev) {
            if(specialChild == -1 || subTree[specialChild] < subTree[tree[currNode][i]]) {
                specialChild = tree[currNode][i];
                ncost = tree[currNode][i];
            }    
        }    
    }    
    
    
    if(specialChild != -1) {
        HLD(specialChild, ncost, currNode);
    }    
    
    for(int i=0; i<tree[currNode].size(); i++) {
        if(tree[currNode][i] != prev) {
            if(specialChild != tree[currNode][i]) {
                // New chains at each normal node
                chain++;
                HLD(tree[currNode][i], cost[currNode][i], currNode);
            }    
        }
    }
}    




void DFS(int curr, int prev, int dep=0) {
    parent[curr] = prev;
    depth[curr] = dep;
    subTree[curr] = 1;
    
    for(int i=0;i<tree[curr].size();i++) {
        if(tree[curr][i] != prev) {
            DFS(tree[curr][i], curr, dep+1);
            subTree[curr] += subTree[tree[curr][i]];
        }    
    }    
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    cin>>t;
    
    while(t--) {
        int n;
        cin>>n;
        
        for(int i=0;i<N;i++) {
            tree[i].clear();
            cost[i].clear();
            indexx[i].clear();
            chainHead[i] = -1;
            parent[i] = -1;
        }    
        
        int a,b,c;
        ptr = 0;
        for(int i=1;i<n;i++) {
            cin>>a>>b>>c;
            a--;
            b--;
            
            tree[a].push_back(b); 
            cost[a].push_back(c);
            indexx[a].push_back(i-1);
            
            tree[b].push_back(a);
            cost[b].push_back(c);
            indexx[b].push_back(i-1);
        }  
        
        chain = 0;
        DFS(0, -1, 0);  
        
        
    }    
}    
