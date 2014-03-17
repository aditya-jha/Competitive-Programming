#include<iostream>
using namespace std;

unsigned long long prev,next;

int main() {
    prev = 8;
    next = 8;
    
    for(unsigned long long int i=3;i<=1000000000;i++) {
        cout<<prev<<" "<<next<<endl;
        long long hold = (i-2)*(i-2);
        hold *= prev;
        hold /= (i*i);
        
        hold += 8;
        
        prev = next;
        next = hold;
    }        
    
    cout<<prev<<" "<<next<<endl;
    
    getchar();
    return 0;
}    
