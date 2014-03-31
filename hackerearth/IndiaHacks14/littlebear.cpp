#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
 
using namespace std;

string s,t1,t2;
vector<int> a,b;


void computeLPSArray(string pat, int M, int *lps);
 
void KMPSearch(string pat, string txt) {
    int M = pat.length();
    int N = txt.length();

    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;
 
    computeLPSArray(pat, M, lps);
 
    int i = 0; 
    while(i < N) {
        if(pat[j] == txt[i]) {
            j++;
            i++;
        }        
        if (j == M) {
            //printf("Found pattern at index %d \n", i-j);
            a.push_back(i-j);
            j = lps[j-1];
        }
        else if(pat[j] != txt[i]) {
            if(j != 0) j = lps[j-1];
            else i = i+1;
        }
    }
    free(lps); // to avoid memory leak
}

void KMPSearchB(string pat, string txt) {
    int M = pat.length();
    int N = txt.length();

    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;
 
    computeLPSArray(pat, M, lps);
 
    int i = 0; 
    while(i < N) {
        if(pat[j] == txt[i]) {
            j++;
            i++;
        }        
        if (j == M) {
            //printf("Found pattern at index %d \n", i-j);
            b.push_back(i-j);
            j = lps[j-1];
        }
        else if(pat[j] != txt[i]) {
            if(j != 0) j = lps[j-1];
            else i = i+1;
        }
    }
    free(lps); // to avoid memory leak
}
 
void computeLPSArray(string pat, int M, int *lps) {
    int len = 0; 
    int i;
 
    lps[0] = 0; 
    i = 1;
 
    while(i < M) {
        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if( len != 0 ) {
                len = lps[len-1];
            }
            else {
                lps[i] = 0;
                i++;
            }
       }
    }
}

vector<string> v;

void solve() {
	
    v.clear();
    
    for(int i=0;i<a.size();i++) {
        for(int j=0;j<b.size();j++) {
                       
            if(a[i]>b[j]) continue;
            string temp = s.substr(a[i]+t1.length(), b[i]-a[i]+t1.length());                          
            v.push_back(temp);
            
        }    
    }   
    
    int counter=0;
    if(v.size()>0) counter++;
    
    sort(v.begin(), v.end());

    for(int i=1;i<v.size();i++) {
        if(v[i].compare(v[i-1]) != 0) counter++;
    }    
     
    cout<<counter<<endl;
}    

int main() {
    
    while(cin>>s) {
        cin>>t1>>t2;
        a.clear(); b.clear();
        KMPSearch(t1,s);
        
        KMPSearchB(t2,s);
 
        solve();
        
    }    
    return 0;
}
