#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <utility>
#include <cmath>
#include <climits>

using namespace std;

#define MOD 1000000007
#define ld long
#define lu long unsigned 
#define llu long long unsigned
#define lld long long
#define INF -1

#define maxm(a,b) (a>b?a:b)
#define minm(a,b) (a<b?a:b)
#define REP(a) for(int i=0;i<a;i++)
#define REPR(a,b) for(int i=a;i<b;i++)
#define pb(a) push_back(a)
#define mk(a,b) make_pair(a,b)
#define DEBUG(a) cout<<a<<" "

const llu maxn = 1e19;

int main() {
	ios_base::sync_with_stdio(0);
	string s;
	int t,temp;
	size_t found;
	cin>>t;
	
	while(t--) {
		cin>>s;
		found = s.find("010");
  		if (found!=std::string::npos) {
  			cout << "Good\n";
  			continue;
  		}
  		found = s.find("101");
  		if (found!=std::string::npos) {
  			cout << "Good\n";
  			continue;
  		}
  		cout<<"Bad\n";
	}
	return 0;
}
