#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<climits>
#include<cstdlib>
 
using namespace std;
 
int scan_d() {
int ip=getchar_unlocked(),ret=0;
for(;ip<'0'||ip>'9';ip=getchar_unlocked());
for(;ip>='0'&&ip<='9';ip=getchar_unlocked())
ret=ret*10+ip-'0';
 
return ret;
}
 
void print_d(int n) {
int i=10;
char output_buffer[11];output_buffer[10]='\n';
do {
output_buffer[--i]=(n%10)+'0';
n/=10;
} while(n);
do {
putchar_unlocked(output_buffer[i]);
} while(++i<11);
}
 
#define node pair<int,int>
#define point pair<int,node>
 
vector<point> v;
vector<node> a;
 
int foo(vector<node> &z) {
int len = z.size(), con=1;
int j=0;
for(int i=1;i<len;i++) {
if(z[i].second >= z[j].first) {
con++;
j = i;
}
}
return con;
}
 
int main() {
int t,n,s,f,p,k,sol;
t = scan_d();
//cin>>t;
while(t--) {
//cin>>n>>k;
n = scan_d(); k = scan_d();
if(n==0) {
cout<<"0\n";
continue;
}
v.clear();
//cout<<v.size()<<endl;
for(int i=0;i<n;i++) {
//cin>>s>>f>>p;
s = scan_d(); f= scan_d(); p = scan_d();
v.push_back(make_pair(p,make_pair(f,s)));
}
sort(v.begin(),v.end());
sol = 0;
for(int i=0;i<v.size();) {
a.clear();
int temp = v[i].first;
while(i<v.size() and v[i].first == temp) {
a.push_back(make_pair(v[i].second.first,v[i].second.second));
i++;
}
sort(a.begin(),a.end());
sol += foo(a);
}
print_d(sol);
// cout<<sol<<endl;
}
}
