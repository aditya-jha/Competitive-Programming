#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>

using namespace std;

vector<vector<int> > v(101,vector<int>());
vector<vector<int> > store(101,vector<int>());
vector<int> cant_reach;
bool visited[102], spoken[102];

void DFS(int i) {
    visited[i] = true;
    
    for(int j=0;j<v[i].size();j++) {
        if(!visited[v[i][j]]) {
            DFS(v[i][j]);
        }    
    }    
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    for(int i=1;i<102;i++) {
        visited[i] = false;
        spoken[i] = false;
    }    
    
    int n,m,a,b;
    cin>>n>>m;
    
    for(int i=1;i<=n;i++) {
        cin>>a;
        if(a==0) {
            cant_reach.push_back(i);
            continue;
        }    

        for(int j=0;j<a;j++) {
            cin>>b;
            spoken[b] = true;
            store[b].push_back(i);
        }    
    }    

    int sum=0;
    
    for(int i = 1;i<=m;i++) {
        if(spoken[i]) {
            for(int j=0;j<cant_reach.size();j++) {
                sum++;
                store[i].push_back(cant_reach[j]);
            }        
            break;    
        }    
    }    
    
    if(sum == 0 and cant_reach.size() != 0) {
        cout<<cant_reach.size()<<endl;
        return 0;
    }    
    
    for(int i=1;i<=m;i++) {
        for(int j=1;j<store[i].size();j++) {
            v[store[i][j]].push_back(store[i][j-1]);
            v[store[i][j-1]].push_back(store[i][j]);
        }           
    }
    
    DFS(1);
    int count=0;
    
    for(int i=1;i<=n;i++) {
        if(!visited[i]) {
            DFS(i);
            count++;
        }
    }
    cout<<sum+count<<endl;
    
    return 0;   
}    
