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

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	
	int a,b;
	int wina,winb,draw=0,diffa,diffb;
	
	cin>>a>>b;
	
	wina = 0;
	winb = 0;
	
	for(int i=1;i<7;i++) {
		diffa = abs(i-a);
		diffb = abs(b-i);
		//cout<<diffa<<" "<<diffb<<endl;
		if(diffa<diffb) { wina++; }
		else if(diffa==diffb) { draw++; }
		else winb++;
	}	
	
	cout<<wina<<" "<<draw<<" "<<winb<<'\n';
	
	return 0;
}
