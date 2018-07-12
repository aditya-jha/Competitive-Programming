#include<iostream>

using namespace std;

int main() {
    int duration, depRecords;
    double downPayment, loanAmount, monthlyPayment;

    cin>>duration>>downPayment>>loanAmount>>depRecords;

    while(duration > 0) {
        int* depMonths = new int[depRecords];
        double* depPercents = new double[depRecords];

        monthlyPayment = loanAmount/duration;

        for(int i=0; i<depRecords; i++) {
            cin>>depMonths[i]>>depPercents[i];
        }

        double carValue = downPayment + loanAmount;
        double worth = downPayment + loanAmount;
        double owed = loanAmount;
        int month = 0, r = 0;

        if (depRecords > 0 && depMonths[0] == 0) {
            worth -= (carValue * depPercents[0]);
            r++;
        }

        while(owed >= worth) {
            month++;
            if (r < depRecords && depMonths[r] == month) {
                worth -= (worth * depPercents[r]);
                r++;
            } else {
                if (r > 0) {
                    worth -= (worth * depPercents[r-1]);
                }
            }
            owed -= monthlyPayment;
        }
        
        delete[] depMonths;
        delete[] depPercents;

        cout<<month;
        if (month == 1) {
            cout<<" month\n";
        } else {
            cout<<" months\n";
        }

        cin>>duration>>downPayment>>loanAmount>>depRecords;
    }

    return 0;
}