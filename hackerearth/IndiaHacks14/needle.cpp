#include<iostream>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

string p,t;
int lenP, lenT;
int a[30], b[30];
int sumP=0, sumT=0;

bool perform() {
    int index = lenP-1;
    
    while(true) {
        
        sumT += (int)t[index];                
        if(sumP == sumT) {
            for(int i=0;i<30;i++) b[i]=0;
            
            //cout<<index<<endl;    
            
            for(int i=index-lenP+1;i<=index;i++) {
                b[t[i]-'a']++;
            }    
            
            int flag=1;
            for(int i=0;i<30;i++) {
                if(a[i] != b[i]) {
                    flag = 0;
                }    
            }    
            if(flag==1) {
                return true;
            }    
        }  
        
        index++;  
        if(index==lenT) break;
        sumT -= (int)t[index-lenP];
        
    }    
    return false;
}    

int main() {
    int cases;
    cin>>cases;
    
    
    while(cases--) {
        cin>>p>>t;
        lenP = p.length();
        lenT = t.length();
        
        if(lenT < lenP) {
            cout<<"NO\n";
            continue;
        }    
        sumP = 0;
        sumT = 0;
        for(int i=0;i<30;i++) a[i] = 0;
    
        for(int i=0;i<lenP;i++) {
            sumP += (int)p[i];
            a[p[i]-'a']++;
        }    
        
        for(int i=0;i<lenP-1;i++) {
            sumT += (int)t[i];
        }    
        
        if(perform() == true) cout<<"YES\n";
        else cout<<"NO\n";
    }  
    
    return 0;  
}    
