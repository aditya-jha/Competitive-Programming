#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define node pair<int,int> 

int n;
vector<node> v;

int find(int a[], int val, int j) {
    for(int i=j+1;j<n;j++) {
        if(a[i] == val) return i;
    }    
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    
    cin>>n;
    
    int *a = new int[n];
    int *b = new int[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
        a[i] = b[i];
    }    
    
    sort(b,b+n);
    
    int q=0, index, diff, j, k;
    for(int i=0;i<n;i++) {
        if(a[i] == b[i]) continue;
        else {
            index = find(a,b[i],i);
            diff = (index-i+1)/2;
            j = i; k = index;
            while(diff>0) {
                diff--;
                swap(a[j++],a[index--]);
            }   
            v.push_back(make_pair(i,index));
            q++;
        }        
    }    
    
    cout<<q<<endl;
    for(int i=0;i<v.size();i++) cout<<v[i].first<<" "<<v[i].second<<endl;
    
    return 0;
}    
