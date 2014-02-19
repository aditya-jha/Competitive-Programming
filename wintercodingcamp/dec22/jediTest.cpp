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

class TheJediTest {
public:
	int minimumSupervisors(vector <int>, int);
};

int TheJediTest::minimumSupervisors(vector <int> students, int k) {
	int n = students.size();

        students.push_back(0);
        students.push_back(0);
        
        int counter=0;
        
        for (int i = 1; i<=n; i++) {
        	int j = students[i-1];
                
                counter += (j/k);
                j %= k;
                
                if (j>0) {
                	counter++;
                	
                	int temp = min(k-j, students[i]);
                	students[i] -= temp;
                	
                	int left = min(k-j-temp, students[i+1]);
                	students[i+1] -= left;
                }
        }
        
        return counter;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
