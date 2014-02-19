#include<iostream>
#include<cstdlib>
using namespace std;

int partition(int a[], int p, int r) {
	int x = a[r], i = p-1;
	for(int j=p; j<r; j++) {
		if(a[j] <= x) {
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[r]);
	return i+1;
}

void quicksort(int a[], int p, int r) {
	if(p<r) {
		int q = partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}

int main()
{
    int k,n;
    cin>>k;
    cin>>n;
    int a[k];
    for(int i=0;i<k;i++)
        a[i]=rand()%n+1;
quicksort(a,0,n-1);
	for(int i=0;i<k;i++)
    cout<<a[i]<<endl;
    return 0;
}
