#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int N  = 100010;

vector<vector<int> > tree;
int level[N], root;


void BFS(int vertex, int dep) {
    level[vertex] = 0;
    
	queue<int> Q;
	Q.push(vertex);
	
	while(!Q.empty()) {
		int v = Q.front();
		Q.pop();
		
		for(int i=0;i<tree[v].size();i++) {
		    if(level[tree[v][i]] == -1) {
		        level[tree[v][i]] = dep;
				Q.push(tree[v][i]);
			}
		}
		dep++;
	}
}

long long get(int n) {
    long long sol = 0;
    long long con = 1;
    for(int i=2;i<n;i++) {
        if(level[i] != level[i-1]) {
            sol += (con*(con-1))/2;
            con = 1;
        }    
        else {
            con++;
            if( i == (n-1)) sol += (con*(con-1))/2;
        }    
    }    
    return sol;
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    cin>>t;
    
    while(t--) {
    	tree.clear();
    	
        for(int i=0;i<N;i++) {
            tree.push_back(vector<int>());
            level[i] = -1;
        }    
        
        int n, temp;
        cin>>n;
        n++;
        
        for(int i=1;i<n;i++) {
            cin>>temp;
            if(temp == 0) {
            	root = i;
            	continue;
            }
            
            tree[i].push_back(temp);
            tree[temp].push_back(i);
        }  
        
        BFS(root,1);
        
        sort(level, level+n);        
        
        //for(int i=1;i<n;i++) cout<<level[i]<<" ";
        //cout<<endl;
        
        long long fist = get(n);
        //cout<<fist<<endl;
        n--;
        
        long long total = (n*(n-1))/2;
        cout<<total - fist<<" "<<fist<<"\n";
    }    
    
    return 0;
}    
