#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
	vector<double> v;
	double temp;
	while(scanf("%lf",&temp)!=EOF) {
		v.push_back(sqrt(temp));
	}
	for(int i=v.size()-1;i>-1;i--) {
		printf("%.4lf\n",v[i]);
	}
	return 0;
}

