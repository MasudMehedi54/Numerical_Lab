#include <bits/stdc++.h>
using namespace std;

/* Rohan */

int n;
double a[20];

double f(double x)
{
    double sum = 0;

    for(int i = 0; i <= n; i++)
        sum = sum * x + a[i];

    return sum;
}

double df(double x)
{
    double sum = 0;

    for(int i = 0; i < n; i++)
        sum = sum * x + a[i] * (n - i);

    return sum;
}

int main()
{
    cout << "Enter degree: ";
    cin >> n;

    cout << "Enter coefficients:\n";

    for(int i = 0; i <= n; i++)
        cin >> a[i];

    // Print polynomial
    cout << "\nPolynomial: ";

    for(int i = 0; i <= n; i++)
    {
        int power = n - i;

        if(i > 0 && a[i] >= 0)
            cout << "+";

        cout << a[i];

        if(power > 1)
            cout << "x^" << power;
        else if(power == 1)
            cout << "x";
    }

    // Find hi
    double hi = 0;

    for(int i = 1; i <= n; i++)
    {
        double temp = abs(a[i] / a[0]);

        if(temp > hi)
            hi = temp;
    }

    hi = 1 + hi;

    double low = -hi;

    cout << "\nRange = [" << low << ", " << hi << "]\n";

    double period = 0.45;
    double error = 0.001;

    cout << "\n===== NEWTON-RAPHSON =====\n";

    double x = low;
    int rootNo = 0;

    while(x < hi && rootNo<n)
    {
        double y = min(x + period, hi);

        // Check whether root is inside this bracket
        if(f(x) * f(y) < 0)
        {
            double xn = (x + y) / 2;
            double xnext = xn;

            int iteration = 0;

            while(iteration < 1000)
            {
                if(abs(df(xn)) < 1e-12)
                    break;

                xnext = xn - f(xn) / df(xn);

                iteration++;

                if(abs(xnext - xn) < error)
                    break;

                xn = xnext;
            }

            rootNo++;

            cout << "\nRoot " << rootNo << " = "
                 << fixed << setprecision(6) << xnext;

            cout << "\nBracket = [" << x << ", " << y << "]";

            cout << "\nIterations = "
                 << iteration << endl;
        }

        x = y;
    }

    return 0;
}
