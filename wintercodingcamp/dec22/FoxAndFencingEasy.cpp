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

class FoxAndFencingEasy {
public:
	string WhoCanWin(int, int, int);
};

string FoxAndFencingEasy::WhoCanWin(int mov1, int mov2, int d) {
	if(d<=mov1 or (2*mov2)<mov1) return "Ciel";
	
	else if(2*mov1<mov2) return "Liss";
	
	else return "Draw";
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
