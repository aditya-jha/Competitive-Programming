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

class TeamContest {
public:
	int worstRank(vector <int>);
};

int TeamContest::worstRank(vector <int> strength) {
	int n = strength.size();
	int my,other,mini,maxi,counter;

	mini = strength[0];
	maxi = strength[0];
	
	for(int i=1;i<3;i++) {
		if(mini>strength[i]) mini = strength[i];
		if(maxi<strength[i]) maxi = strength[i];
	}
	
	my = mini+maxi;
	counter = 1;
	//cout<<my<<endl;
	sort(strength.begin()+3,strength.end());
	
	int start = 3, end = n-1;
	while(start<end) {
		other = strength[start]+strength[end];
		//cout<<other<<endl;
		if(other>my) {
			start+=2;
			end--;
			counter++;
		} else {
			start+=3;
		}
	}
	
	return counter;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
