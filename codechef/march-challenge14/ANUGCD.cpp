#include <string.h>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <complex>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std;

#define mp(a, b) make_pair(a, b)
#define det(a, b, c, d) (a * d - c * b)
#define sbstr(s, i, j) s.substr(i, j - i + 1)

#define EPS 1e-9
#define PI acos(-1.0)
#define MOD 1000000007
#define IINF 1000000000
#define LINF 6000000000000000000LL

#define y0 asdjaksjd
#define y1 asjdhasdh
#define yn asdkajsddd
#define j1 poaisdmsdkd
#define tm alsdkjdshdbnd
#define lr askdjdjjrt

#ifdef ALPHA_RAU_PROJECT
std::ofstream fout("debug.out");
#define print_var(a) {fout << "Debug : " << __LINE__ << " " << #a << "=" << a << endl;}
#define print_data(c) {print_var(#c) \
for(__typeof((c).begin()) ittrrrry=(c).begin();ittrrrry!=(c).end();ittrrrry++) \
cout << *ittrrrry << " ";}
#else
#define print_var(a) {}
#define print_data(a) {}
#endif

const int maxN = 100000 + 7;

struct Data {
int maxMul;
int prFactor;
int maxMulCnt;

Data () : maxMul(-1), maxMulCnt(-1), prFactor (-1) {}
Data (int pf, int mm, int mmc) : prFactor(pf), maxMul(mm), maxMulCnt(mmc) {}
};

int n, q;
int sieve[maxN], a[maxN];
int l[maxN], factorization[maxN][10];
vector < Data > merge_sort_tree[maxN << 2];

void build_merge_sort_tree (int v, int tl, int tr) {
if(tl == tr) {
for(int i = 0; i < l[a[tl]]; ++i) {
merge_sort_tree[v].push_back(Data(factorization[a[tl]][i], a[tl], 1));
}
}
else {
int tm = (tl + tr) >> 1;
build_merge_sort_tree(v << 1, tl, tm);
build_merge_sort_tree((v << 1) | 1, tm + 1, tr);
int ptrl = 0, wl = merge_sort_tree[v << 1].size() - 1;
int ptrr = 0, wr = merge_sort_tree[(v << 1) | 1].size() - 1;
while(ptrl <= wl && ptrr <= wr) {
if(merge_sort_tree[v << 1][ptrl].prFactor == merge_sort_tree[(v << 1) | 1][ptrr].prFactor) {
                            if(merge_sort_tree[v << 1][ptrl].maxMul == merge_sort_tree[(v << 1) | 1][ptrr].maxMul)
                                merge_sort_tree[v].push_back(Data(merge_sort_tree[v << 1][ptrl].prFactor, merge_sort_tree[v << 1][ptrl].maxMul,
                                            merge_sort_tree[v << 1][ptrl].maxMulCnt + merge_sort_tree[(v << 1) | 1][ptrr].maxMulCnt));
                            else if(merge_sort_tree[v << 1][ptrl].maxMul < merge_sort_tree[(v << 1) | 1][ptrr].maxMul)
                                merge_sort_tree[v].push_back(merge_sort_tree[(v << 1) | 1][ptrr]);
                            else
                                merge_sort_tree[v].push_back(merge_sort_tree[v << 1][ptrl]);
                            ++ptrr, ++ptrl;
}
else if(merge_sort_tree[v << 1][ptrl].prFactor < merge_sort_tree[(v << 1) | 1][ptrr].prFactor) {
                            merge_sort_tree[v].push_back(merge_sort_tree[v << 1][ptrl]);
                            ++ptrl;
}
else {
                            merge_sort_tree[v].push_back(merge_sort_tree[(v << 1) | 1][ptrr]);
                            ++ptrr;
}
}
                while(ptrr <= wr)
                    merge_sort_tree[v].push_back(merge_sort_tree[(v << 1) | 1][ptrr++]);
                while(ptrl <= wl)
                    merge_sort_tree[v].push_back(merge_sort_tree[v << 1][ptrl++]);
}
}

Data query (int v, int tl, int tr, int l, int r, int num) {
    if(l > r)
        return Data ();
    if(tl == l && tr == r) {
        int lo = 0, hi = merge_sort_tree[v].size() - 1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            int x = merge_sort_tree[v][mid].prFactor;
            if(num == x) {
                return merge_sort_tree[v][mid];
            }
            else if(x < num) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return Data ();
    }
    else {
        int tm = (tl + tr) >> 1;
        Data q1 = query(v << 1, tl, tm, l, min(r, tm), num);
        Data q2 = query((v << 1) | 1, tm + 1, tr, max(l, tm + 1), r, num);
        Data ret;
        if(q1.maxMul == q2.maxMul) {
            ret.maxMul = q1.maxMul;
            ret.maxMulCnt = q1.maxMulCnt + q2.maxMulCnt;
        }
        else if(q1.maxMul < q2.maxMul) {
            ret = q2;
        }
        else {
            ret = q1;
        }
        return ret;
    }
}
        
int main () {
memset(sieve, -1, sizeof(sieve));
sieve[0] = sieve[1] = 1;
for(int i = 2; i <= 100000; ++i) {
if(sieve[i] == -1) {
sieve[i] = i;
if(i > 1000) continue;
for(int j = i * i; j <= 100000; j += i)
sieve[j] = i;
}
}
l[1] = 1;
factorization[1][0] = 1;
for(int i = 2; i <= 100000; ++i) {
int num = i;
l[num] = 0;
while(num > 1) {
int factor = sieve[num];
factorization[i][l[i]++] = factor;
while(num % factor == 0) {
num /= factor;
}
}
}
scanf("%d%d", &n, &q);
for(int i = 0; i < n; ++i) {
scanf("%d", a + i);
}
build_merge_sort_tree(1, 0, n - 1);
        for(int i = 0; i < q; ++i) {
            int g, x, y;
            scanf("%d%d%d", &g, &x, &y);
            --x, --y;
            Data answer;
            if(g == 1) {
                puts("-1 -1");
                continue;
            }
            for(int j = 0; j < l[g]; ++j) {
                Data ans = query(1, 0, n - 1, x, y, factorization[g][j]);
                if(ans.prFactor != -1) {
                    if(ans.maxMul > answer.maxMul) {
                        answer = ans;
                    }
                }
            }
            printf("%d %d\n", answer.maxMul, answer.maxMulCnt);
        }

        return 0;
}
