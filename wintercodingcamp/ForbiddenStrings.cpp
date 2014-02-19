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

class ForbiddenStrings {
public:
	long long countNotForbidden(int);
};

long long ForbiddenStrings::countNotForbidden(int n) {
	long long int rep[n+2], non[n+2], sol;
	
        rep[0] = 1; rep[1] = 3; rep[2] = 6;
        non[1] = 0; non[2] = 3;
        
        for (int i=3; i<=n; i++) {
        	rep[i] = rep[i-1]+(2*non[i-1]);
        	
        	non[i] = rep[i-1]+non[i-1];
        }
        
        sol = rep[n]+non[n];
        
        return sol;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
