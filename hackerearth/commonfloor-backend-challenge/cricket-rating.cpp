#include<iostream>

using namespace std;

#define max(a,b) (a>b?a:b)

int kadanes(int a[], int n) {
    int max_so_far = 0;
    int max_ending_here = 0;
    
    for(int i=0;i<n;i++) {
        max_ending_here += a[i];
        if(max_ending_here < 0) max_ending_here = 0;
        
        max_so_far = max(max_so_far, max_ending_here);
        //cout<<max_so_far<<endl;
    }    
    
    return max_so_far;
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    int n;
    cin>>n;
    
    int *arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    cout<<kadanes(arr,n)<<'\n';
    
    delete[] arr;
    
    system("pause");
    return 0;
}    
