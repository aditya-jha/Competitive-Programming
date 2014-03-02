#include<iostream>
#include<algorithm>
using namespace std;

void print(int a[], int n) {
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}    

void permute(int a[], int i, int n) {
    if(i == n) {
        print(a,n);
        return;
    }    
    for(int j=i;j<n;j++) {
        swap(a[i],a[j]);
        permute(a,i+1,n);
        swap(a[i],a[j]);
    }    
}    

int main() {
    int a[] = {1,2,3,4};
    
    permute(a,0,4);
    
    system("pause");
    return 0;
}    
