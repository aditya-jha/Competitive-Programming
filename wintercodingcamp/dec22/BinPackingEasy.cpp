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

class BinPackingEasy {
public:
	int minBins(vector <int>);
};


int BinPackingEasy::minBins(vector <int> item) {
	sort(items.begin(),items.end());
	
	int cap=300,i=items.size()-1,j=0,counter=0;
	
	while(i>j) {
		if(item[i]+item[j]<=cap) {
			cap -= (item[i]+item[j]);
			i--; j++; 
			continue;
		}
		else if(item[i]<=cap) {
			cap -= item[i];
			i--; continue;
		}
		else if(item[j]<=cap) {
			cap -= item[j];
			j++; continue;
		}
		else {
			counter++;
			cap = 300;
		}
	}
	counter++;
	
	if(i==j) {
		if(item[i]>cap) counter++;
	}
	
	return counter;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
