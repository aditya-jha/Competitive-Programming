#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>
     
#define getcx getchar_unlocked
     
using namespace std;
     
inline int in( ) {
    	int n=0;
    	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ) {
    		//if(ch=='-')sign=-1;
		ch=getcx();
	}
	while( ch >= '0' && ch <= '9' )
    		n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    	return n*sign;
}
     
void print_d(int n) {
    	int i=10;
    	char output_buffer[11];output_buffer[10]='\n';
    	do {
    		output_buffer[--i]=(n%10)+'0';
    		n/=10;
    	} while(n);
    	do {
    		putchar_unlocked(output_buffer[i]);
    	} while(++i<11);
}
     
int N,M,t,u,v,counter,temp,root,flag=0;
char color[100010],col;

vector<vector<int> > p(100010,vector<int>());
     
void BFS() {
	int ex[temp];
	for(int i=0;i<temp;i++) ex[i] = 0;
    	
    	char cc = color[u];
    	queue<int> Q;
    	Q.push(u);
     
    	while(!Q.empty()) {
    		v = Q.front();
    		Q.pop();
    		ex[v] = 1;
    		
    		for(int i=0;i<p[v].size();i++) {
    			if(color[p[v][i]]==cc and ex[p[v][i]]==0) {
    				Q.push(p[v][i]);
    				counter++;
    			}
    		}
	}
}
     
int main() {
     
    	N = in();
    	temp = N+1;
    	for(int i=0;i<temp;i++) {
    		color[i] = 'w';
    		//p.push_back(vector<int>());
    	}

    	color[0] = 'k';
    	
    	for(int i=1;i<N;i++) {
    		u = in();
    		v = in();
    		p[u].push_back(v);
    		p[v].push_back(u);
    	}
	     
    	M = in();

    	while(M--) {
    		t = in();
    		u = in();
    		if(t==0) {
    			if(flag==1) {
    				counter=1;
    				BFS();
    				print_d(counter);
    				break;
    			}
    			else { print_d(N); }
    		}
    		else {
    			if(color[u]=='w') color[u]='b';
    			else color[u] = 'w';
    			flag = 1;
    		}
    	}
    	
    	while(M>0) {
    		t = in();
    		u = in();
    		if(t==0) {
    			counter = 1;
    			BFS();
    			print_d(counter);
    		} else {
    			if(color[u]=='w') color[u]='b';
    			else color[u] = 'w';
    		}
    		M--;
    	}
    	return 0;
}

