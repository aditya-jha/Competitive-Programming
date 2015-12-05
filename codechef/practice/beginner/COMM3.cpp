#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int r;
        double x1,y1,x2,y2,x3,y3;

        cin>>r;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;

        double x1x2 = sqrt((x1-x2)*(x1-x2) + (y2-y1)*(y2-y1));
        double x1x3 = sqrt((x1-x3)*(x1-x3) + (y3-y1)*(y3-y1));
        double x3x2 = sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));

        //cout<<x1x2<<" "<<x1x3<<" "<<x3x2<<endl;
        if(x1x2 <= r && x1x3 <= r) {
            cout<<"yes\n";
        }
        else if(x1x2 <= r && x3x2 <= r) {
            cout<<"yes\n";
        }
        else if(x3x2 <= r && x1x3 <= r) {
            cout<<"yes\n";
        }
        else cout<<"no\n";
    }

    return 0;
}
