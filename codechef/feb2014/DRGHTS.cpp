#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n,m,layer=0,v;
bool window[50001];
int explored[50001];
vector<vector<int> > node(50001, vector<int>());
int total[50001], yes[50001];

void BFS(int vertex) {
    layer++;
    explored[vertex] = layer;
    
    if(window[vertex] == true) total[layer]++;
    
    queue<int> Q;
    Q.push(vertex);
    
    while(!Q.empty()) {
        v = Q.front();
        Q.pop();
        
        if(node[v].size() == 1) if(window[v] == true) yes[v]++;
        else if(node[v].size() == 0) if(window[v] == true) yes[v]++;
        
        for(int i=0;i<node[v].size();i++) {
            if(explored[node[v][i]] == 0) {
                explored[node[v][i]] = layer;
                if(window[node[v][i]] == true) {
                    total[layer]++;
                    yes[v]++;
                }    
                Q.push(node[v][i]);
            }
            else if(yes[node[v][i]] > 0 || window[node[v][i]]) yes[v]++;
        } 
           
    }    
}    

long long getval(int val) {
    long long mul=1;
    int upto = max(val-2,2);
    
    for(int i=val;i>upto;i--) {
        mul *= i;
    }    
    
    if(upto != 2) mul = mul/2;
    
    return mul;
}    

int main(){
    ios_base::sync_with_stdio(0);
    
    int a,b,rubik=0;
    cin>>n>>m;
    
    for(int i=1;i<=n;i++) cin>>window[i];    
    
    for(int i=0;i<m;i++) {
        cin>>a>>b;
        node[a].push_back(b);
        node[b].push_back(a);
    }        
    
    for(int i=1;i<=n;i++) {
        if(explored[i] == 0) {
            BFS(i);
        }     
    } 
    
    //for(int i=1;i<=n;i++) cout<<i<<" "<<explored[i]<<endl;
    long long sum=0;
    for(int i=1;i<=layer;i++) {
        if(total[i]>1) {
            sum += getval(total[i]);
        }    
    }    
    
    for(int i=1;i<=n;i++) if(yes[i]>1) rubik++;
    
    cout<<sum<<" "<<rubik<<'\n';
    
    system("pause");
    return 0;
}    
