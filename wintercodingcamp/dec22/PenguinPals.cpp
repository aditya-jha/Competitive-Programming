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
#include <cstring>

using namespace std;

class PenguinPals {

public:
	string ana(string);
	int findMaximumMatching(string);
	
};

int PenguinPals::findMaximumMatching(string colors) {
	string rem;
	
	bool connected[len];
	memset(connected,false,sizeof(connected));
	
	//if(len==1) return colors;	
	
	for(int i=0;i<len-1;i++) {
		if(connected[i]==true or connected[i+1]==true) continue;
		if(colors[i]==colors[i+1]) {
			connected[i] = true;
			connected[i+1] = true;
		}
	}
	if(connected[len-1]==false and connected[0]==false and len!=1) {
		if(colors[len-1]==colors[0]) {
			connected[len-1] = true;
			connected[0] = true;
		}
	}
	
	for(int i=0;i<len;i++) {
		if(connected[i]==false) {
			rem += colors[i];
		}
	}
	
	return rem;
}

int PenguinPals::findMaximumMatching(string colors) {
	int len = colors.length();
	int counter=0,add;
	string temp;
	
	while(true) {
		temp = ana(colors);
		add = ((colors.length()-temp.length())/2);
		if(add==0) break;
		colors = temp;
		counter+=add;
	}
	
	int n = temp.length();
	if(n%2==0) n++;
	add = ((n-2)/2);
	if(add<0) add=0; 
	//cout<<"counter: "<<counter<<", add: "<<add<<endl;
	counter+=add;
	
	return counter;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
