/*
    Aditya Jha
    24-04-2014
    Runtime: 0.03s Mem: 2.6M
*/

#include<iostream>
#include<cstdio>

using namespace std;

int rev(int n) {
    int temp, num=0;
    while(n>0) {
        temp = n%10;
        if(temp==0) n=n/10;
        else break;
    }    
    while(n>0) {
        num = num*10 + temp;
        n = n/10;
        temp = n%10;
    }    
    
    return num;
}    

int solve(int x, int y) {
    int reva = rev(x);
    int revb = rev(y);
    
    return rev(reva+revb);
}    

int main() {
    
    int t, x, y;
    scanf("%d",&t);
    
    while(t--) {
        scanf("%d %d",&x, &y);
        printf("%d\n",solve(x,y));
    }    
    return 0;
}    

/*
    Note: using scanf instead of cin(with ios_base::sync_with_stdio(0),
    considerably decreased time limit(0.17 to 0.03s)
*/
