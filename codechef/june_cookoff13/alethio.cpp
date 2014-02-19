#include<iostream>
#include<string>
using namespace std;

void keep(char *input) {
    cout<<strlen(input);
}

int main() {
    int t;
    char input[1001];
    cin>>t;
    
    for(int i=0; i<t; i++) {
        gets(input);
        keep(input);   
    }    
    system("pause");    
    return 0;
}
