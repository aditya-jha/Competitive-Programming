#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxM = 22;
const int maxN = 20000 + 7;

int n, m;
int k[maxM], g[maxM], a[maxM][maxN];

int main () {
    
    scanf("%d%d", &n, &m);
    
    for(int i = 0; i < m; ++i) {
        scanf("%d", k + i);
        for(int j = 0; j < k[i]; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    
    memset(g, 0, sizeof(g));
    
    for(int i = 0; i < m; ++i) {
        for(int j = i + 1; j < m; ++j) {
            bool ok = true;
            int x = 0, y = 0;
            while(x < k[i] && y < k[j]) {
                if(a[i][x] == a[j][y]) {
                    ok = false;
                    break;
                }
                else if(a[i][x] > a[j][y]) {
                    y++;
                }
                else {
                    ++x;
                }
            }
            if(ok) {
                g[i] ^= 1 << j;
                g[j] ^= 1 << i;
            }
        }
    }
    int ans = 0;
    for(int mask = 0; mask < (1 << m); ++mask) {
        bool ok = true;
        int msk = mask, bc = 0;
        for( ; msk; msk &= msk - 1) ++bc;
        for(int i = 0; i < m; ++i) {
            if((mask & (1 << i)) == 0)
                continue;
            for(int j = i + 1; j < m; ++j) {
                if((mask & (1 << j)) == 0)
                    continue;
                if((g[i] & (1 << j)) == 0)
                    ok = false;
            }
        }
        ans = max(ans, ok * bc);
    }
    
    printf("%d\n", ans);

    return 0;
}
