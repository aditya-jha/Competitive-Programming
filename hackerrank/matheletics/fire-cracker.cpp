#include<iostream>
#include<cmath>

using namespace std;

int main() {
    unsigned long long n,a,b,i;

    unsigned long long p = 11513628481LL;
    
    n=0;
    for(a=11513628482LL,b=11513628482LL; ;b++) {
        i=0;
        while(i<1000000) {
                if((a*b)%((a-p)*(b-p)) == 0) {
                            n++;
                                        cout<<a<<" "<<b<<endl;
                                                    cout<<n<<endl;
                } 
                i++;   
                a++;
        }  
        //cout<<a<<" "<<b<<endl;
        a = 11513628482LL;  
    }    
    
    return 0;
}    
