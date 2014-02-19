#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class PrefixFreeSubsets {
public:
	bool myfunction(string, string);
	long long cantPrefFreeSubsets(vector <string>);
};

bool PrefixFreeSubsets::myfunction (string a,string b) { return (a.length()<b.length()); }

//bool func (string a,string b) { return (a.length()<b.length()); }
bool func (string a,string b) { return (a.length()<b.length() or a<b); }

long long PrefixFreeSubsets::cantPrefFreeSubsets(vector <string> words) {
	sort(words.begin(),words.end());
	
	long long int count[55];
	
	for(int i=0;i<words.size();i++) {
		count[i] = 1;
		for(int j=0;j<i;j++) {
			size_t found = words[i].find(words[j]);
			if(found!=0) count[i]+=count[j];
		}		
	}
	
	long long sol=1;
	for(int i=0;i<words.size();i++) sol+=count[i];
	
	return sol;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
