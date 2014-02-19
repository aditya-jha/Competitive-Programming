#include<stdio.h>
#include<string.h>

int R,C;
char map[51][51];

int monster(int x,int y) {
    int l=0,r=0,t=0,b=0,i;
    for(i=x-1; i>-1; i--) { if(map[i][y]=='^') t++; else break;   }
    if(t<2) return 0;
    for(i=x+1; i<R; i++) { if(map[i][y]=='^') b++; else break; }
    if(b<2) return 0;
    for(i=y-1; i>-1; i--) { if(map[x][i]=='^') l++; else break; }
    if(l<2) return 0;
    for(i=y+1; i<C; i++) { if(map[x][i]=='^') r++; else break; }
    if(r<2) return 0;           
    
    return 1;
}

int main() {
    int t;
    scanf("%d",&t);    
    while(t--) {
        int i,j,count=0;
        scanf("%d %d",&R,&C);
//        printf("%d %d\n",R,C);
        getchar();
        for(i=0; i<R; i++) gets(map[i]);
        //for(i=0; i<R; i++) puts(map[i]);
        
        for(i=2; i<R-2; i++) {
            for(j=2; j<C-2; j++) {
                if(map[i][j]=='^') count+=monster(i,j);                                      
            }
        }        
        printf("%d\n",count);
    }    
    return 0;       
}        
