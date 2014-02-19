#include<iostream>
#include<string>
using namespace std;

int main() {
    long long int t=0;
    cin>>t;
    while(t>0) {
        string s;
        long long int days=0,count=0;
        cin>>s;
        for(int i=0; i<s.length(); i++) {
            if(s[i]=='.') {
                int j=i;
                long long int jump=0;
                while(s[j]=='.') {
                    jump++;
                    j++;
                }    
                i=j;
                if(jump>count) {
                    days++;
                    count=jump;
                }    
            } else continue;    
        }    
        cout<<days<<endl;
        t--;
    }
    system("pause");        
    return 0;
}    
