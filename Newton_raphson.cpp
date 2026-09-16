#include <bits/stdc++.h>
using namespace std;

/*Rohan*/

int n;
double cof[20];

double f(double x) {
    double sum = 0;
    for (int i = 0; i <= n; i++) {
        sum = sum * x + cof[i];
    }
    return sum;
}

double df(double x) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum * x + cof[i] * (n - i);
    }
    return sum;
}

int main() {
    cout << "Enter degree: ";
    cin >> n;

    cout << "Enter coefficients (from highest power to constant term):\n";
    for (int i = 0; i <= n; i++) {
        cin >> cof[i];
    }

    cout << "\nEquation:\n";
    for (int i = 0; i <= n; i++) {
        int power = n - i;
        if (i > 0 && cof[i] >= 0) cout << "+";
        cout << cof[i];
        if (power == 1) cout << "x";
        else if (power > 1) cout << "x^" << power;
    }
    cout << endl;

    cout << "Derivative eqn:\n";
    for (int i = 0; i < n; i++) {
        int power = n - i - 1;
        double d_cof = cof[i] * (n - i);
        if (i > 0 && d_cof >= 0) cout << "+";
        cout << d_cof;
        if (power == 1) cout << "x";
        else if (power > 1) cout << "x^" << power;
    }
    cout << endl;

    double max_ratio = 0;
    for (int i = 1; i <= n; i++) {
        max_ratio = max(max_ratio, abs(cof[i] / cof[0]));
    }
    double high = 1.0 + max_ratio;
    double low = -high;

    cout << "Interval: [" << low << ", " << high << "]\n\n";

    double step = 0.1;
    double E = 0.0001;
    double x = low;
    int rootCount = 0;

    // Search intervals for roots
    while (x < high && rootCount < n) {
        double y = min(high, x + step);

        // Check for root sign change in interval [x, y]
        if (f(x) * f(y) <= 0) {
            rootCount++;
            int iteration = 0;
            double xn = (x + y) / 2.0;
            double xnext = xn;

            while (iteration < 1000) {
                double derivative = df(xn);

                if (abs(derivative) < 1e-9) {
                    cout << "Derivative close to 0; stopping iteration.\n";
                    break;
                }

                xnext = xn - f(xn) / derivative;

                if (abs(xnext - xn) < E && abs(f(xnext)) < E) {
                    break;
                }

                xn = xnext;
                iteration++;
            }

            cout << "Bracket: [" << x << ", " << y << "]\n";
            cout << "Root: " << xnext << "\n\n";
        }
        x = y;
    }

    return 0;
}
