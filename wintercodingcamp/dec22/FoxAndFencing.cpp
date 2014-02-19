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

class FoxAndFencing {
public:
	string WhoCanWin(int, int, int, int, int);
};

string FoxAndFencing::WhoCanWin(int mov1, int mov2, int rng1, int rng2, int d) {
	if(d <= (mov1+rng1)) return "Ciel";
	else if(d+mov1<=(mov2+rng2)) retrun "Liss";
	else if((mov1>mov2) and (2*mov2+rng2)<(mov1+rng1)) return "Ciel";
	else if((mov2>mov1) and (2*mov1+rng1)<(mov2+rng2)) return "Liss";
	else return "Draw";
}


<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
