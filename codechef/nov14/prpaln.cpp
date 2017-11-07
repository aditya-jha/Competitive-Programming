#include<iostream>
#include<string>

using namespace std;

bool isPalindrome(string s, int start, int end) {
    while( start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

int main() {
    int t;
    string s;

    cin>>t;

    while(t--) {
        cin>>s;

        int start = 0, end = s.length() - 1;
        while(s[start] == s[end] && start < end) {
            start++;
            end--;
        }

        if (start >= end) {
            // already and will be
            cout<<"YES\n";
        } else if (s[start+1] == s[end] && isPalindrome(s, start+1, end)) {
            cout<<"YES\n";
        } else if (s[start] == s[end-1] && isPalindrome(s, start, end-1)) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }

    return 0;
}
