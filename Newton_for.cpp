#include <bits/stdc++.h>
using namespace std;

/*Rohan*/

int main() {

    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);

    cout << "Enter x values:\n";
    for (int i = 0; i < n; i++)
        cin >> x[i];

    cout << "Enter y values:\n";
    for (int i = 0; i < n; i++)
        cin >> y[i];

    double value;
    cout << "Enter the value of x to find f(x): ";
    cin >> value;

    // Difference table
    vector<vector<double>> diff(n, vector<double>(n));

    for (int i = 0; i < n; i++)
        diff[i][0] = y[i];

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
        }
    }

    double h = x[1] - x[0];

    double p = (value - x[0]) / h;

    double result = diff[0][0];
    double term = 1;

    for (int i = 1; i < n; i++) {

        term = term * (p - (i - 1)) / i;

        result += term * diff[0][i];
    }

    cout << "\nf(" << value << ") = " << result << endl;

    return 0;
}
