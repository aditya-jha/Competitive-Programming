//
// Created by Aditya Jha on 2018-12-28.
//

#include<iostream>
#include<string>
#include <algorithm>

using namespace std;

bool isPalindrome(long long int n) {
    string s = to_string(n);
    int i=0, j=s.length()-1;
    while(i<j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

long long getSum(long long a) {
    string s = to_string(a);
    reverse(s.begin(), s.end());

    long long b = stoi(s);
    return a+b;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        long long a;
        cin>>a;

        int itrs = 0;
        long long sum = a;

        while(!isPalindrome(sum)) {
            sum = getSum(sum);
            itrs++;
        }

        cout<<itrs<<" "<<sum<<endl;
    }

    return 0;
}