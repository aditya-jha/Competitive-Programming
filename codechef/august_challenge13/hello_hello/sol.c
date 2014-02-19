#include<stdio.h> 
int main() { 
	int T,N,M,C,U,i,j,Ans; 
	int D1,D2,R1,R2,X,Y,A,B; 
	double Q,W,Z,MAX; 
	char Buf[100]; 
	scanf("%d",&T); 
	while(T--) { 
		Ans=0; 
		MAX=0; 
		scanf("%lf%d%d",&Q,&U,&N); 
		sprintf(Buf,"%.2lf",Q); 
		sscanf(Buf,"%d.%d",&D1,&D2); 
		for(i=0;i<N;i++) { 
			scanf("%d%lf%d",&M,&W,&C); 
			sprintf(Buf,"%.2lf",W); 
			sscanf(Buf,"%d.%d",&R1,&R2); 
			X=U*D1*M;A=U*D2*M; 
			X=X*100+A; 
			Y=U*M*R1+C;
			B=U*M*R2; 
			Y=Y*100+B; 
			Z=(X-Y)/M; 
			if(Z>MAX) { 
				Ans=i+1; 
				MAX=Z; 
			} 
		} 
		printf("%d\n",Ans); 
	} 	
	return 0; 
}
