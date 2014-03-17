#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main() {
    double value = 1.3063778838630806904686144926, it = 0.0000000000001;
    
    for(int i=0;i<100;i++) {
        printf("%.15lf\n",value*value*value);
        value += it;
    }    
    
    getchar();
    return 0;
} 

/*
    This is known as Mills Constant and has value 1.3063778838630806904686144926
*/   
