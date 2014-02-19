#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
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

#define max(a,b) (a>b?a:b)

class TheTree {
public:
	int maximumDiameter(vector <int>);
};

int TheTree::maximumDiameter(vector <int> cnt) {
	int n = cnt.size(), sol=0, flag;
	
	for(int i=0;i<n;i++) {
		flag=0;
		for(int j=i;j<n;j++) {
			if(cnt[j]==1) {
				//flag=1;
				sol = max(sol,n-i+j-i);
				break;
			}
		}
		sol = max(sol,2*(n-i));
	}
	
	return sol;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
