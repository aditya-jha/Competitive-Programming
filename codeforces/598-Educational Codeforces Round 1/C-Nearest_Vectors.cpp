#include<iostream>
#include<cmath>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

#define PI 3.14159265

bool comp(pair<int, double> a, pair<int, double> b) {
    return a.second < b.second;
}

int main() {
    int t, minI;
    double x,y;
    vector< pair<int, double> > v;

    cin>>t;

    int index = 1;
    while(t--) {
        cin>>x>>y;
        double theta = atan(abs(y)/abs(x)) * 180/PI;

        if (x<=0 && y<=0) {
            theta = theta - 180;
        } else if(x<=0 && y>=0) {
            theta = 180 - theta;
        } else if(x>=0 && y<=0) {
            theta = -1*theta;
        }
        if (theta >= 360) {
            theta = theta - 360;
        }
        v.push_back(make_pair(index++, theta));
    }

    sort(v.begin(), v.end(), comp);

    int l = v[0].first, r = v[v.size()-1].first;
    double minDiff = v[v.size()-1].second - v[0].second;

    for(int i=1; i<v.size(); i++) {
       double diff = v[i].second - v[i-1].second;
       if (diff < minDiff) {
           minDiff = diff;
           l = v[i-1].first;
           r = v[i].first;
       }
    }

    cout<<l<<" "<<r<<endl;

    return 0;
}
