#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int n,a;
    cin>>n;
    
    while(n) {
        stack<int> s;
        queue<int> q;
        
        int count=1;
        bool sol = true;
        
        for(int i=0;i<n;i++) {
            cin>>a;
            q.push(a);
        }    
        
        while(count<=n) {
            if(!q.empty()) {
                if(q.front() == count) {
                    count++;
                    q.pop();
                }    
                else if(!s.empty()) {
                    if(s.top() == count) {
                        count++;
                        s.pop();
                    }    
                    else {
                        s.push(q.front());
                        q.pop();
                    }    
                }
                else {
                    s.push(q.front());
                    q.pop();
                }        
            }
            else {
                if(s.top() == count) {
                    count++;
                    s.pop();
                }    
                else {
                    sol = false;
                    break;
                }    
            }        
        } 
        
        if(sol) {
            cout<<"yes\n";
        }       
        else cout<<"no\n";
        
        cin>>n;
    }    
    return 0;
}    
    
