#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<utility>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	
	int t,index;
	char temp[5],tt;
	
	cin>>t;
	cin.getline(temp,1);
	
	while(t--) {
		char f[30], c[150010];
		
		vector<pair<int,char> > v;
		for(int i=97;i<123;i++) {
			v.push_back(make_pair(0,(char)i));
		}
		
		cin.getline(f,30);
		cin.getline(c,150005);
		
		index = strlen(c);
		
		for(int i=0;i<index;i++) {
			if(((int)c[i])>96 and ((int)c[i])<123) {
				v[((int)c[i])-97].first++;
			}
			else if(((int)c[i])>64 and ((int)c[i])<91) {
				v[((int)c[i])-65].first++;
			}
		}
		
		sort(v.begin(),v.end());
		
		for(int i=0;i<v.size();i++) cout<<v[i].second<<" ";
		cout<<endl;
		
		
		char *cc = new char[30];
		int j=strlen(f)-1;
		for(int i=v.size()-1;i>-1;i--) {
			cc[((int)v[i].second)-97] = f[j];
			cout<<v[i].second<<" : "<<f[j]<<endl;
			j--;
		}
		cout<<endl;
		//for(int i=0;i<27;i++) cout<<cc[i]<<" ";
		//cout<<endl;
		
		//cout<<"cc[m]: "<<cc[12]<<endl;
		
		for(int i=0;i<index;i++) {
			//cout<<"here\n";
			if(((int)c[i])>96 and ((int)c[i])<123) {
				cout<<cc[c[i]-97];
			} 
			else if(((int)c[i])>64 and ((int)c[i])<91) {
				tt = cc[((int)c[i])-65];
				tt += 'A' - 'a';
				cout<<tt;
			}
			else cout<<c[i];
		}
		cout<<'\n';
		delete[] cc;
	}
	return 0;
}
