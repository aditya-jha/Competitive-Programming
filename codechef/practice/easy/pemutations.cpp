//All permutations of a string
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void printAllPermutations(char s[], int i, int len) {
    if(i == len-1) {
        cout<<s<<endl;
    }    
    else {
        
        for(int j=i; j<len; j++) {
            swap(s[i], s[j]);
            printAllPermutations(s, i+1, len);
            swap(s[i],s[j]);
        }    
    }    
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    char s[] = {'A', 'B', 'C'};
    int len = 3;
    
    printAllPermutations(s,0,len);
    
    system("pause");
    return 0;
    
}    
