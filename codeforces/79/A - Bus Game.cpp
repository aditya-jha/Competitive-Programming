#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int x,y;
    cin>>x>>y;
    
    int turn =0;
    
    while(true) {
        if(turn == 0) {
            if(x>=2 and y>=2) {
                x -= 2;
                y -= 2;
                
                turn =1;
            }    
            else if(x==1 and y>=12) {
                x -= 1;
                y -= 12;
                turn =1;
            }    
            else if(x==0 and y>=22) {
                y -= 22;
                turn =1;
            }    
            else {
                cout<<"Hanako\n";
                break;
            }    
        }    
        else {
            if(y>=22) {
                y -= 22;
                turn = 0;
            }    
            else if(x>=1 and y>=12) {
                x -= 1;
                y -= 12;
                turn = 0;
            }    
            else if(x>=2 and y>=2) {
                x -= 2;
                y -= 2;
                turn = 0;
            }    
            else {
                cout<<"Ciel\n";
                break;
            }
        }    
    }    
    
    return 0;
}    
