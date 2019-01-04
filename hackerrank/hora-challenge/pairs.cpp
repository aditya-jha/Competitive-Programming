#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

int pairs(int k, vector<int> arr) {
    sort(arr.begin(), arr.end());
    long long count=0;

    for (int i=0; i<arr.size(); i++) {
        long long toFind = arr[i] + k;
        if (binary_search(arr.begin() + 1, arr.end(), toFind)) {
            count++;
        }
    }

    return count;
}

int main() {
    int n, k, t;
    cin>>n>>k;

    vector<int> v;
    for (int i=0; i<n; i++) {
        cin>>t;
        v.push_back(t);
    }

    cout<<pairs(k, v)<<endl;
}